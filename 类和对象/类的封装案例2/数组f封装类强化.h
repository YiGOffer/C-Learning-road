#pragma once
#include<iostream>
#include<string>
using namespace std;
//只做声明
class myArray 
{
//权限
public:
	/*********行为*********/
	myArray() ;//默认构造函数，可限制容量为100
	myArray(int m_capacity);//有参构造函数，可以自定义容量	

	myArray(const myArray &p);//拷贝函数

	~myArray();//析构函数
	
	//尾插法
	void pushback(int val);
	//设置对应位置数值
	void SetData(int pos,int val);

	//获取对应位置数据
	int GetData(int pos);
	//获取数组容量
	int GetCapacity();
	//获取数组大小
	int GetSize();
	//重载[] 运算符
	int& operator[](int index);
	
//属性
private:
	int m_Size;//数组大小
	int m_Capaity;//数组容量
	int *pAddress;//真实的在堆区开辟的数组的指针
};
