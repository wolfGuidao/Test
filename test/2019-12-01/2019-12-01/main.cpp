/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {

		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* cur1 = head;//�����Ƚϵ�ǰһ���ڵ�
		ListNode* cur2 = head->next;//�����Ƚϵĺ�һ���ڵ�
		while (cur2)//ѭ���Ƚ�
		{
			while (cur2&&cur2->val > cur1->val)//�����һ���ڵ��ֵ��ǰһ���ڵ��ֵ�󣬾�ֱ�Ӱ�����ָ�������ƶ�����֮�˳�ѭ��
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			//�˳�ѭ�����������
			if (cur2 == nullptr)//��һ������Ϊcur2Ϊ���˳�ѭ����˵�����������нڵ㶼�����һ���ڵ��ǰһ���ڵ�󣬾�ֱ�ӷ���
			{
				return head;
			}
			//�ڶ�������Ϊ���ֺ�һ���ڵ��ֵ��ǰһ���ڵ��ֵС�������ͱ���Ѻ�һ���ڵ����������һ�����ʵ�λ�ò����ȥ
			ListNode* temp = cur2;//��ʱ��temp��ʾ��һ���Ƚ�С�Ľڵ㣬Ҳ���Ǵ�����Ľڵ�
			cur2 = cur2->next;//cur2�Լ����¼��һ������������ѭ��ǰ��
			//��temp�����ʱ����������
			if (temp->val <= head->val)//��һ�����������ͷ�ڵ�С
			{
				temp->next = head;
				head = temp;
			}
			else//�ڶ������������ͷ�ڵ��������λ��
			{
				ListNode* tempp = head;//���ܻ��õ�������ͷ�ڵ㲻������tempp
				while (temp->val > tempp->next->val)//Ϊ�˷�����룬ֱ�Ӻ�tempp��next�Ƚϣ���Ϊ����else�У��϶���һ���ڵ��ֵ����temp��tempp����һ���ڵ���бȽϣ��������һ���ڵ�󣬾�ֱ�Ӱ�tempp�����ƶ�
				{
					tempp = tempp->next;
				}
				//��֮����temp��tempp����һ��С�����϶��Ǳ�tempp�����ȣ���ֱ�Ӳ嵽tenpp�ĺ���
				temp->next = tempp->next;
				tempp->next = temp;

			}
			cur1->next = cur2;//�������Ƚϵ�ǰһ���ڵ�����
			//����ѭ���Ƚ�
		}
		return head;

		/*
		if(head==nullptr||head->next==nullptr)
		{
			return head;
		}

		ListNode* newhead=new ListNode(0);//����һ��ͷ�ڵ㷽�����
		newhead->next=head;

		ListNode* cur=head;//������ĵ�һ���ڵ㴦�Ͽ��������ڵ�ͷ�ڵ�ֻ����һ���ڵ�
		ListNode* temp=cur->next;//��tempָ��ʣ�µĽڵ�
		cur->next=nullptr;
		while(temp)//ѭ������
		{
			ListNode* cur1=temp->next;//��¼temp����һ���ڵ㣬��ֹ�����temp���Ҳ���

			ListNode* tempp=newhead;//��������ѭ��

			while(tempp->next&&tempp->next->val<=temp->val)//��temp�Һ��ʵĲ���λ��
			{
				tempp=tempp->next;
			}
			temp->next=tempp->next;
			tempp->next=temp;

			temp=cur1;//�����ϼ���ѭ���ж�
		}
		return newhead->next;
		*/
		/*
		if(head==nullptr||head->next==nullptr)
		{
			return head;
		}
		for(ListNode* i=head;i;i=i->next)
		{
			for(ListNode* j=i->next;j;j=j->next)
			{
				if(i->val>j->val)
				{
					int temp=j->val;
					j->val=i->val;
					i->val=temp;
				}
			}
		}
		return head;
		*/
	}
};