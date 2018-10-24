#include "stdafx.h"
#include <iostream>
#include <windows.h>
//#include <thread>
//#include <conio.h>

using namespace std;

void points(double Rad, double a, double b)
{
	double x, y, line, circle;
	Rad = pow(Rad, 2);
	while (1)
	{
		cout << "(Press Esc to exit) Give me your point: ";
		cin >> x >> y;
		circle = pow(x, 2) + pow(y, 2);
		line = a * x + b;
		if (x > 0 && line > y && circle <= Rad)
			cout << "It's in zone.\n\n";
		else
			cout << "Thats a miss.\n\n";
		cout << "Continue?(1-yes,2-no)";
		cin >> x;
		if (x == 2)
			break;
	}
}

int main()
{
	double Rad,a,b,cross;
	do
	{
		cout << "Programm 23-1 ready to serve.\nInput Radius: ";
		cin >> Rad;
		cout << "Nice, now input \"a\" and \"b\" from y=ax+b: ";
		do
		{
			cin >> a >> b;
			cross = pow(2 * a*b, 2) - 4 * (pow(a, 2) + 1)*(pow(b, 2) - pow(Rad, 2));
			if (cross > 0)
				break;
			cout << "We have no zone, try another A or B: ";
		} while (1);
		cout << "We have a zone.\n";
		points(Rad, a, b); //thread вот тут
		cout << "Continue?(1-yes,2-no)";
		cin >> a;
		if (a == 2)
			break;
	} while (1);
	
	
	/*
	thread PointList(points, Rad, a, b);
	MSG Mess;
	bool bRet=false;
	while (1)
	{
		bRet = PeekMessage(&Mess, NULL, NULL, NULL, PM_NOREMOVE);
		if (bRet == 1)
			cout << "hi";
		if (bRet != false)
		{
			cout << "if";
			TranslateMessage(&Mess);
			DispatchMessage(&Mess);
			cout << Mess.message;
			if (Mess.message == 0x0100)
				if (Mess.wParam == VK_ESCAPE)
				{
					if (PointList.joinable())
						PointList.join();
					break;
				}
		}
	}*/
    return 0;
}



