#pragma once
#include <windows.h>
#include <pjsua2.hpp>
using namespace pj;

class MyBuddy :public Buddy
{
public:
	virtual void onBuddyState();
};

