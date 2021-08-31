#include "pch.h"
#include "Robot.h"

Robot::Robot()
{
	int mx = 0, my = 0;
	dau = Hcn(mx - 5, my, mx + 5, my + 10);
	than = Hcn(dau.x1 - 10, dau.y2, dau.x2 + 10, dau.y1 + 20);
	chan = Hcn(than.x1 + 4, than.y2, than.x2 - 4, than.y2 + 10);
}

Robot::Robot(int mx, int my)
{
	dau = Hcn(mx - 5, my, mx + 5, my + 10);
	than = Hcn(dau.x1 - 10, dau.y2, dau.x2 + 10, dau.y1 + 20);
	chan = Hcn(than.x1 + 4, than.y2, than.x2 - 4, than.y2 + 10);
}

void Robot::venhinh(CClientDC* pdc)
{
	dau.vehinh(pdc);
	than.vehinh(pdc);
	chan.vehinh(pdc);
}

void Robot::nhaylen()
{
	int i = 0;
	for (i = 0; i < 16; i++)
	{
		dau.dichlen();
		than.dichlen();
		chan.dichlen();
		Sleep(20);
	}
	for (i = 0; i < 16; i++)
	{
		dau.dichxuong();
		than.dichxuong();
		chan.dichxuong();
		Sleep(20);
	}
}
