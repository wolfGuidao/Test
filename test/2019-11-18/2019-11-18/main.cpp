#if 0

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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		/*
		ListNode* head=new ListNode(1);//����һ��ͷ�ڵ�
		head->next=pHead;

		ListNode* cur1=head;//cur1ָ��ͷ�ڵ�
		ListNode* cur2=pHead;//cur1ָ���һ���ڵ�

		if(pHead==nullptr)
		{
			return nullptr;
		}

		int count=0;//��һ����־��
		while(1)
		{
			if(cur2->next==nullptr)
			{
				if(count)
				{
					count=0;
					cur2=cur2->next;
					cur1->next=cur2;
				}
				break;
			}
			if(cur2->next->val==cur2->val)//�������cur2->next->val==cur2->val����ɾ��cur2-��next�����ѱ�־����Ϊ1
			{
				count++;
				cur2->next=cur2->next->next;
			}
			else
			{
				if(count==0)//���count����0��˵��û��ɾ��������ֱ��������
				{
					cur2=cur2->next;
					cur1=cur1->next;

				}
				else//�������ɾ�����������ð�cur2���Ǹ�λ�ø�ɾ�������Ұ�count��Ϊ0
				{
					count=0;
					cur2=cur2->next;
					cur1->next=cur2;
				}
			}
		}
		return head->next;
		*/
		if (pHead == nullptr)
		{
			return nullptr;
		}
		if (pHead->next == nullptr)
		{
			return pHead;
		}
		//
		ListNode* cur = pHead;
		ListNode* temp = pHead->next;
		ListNode* list = new ListNode(0);
		ListNode* listtail = list;
		//��Ҫ˼���Ǵ���һ���µ�ͷ�ڵ�ָ�룬�������cur��tempָ��������ڵ�ֵ����ȣ��Ͱ�curβ�嵽�½ڵ���棬
		while (temp)//
		{
			if (cur->val == temp->val)//��������ڵ�ֵ��ȣ���ִ�������ƶ�
			{
				while (cur->val == temp->val&&temp)//��������ڵ�ֵ��ȣ��Ͱ�temp����
					//�ƶ���ֱ����temp���ں�cur����ȵĽڵ��ϣ�����temp=nullptr
				{
					temp = temp->next;
				}
				while (cur != temp)//��cur��ʼ��һֱɾ����tempλ�ô�
				{
					ListNode* next = cur;
					cur = cur->next;
					delete next;
				}

				if (temp)//��Ϊtemp��ΪԪ����ȶ��ŵ���λ���ϣ���ʱ�Ͳ�������temp����next����
					temp = temp->next;
			}
			else//����ֵ����ȣ��Ͱ�cur��ֵβ�嵽ͷ�ڵ�ĺ���
			{
				listtail->next = cur;
				listtail = cur;
				cur = temp;
				temp = temp->next;
			}
		}
		listtail->next = cur;//�����ܻ����ĩβȫ��������ͬ��Ԫ�أ�������մ���ִ�У�listtail��ָ��ԭ���Ľڵ�,���Ե���Ϊcur
		return list->next;
	}
};

#endif

#if 0

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		/*
		if(A==nullptr)
		{
			return false;
		}
		else if(A->next==nullptr)
		{
			return true;
		}

		vector<int> s;
		ListNode* cur=A;
		while(cur)
		{
			s.push_back(cur->val);
			cur=cur->next;
		}
		int start=0;
		int end=s.size()-1;
		while(start<end)
		{
			if(s[start]==s[end])
			{
				start++;
				end--;
			}
			else{
				return false;
			}
		}
		return true;
		*/
		ListNode* faster = A;//���ַ����ǰ�����ĺ�벿�ֽ��з�ת������һ��ָ����ǰ����һ��ָ���غ���ǰ���бȽ�
		ListNode* slower = A;
		ListNode* prev = A;
		ListNode* cur = A;
		int count = 0;
		while (cur)//�����������ȣ�����Ҫ����ż
		{
			count++;
			cur = cur->next;
		}
		while (faster&&faster->next)//�ÿ���ָ���ҵ�������������м�һ���ڵ㣬ż�������м������ڵ���ұ߽ڵ㣬����faster
		{
			slower = slower->next;
			faster = faster->next->next;
		}
		ListNode* sss = slower;//��ʱ����
		prev = slower;//Ϊ���淴ת���̵�
		slower = slower->next;
		ListNode* next = slower;
		while (next)//��ɷ�ת
		{
			next = slower->next;
			slower->next = prev;
			prev = slower;
			if (next)
				slower = next;
		}
		if (count % 2 == 0)//����ż���бȽ�
		{
			cur = A;
			while (cur->next != sss)
			{
				if (cur->val == slower->val)
				{
					cur = cur->next;
					slower = slower->next;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			cur = A;
			while (cur != sss)
			{
				if (cur->val == slower->val)
				{
					cur = cur->next;
					slower = slower->next;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}
};

#endif