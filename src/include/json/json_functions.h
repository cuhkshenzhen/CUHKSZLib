#include <string>

#ifndef CUHKSZ_JSON_JSONFUNCTIONS
#define CUHKSZ_JSON_JSONFUNCTIONS
namespace cuhksz{
/**
 * Escape special characters to be put into a json document
 * @param ptr string to put
 * @return escaped string
 */
std::string jsonEscape(const std::string &ptr);
}
#endif //CUHKSZ_JSON_JSONwFUNCTIONS
