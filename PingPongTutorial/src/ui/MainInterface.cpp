#include "../../inc/ui/Interface.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"

MainInterface::MainInterface()
	: Interface(L"Main")
{
	_pOnePlayerButton = new Button(Rect(350, 280, 100, 60), L"1 player");
	_pOnePlayerButton->SetDownStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
		->SetOnClick(_OnClickOnePlayerButton);
	_pTwoPlayerButton = new Button(Rect(550, 280, 100, 60), L"2 player");
	_pTwoPlayerButton->SetDownStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
		->SetOnClick(_OnClickTwoPlayerButton);

	_pExitButton = new Button(Rect(900, 460, 60, 60), L"Exit");
	_pExitButton->SetDownStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA)
		->SetOnClick(_OnClickExitButton);
}
MainInterface::~MainInterface() {
	delete _pOnePlayerButton;
	delete _pTwoPlayerButton;
	delete _pExitButton;
}
void MainInterface::Update()
{
	_pOnePlayerButton->Update();
	_pTwoPlayerButton->Update();
	_pExitButton->Update();
}
void MainInterface::Draw()
{
	RECT rect{ 0,0,1000,280 };

	LOGFONT style;
	gettextstyle(&style);
	settextstyle(100, 0, L"Consolas");
	drawtext(L"Ping Pong", &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(&style);

	_pOnePlayerButton->Draw();
	_pTwoPlayerButton->Draw();
	_pExitButton->Draw();
}
void MainInterface::_OnClickOnePlayerButton() 
{
	Application* app = GetApplication();
	app->ChangeInterface(L"Game");
}
void MainInterface::_OnClickTwoPlayerButton()
{
	Application* app = GetApplication();
	app->ChangeInterface(L"Game");
}
void MainInterface::_OnClickExitButton() 
{
	isRunning = false;
}