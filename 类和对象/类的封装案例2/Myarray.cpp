#include"myArray.h"



	myArray::myArray()
	{
		cout << "无参构造函数调用" << endl;
		this->m_Capaity = 100;
		this->m_Size = 0;
		this->pAddress = new int[100];
	}//默认构造函数，可限制容量为100
	myArray::myArray(int m_capacity)
	{
		cout << "you参构造函数调用" << endl;
		this->m_Capaity = m_capacity;  //理解this解决名字冲突的作用
		this->m_Size = 0;
		this->pAddress = new int[this->m_Capaity];
	}//有参构造函数，可以自定义容量	

	myArray::myArray(const myArray &p) 
	{
		cout << "拷贝函数调用" << endl;
		this->m_Capaity = p.m_Capaity;  //理解this解决名字冲突的作用
		this->m_Size = p.m_Size;
		
		this->pAddress = new int[p.m_Capaity];
		for (int i = 0; i <m_Size; i++)
		{
			this->pAddress[i] =p.pAddress[i];
		}
	}//拷贝函数
	int& myArray:: operator[](int index)
	{
		return this->pAddress[index];
	}
	myArray::~myArray()
	{
		cout << "析构函数调用" << endl;
		if(this->pAddress!=NULL)
		{
			delete [] this->pAddress;
			this->pAddress = NULL;
		}
	}//析构函数

	//尾插法
	void myArray:: pushback(int val)
	{
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//设置对应位置数值
	void myArray::SetData(int pos, int val)
	{
		this->pAddress[pos] = val;
	}

	//获取对应位置数据
	int myArray::GetData(int pos)
	{
		return (this->pAddress[pos]);
	}
	//获取数组容量
	int myArray::GetCapacity()
	{
		return this->m_Capaity;
	}
	//获取数组大小
	int myArray::GetSize()
	{
		return this->m_Size;
	}
