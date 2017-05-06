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
}
#endif //CUHKSZ_NETWORK_NETWORKFUNCTIONS
