#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
using namespace std;

#if 0
//���
namespace wolf
{
	class string
	{
	public:
		string(const char* str = "")//���캯��
			:_str(new char[strlen(str) + 1])
		{
			if (str == nullptr)
			{
				str = "";
			}
			strcpy(_str, str);
		}

		string(const string& s)//�������캯��
			:_str(nullptr)
		{
			//_str=s._str,���������ǳ����
			string strtemp(s._str);
			swap(_str, strtemp._str);
		}

		string& operator=(const string& s)//��ֵ���������
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				string strtemp(s._str);
				swap(_str, strtemp._str);
			}
			return *this;
		}

		~string()//��������
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

#endif

//ǳ����+���ü������ǳ�������⣺
//ͨ�����ַ��������Ҫ˼���ǣ�
//1.��ô�������ͷ�һ����Դ���⣺��ʱ�Ǻͽ��������һ�����߹ص�һ�����������֪����ǰ���ж��ٸ�������һ����Դ��
//��һ������׼���ͷ�ʱ��������ֻ��ж���ʹ�������Դ���Ͳ��ͷţ���ʱ�ͽ��һ����Դ����ͷ�����
//2.��ô֪����ǰ���ж��ٸ������������Դ�����ü���

#if 0
//һ���������캯���Ľ��������
//���1���ڳ�Ա�ж���һ��int�ͱ�����������¼���������Դ�Ķ���ĸ���
namespace wolf
{
	class string
	{
	public:
		string(const char* str = "")//���캯��
			:_str(new char[strlen(str) + 1])
		{
			if (str == nullptr)
			{
				str = "";
			}
			_count = 1;//��Ϊһ��ͨ�����캯��������һ������˵������������Դֻ�����Լ��ã���û���ü������Ͱ�_count��Ϊ1
			strcpy(_str, str);
		}

		string(string& s)//�������캯��
			:_str(s._str)//�ڿ������캯���в���ǳ�����ķ�ʽ
			,_count(++s._count)//string s1("wolf");string s2(s1);��ʱ�ж���s2ͨ���������캯������s1����������Դʱ��
			//�Ͱ�s1._count��1���������ڳ���s1�Լ��⻹�б��˹��������Դ��Ȼ���s1._count��ֵ����Ҫ����Ķ���s2��
			//��ʱs2._countҲ��¼�˵�ǰ����һ����Դ�Ķ���ĸ�����
		{
			
		}

		string& operator=(const string& s)//��ֵ���������
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				//.....
			}
			return *this;
		}

		~string()//��������
		{
			if (_str&&(--_count==0))//_count-1==0����˼�ǳ�ȥ�Լ��������ʹ�������Դ�⣬���Ϊ0�����������Լ�
				//û�����������������Դ����ʱ�ͷžͲ�������һ����Դ������ͷŵ����⣬��֮_count-1��=0�ͱ�ʾ
				//���ж���ʹ�������Դ����ʱ�Ͳ����ͷš�
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		int _count;
	};
}
//string s1("wolf");string s2(s1);ͨ�����Է������ַŷ��Ǵ���ģ���Ϊ��s2�ͷź�s2._countȷʵ�����ˣ�
//���ǵ�����ȥ�ͷ�s1ʱ��s1��s2._count��Ϊ2������s2��û���ͷţ����յ�����Դй¶

#endif

#if 0
//���2����Ϊ��һ�ַ����ŷ���Ҫ��_count��ͬ����ɵģ����Բ���static����_count�ķ���
namespace wolf
{
	class string
	{
	public:
		string(const char* str = "")//���캯��
			:_str(new char[strlen(str) + 1])
		{
			if (str == nullptr)
			{
				str = "";
			}
			_count = 1;//��Ϊһ��ͨ�����캯��������һ������˵������������Դֻ�����Լ��ã���û���ü��������ԾͰ�_count��Ϊ1
			strcpy(_str, str);
		}

		string(string& s)//�������캯��
			:_str(s._str)//�ڿ������캯���в���ǳ�����ķ�ʽ
		{
			_count++;//
		}

		string& operator=(const string& s)//��ֵ���������
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				//.......
			}
			return *this;
		}

		~string()//��������
		{
			if (_str && (--_count == 0))//_count-1==0����˼�ǳ�ȥ�Լ��������ʹ�������Դ�⣬���Ϊ0�����������Լ�
				//û�����������������Դ����ʱ�ͷžͲ�������һ����Դ������ͷŵ����⣬��֮_count-1��=0�ͱ�ʾ
				//���ж���ʹ�������Դ����ʱ�Ͳ����ͷš�
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		static int _count;
	};
	int string::_count = 0;
}
//���ַ�����һ�����ص����⣺������Ϊ_countʱ��̬�ģ������ж�����ģ���ִ��string s1("wolf guidao");
//string s2(s1);����ȫû������ģ���һ��ִ��string  s3;��Ϊs3������ͨ�����캯�������Ķ���ʹ�õ�������һ����Դ��
//û�к�s1s2������ʱ_count=1�������ͻ�Ӱ�쵽s1s2���ͷ�����,������ú���Դ��������һ�¡�

