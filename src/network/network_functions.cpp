#include "network/network_functions.h"
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

namespace cuhksz {
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
}  // namespace cuhksz
