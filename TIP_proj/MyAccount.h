#pragma once
#include <windows.h>
#include <pjsua2.hpp>
#include <iostream>
#include <functional>
#include "MyCall.h"
using namespace pj;
typedef std::function<void()> FunctionPtr;
class MyAccount : public Account
{
public:
	std::vector<Buddy*> buddies;
	MyCall* active_call;

public:
	~MyAccount();

	void removeCall(Call* call);
	virtual void onRegState(OnRegStateParam& prm);
	virtual void onIncomingCall(OnIncomingCallParam& iprm);
};

