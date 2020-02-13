class MyStack {
public:
	//��Ҫ˼���Ƕ����������У���ջʱ�������������ͬʱΪ�գ��������һ�������в������������һ�����в�Ϊ�գ�ÿ�β�����ǿյĶ����в��롣��ջʱ��ÿ�ΰѷǿն��е�ǰsize-1��Ԫ���ƶ����ն����У�ԭ�ǿն��о�ֻʣ�����һ��Ԫ�أ����Ԫ������ջ��Ҫ��ֱ�ӳ��ӡ���֮����Ҫ˼���ǰ����������е�Ԫ�������ƶ���ÿ��ʣ�����һ��Ԫ��ֱ�ӳ��ӣ����൱����ջ��Ԫ��
		/** Initialize your data structure here. */
	MyStack() {
		queue<int>q1;
		queue<int>q2;
	}

	/** Push element x onto stack. */
	void push(int x) {
		//����������ж�Ϊ�գ������뵽һ�������У���֮���뵽�ǿն�����
		if (!q1.empty())
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		//ÿ�ΰѷǿն����е�ǰsize-1��Ԫ���ƶ����ն�����ȥ��ԭ�ǿն���ʣ�����һ��Ԫ�ؾ��൱��ջ��Ԫ�أ���ջʱ����ֱ�ӳ���
		int data;
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			data = q2.front();
			q2.pop();

		}
		else
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			data = q1.front();
			q1.pop();
		}
		return data;
	}

	/** Get the top element. */
	int top() {
		//���طǿն��еĶ�βԪ�أ����൱��ջ��Ԫ�أ�
		if (!q1.empty())
		{
			return q1.back();
		}
		else
		{
			return q2.back();
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		//��������ͬʱΪ���ǣ���ʱ�ű���ջ��û���κ�Ԫ��
		return q1.empty() && q2.empty();
	}
private:

	queue<int>q1;
	queue<int>q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */