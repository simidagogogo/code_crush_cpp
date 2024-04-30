/********************************************************************************
 * @File        : Main.h
 * @Author      : Shard Zhang
 * @Date        : 2024/4/30 12:06
 * @Brief       : 5152. 实现插入排序算法 https://www.codecrush.cn/partner/oj/problem/26
 ********************************************************************************/
#ifndef CODE_CRUSH_CPP_MAIN_H
#define CODE_CRUSH_CPP_MAIN_H

#include <string>
#include <iostream>
#include "Solution.h"

using namespace std;

/**
 * 输入: 从cin输入等价于从fileInput文件输入
 * 输出: cout的输出会定向到fileResPrint关联文件
 */
class Main {
 public:
  static int main() {
      // 1. 输入
      int n;
      cin >> n;
      vector<int> arr(n);
      for (int i = 0; i < n; ++i) {
          cin >> arr[i];
      }

      // 2. 调用Solution执行
      Solution solution;
      solution.insertSort(arr, n);

      // 3. 输出
      // printf("output: \n");
      for (int i = 0; i < n; ++i) {
          // printf("%d ", arr[i]);
          cout << arr[i] << " ";
      }
      // printf("\n");
      return 0;
  }

//#code#
};

#endif //CODE_CRUSH_CPP_MAIN_H
