#pragma once
#include "Hcn.h"
class Robot
{
public:
	Hcn dau, than, chan;
	Robot();
	Robot(int mx, int my);
	void venhinh(CClientDC* pdc);
	void nhaylen();


};

