#include <easyx.h>
#include "../inc/Message.h"

static MouseMessage mouse;

void PeekInputMessage()
{
	ExMessage msg;
	
	mouse.isUp = false;
	mouse.isDown = false;
	while (peekmessage(&msg, EX_MOUSE))
	{
		if (msg.message == WM_MOUSEMOVE)
		{
			mouse.x = msg.x;
			mouse.y = msg.y;
		}
		else if (msg.message == WM_LBUTTONUP)
		{
			mouse.isUp = true;
			mouse.isDown = false;
		}
		else if (msg.message == WM_LBUTTONDOWN)
		{
			mouse.isUp = false;
			mouse.isDown = true;
		}
	}
}
bool IsKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000);
}
MouseMessage* GetMouseMessage()
{
	return &mouse;
}