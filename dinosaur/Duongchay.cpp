#include "pch.h"
#include "Duongchay.h"

Duongchay::Duongchay()
{
	duongvien = Hcn(XDAU, YDAU, XDAU + 1500, YDAU + 400);
	int a[5];
	a[0] = 20;
	a[1] = 15;
	a[2] = 25;
	a[3] = 30;
	a[4] = 35;
	int h = rand() % 5;
	for (int i = 0; i < 5; i++)
	{
		h = rand() % 5;
		vatcan[i] = Hcn(XDAU + 50 + i* 300, duongvien.y2 - a[h], XDAU + 60 + i * 300, duongvien.y2);
	}

}

void Duongchay::vehinh(CClientDC* pdc)
{
	duongvien.vehinh(pdc);
	for (int i = 0; i < 5; i++)
		vatcan[i].vehinh(pdc);
}

void Duongchay::chay()
{
	//int dem = 0;
//	while (dem < 50)
//	{
	//	duongvien.vehinh(pdc);
		for (int i = 0; i < 5; i++)
		{
			vatcan[i].dichtrai();
			if (vatcan[i].x1 < duongvien.x1)
			{
				vatcan[i].x1 = duongvien.x2 - 10;
				vatcan[i].x2 = duongvien.x2;
				int a[5];
				a[0] = 20;
				a[1] = 15;
				a[2] = 25;
				a[3] = 30;
				a[4] = 35;
				int h = rand() % 5;
				vatcan[i].y1 = vatcan[i].y2 - a[h];
			}

	//		vatcan[i].vehinh(pdc);
		}
		
	//	dem++;
	//}
}

int Duongchay::chamrobot(Robot rb)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (vatcan[i].ktgiaonhau(rb.dau) == 1 || vatcan[i].ktgiaonhau(rb.than) == 1
			|| vatcan[i].ktgiaonhau(rb.chan) == 1)
			return 1;
	}
	return 0;
}
