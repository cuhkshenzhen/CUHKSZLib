#include "network/network_functions.h"
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

namespace cuhksz {

namespace {
int hexToInt(const char &x) {
  int y;
  if (x >= 'A' && x <= 'Z')
    y = x - 'A' + 10;
  else if (x >= 'a' && x <= 'z')
    y = x - 'a' + 10;
  else if (isdigit(x))
    y = x - '0';
  else
    y = 0;
  return y;
}
}  // namespace

std::string urlEncode(const std::string &string) {
  std::ostringstream escaped;
  escaped.fill('0');
  escaped << std::hex;

  for (const char &c : string) {
    if (c >= 0) {
      if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
        escaped << c;
        continue;
      }
    }

    escaped << std::uppercase;
    escaped << '%' << std::setw(2) << int((unsigned char)c);
    escaped << std::nouppercase;
  }

  return escaped.str();
}

std::string urlDecode(const std::string str) {
  std::ostringstream escaped;
  escaped.fill('0');
  escaped << std::hex;

  size_t length = str.length();
  for (size_t i = 0; i < length; i++) {
    if (str[i] == '+') {
      escaped << ' ';
    } else if (str[i] == '%') {
      int high = hexToInt(str[++i]);
      int low = hexToInt(str[++i]);

      escaped << (unsigned char)(high * 16 + low);
    } else {
      escaped << str[i];
    }
  }
  return escaped.str();
}

}  // namespace cuhksz
