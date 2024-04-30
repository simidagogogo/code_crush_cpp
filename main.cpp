#include <iostream>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "TestRunner.h"

using namespace std;

int main() {
    {
        char cwd[1024];
        chdir("/path/to/change/directory/to");
        getcwd(cwd, sizeof(cwd));
        printf("Current working dir: %s\n", cwd);
    }

    std::cout << "Hello, World!" << std::endl;
    std::cout << "========================\n" << std::endl;

    code_crush::TestRunner::run();

    return 0;
}