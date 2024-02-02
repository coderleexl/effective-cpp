#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>
typedef unsigned char BYTE;

namespace Base64
{
    std::string base64_encode(BYTE const *buf, unsigned int bufLen);
    std::vector<BYTE> base64_decode(const std::string &);
}

#endif