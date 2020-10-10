
#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>


namespace sio
{
	namespace utility
	{
		////////////////////////////////////////////////////////////////////////////////
		//        NAME: Base64
		// DESCRIPTION: This is the root of HTTPHypertextTransferProtocol HEADER FIELDS
		//   ARGUMENTS: N/A
		// USES GLOBAL: N/A
		// MODIFIES GL: N/A
		//     RETURNS: N/A
		//      AUTHOR: SHERIFI
		// AUTHOR/DATE: GMT Saturday, July 12, 2020
		////////////////////////////////////////////////////////////////////////////////
		static const unsigned char from_base64[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
							255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
							255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  62, 255,  62, 255,  63,
							52,  53,  54,  55,  56,  57,  58,  59,  60,  61, 255, 255, 255, 255, 255, 255,
							255,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
							15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25, 255, 255, 255, 255,  63,
							255,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
							41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51, 255, 255, 255, 255, 255 };

		static const char to_base64[] =	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		class Base64
		{
		private:
		public:
			static std::string encode(const std::vector<unsigned char>& buf);
			static std::string encode(const unsigned char* buf, unsigned int bufLen);
			static std::vector<unsigned char> decode(std::string encoded_string);
		};
	}
}

/*
unsigned char buf[] = "ABCD";
std::string encoded = Base64::encode(buf, 4);
// encoded = "QUJDRA=="
std::vector<unsigned char> decoded = Base64::decode(encoded);
*/

#endif //_BASE64_H_
