#include<iostream>
#include<Windows.h>
#include<string>
//int a = 10;
using namespace std;
//template<class T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	/*enum WM
//	{
//		MAN,
//		WOMAN
//	};*/
//	//printf("%d", Add<char>('1', '2'));
//	//cout << Add(1.1, 2.2);
//	/*printf("%d\n", '0');
//	printf("%d\n", '\0');
//	printf("%d\n", 48);*/
//
//	
//	/*enum WM b=MAN;
//	cout << a << endl;
//	cout << b << endl;
//	printf("%s",b );*/
//	system("pause");
//	return 0;
//}
void TestString1()
{
	string a("hello world");//���캯��
	cout << a << endl;
	string b(a);//��������
	cout << b << endl;
	string c = a;//��ֵ���������
	cout << c << endl;
	string d;
	cout << d << endl;
	string e(7, 'a');//����7���ַ�'a',
	cout << e << endl;
}

void TestString2()
{
	string a("hello world");
	cout << a.size() << endl;//Ԫ�ظ���
	cout << a.length() << endl;//Ԫ�ظ���
	cout << a.capacity() << endl;//�ռ�����
	cout << a.empty() << endl;//�пգ���Ϊ1������Ϊ��0
	a.clear();//�����ͷ�
	cout << a.size() << endl;
	cout << a.length() << endl;
	cout << a.capacity() << endl;
	cout << a.empty() << endl;

}

void TestString3()
{
	string a("wolf guidao");
	a.reserve(20);//���ռ�ı䣬����һ��capacity��䣬������С��һ����ı�
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	
	a.reserve(40);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.reserve(30);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.reserve(14);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.reserve(8);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.resize(10, '!');
	cout << a << endl;

	a.resize(20, '!');
	cout << a << endl;	
}

void TestString4()
{
	string a("wolf guidao");//�±����
	cout << a[0] << a[4] << endl;
	//cout << a[20];
	cout << a.at(0) << a.at(4) << endl;
	for (auto i : a)//��Χfor��ӡ
	{
		cout << i;//i���Ƕ�����ÿ��Ԫ�صĿ���
	}
	cout << endl;
	for (int i = 0;i < a.size();i++)
	{
		cout << a[i];
	}
	cout << endl;
	string::iterator it = a.begin();//�������������
	while (it != a.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}

void TestString5()
{
	string a("wolf guidao");
	a.push_back(' ');//��ĩβ׷��һ���ַ�
	a.push_back('I');
	a.append(" Love");//��ĩβ׷��һ���ַ���
	a += ' ';//���������
	a.append("you");
	cout <<a.c_str() << endl;//תΪC��ʽ�ַ�
	string b ("hello world");
	cout << b.c_str() << endl;;
	cout << a << endl;
}

void TestString6()
{
	string a("wolf guidao");
	//cout << a.find('o') << endl;
	a[a.find('w')] = 'W';
	cout << a << endl;
	a[a.rfind('g')] = 'G';
	cout << a << endl;
	cout << a.find("lf") << endl;
	if (a.find("lf") == string::npos)//npos��һ��������ֵΪ-1��һ���ʾ�����ڣ���Ϊ�����find��rfind���ҵ��ַ����ַ����ͻ᷵�ض�Ӧ�±꣬һ��û���ҵ����ͻ᷵��npos
	{
		cout << "δ�ҵ��ַ�" << endl;
	}
	else
	{
		cout << "�ҵ����ַ�" << endl;
	}


	if (a.find('o',1)==string::npos)
	{
		cout << "δ�ҵ��ַ�" << endl;
	}
	else
	{
		cout << "�ҵ����ַ�" << endl;
	}
	
	cout << a.substr(a.find(' ')) << endl;
	cout << a.substr() << endl;//Ĭ�ϴӿ�ʼ��ȡ�����ַ�
	cout << a.substr(0, 4) << endl;
	cout << a.substr(2, 20) << endl;//��2��ʼ��ȡ20���ַ�

}

void TestString7()
{
	string a;
	//cin >> a;//ע��cin/cout�����ո����һ���ַ�����������������ַ������пո�͵���getline������ȡһ���ַ���
	string b;
	//cin >> b;
	getline(cin, a);//ע���÷�
	getline(cin, b);
	cout << a << endl;
	cout << b << endl;
	

}

void TestString8()
{
	string a("wolf guidao");
	string b("wolf Guidao");
	cout << a << endl;
	cout << b << endl;
	swap(a, b);
	cout << a << endl;
	cout << b << endl;
	int x = 10;
	int y = 20;
	swap(x, y);
	cout << x << endl;
	cout << y << endl;
	//cout << a > b  << endl;

}

void TestString9()
{
	string a("12345");
	string b("wolf guidao");
	//b += a;
	reverse(b.begin()+2,b.end()-2);
	string::iterator it = b.begin(); it < b.end();
	//b.erase(0,1);
	cout << b << endl;
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	TestString9();

	system("pause");
	return 0;
}