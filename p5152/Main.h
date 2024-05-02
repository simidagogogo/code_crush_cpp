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
      string s;
      getline(cin, s, '\n');
      int n = stoi(s);

      string line;
      getline(cin, line, '\n');
      stringstream iss(line);
      string token;
      vector<int> arr;
      while (iss >> token) {
          arr.push_back(stoi(token));
      }

      // 2. 调用Solution执行
      Solution solution;
      solution.insertSort(arr, n);

      // 3. 输出
      for (int i = 0; i < n; ++i) {
          cout << arr[i] << " ";
      }
      return 0;
  }

//#code#
};

#endif //CODE_CRUSH_CPP_MAIN_H
