#include "framework.h"
#include "stdafx.h"
#include "Utils.h"
#include "cTimer.h"
#pragma once
cTimer::cTimer() :
	fr(0),
	c1(0),
	c2(0)
{
	//c2=c1=0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&c1);
	c2 = c1;
}

cTimer::~cTimer() {};

void cTimer::reset() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&c1);
	c2 = c1;

}

LONGLONG cTimer :: get() {
	set();
	return c2 - c1;
}

float cTimer :: getns() {
	set();
	return (c2 - c1) * (1000000.0f / fr);
}

float cTimer :: getms() {
	set();
	return (c2 - c1) * (1000000.0f / fr) / 1000.0f;
}

float cTimer :: gets() {
	set();
	return (c2 - c1) * (1000000.0f / fr) / 1000000.0f;
}

double cTimer :: getdns() {
	return double((c2 - c1) * (1000000.0 / fr));
}

double cTimer :: getdms() {
	return double((c2 - c1) * (1000000.0 / fr) / 1000.0);
}

double cTimer:: getds() {
	return double((c2 - c1) * (1000000.0 / fr) / 1000000.0);
}

void cTimer :: set() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&c2);

}

float cTimer :: getFPS() {
	return 1.0f / (getns() / 1000000.0f);
}

float cTimer :: FPS() {
	set();
	return 1.0f / (getns() / 1000000.0f);
}
	
