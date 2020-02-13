#include<iostream>
#include<Windows.h>

using namespace std;


#if 0

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 0 || n == 0)
		{
			return 0;
		}
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			int temp = i;//ע�ⲻ����ֱ�Ӹı�i��ֵ
			while (temp)
			{
				if (temp % 10 == 1)
				{
					count++;
				}
				temp /= 10;
			}
		}
		return count;
	}
};

#endif

#if 0

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (n < 0)
		{
			return nullptr;
		}
		if (n == 0 || str.size() <= 0)
		{
			return str;
		}
		/*
		void reverse(string &str, int begin, int end)
		{
			while(begin < end)
			{
				char tmp = str[begin];
				str[begin] = str[end];
				str[end] = tmp;
				begin++;
				end--;
			}
		}
		*/
		if (n > str.size() && str.size() != 0)
		{
			n = n % (str.size());
		}
		int num = n ;

		reverse(str.begin(), str.begin() + num);
		reverse(str.begin() + num , str.end());
		reverse(str.begin(), str.end());
		return str;

	}
};

class Solution {
public:
	string ReverseSentence(string str) {
		reverse(str.begin(), str.end());
		int start = 0;
		int i;
		for (i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				reverse(str.begin() + start, str.begin() + i);
				start = i + 1;
			}
		}
		if (str[i] == '\0')
		{
			reverse(str.begin() + start, str.end());
		}


		return str;
	}
};

#endif

class Solution {
public:
	int StrToInt(string str) {

		int i = 0;
		long long sum = 0;
		long long temp = 0;
		int flage = 1;

		while (str[i] == ' ')
		{
			i++;
		}

		if (str[i] == '+')
		{
			flage = 1;
			i++;
		}
		else if (str[i] == '-')
		{
			flage = -1;
			i++;
		}
		while (str[i] != '\0')
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				temp = temp * 10 + str[i] - '0';
				i++;
			}
			else
			{
				//sum=0;
				return 0;
			}
		}
		sum = flage * temp;
		if (sum >= INT_MIN && sum <= INT_MAX)
			return sum;
		else
			return 0;
	}
};

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>>ret;//��α�������count�����ͺ���
		vector<int>ret1;
		queue<TreeNode*>q;
		if (pRoot == nullptr)
		{
			return ret;
		}
		q.push(pRoot);
		int count = 0;
		while (!q.empty())
		{
			count = q.size();

			while (count > 0)
			{
				ret1.push_back(q.front()->val);
				TreeNode* cur = q.front();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
				q.pop();
				count--;
			}
			ret.push_back(ret1);
			ret1.clear();
		}
		return ret;
	}

};


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{

		if (pHead == nullptr || pHead->next == nullptr)
		{
			return nullptr;
		}
		ListNode* fast = pHead->next;
		ListNode* slow = pHead;
		while (fast&&fast->next)//�ж��Ƿ��л�
		{
			if (fast == slow)//��Ⱦ����л�
			{
				break;
			}
			slow = slow->next;
			fast = fast->next->next;

		}
		//��ѭ�������ַ�ʽ��1.�������Ϊfast==slow��break����˵���������л���
		//2.�������Ϊ��ָ���ߵ�nulptr���˳��ģ�˵��������û�л���
		if (fast == nullptr || fast->next == nullptr)//�����޻���ֱ�ӷ���nullptr
		{
			return nullptr;
		}
		fast = pHead;//�ߵ�����˵���������л��ģ��ÿ���ָ���еĿ�ָ�������ͷ����ָ��ָ��
		//�����ڵ����һ���ڵ㣬
		slow = slow->next;
		while (fast != slow)//����ָ��һ����һ����Ȼ���ٴ������Ľڵ�������������
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};

void test()
{
	Solution s;
	string s1 = "-2147483649";
	s.StrToInt(s1);
	/*
	string s1 = "abcdefg";
	s.LeftRotateString(s1, 2);
	string s = "wolf guidao ai ni";
	cout << s.find( ' ',10) << endl;
	cout << s.find( ' ',4) << endl;
	*/
}

int main()
{
	test();
	system("pause");
	return 0;
}