#include "Mystring.h"
//有参构造

MyString::MyString()
{
	this->m_MyString = new char[10];
	//memset(m_MyString, 0, 10);
	cout << "无参构造函数调用" << endl;
}

MyString::MyString(char *S)
{
	cout << "有参构造函数调用" << endl;
	this->m_MyString = new char[strlen(S) + 1];
	strcpy(m_MyString, S);
	this->m_Size = strlen(S) ;
}



MyString::MyString(const MyString & p)
{
	cout << "拷贝函数调用" << endl;
	this->m_MyString = new char[strlen(p.m_MyString) + 1];
	strcpy(this->m_MyString, p.m_MyString);
}

MyString & MyString::operator=(const MyString & p)
{
	//判断
	if(this->m_MyString!=NULL)
	{
		delete[] this->m_MyString;
		this->m_MyString = NULL;
	}
	this->m_MyString = new char[strlen(p.m_MyString) + 1];
	strcpy(this->m_MyString , p.m_MyString);
	return *this;
}

MyString MyString::operator=(const char * S)
{
	if (this->m_MyString != NULL)
	{
		delete[] this->m_MyString;
		this->m_MyString = NULL;
	}
	this->m_MyString = new char[strlen(S) + 1];
	strcpy(this->m_MyString, S);
	return *this;
}

   char& MyString::operator[](int index)
{
	return  m_MyString[index];
}



MyString MyString::operator+(char * S)
{
	char * temp;
	int NewSize = this->m_Size + strlen(S) + 1;
	temp = new char[NewSize];
	memset(temp, 0, NewSize);
	strcat(temp, this->m_MyString);
	strcat(temp, S);
	
	MyString p1 = temp;//相当于有参构造

	return  p1;
}

MyString MyString::operator+(MyString & p)
{
	char * temp;
	int NewSize = this->m_Size + p.m_Size+1 ;
	temp = new char[NewSize];
	memset(temp, 0, NewSize);
	strcat(temp, this->m_MyString);
	strcat(temp, p.m_MyString);
	MyString p1 = temp;//相当于有参构造

	return  p1;
}

char * MyString::GetString()
{
	
	return this->m_MyString;
}

MyString::~MyString()
{
	cout << "析构函数调用" << endl;
	if(this->m_MyString!=NULL)
	{
		delete [] this->m_MyString;
		this->m_MyString = NULL;
	}
}
// 左移位运算符重载<<
ostream & operator<<(ostream &cout, MyString & p) 
{
	cout << p.GetString() << endl;
	// TODO: 在此处插入 return 语句
	return cout;
}
istream & operator>>( istream &cin,MyString & p)
{
	if (p.m_MyString != NULL)
	{
		delete[] p.m_MyString;
		p.m_MyString = NULL;
	}
	//char * buf;  //不能这样创建一个数组指针去接收 用户输入的东西
	char buf[1024];//要创建具体空间去接受用户输入的东西
	p.m_MyString = new char[strlen(buf) + 1];
	cin >> buf;
	strcpy(p.m_MyString,buf );
	// TODO: 在此处插入 return 语句
	return cin;
}
