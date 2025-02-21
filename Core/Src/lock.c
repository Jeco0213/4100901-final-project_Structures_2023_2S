#include "lock.h"
#include "ring_buffer.h"
#include "keypad.h"
#include "main.h"
#include "gui.h"

#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD 12

uint8_t failed_counter = 0;

uint8_t password[MAX_PASSWORD] = "1992";

uint8_t keypad_buffer[MAX_PASSWORD];
ring_buffer_t keypad_rb;

extern volatile uint16_t keypad_event;

// Función para encender el LED
void Encender_LED(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

// Función para apagar el LED
void Apagar_LED(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

static uint8_t lock_get_passkey(void)
{
	while (ring_buffer_size(&keypad_rb) == 0) {
		/* wait for key press */
		uint8_t key_pressed = keypad_run(&keypad_event);
		if (key_pressed != KEY_PRESSED_NONE) {
			ring_buffer_put(&keypad_rb, key_pressed);
		}
	}
	uint8_t key_pressed;
	ring_buffer_get(&keypad_rb, &key_pressed);
	if (key_pressed == '*' || key_pressed == '#') {
		return 0xFF;
	}
	return key_pressed;
}

static uint8_t lock_get_password(void)
{
	uint8_t idx = 0;
	uint8_t passkey = 0;
	uint8_t new_password[MAX_PASSWORD];
	memset(new_password, 0, MAX_PASSWORD);
	uint8_t password_shadow[MAX_PASSWORD + 1]  = {
			'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\0'
	};
	while (passkey != 0xFF) {
		GUI_update_password(password_shadow);
		passkey = lock_get_passkey();
		password_shadow[idx] = '*';
		new_password[idx++] = passkey;
		GUI_update_password(new_password);
		HAL_Delay(200);
	}

	if (idx > 1) {
		memcpy(password, new_password, MAX_PASSWORD);
		GUI_update_password_success();
	} else {
		GUI_locked();
		return 0;
	}
	return 1;
}

static uint8_t lock_validate_password(void)
{
	uint8_t sequence[MAX_PASSWORD];
	uint8_t seq_len = ring_buffer_size(&keypad_rb);
	for (uint8_t idx = 0; idx < seq_len; idx++) {
		ring_buffer_get(&keypad_rb, &sequence[idx]);
	}
	if (memcmp(sequence, password, 4) == 0) {
		return 1;
	}
	return 0;
}

static void lock_update_password(void)
{
	if (lock_validate_password() != 0) {
		GUI_update_password_init();
		lock_get_password();
	} else {
		GUI_locked();
	}
}

static void lock_open_lock(void)
{
	if (lock_validate_password() != 0) {
		GUI_unlocked();
		Encender_LED();
		HAL_Delay(5*1000);
		failed_counter = 0; // reset the failure counter if succes
	} else {
		failed_counter++;
		if (failed_counter < 3) {
			/* 3.2 -> Show "Failed" if the string is incorrect */
			GUI_locked();
			HAL_Delay(3*1000);
		} else {
			/* 4 -> Show "Blocked" if the string is incorrect 3 times */
			GUI_Blocked();
			failed_counter = 0;
			HAL_Delay(10*1000);
		}
	}
	Apagar_LED();
}

void lock_init(void)
{
	ring_buffer_init(&keypad_rb, keypad_buffer, 12);
	GUI_init();
}

void lock_sequence_handler(uint8_t key)
{
	if (key == '*') {
		lock_update_password();
		HAL_Delay(5*1000);
	} else if (key == '#') {
		lock_open_lock();
	} else {
		ring_buffer_put(&keypad_rb, key);
	}

}
