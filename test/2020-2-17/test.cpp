#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ret;
      int flag = 0;
      for(size_t i = 0; i < nums.size();i++)
      {
        if(nums[i] == target)
        {
          ret.push_back(i);
          flag = 1;

        }

      }
      vector<int> Ret;
      if(flag)
      {
        Ret.push_back(ret[0]);
        Ret.push_back(ret[ret.size() - 1]);
        return Ret;

      }

      Ret.push_back(-1);
      Ret.push_back(-1);
      return Ret;

    }

};
