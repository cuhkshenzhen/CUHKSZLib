#include <string>

#ifndef CUHKSZ_NETWORK_NETWORKFUNCTIONS
#define CUHKSZ_NETWORK_NETWORKFUNCTIONS
namespace cuhksz {
/**
 * Encode a string to url-safe type
 * @param string string to encode
 * @return url-safe string
 */
std::string urlEncode(const std::string &string);

/**
 * Encode a url-safe string to its origin
 * @param string string to decode
 * @return string
 */
std::string urlDecode(const std::string str);
}  // namespace cuhksz
#endif  // CUHKSZ_NETWORK_NETWORKFUNCTIONS
