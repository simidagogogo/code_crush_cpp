/********************************************************************************
 * @File        : Scmp.h
 * @Author      : Shard Zhang
 * @Date        : 2024/4/30 11:57
 * @Brief       : 
 ********************************************************************************/
#ifndef CODE_CRUSH_CPP_SCMP_H
#define CODE_CRUSH_CPP_SCMP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace code_crush {

class Scmp {
 public:
  std::string &trim(std::string &str) {
      size_t first = str.find_first_not_of(' ');
      if (std::string::npos == first) {
          return str = "";
      }
      size_t last = str.find_last_not_of(' ');
      return str = (first > last) ? "" : str.substr(first, (last - first + 1));
  }

  bool compare(const std::string &outFilePath, const std::string &resFilePath) {
      std::ifstream file1(outFilePath, std::ios::in);
      std::ifstream file2(resFilePath, std::ios::in);

      if (!file1.is_open() || !file2.is_open()) {
          printf("!file1.is_open() || !file2.is_open()\n");
          return false;
      }

      std::string line1, line2;
      while (std::getline(file1, line1) && std::getline(file2, line2)) {
          trim(line1);
          trim(line2);
          printf("truth: %s\n", line1.c_str());
          printf("output : %s\n", line2.c_str());
          if (line1 != line2) {
              printf("line1 != line2\n");
              return false;
          }
      }
      return file1.eof() && file2.eof();
  }
};

int run_scmp() {
    Scmp scmp;
    std::string outFilePath = "output.txt";
    std::string resFilePath = "result.txt";
    bool result = scmp.compare(outFilePath, resFilePath);
    std::cout << (result ? "Files are identical." : "Files are different.") << std::endl;
    return 0;
}
}

#endif //CODE_CRUSH_CPP_SCMP_H