#endif

#if 0
//���⣺���ÿһ����Դ�����Լ���һ�����������������ͺ���Դ��������һ�£����Բ��ù�������ķ���
namespace wolf
{
	class string
	{
	public:
		string(const char* str = "")//���캯��
			:_str(new char[strlen(str) + 1])
			,_pcount(new int (1))//�ڶ�������һ���ռ䲢��ʼ��Ϊ1��
		{
			if (str == nullptr)
			{
				str = "";
			}
		    strcpy(_str, str);
		}

		string(string& s)//�������캯��
			:_str(s._str)//�ڿ������캯���в���ǳ�����ķ�ʽ
			,_pcount(s._pcount)//����ͬһ����Դ�ļ���
		{
			++(*_pcount);
		}

		string& operator=(const string& s)//��ֵ���������
		{
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				//.........
			}
			return *this;
		}

		~string()//��������
		{
			if (_str && (--(*_pcount) == 0))//_pcount-1==0����˼�ǳ�ȥ�Լ��������ʹ�������Դ�⣬���Ϊ0�����������Լ�
				//û�����������������Դ����ʱ�ͷžͲ�������һ����Դ������ͷŵ����⣬��֮_pcount-1��=0�ͱ�ʾ
				//���ж���ʹ�������Դ����ʱ�Ͳ����ͷš�
			{
				delete[] _str;
				_str = nullptr;
				delete _pcount;
				_pcount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pcount;
	};
}
//ִ��string s1("wolf guidao");string s2(s1);ͨ�����ַ���ÿ����Դ�����Լ��ļ����ռ䣬�������������s2�������
//��Դs1��ͬʱҲ�͹����������Դ�ļ�����string  s3;s3������һ����Դ��s3����Դ���ݺͼ����ռ䶼������һ�ݣ��Ͳ���
//����s1�����ݺ�s1����Դ���������ַ����ͽ��������һ�ַ����������⡣

#endif

#if 0
//������ֵ��������صĽ��������
//����������̵�ͺ����׵ĵ���ֵ��������صĽ������
namespace wolf
{
	class string
	{
	public:
		string(const char* str = "")//���캯��
			:_str(new char[strlen(str) + 1])
			, _pcount(new int(1))//�ڶ�������һ���ռ䲢��ʼ��Ϊ1��
		{
			if (str == nullptr)
			{
				str = "";
			}
			strcpy(_str, str);
		}

		string(string& s)//�������캯��
			:_str(s._str)//�ڿ������캯���в���ǳ�����ķ�ʽ
			, _pcount(s._pcount)//����ͬһ����Դ�ļ���
		{
			++(*_pcount);
		}
		//1.s3 = s2;�����ֵ�ɹ���s2��s3�ͻṲ��ͬһ����Դ��s2�Ƿ���Դ�Ͷ�һ������������Թ���s2�Ƿ���Դ�ļ�����1
		//2.s3ԭ�����Ƿ���Դ�Ͳ�����ʹ�ã�����Ҫ�ͷ�s3����ô����s3�����Դ�Ķ������һ�ݣ����Ծ���ðѹ���s3�ļ�����1
		//�����s3�ļ�����1��պ�Ϊ0����ʾֻ��s3ʹ����һ����Դ����ôΪ�˷�ֹ��Դй¶����Ҫ�ֶ��ͷ�
		string& operator=(const string& s)//��ֵ���������
		{
			//��ʱ_pcountΪs3��s._pcountΪs2
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				if (--(*_pcount) == 0)
				{
					delete[] _str;
					delete _pcount;
				}
				_str = s._str;
				_pcount = s._pcount;
				++(*_pcount);
			}
			return *this;
		}

