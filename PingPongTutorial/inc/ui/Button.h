#pragma once

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <easyx.h>
#include <string>
#include "..\Defines.h"

enum ButtonState
{
	BUTTON_UP = 0,
	BUTTON_HOVER,
	BUTTON_DOWN,
	BUTTON_STATE_NUM
};
class Button
{
private:
	Rect _range;
	COLORREF _color[BUTTON_STATE_NUM];
	std::wstring _text;

	void (*_onClick)(void);

public:
	Button(Rect& range, const std::wstring& text);

	Button* SetUpStyle(COLORREF color);
	Button* SetHoverStyle(COLORREF color);
	Button* SetDownStyle(COLORREF color);
	Button* SetText(const std::wstring& text);
	Button* SetOnClick(void (*onClick)(void));

	virtual void Update();
	virtual void Draw();
};
#endif