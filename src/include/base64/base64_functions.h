#ifndef CUHKSZ_BASE64_BASE64FUNCTIONS
#define CUHKSZ_BASE64_BASE64FUNCTIONS

#include <string>
namespace cuhksz {

/**
 * Encode a string to base64
 * @param str string to hash
 * @param length (optional) length of the hash
 * @return base64 hash. empty if failed to encode or exceeded the length.
 */
std::string base64Encode(std::string str, int length = -1);

/**
 * Decode base64 to its original string
 * @param decodeStr string to decode
 * @return original string.
 */
std::string base64Decode(std::string decodeStr);
}  // namespace cuhksz
#endif  // CUHKSZ_BASE64_BASE64FUNCTIONS