		~string()//��������
		{
			if (_str && (--(*_pcount) == 0))//_pcount-1==0����˼�ǳ�ȥ�Լ��������ʹ�������Դ�⣬���Ϊ0�����������Լ�
				//û�����������������Դ����ʱ�ͷžͲ�������һ����Դ������ͷŵ����⣬��֮_pcount-1��=0�ͱ�ʾ
				//���ж���ʹ�������Դ����ʱ�Ͳ����ͷš�
			{
				delete[] _str;
				_str = nullptr;
				delete _pcount;
				_pcount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pcount;
	};
}
#endif

//���Ͻ��ǳ�����ķ���Ҳ�������⣺����޸Ķ���s3�е���Դʱs3[0] = 'W';���ͷ����������乲����Դ�Ķ���s1,s2Ҳ������
//�ı䣬�൱��һ��ȫ�Ľ�������������ô�����һ���⡣
//�������ǳ����+���ü�����ȱ�ݣ�дʱ����copy on write(COW)������ֻ��Բ��֣�
//string s1("wolf guidao");string s2(s1);string  s3;s3 = s2;ǰ��Ĵ��붼��û������ģ�����s3[0] = 'W';�ͻ�������⣬
//�������������⣻����ý����жϣ��������������s1��s2���������Դ����Ӧ����������ռ��s3�������������Ұѹ�
//��������Դ����һ�ݣ�����һ��ȫ�ĵ����⣬�����дʱ���������û�����������s3����ͬһ����Դ���Ͳ��÷��롣

//��������ʱ�������е�д����||����ܻ�����д������Ӧ����
namespace wolf
{
	class string
	{
	public:
		string(const char* str = "")//���캯��
			:_str(new char[strlen(str) + 1])
			, _pcount(new int(1))//�ڶ�������һ���ռ䲢��ʼ��Ϊ1��
		{
			if (str == nullptr)
			{
				str = "";
			}
			strcpy(_str, str);
		}

		string(string& s)//�������캯��
			:_str(s._str)//�ڿ������캯���в���ǳ�����ķ�ʽ
			, _pcount(s._pcount)//����ͬһ����Դ�ļ���
		{
			++(*_pcount);
		}
		//1.s3 = s2;�����ֵ�ɹ���s2��s3�ͻṲ��ͬһ����Դ��s2�Ƿ���Դ�Ͷ�һ������������Թ���s2�Ƿ���Դ�ļ�����1
		//2.s3ԭ�����Ƿ���Դ�Ͳ�����ʹ�ã�����Ҫ�ͷ�s3����ô����s3�����Դ�Ķ������һ�ݣ����Ծ���ðѹ���s3�ļ�����1
		//�����s3�ļ�����1��պ�Ϊ0����ʾֻ��s3ʹ����һ����Դ����ôΪ�˷�ֹ��Դй¶����Ҫ�ֶ��ͷ�
		string& operator=(const string& s)//��ֵ���������
		{
			//��ʱ_pcountΪs3��s._pcountΪs2
			if (this != &s)//��ֹ�Լ����Լ���ֵ
			{
				if (--(*_pcount) == 0)
				{
					delete[] _str;
					delete _pcount;
				}
				_str = s._str;
				_pcount = s._pcount;
				++(*_pcount);
			}
			return *this;
		}

		~string()//��������
		{
			if (_str && (--(*_pcount) == 0))//_pcount-1==0����˼�ǳ�ȥ�Լ��������ʹ�������Դ�⣬���Ϊ0�����������Լ�
				//û�����������������Դ����ʱ�ͷžͲ�������һ����Դ������ͷŵ����⣬��֮_pcount-1��=0�ͱ�ʾ
				//���ж���ʹ�������Դ����ʱ�Ͳ����ͷš�
			{
				delete[] _str;
				_str = nullptr;
				delete _pcount;
				_pcount = nullptr;
			}
		}
		char& operator[](size_t index)//�±����������
		{
			//�ò������ܻ�ı䵱ǰ��������ݣ��Ӷ�������������������ݵĸı䣬������ò��÷��뵱ǰ�������
			if (Getpcount() > 1)//���������ͱ�ʾ��������������Դ������÷���
			{
				string strtemp(_str);
				this->Swap(strtemp);
			}
			return _str[index];
		}
		//ִ��s3[0] = 'W'ʱ����Ϊs1��s2���乲��һ����Դ����ʱ����strtemp._strָ��ԭ��s3������Ƿ�_str��
		//strtemp._pcountָ��_pcount�������ú���ʱ������_pcount��ֵ���Ƿ�Ҫ�ͷ���Դ��
		//����ͷŶ���s3ʱ����Ϊstrtemp��ͨ�����캯��string strtemp(_str);�������ģ�����strtrmp._pcount=1������
		//������s3._pcount=1������s3���������ͷš�

		void Swap(string& s)//������������
		{
			swap(_str, s._str);//�����ַ�������
			swap(_pcount, s._pcount);//������Դ����
		}

	private:
		int Getpcount()
		{
			return *_pcount;
		}

		char* _str;
		int* _pcount;
	};
}

void TestMystring()
{
	wolf::string s1("wolf guidao");
	wolf::string s2(s1);
	wolf::string  s3;
	s3 = s2;
	s3[0] = 'W';
}

int main()
{
	TestMystring();
	system("pause");
	return 0;
}

