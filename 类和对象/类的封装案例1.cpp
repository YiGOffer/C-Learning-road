#include "stdafx.h"
using namespace std;
#include<iostream>
#include<string>
const double PI = 3.14;
class circle
{
	
	//访问权限
public://公共权限


	//属性,即参数
	int m_r;
	int m_r1;
	
	//行为
	//获取圆的周长
	double calculateZC() 
	{
		return 2 * PI*m_r;
	}
};

int main()
{
	circle c1;
	c1.m_r = 10;
	cout << "圆的周长是：" << c1.calculateZC() << endl;
    return 0;
}
