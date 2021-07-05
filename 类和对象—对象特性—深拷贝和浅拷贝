///*********************深拷贝（有在堆区开辟空间）、浅拷贝************************/
class Person
{
public:
	Person()
	{
		cout << "无参构造函数调用" <<  endl;
	}

	Person(int age,int height)
	{
		m_height = new int(height);
		m_age = age;
		cout << "有参构造函数调用" << endl;
	}
	
	
	
	/******************************************/
	//为什么要传入引用即Person &p，因为如果main代码中Person p3(p2)相当于Person p3=p2,调用了拷贝构造函数，就相当于Person p=p2 又调用了拷贝构造函数即Person p=p2 无限递归出错
	如果这些知识你都能理解。下面就来解释一下为什么值传递会无限递归!
如果复制构造函数是这样的 ： 
test(test t);
我们调用
test ort;
test a(ort）; --> test.a(test t=ort)==test.a(test t(ort))
              -->test.a(test t(test t = ort))
                 ==test.a(test t(test t(ort)))
              -->test.a(test t(test t(test t=ort)))
	 /******************************************/
	
	
	Person(const Person &p)
	{
		m_age = p.m_age;
		//m_height = p.m_height; //编译器默认实现的拷贝 代码
		//深拷贝操作
		m_height = new int(*p.m_height);
	 	cout << "拷贝函数调用" << endl;
	}
	~Person()
	{
		if(m_height!=NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "析构函数调用" << endl;
		
	}
public:
	int m_age;
	int *m_height;
};

void test01()
{
	Person p1;
	Person p2(10,160);
	cout << "P2的年龄" <<p2.m_age<<" p2的身高"<<*p2.m_height<< endl;
	Person p3(p2);
	cout << "P3的年龄" << p3.m_age << " p3的身高" << *p3.m_height << endl;
	
}
int main()
{
	test01();
}



