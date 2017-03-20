#include <string>
#include "json/json_functions.h"

namespace cuhksz {
std::string jsonEscape(const std::string &str) {
  std::string output;
  for (unsigned i = 0; i < str.length(); ++i)
    switch (str[i]) {
      case '\"':
        output += "\\\"";
        break;
      case '\\':
        output += "\\\\";
        break;
      case '\b':
        output += "\\b";
        break;
      case '\f':
        output += "\\f";
        break;
      case '\n':
        output += "\\n";
        break;
      case '\r':
        output += "\\r";
        break;
      case '\t':
        output += "\\t";
        break;
      default  :
        output += str[i];
        break;
    }
  return std::move(output);
}
}