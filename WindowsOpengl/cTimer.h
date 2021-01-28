#pragma once
class cTimer {
public:
	LONGLONG fr, // processador frequencia
		c1, // primeiro tempo
		c2; // segundo tempo
	cTimer();
	~cTimer();
	void   reset();
	LONGLONG get();
	float  getns();
	float  getms();
	float  gets();
	double getdns();
	double getdms();
	double getds();
	void   set();
	float  getFPS();
	float  FPS();
};
