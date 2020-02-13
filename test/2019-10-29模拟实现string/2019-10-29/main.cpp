#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

namespace wolf
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")//���캯��
		{
			if (str == nullptr)//���������Ϊ��ָ�룬��������Ϊ"",�����Ϳ��Է�ֹ�������
			{
				str = "";
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];//����ռ�
			strcpy(_str, str);//��str�е����ݿ�����ȥ
		}

		string(const string& s)//�������캯�����������
			:_size(s._size)
			,_capacity(s._size+1)
		{
			_str = new char[_capacity];
			strcpy(_str, s._str);
		}

		string& operator=(string& s)//��ֵ���������
		{
			if (this != &s)
			{
				string temp(s._str);//���ù��캯����s���ַ�������һ�ݣ���ֹǳ��������
				swap(_str, temp._str);
			}
			return *this;
		}

		~string()//��������
		{
			if (_str)//��Ϊ�ղŽ����ͷţ���������ͷ�
			{
				_size = 0;
				_capacity = 0;
				delete[] _str;
				_str = nullptr;
			}
		}

		size_t Size()const//�����ַ�������
		{
			return _size;
		}

		size_t Capacity()const//���ؿռ�����daxiao
		{
			return _capacity;
		}

		bool Empty()const//�п�
		{
			return _size == 0;
		}

		iterator begin()//��������ע��������ķ�Χ����[begin,end))
		{
			return _str;//�����ַ����׵�ַ
		}

		iterator end()
		{
			return _str + _size;//�����ַ������һ��λ�ã���\0��
		}

		void Reserve(size_t newcapacity)//�����ռ��С
		{
			
			if (newcapacity > _capacity)//����¿ռ��С���ھɿռ��С�Ž���
			{
				char* strtemp = new char[newcapacity + 1];//��һ����Ϊ�˷�'\0'
				strcpy(strtemp, _str);
				delete[]_str;
				_str = strtemp;
				_capacity = newcapacity;//�¿ռ��С����newcapacity+1��Ϊ�˺������string����һ��
			}
		}

		void Resize(size_t newsize,char ch)//�ѿռ�����Ч�ַ���������Ϊnewsize�ģ�����Ŀռ���ch���
		{
			size_t oldsize = Size();
			if (newsize < oldsize)//�����������Ч�ַ�����С��ԭ���ַ�����
			{
				_size = newsize;
				_str[_size] = '\0';
			}
			else
			{
				if (newsize > _capacity)//����������ַ��������ڿռ��������ͽ�������
				{
					Reserve(newsize);
				}
				memset(_str+_size, ch, newsize - oldsize);//��ԭ���ַ�����������ch
			}
			_size = newsize;
			_str[_size] = '\0';//�ǵü���\0
		}

		void Push_back(char ch)//��ԭ���ַ���ĩβ׷��һ���ַ�ch
		{
			if (_size == _capacity)//����
			{
				Reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)//���������
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			Push_back(ch);
			_size = _size + 1;
			return *this;
		}

		void Append(const char* str);//׷���ַ���
		string& operator+=(const char* str);//���������

		void Clear()//�ѿռ�����Ч�ַ��������
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void Swap(string& s)//������string�����е����ݽ�����ע��Ҫȫ������
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		const char* C_str()const//���ص�ǰ�����C��ʽ�ַ���
		{
			return _str;
		}

		char& operator[](size_t index)//���������
		{
			if (index < _size)
			{
				return _str[index];
			}
		}

		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;

		int Find(char ch, size_t pos = 0)const//��pos��ʼ����ǰ�������ַ�������ch���±�
		{
			for (size_t i = pos;i < _size;i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return -1;
		}

		int rFind(char ch, size_t pos = -1)const//��pos��ʼ���Ӻ���ǰ���ַ�������ch���±�
		{
			if (pos == npos)
			{
				pos = _size - 1;
			}
			for (size_t i = pos;i >= 0;i--)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}


		int Find(char* str, size_t pos = 0)const//��pos��ʼ����ǰ�������ַ���������str���±�
		{}
		int rFind(char* str, size_t pos = 0)const//��pos��ʼ���Ӻ���ǰ���ַ���������str���±�
		{}

		string& Erase(size_t pos,size_t num)//��pos��ʼɾ��num���ַ�
		{}
		
		string& Insert(size_t pos,char ch)//��pos�����ַ�ch
		{}
		string& Insert(size_t pos, char* str)//��pos�����ַ���str
		{}

		friend ostream& operator<<(ostream& _cout, const string& s)
		{
			_cout << s.C_str();
			return _cout;
		}
		friend istream& operator>>(istream& _cin, const string& s)
		{
			_cin >> s._str;
			return _cin;
		}

	private:
		char* _str;//����ַ���
		size_t _size;//�ַ�������
		size_t _capacity;//�ַ�������
		static size_t npos;
	};
}

size_t wolf::string::npos = -1;



void Teststeing()
{
	wolf::string a("wolf");
	//cout << a.Size() << endl;
	//cout << a.Capacity() << endl;
	wolf::string b(a);
	//cout << b.Size() << endl;
	//cout << a.Capacity() << endl;
	b.Resize(10, '!');
	//cout << b << endl;
	//cout << b.Size() << endl;
	//cout << b.Capacity() << endl;
	b.Reserve(30);
	//cout << b.Capacity() << endl;
	b.Push_back(' ');
	b.Push_back('i');
	//cout << b << endl;
	//b.Clear();
	//cout << b << endl;
	//cout << b.Find('o') << endl;
	//cout << b.rFind('o') << endl;
	//cout << b.C_str() << endl;
	wolf::string::iterator it = b.begin();
	/*while (it < b.end())
	{
		cout << *it;
		it++;
	}*/
	//cout << endl;
	/*for (auto e: b)
	{
		cout << e;
	}*/
	//cout << endl;
	wolf::string c;
	cin >> c;
	cout << c;
}

int main()
{
	Teststeing();
	system("pause");
	return 0;
}
