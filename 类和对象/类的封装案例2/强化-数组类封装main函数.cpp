#include"myArray.h"
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	myArray arr(10);
	for (int i = 0; i <arr.GetCapacity();i++)
	{
		arr.pushback(i);
		
	}
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr.GetData(i) << endl;
	}
	arr.SetData(0, 100);
	cout << "修改数组0位后" << endl;
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr.GetData(i) << endl;
	}
	arr[0] = 1000;//对【】运算符进行重载后 返回引用即地址就可以当左值，然后进行对改地址的值得修改。
	cout << "arr[0]= " << arr[0] << endl;
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr.GetData(i) << endl;
	}
}

int main()
{
	test01();
	
}
