#include "gui.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"


extern const uint8_t locked[];
extern const uint8_t unlocked[];
extern const uint8_t X[];
extern const uint8_t blocked[];


void GUI_init(void)
{
	ssd1306_Init();
	GUI_Start();
}

void GUI_locked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(20, 5);
	ssd1306_WriteString("Error", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, X, 30, 30, White);
	ssd1306_UpdateScreen();
}

void GUI_unlocked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(20, 5);
	ssd1306_WriteString("Sucess", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, unlocked, 30, 30, White);
	ssd1306_UpdateScreen();
}

void GUI_Blocked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(10, 5);
	ssd1306_WriteString("Blocked", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, blocked, 30, 30, White);
	ssd1306_UpdateScreen();
}

void GUI_Start(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(10, 5);
	ssd1306_WriteString("Welcome", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, locked, 30, 30, White);
	ssd1306_UpdateScreen();
}

void GUI_Password(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 5);
	ssd1306_WriteString("Password", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, locked, 30, 30, White);
	ssd1306_UpdateScreen();
}

void GUI_update_password_init(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 5);
	ssd1306_WriteString("New PW:", Font_16x26, White);
	ssd1306_UpdateScreen();
}

void GUI_update_password(uint8_t *password)
{
	ssd1306_SetCursor(10, 35);
	ssd1306_WriteString((char *)password, Font_7x10, White);
	ssd1306_UpdateScreen();
}

void GUI_update_password_success(void)
{
	ssd1306_SetCursor(5, 35);
	ssd1306_WriteString("Success!", Font_16x26, White);
	ssd1306_UpdateScreen();
}

