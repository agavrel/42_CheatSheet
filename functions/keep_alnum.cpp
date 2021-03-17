// g++ -O3 keep_alnum.cpp && ./a.out "gdrgdrgdrgd5%#$%#^#$^#$"
// g++ -O3 keep_alnum.cpp && ./a.out FILE test.txt

#include <ctime>

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include <locale> // ispunct
#include <cctype>

#include <fstream> // read file
#include <streambuf>

#include <sys/stat.h> // check if file exist
#include <cstring>

#include <assert.h>

using namespace std;

bool exist(const char *name)
{
  struct stat   buffer;
  return !stat(name, &buffer);
}

constexpr int SIZE = 8092 * 1024;

void keep_alnum(string &s) {
    stringstream ss;
    int i = 0;
    for (i = 0; i < SIZE; i++)
        if (isalnum(s[i]))
            ss << s[i];
    s = ss.str();
}
static const int t[256] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
        0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
        0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };
void old_school(char *s) {

    int n = 0;
    for (int i = 0; i < SIZE; i++) {
        unsigned int c = s[i] - 0x30;
        if (c < 10 || (c -= 0x11) < 26 || (c -= 0x20) < 26) // 0x30 + 0x11 = 'A' + 0x20 = 'a'
            s[n++] = s[i];
    }
    s[n] = '\0';
}


void agavrel_style(char *s) {
    int n = 0;
    for (int i = 0; i < SIZE; i++) {
        int mask = (t[s[i]]&1);
        s[n] ^= (s[n] ^ s[i]) * mask;
        n += mask;
    }
    s[n] = '\0';
}

void alnum_from_libc(char *s) {
    int n = 0;
    for (int i = 0; i < SIZE; i++) {
        if (isalnum(s[i]))
            s[n++] = s[i];
    }
    s[n] = '\0';
}

#define benchmark(x) printf("\033[30m(%6.0lf cycles) \033[32m%5.1lfms\n\033[0m", x, x / (CLOCKS_PER_SEC / 1000))

int main(int ac, char **av) {
    if (ac < 2) {
        cout << "usage: ./a.out \"{your string} or ./a.out FILE \"{your file}\n";
        return 1;
    }
    string s;
    s.reserve(SIZE+1);
    string s1;
    s1.reserve(SIZE+1);
    char s4[SIZE + 1], s5[SIZE + 1];
    if (ac == 3) { if (exist(av[2])) remove(av[2]);
        if (!exist(av[2])) {
            for (size_t i = 0; i < SIZE; i++)
              s4[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnoporstuvwxyz!@#$%^&*()__+:\"<>?,./'"[rand() % 74];
          s4[SIZE] = '\0';
          ofstream ofs(av[2]);
          if (ofs)
            ofs << s4;
        }
        ifstream ifs(av[2]);
        if (ifs) {
          ifs.rdbuf()->pubsetbuf(s4, SIZE);
          copy(istreambuf_iterator<char>(ifs), {}, s.begin());
        }
        else
          cout << "error\n";

        ifs.seekg(0, ios::beg);
        s.assign((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    }
    else
        s = av[1];

   // s1 = s;
   //// cout << s1.size() << " " << s.size() << endl;
    //return 0;

    double elapsedTime;
    clock_t start;
    bool is_different = false;

    s1 = s;
    start = clock();
    keep_alnum(s1);
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    string tmp = s1;

    s1 = s;
    start = clock();
    s1.erase(std::remove_if(s1.begin(), s1.end(), [](char c) { return !isalnum(c); }), s1.end());
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s1.c_str());

    s1 = s;
    start = clock();
    s1.erase(std::remove_if(s1.begin(), s1.end(), [](char c) { return ispunct(c); }), s1.end());
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s1.c_str());

    s1 = s;
    start = clock();
    s1.erase(remove_if(s1.begin(), s1.end(), not1(ptr_fun( (int(*)(int))isalnum ))), s1.end());
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s1.c_str());

    s1 = s;
    start = clock();
    s1.erase(remove_if(s1.begin(), s1.end(), []( auto const& c ) -> bool { return !isalnum(c); } ), s1.end());
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s1.c_str());

    memcpy(s4, s.c_str(), SIZE);
    start = clock();
    alnum_from_libc(s4);
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s4);

    memcpy(s4, s.c_str(), SIZE);
    start = clock();
    old_school(s4);
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s4);

    memcpy(s4, s.c_str(), SIZE);
    start = clock();
    agavrel_style(s4);
    elapsedTime = (clock() - start);
    benchmark(elapsedTime);
    is_different |= !!strcmp(tmp.c_str(), s4);

    cout << "Original length: " << s.size() << ", current len with alnum only: " << strlen(s4) << endl;
    // make sure that strings are equivalent
    printf("\033[3%cm%s\n", ('3' + !is_different), !is_different ? "OK" : "KO");

    return 0;
}