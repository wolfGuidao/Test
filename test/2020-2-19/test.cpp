class Solution {
  public:
    int temp=0;
    stack<int>s;
    void push(int value) {
      if(s.empty())
      {
        temp=value;
        s.push(value);
        s.push(temp);

      }
      else
      {
        temp=temp>value?value:temp;
        s.push(value);
        s.push(temp);

      }

    }
    void pop() {
      s.pop();
      s.pop();

    }
    int top() {
      s.pop();
      int num=s.top();
      s.pop();
      return num;

    }
    int min() {
      return s.top();

    }

};
