struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
    val(x), next(NULL) {

    }

};*/
class Solution {
  public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if(pListHead==nullptr)
      {
        return nullptr;
      }
      if(pListHead->next==nullptr)
      {
        return pListHead;
      }
      ListNode* slower=pListHead;
      ListNode* faster=pListHead;
      int num=k-1;
      ListNode*cur=pListHead;
      int count=0;
      while(cur)
      {
        count++;
        cur=cur->next;
      }
      if(count<k||k<1)
      {
        return nullptr;
      }
      while(num-->0)
      {

        faster=faster->next;
      }
      while(faster->next!=nullptr)
      {

        slower=slower->next;
        faster=faster->next;
      }

      return slower;
          Definition for singly-linked list.
          struct ListNode {
              int val;
              ListNode *next;
              ListNode(int x) : val(x), next(NULL) {}
          };
        if(pListHead==nullptr||k<1)
        {
          return nullptr;

        }
      ListNode* newhead=new ListNode(0);//创一个头节点是为了防止删除第一个
      newhead->next=pListHead; 

      ListNode* faster=newhead;
      ListNode* slower=newhead;
      for(int i=1;i<=k+1;i++)//让快指针先走n+1步，慢指针才开始走，这样快慢指针中间总有n个节点，这样当快指针走到空时，慢指针走到待删除节点的的上一个节点，这样句可以直接删除
      {
        faster=faster->next;
        if(faster==nullptr)//防止空指针异常
          return i>k?pListHead:nullptr;            

      } 

      while(faster)
      {
        slower=slower->next;
        faster=faster->next;

      }

      return slower->next;

    }
};
