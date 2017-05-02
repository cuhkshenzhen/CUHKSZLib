#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <bitset>
#include "base64/base64_functions.h"

namespace cuhksz {
static const std::string codes = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

// Note: this is not essicient but enough for simple usage.
std::string base64Encode(std::string str, int length) {
  if (length < -1) {
    return "";
  }
  std::ostringstream encoded;
  std::string binaryStr = "";
  for (char &c: str) {
    binaryStr += std::bitset<8>((uint64_t) c).to_string();
  }
  if (binaryStr.length() % 6) {
    binaryStr += std::string(6 - binaryStr.length() % 6, '0');
  }
  std::size_t size = binaryStr.length();
  for (std::size_t i = 0; i < size; i += 6) {
    int index = (int) std::bitset<6>(binaryStr.substr((uint64_t) i, 6)).to_ulong();

    encoded << codes[index];
  }
  std::string encodedStr = encoded.str();
  if (length != -1) {
    if (length < (int)encodedStr.length()) {
      return (std::string) "";
    }
    encodedStr += std::string(length - encodedStr.length(), '=');
  } else {
    uint64_t remainder = encodedStr.length() % 4;
    switch (remainder) {
      case 0:
        break;
      case 2:
        encodedStr += "==";
        break;
      case 3:
        encodedStr += "=";
        break;
      default:
        break;
    }

  }
  return encodedStr;
};

std::string base64Decode(std::string decodeStr){
  std::string binaryDecodeStr;
  std::ostringstream decoded;
  for (char &c: decodeStr) {
    if (c != '=') {
      binaryDecodeStr += std::bitset<6>(codes.find(c)).to_string();
    }
  }
  if (binaryDecodeStr.length() % 8) {
    binaryDecodeStr += std::string(8 - binaryDecodeStr.length() % 8, '0');
  }
  for (std::size_t i = 0; i < binaryDecodeStr.length(); i += 8) {
    int index = (int) std::bitset<8>(binaryDecodeStr.substr((uint64_t) i, 8)).to_ulong();
    if (index != 0) {
      decoded << char(index);
    }
  }
  return decoded.str();
}
}
