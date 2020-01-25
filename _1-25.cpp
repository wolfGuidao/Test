string s, t;
// 在 s 中寻找 t 的「最小覆盖子串」
int left = 0, right = 0;
string res = s;

// 相当于两个计数器
unordered_map<char, int> window;//记录窗口中在need当中某个字符出现的次数
unordered_map<char, int> needs;//���录t中每个字符出现的次数

for (char c : t) needs[c]++;

// 记录 window 中已经有多少字符符合要求了
int match = 0; 

while (right < s.size()) {

  char c1 = s[right];
  if (needs.count(c1)) {//判断键 c1 是否存在，不存在就不用计数，没啥用
    //反而影响后面的判断

    window[c1]++; // 加入 window
    if (window[c1] == needs[c1])//因为t中的某个字符并不是只出现一次，
      //不仅要出现还要次数相同
      // 字符 c1 的出现次数符合要求了
      //不能是 >= 会多次match++
      match++;//一个字符满足要求
  }
  right++;//更新滑动窗口的大小

  // window 中的字符串已符合 needs 的要求了，开始缩小滑动窗口
  while (match == needs.size()) {
    // 更新结果 res
    res = minLen(res, window);

    char c2 = s[left];
    if (needs.count(c2)) {
      window[c2]--; // 移出 window
      if (window[c2] < needs[c2])//不能是 != ，因为Win个数可能大于ned
        // 字符 c2 出现次数不再符合要求
        match--;
    }
    left++;
  }
}
return res;

}
}
}
