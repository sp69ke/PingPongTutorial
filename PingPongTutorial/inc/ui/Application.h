#pragma once

#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include<string>
#include<unordered_map>

class Interface;

class Application final
{
private:
	std::unordered_map<std::wstring, Interface*> _interfaces;
	Interface* _currentInterface;
	Interface* _nextInterface;

public:
	Application();
	~Application();

	Application* RegisterInterface(Interface* intf);

	// Set to target interface immediately
	void ChangeInterface(const std::wstring& name);

	// Set to interace after currnt update
	void SetInterface(const std::wstring& name);

	void Update();
	void Draw();
};

#endif