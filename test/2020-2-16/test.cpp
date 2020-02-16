#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
  public:

    bool isdigit(char ch)
    {
      if(ch >= '0' && ch <= '9')
      {
        return true;

      }
      return false;

    }

    int myAtoi(string str) {
      if(str.size() == 0)
      {
        return 0;

      }

      int res = 0;//保存结果
      int i = 0;//下标，控制循环遍历
      int flag = 1;//正负标记位

      // 1. 检查空格，并去掉多余的空格
      while (str[i] == ' ') 
      { 
        i++; 
      }

      // 2. 检查符号，并给标志位赋值
      if (str[i] == '-') 
      { 
        flag = -1; 
      }

      //如果是‘-’／‘+’需要把i往后移动一位
      if (str[i] == '+' || str[i] == '-') 
      { 
        i++; 
      }

      // 3. 计算数字结果
      while (i < str.size() && isdigit(str[i])) 
      {
        int r = str[i] - '0';

        // ------ 4. 处理溢出，这是关键步骤 ------
        //  如果res > INT_MAX / 10，那么接下来乘以10肯定会越界；如果res == INT_MAX / 10 && r > 7)这种情况是res = res * 10 + r后刚好 == INT_MAX，又因为int型最大值的最后一位位8，所以如果是小于8的情况下是不会越界的，这个oj有点坑，一直不过
        if (res > INT_MAX / 10  || (res == INT_MAX / 10 && r > 7)) 
        { 
          return flag > 0 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + r;
        i++;
      }
      return flag > 0 ? res : -res;
    }
};
