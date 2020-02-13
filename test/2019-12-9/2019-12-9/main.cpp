class MyQueue {
public:
	//��Ҫ˼���Ƕ�������ջ��һ������������Ԫ�ص�ջs1����һ��ջ�������г��Ӳ�����s2���������в�Ԫ��ʱ��ֱ����s1�в��룬����ʱ�����s2��Ϊ�գ�ֱ����s2�н��г�ջ���������s2Ϊ�գ��Ͱ�s1��Ԫ��ȫ���ŵ�s2��
		/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		//ֱ����s1�в���
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		//���г��Ӳ���ʱ�����s2Ϊ�գ���ֱ�Ӱ�s1��Ԫ�����ƶ���s2�У��ڽ��г��Ӳ��������s2��Ϊ�գ�ֱ����s2��ֱ�ӳ��ӣ�ע�ⲻ����s2��Ԫ��ʱ��s1�е�Ԫ���ƶ���s2�У�����˳�����
		int data;
		if (s2.empty())
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
			data = s2.top();
			s2.pop();
		}
		else
		{
			data = s2.top();
			s2.pop();
		}
		return data;

	}

	/** Get the front element. */
	int peek() {
		int data;
		if (s2.empty())
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
			data = s2.top();
			//s2.pop();
		}
		else
		{
			data = s2.top();
			//s2.pop();
		}
		return data;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty() && s2.empty();
	}
private:
	stack<int>s1;
	stack<int>s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */