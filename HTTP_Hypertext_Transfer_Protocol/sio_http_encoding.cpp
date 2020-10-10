#include "sio_http_encoding.h"

namespace sio
{
	namespace httpCaching
	{
		sio::httpCaching::sio_C_HttpEncoding::sio_C_HttpEncoding(const char* sio_V_HttpEncodingString, sio_E_HttpEncoding* sio_PE_HttpEncoding)
		{
			sio_SS_HttpEncoding << sio_V_HttpEncodingString;
			char c;
			while (sio_SS_HttpEncoding.get(c)) {
				if (isalnum(c) || c == '*' || c == '-' || c == '.' || c == '_') {
					sio_V_HttpEncodingResult += c;
				}
				else {
					std::stringstream tem;
					tem << std::hex;
					tem << "%" << std::setw(2) << int(unsigned char(c));
					sio_V_HttpEncodingResult += tem.str();
				}
			}
		}

		std::string sio::httpCaching::sio_C_HttpEncoding::sio_FN_GetHttpEncoding()
		{
			return sio_V_HttpEncodingResult;
		}
	} // namespace httpCaching
} // namespace sio



