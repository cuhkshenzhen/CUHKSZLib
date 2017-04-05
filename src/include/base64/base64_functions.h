#ifndef CUHKSZ_BASE64_FUNCTIONS
#define CUHKSZ_BASE64_FUNCTIONS

#include <string>
namespace cuhksz{
std::string base64Encode(std::string str, int length=-1);
std::string base64Decode(std::string decodeStr);
}
#endif //CUHKSZ_BASE64_FUNCTIONS
