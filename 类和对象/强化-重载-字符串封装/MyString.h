#pragma once
#include<iostream>
#include<string>
using namespace std;

class MyString
{
	friend istream & operator>>(istream &cin, MyString & p);
public:
	//构造函数
	MyString();
	MyString(char *S);
	
	//拷贝函数
	MyString(const MyString &p);

	//重载<<，成员函数无法实现
	//ostream& operator<<(MyString &p)
	
	//重载=
	MyString& operator=(const  MyString &p);
	MyString operator=(const char * S);
	//重载【】
	char& MyString::operator[](int index);
	//重载+
	MyString operator+(char * S);
	MyString operator+(MyString &p);

	char * GetString();
	//析构函数
	~MyString();

private:
	char * m_MyString;//在堆区开辟一个字符数组

	int m_Size;//字符串长度，不计算/0
};

ostream& operator<<(ostream &cout,MyString &p);
istream& operator>>(ostream &cin, MyString &p);
