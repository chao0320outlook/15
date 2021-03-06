// 15.11.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<ctime>
#include<cmath>
#include"15.10.h"
#include <iostream>

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using namespace std;

	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin>>x>>y)
	{
		try
		{
			z = hmean(x, y);
			cout << x << "和" << y << "的调和平均数是："<<z<<endl;
			cout << x << "和" << y << "的几何平均数是：" << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: " << endl;
		}
		catch(bad_hmean &bg)
		{
			bg.mesg();
			cout << "try again." << endl;
			continue;
		}
		catch (bad_gmean &hg)
		{
			cout<<hg.mesg();
			cout << "Value used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "Sorry, you don't get to play any more." << endl;
			break;;
		}
	}
	cout << "Bye!" << endl;

	int secs = 120;                                   //延时120s的程序
	clock_t delay = secs*CLOCKS_PER_SEC;             //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0*a*b/(a+b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a*b);
}
