/********************************************************************************
 * @File        : Main.h
 * @Author      : Shard Zhang
 * @Date        : 2024/4/30 11:57
 * @Brief       : 主程
 ********************************************************************************/
#ifndef CODE_CRUSH_CPP_MAIN_H
#define CODE_CRUSH_CPP_MAIN_H
#include <iostream>
#include <iostream>
#include "Solution.h"

class Main {
 public:
  static int main() {
      // 1. 输入
      int a = 0;
      int b = 0;

      // 从cin输入等价于从fileInput输入
      std::cin >> a >> b;
      // printf("a: %d, b: %d\n", a, b);

      // 2. 调用Solution执行
      Solution solution;
      int c = solution.sum(a, b);

      // 3. 输出
      // 现在std::cout的输出会定向到fileResPrint关联的文件
      std::cout << c;

      return 0;
  }
};

#endif //CODE_CRUSH_CPP_MAIN_H
