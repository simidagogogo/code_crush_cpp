/********************************************************************************
 * @File        : Solution.h
 * @Author      : Shard Zhang
 * @Date        : 2024/4/30 12:06
 * @Brief       : 5152. 实现插入排序算法 https://www.codecrush.cn/partner/oj/problem/26
 ********************************************************************************/
#ifndef CODE_CRUSH_CPP_SOLUTION_H
#define CODE_CRUSH_CPP_SOLUTION_H

#include <vector>
using std::vector;

class Solution {
 public:
  void insertSort(vector<int>& arr, int n) {
      for (int i = 0; i < arr.size(); ++i) {
          int pre = i - 1;
          int cur = arr[i]; // 这里必须记录arr[i]的值，因为后面会在群移时被覆盖
          while (pre >= 0 && arr[pre] > cur) {
              arr[pre + 1] = arr[pre];
              pre--;
          }
          arr[pre + 1] = cur;
      }
  }
};

#endif //CODE_CRUSH_CPP_SOLUTION_H
