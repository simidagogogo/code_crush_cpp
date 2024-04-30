/********************************************************************************
 * @File        : TestRunner.h
 * @Author      : Shard Zhang
 * @Date        : 2024/4/30 11:57
 * @Brief       : 
 ********************************************************************************/
#ifndef CODE_CRUSH_CPP_TESTRUNNER_H
#define CODE_CRUSH_CPP_TESTRUNNER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <filesystem>
#include "Scmp.h"
#include "p5152/Solution.h"
#include "p5152/Main.h"

using std::string;

namespace code_crush {

bool ends_with(const std::string &value, const std::string &ending) {
    if (ending.size() > value.size()) {
        return false;
    }
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

// TestRunner类
class TestRunner {
 private:
  static const std::string CPT_BASE_PATH; // 定义为静态常量
  static const std::string PROBLEM_NO; // 定义为静态常量
  static Scmp *checker; // 使用指针以支持多态

 public:
  static std::vector<std::string> listFiles(const std::string &dir) {
      printf("dir: %s\n", dir.c_str());
      std::vector<std::string> fileNames;
      for (const auto &entry : std::filesystem::directory_iterator(dir)) {
          string name = entry.path().filename().string();
          printf("name: %s\n", name.c_str());
          fileNames.push_back(name);
      }
      return fileNames;
  }

  static std::string genFilePath(int no, const std::string &suffix) {
      return CPT_BASE_PATH + "/" + PROBLEM_NO + "/" + "5152" + "/" + std::to_string(no) + suffix;
  }

  static void run() {
      int total_cnt = -1;
      std::vector<std::string> files = listFiles(CPT_BASE_PATH + "/" + PROBLEM_NO + "/5152");
      for (const auto &file : files) {
          if (!file.ends_with(".in") && !file.ends_with(".out")) continue;
          int no = std::stoi(file.substr(0, file.find('.')));
          if (no > total_cnt) total_cnt = no;
      }

      printf("Total case: %d\n", total_cnt);
      int pass_cnt = 0;
      for (int i = 1; i <= total_cnt; ++i) {
          if (Process(i, total_cnt)) {
              pass_cnt++;
              std::cout << "case " << i << ": 通过" << std::endl;
          }
      }
      printf("==============================================\n");
      printf("                 通过率: %d%%                 \n", int(pass_cnt * 1.0 / total_cnt * 100));
      printf("==============================================\n");
  }

  static bool Process(int num, int total) {
      printf("========= Test Case %d/%d =========\n", num, total);

      // 输入重定向
      string input = genFilePath(num, ".in");
      std::ifstream fileInput(input);
      if (!fileInput.is_open()) {
          fprintf(stderr, "无法打开输入文件: %s\n", input.c_str());
          return false;
      }
      // 将标准输入重定向到文件输入
      std::cin.rdbuf(fileInput.rdbuf());

      // 输出重定向
      string output = genFilePath(num, ".res");
      std::ofstream fileResPrint(output);
      if (!fileResPrint.is_open()) {
          fprintf(stderr, "无法打开输出文件: %s\n", output.c_str());
          return false;
      }

      // 保存原始的std::cout缓冲区
      std::streambuf* originalCoutBuf = std::cout.rdbuf();

      // 将std::cout的缓冲区绑定到fileResPrint的缓冲区
      std::cout.rdbuf(fileResPrint.rdbuf());

      // 运行测试程序
      Main::main();

      // 确保所有内容都被写入到文件中
      fileResPrint.flush();
      fileInput.close();
      fileResPrint.close();

      // 解除绑定，将std::cout的缓冲区重新绑定到原始的控制台输出
      std::cout.rdbuf(originalCoutBuf);

      bool pass = (*checker).compare(genFilePath(num, ".out"), genFilePath(num, ".res"));
      // 现在std::cout的输出会回到控制台
      return pass;
  }
};

const std::string TestRunner::CPT_BASE_PATH = "/Users/zhangda/CLionProjects/code_crush_cpp";
const std::string TestRunner::PROBLEM_NO = "p5152";
Scmp *TestRunner::checker = new Scmp();
}

#endif //CODE_CRUSH_CPP_TESTRUNNER_H
