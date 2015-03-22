#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>

std::vector<int> read_ints(std::string s);
int modPow(int a, int b, int MOD);
int modInverse(int a, int m);

#endif
