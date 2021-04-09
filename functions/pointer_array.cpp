#include <vector>
#include <string>
#include <iostream>

using namespace std;

std::vector<std::string> convert_arguments(int argc, const char **argv) {
  return std::vector<std::string>(argv + 1, argv + argc);
}

bool test1(void) {
    int argc = 5;
    const char *argv[] = {"program", "some string", "another","command", "ok", NULL };
    std::vector<std::string> myexpectedvector =  {"some string", "another","command", "ok" };
    std::vector<std::string> s = convert_arguments(argc, argv);
    return (s == myexpectedvector);
}

int main () {
    std::cout << test1() << std::endl;
}