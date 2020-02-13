#include<iostream>
#include<CoreWindow.h>
using namespace std;

#if 0

class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<string> ret;//�洢���
		int B_info[26] = { 0 };//������¼B������ÿ����ĸ���ֵ�������
		for (int i = 0; i < B.size(); i++)//����B
		{
			int temp_info[26] = { 0 };//��ʱ�洢
			for (auto j : B[i])//����B��ÿ�������string
			{
				temp_info[j - 'a']++;//��ʱ��¼B��ÿ��string��ÿ����ĸ���ֵĴ���
				B_info[j - 'a'] = max(B_info[j - 'a'], temp_info[j - 'a']);//��Ϊ������ͬһ����ĸ���ֶ�Σ���������²���ֻ��¼һ�Σ�B_info��Ӧ���ÿ����ĸ���ֵ�������
			}
		}
		for (auto i : A)//����A
		{
			int temp1_info[26] = { 0 };//��ʱ�洢A��ÿ����ĸ���ֵĴ���
			for (auto j : i)//����A��ÿ��string
			{
				temp1_info[j - 'a']++;//�洢A��ÿ����ĸ���ֵĴ���
			}
			int k = 0;//��ʱ����������ѭ��
			while (k < 26)
			{
				if (temp1_info[k] >= B_info[k])//�������A��ÿ����ĸ�ĳ��ֵĴ������ڵ���B_info�м�¼�Ľ�����ͼ���ѭ��
				{
					k++;
				}
				else//һ������С�ڵ������ֱ��break���Ͳ����ڽ����ж�
				{
					break;
				}
			}
			if (k == 26)//����ߵ����˵��A��ÿ����ĸ������������ֱ�Ӱ�����ַ���β�嵽ret��
			{
				ret.push_back(i);
			}
		}
		return ret;
	}
};
#endif


#if 0

#include<string>
class Solution {
public:
	void replaceSpace(char *str, int length) {
		/*
		string ret=str;
		auto it=ret.begin();
		int i= 0;
		while(it!=ret.end())
		{
			i = ret.find(" ");
			if(i<0)
			{
				break;
			}
			else
			{

				if(it!=ret.end())
				it=it+1;
			}

		}
		char* newstr=ret.c_str();
		str=(char*)newstr;
		*/
		char* newstr = new char[length * 2];
		int k = 0;
		if (str == nullptr || length < 0)
		{
			str = nullptr;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (str[i] == ' ')
				{
					newstr[k++] = '%';
					newstr[k++] = '2';
					newstr[k++] = '0';
				}
				else
				{
					newstr[k++] = str[i];
				}
			}
			newstr[k] = '\0';
			str = newstr;
			cout << str;
		}
	}
};

class Solution
{
	//ע�⣬һ��Ҫ��stack1�е�Ԫ����stack2�зţ�һ��Ҫ��ȫ��
	//ֻ��stack2Ϊ��ʱ��������stack2�з�Ԫ��
public:
	void push(int node) {
		stack1.push(node);

	}

	int pop() {
		if (stack2.empty())//�������stack2Ϊ�գ��Ͱ�stack1�е�����Ԫ�ض��嵽stack1�У�
			//��ס�����У�����һ����
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			int ret = stack2.top();
			stack2.pop();
			return ret;
		}
		else//�������stack2�л���Ԫ�أ���ʱ�����ܰ�stack1�е�Ԫ����stack2�в��룬
			//��Ϊ�����Ƚ��ȳ��ģ�stack2�е�Ԫ�����Ƚ����ģ�������ȳ�ȥ��
			//��stack2�е�Ԫ����ȫ��ջ���ܽ�����ջ������
		{
			int ret = stack2.top();
			stack2.pop();
			return ret;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

class Solution {
public:
	int rectCover(int number) {
		//����쳲�����
		if (number == 0 || number == 1 || number == 2)
		{
			return number;
		}
		return rectCover(number - 1) + rectCover(number - 2);

		/*
		if(number==0||number==1||number==2)
		{
			return number;
		}
		int n1=1;
		int n2=2;
		int n3=0;
		while(number>=3)
		{
			n3=n1+n2;
			n1=n2;
			n2=n3;
			number--;
		}
		return n3;
		*/
	}
};

void test()
{
	Solution s;
	char str[] = "hello world";
	int len = strlen(str);
	s.replaceSpace(str,len);
}

#endif

#if 0
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr&&pHead2 == nullptr)
		{
			return nullptr;
		}
		if (pHead1 == nullptr&&pHead2 != nullptr)
		{
			return pHead2;
		}
		if (pHead1 != nullptr&&pHead2 == nullptr)
		{
			return pHead1;
		}
		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		while (pHead1&&pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				if (cur == nullptr)
				{
					head = pHead1;
					pHead1 = pHead1->next;
				}
				else
				{
					cur->next = pHead1;
					cur = pHead1;
					pHead1 = pHead1->next;
				}
			}
			else
			{
				if (cur == nullptr)
				{
					head = pHead2;
					pHead2 = pHead2->next;
				}
				else
				{
					cur->next = pHead2;
					cur = pHead2;
					pHead2 = pHead2->next;
				}
			}
		}
		if (pHead1 == nullptr)
		{
			cur->next = pHead2;
		}
		if (pHead2 == nullptr)
		{
			cur->next = pHead1;
		}
		return head->next;

	}
};

#include<vector>
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int start = 0;
		int end = array.size() - 1;
		int temp = array[0];
		while (start < end)
		{
			while (array[end] % 2 == 0 && start < end)
			{
				end--;
			}
			array[start] = array[end];
			while (array[start] % 2 != 0 && start < end)
			{
				start++;
			}
			array[end] = array[start];
		}
		array[start] = temp;


	}
};
void test()
{
	Solution s;
	vector<int>l = { 1,2,3,4,5,6,7 };
	s.reOrderArray(l);
	for (auto e : l)
	{
		cout << e << ' ' << endl;
	}
}

#endif

#include<vector>

int main()
{
	vector<vector<int>>arr;
	int m;
	int n;
	cin >> m >> n;
	arr.resize(m);
	for (int i = 0; i < m; i++)
	{
		arr[i].resize(n, 0);
	}
	//int arr[4][4] = { 0 };
	arr[0][0] = 1;
	int num = n * m;
	int x = 0;//��סx��y���Ǵ�0��ʼ�ģ���ס��ס
	int y = 0;
	int k = 1;//ע��߽�����
	while (num-1)//��Ϊk��1��ʼ������ѭ��һ��
	{
		//ע��ǰ��++�ͺ���++�ڴ˴�������
		while (y + 1 < n && arr[x][y+1] == 0  )//���ң�����ȡ��n����Ϊ�±궼�Ǵ�0��ʼ�ģ�+1����Ϊy�Ǵ�0��ʹ�ģ�
			//arr[x][y+1] == 0��Ϊ���ж���Щλ�ÿ��Էţ���Щλ�ò��ܷ�
		{
			arr[x][++y] = ++k;
			num--;
		}
		//y--;
		while (x+1 < m && arr[x+1][y] == 0  )//����
		{
			arr[++x][y] = ++k;
			num--;
		}
		//x--;
		while (y-1 >= 0 && arr[x][y-1] == 0  )//����
		{
			arr[x][--y] = ++k;
			num--;
		}
		//y++;
		while (x-1 >=0  && arr[x-1][y] == 0  )//����
		{
			arr[--x][y] = ++k;
			num--;
		}
		//x++;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//cout << arr[i][j] << "  ";
			printf("%3d", arr[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}