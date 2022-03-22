#ifndef EDITDISTANCE_UTILS_INCLUDE__
#define EDITDISTANCE_UTILS_INCLUDE__
#include <cstring>
#include <locale>
#include <codecvt>
using namespace std;

std::wstring to_wide_string(const std::string& input);
std::string to_byte_string(const std::wstring& input);

#endif