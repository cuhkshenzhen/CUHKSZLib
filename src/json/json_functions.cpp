#include "json/json_functions.h"
#include <string>

namespace cuhksz {
std::string jsonEscape(const std::string &str) {
  std::string output;
  for (auto const &i : str) switch (i) {
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
      default:
        output += i;
        break;
    }
  return output;
}
}  // namespace cuhksz
