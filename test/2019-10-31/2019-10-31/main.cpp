#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

namespace wolf
{
	template<class T>
	
	class vector
	{
	public:

		typedef T* iterator;

		int capacity()
		{
			return _endofstorage - _start;
		}

		int size()
		{
			return _finish - _start;
		}

		vector()//Ĭ���޲ι��캯��
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{

		}

		vector(int n,const T& value=T())//��TΪ��������ʱ��T()����0����TΪ�Զ�������ʱ��T()���ڵ��乹�캯��
			:_start(new T[n])
		{
			for (int i = 0;i < n;i++)
			{
				_start[i] = value;
			}
			_finish = _start + n;
			_endofstorage = _start + n;
		}
		template<class T1>//������������vector�ĵ���������ô��������ֻ����vector�ģ����Ե����¶����µĵ�������������������
		vector(T1 first, T1 last)//��Ϊ���乹����Ǹ������������Ͳ��������Ե���һ��ģ��
		{
			int n = 0;//��Ϊ��first��last����֮�䲻һ��ʱ�����ģ������������һ�����䣬���Բ�����first-last��Ԫ�ظ���
			while (first != last)
			{
				n++;
				first++;
			}
			_start = new T[n];
			for (int i = 0;i < n;i++)
			{
				_start[i] = *first;
				first++;
			}
			_finish = _start + n;//����
			_endofstorage = _finish;
		}

		//vector(const vector<T>& s)//��������
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	reserve(s.capacity);
		//	iterator it =
		//		delete[] _start;
		//		_start = str;
		//		_finish = _start + s.size();
		//		_endofstorage = _start + s.capacity();
		//}

		~vector()//����
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		void Swap(vector<T>& s)//����
		{
			swap(_start, s._start);
			swap(_finish, s._finish);
			swap(_endofstorage, s._endofstorage);
		}

		vector<T>& operator=(vector<T> s)//��ֵ���������
		{
			Swap(s);
			return *this;
		}

		void resize(size_t newsize, const T value = T())
		{
			if (newsize <= size())
			{
				_finish = _start + newsize;
			}
			else
			{
				if (capacity() < newsize)
				{
					reserve(newsize);
				}
				iterator it = begin();
				 _finish = it + newsize;
				while (it != _finish)
				{
					*it = value;
					it++;
				}
			}
		}

		void reserve(size_t newcapacity)//���ݲ���
		{
			size_t size1 = size();//�ȼ�¼Ԫ�صĸ�������Ϊsize�ļ��㷽��Ϊ_finish-_start;�����ڽ���_finish����ʱ
			//_finish���ھɿռ䣬��_start�Ѿ�ָ���¿ռ䣬�������_finish-_start�������ͻ����
			size_t oldcapacity = capacity();
			if (newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];
				if (_start)//��ֹ�ڹ��캯�������ã���Ϊ��ʱ_startΪ�գ��Ͳ��ܽ���Υ�����
				{
					for (int i = 0;i < size();i++)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + size1;
				_endofstorage = _start + newcapacity;
			}
		}

		void push_back(const T value = T())
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2+2);
			}
			*_finish = value;
			_finish++;
		}
		void pop_back()
		{
			_finish--;
		}
		T* insert(T* pos, const T& value)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() + 2);
			}
			T* _finish1 = _finish;
			while (_finish1 > pos)
			{
				_start[*_finish1] = _start[*(_finish1 - 1)];
				_finish--;
			}
			*pos = value;
			_finish++;
			return pos;
		}

		T* erase(T* pos)
		{
			if (_start)
			{
				T* pos1 = pos;
				while ((pos1+2) != _finish)
				{
					_start[*pos1] = _start[*(pos1 + 1)];
					pos1++;
				}
				_finish--;
			}
			return pos;
		}

	private:
		T* _start;//��ʼλ��
		T* _finish;//���һ��Ԫ�ص���һ��λ��
		T* _endofstorage;//�洢������ĩβ

	};
}

void Testvector()
{
	//wolf::vector <int>a(10,5);
	////cout<<a.size()<<endl;
	////cout << a.capacity()<<endl;
	///*wolf::vector<int>b(a);
	//cout << a.size() << endl;
	//cout << a.capacity() << endl;*/
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	/*wolf::vector<int>c(arr, arr + 8);
	cout << c.size() << endl;
	cout << c.capacity() << endl;
	c.reserve(10);
	c.push_back(99);
	cout << c.size() << endl;
	c.pop_back();
	cout << c.size() << endl;*/
	//wolf::vector <int>a(10, 5);
	//cout<<a.size()<<endl;
	wolf::vector <int>c(5, 5);
	//cout << c.size() << endl;
    /*a.Swap(c);
	cout << a.size() << endl;
	cout << c.size() << endl;*/
	c.push_back(9);
	//a.operator=(c);
	/*cout << a.size() << endl;*/
	cout << c.size() << endl;
	c.insert(c.begin()+8, 9999);
	cout << c.size() << endl;
	c.erase(c.begin()+4);
	cout << c.size() << endl;
}
int main()
{
	//int arr[] = { 12,3,4,56,7,8,9 };
	Testvector();
	//vector<int>a(arr, arr + 6);
	//cout << a.size() << endl;
	//a.insert(a.begin()+2, 99);
	system("pause");
	return 0;
}