#include "sio_http_parameters.h"

namespace sio {
	namespace httpParameters {

		sio_C_HttpVersion::sio_C_HttpVersion(const char* sio_CV_name, uint8_t sio_CV_major, uint8_t sio_CV_minor)
		{
			sio_V_name = sio_CV_name;
			sio_V_major = sio_CV_major;
			sio_V_minor = sio_CV_minor;
			sio_SS_HttpVersion << sio_V_name << "/" << sio_V_major << "." << sio_V_minor;
			sio_V_HttpVersionResult = sio_SS_HttpVersion.str();
		}

		std::string sio_C_HttpVersion::sio_FN_GetHttpVersion()
		{
			return sio_V_HttpVersionResult;
		}

		sio_C_HttpUniformResourceIdentifier::sio_C_HttpUniformResourceIdentifier(const char* sio_CV_protocolName, const char* sio_CV_host, uint8_t sio_CV_port, const char* sio_CV_absPath, const char* sio_CV_query)
		{
			sio_V_protocolName = sio_CV_protocolName;
			sio_V_host = sio_CV_host;
			sio_V_port = sio_CV_port;
			sio_V_absPath = sio_CV_absPath;
			sio_V_query = sio_CV_query;
			if (sio_V_port != 0 && sio_V_absPath != 0 && sio_V_query != 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << ":" << sio_V_port << sio_V_absPath << "?" << sio_V_query;
			}
			else if (sio_V_port != 0 && sio_V_absPath != 0 && sio_V_query == 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << ":" << sio_V_port << sio_V_absPath;
			}
			else if (sio_V_port != 0 && sio_V_absPath == 0 && sio_V_query != 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << ":" << sio_V_port << sio_V_absPath << "?" << sio_V_query;
			}
			else if (sio_V_port != 0 && sio_V_absPath == 0 && sio_V_query == 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << ":" << sio_V_port;
			}
			else if (sio_V_port == 0 && sio_V_absPath != 0 && sio_V_query == 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << sio_V_absPath;
			}
			else if (sio_V_port == 0 && sio_V_absPath == 0 && sio_V_query != 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << sio_V_absPath << "?" << sio_V_query;
			}
			else if (sio_V_port == 0 && sio_V_absPath != 0 && sio_V_query != 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host << sio_V_absPath << "?" << sio_V_query;
			}
			else if (sio_V_port == 0 && sio_V_absPath == 0 && sio_V_query == 0) {
				sio_SS_HttpUniformResourceIdentifier << sio_V_protocolName << ":" << "//" << sio_V_host;
			}
			sio_V_HttpUniformResourceIdentifierResult = sio_SS_HttpUniformResourceIdentifier.str();
		}

		std::string sio_C_HttpUniformResourceIdentifier::sio_FN_GetHttpUniformResourceIdentifiers()
		{
			return sio_V_HttpUniformResourceIdentifierResult;
		}

		sio_C_HttpDateTimeFormat::sio_C_HttpDateTimeFormat(sio_E_HttpDateTimeFormat* sio_PE_HttpDateTimeFormat)
		{
			now = time(0);
			if (*sio_PE_HttpDateTimeFormat == sio_E_HttpDateTimeFormat::RFC822) {
				char TIME_BUFF[64];
				tm* t_m_f = gmtime(&now);
				strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
				sio_SS_HttpDateTimeFormat << TIME_BUFF;
			}
			else if (*sio_PE_HttpDateTimeFormat == sio_E_HttpDateTimeFormat::RFC850) {
				char TIME_BUFF[64];
				tm* t_m_f = gmtime(&now);
				strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
				sio_SS_HttpDateTimeFormat << TIME_BUFF;
			}
			else if (*sio_PE_HttpDateTimeFormat == sio_E_HttpDateTimeFormat::ANSI) {
				char TIME_BUFF[64];
				tm* t_m_f = gmtime(&now);
				strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
				sio_SS_HttpDateTimeFormat << TIME_BUFF;
			}
			else {
				assert("No Date Time Format specified");
			}
			sio_V_HttpDateTimeFormatResult = sio_SS_HttpDateTimeFormat.str();
			delete sio_PE_HttpDateTimeFormat;
		}

		std::string sio_C_HttpDateTimeFormat::sio_FN_GetHttpDateTimeFormat() {
			return sio_V_HttpDateTimeFormatResult;
		}

		sio_C_HttpCharacterSets::sio_C_HttpCharacterSets(sio_E_HttpCharacterSets* sio_PE_HttpCharacterSets)
		{
			if (*sio_PE_HttpCharacterSets == sio_E_HttpCharacterSets::US_ASCII) {
				sio_V_HttpCharacterSetsResult = "US-ASCII";
			}
			else if (*sio_PE_HttpCharacterSets == sio_E_HttpCharacterSets::ISO_8859_1) {
				sio_V_HttpCharacterSetsResult = "ISO-8859-1";
			}
			else if (*sio_PE_HttpCharacterSets == sio_E_HttpCharacterSets::ISO_8859_7) {
				sio_V_HttpCharacterSetsResult = "ISO-8859-7";
			}
			else {
				assert("No Character Set specified");
			}
			delete sio_PE_HttpCharacterSets;
		}

		std::string sio_C_HttpCharacterSets::sio_FN_GetHttpCharacterSets()
		{
				return sio_V_HttpCharacterSetsResult;
		}

		sio_C_HttpContentEncodings::sio_C_HttpContentEncodings(sio_E_HttpContentEncodings* sio_PE_HttpContentEncodings)
		{
			if (*sio_PE_HttpContentEncodings == sio_E_HttpContentEncodings::GZIP) {
				sio_SS_HttpContentEncodings << "Accept-encoding: " << "gzip";
			}
			else if (*sio_PE_HttpContentEncodings == sio_E_HttpContentEncodings::COMPRESS) {
				sio_SS_HttpContentEncodings << "Accept-encoding: " << "compress";
			}
			else if (*sio_PE_HttpContentEncodings == sio_E_HttpContentEncodings::DEFLATE) {
				sio_SS_HttpContentEncodings << "Accept-encoding: " << "deflate";
			}
			else {
				assert("No Content Encoding specified");
			}
			sio_V_HttpContentEncodingsResult = sio_SS_HttpContentEncodings.str();
			delete sio_PE_HttpContentEncodings;
		}

		std::string sio_C_HttpContentEncodings::sio_FN_GetHttpContentEncodings()
		{
			return sio_V_HttpContentEncodingsResult;
		}

		sio_C_HttpMediaType::sio_C_HttpMediaType(const char* sio_FV_mediaType, const char* sio_FV_mediaSubtype, const char* sio_FV_mediaParameter, sio_E_HttpMediaType* sio_PE_HttpMediaType)
		{
			sio_V_mediaType = sio_FV_mediaType;
			sio_V_mediaSubtype = sio_FV_mediaSubtype;
			sio_V_mediaParameter = sio_FV_mediaParameter;
			if (*sio_PE_HttpMediaType == sio_E_HttpMediaType::CONTENT_TYPE) {
				sio_SS_HttpMediaType << "Content-Type: " << sio_V_mediaType << "/" << sio_V_mediaSubtype << "*( " << sio_V_mediaParameter << ")";
			}
			else if (*sio_PE_HttpMediaType == sio_E_HttpMediaType::ACCEPT) {
				sio_SS_HttpMediaType << "Accept: " << sio_V_mediaType << "/" << sio_V_mediaSubtype << "*( " << sio_V_mediaParameter << ")";
			}
			else {
				assert("No Media Type specified");
			}
			sio_V_HttpMediaTypeResult = sio_SS_HttpMediaType.str();
			delete sio_PE_HttpMediaType;
		}

		std::string sio_C_HttpMediaType::sio_FN_GetHttpMediaType()
		{
			return sio_V_HttpMediaTypeResult;
		}

		sio_C_HttpLanguageTags::sio_C_HttpLanguageTags(const char* sio_FV_primaryTag, const char* sio_FV_subTag, sio_E_HttpLanguageTags* sio_PE_HttpLanguageTags)
		{
			sio_V_primaryTag = sio_FV_primaryTag;
			sio_V_subTag = sio_FV_subTag;
			if (*sio_PE_HttpLanguageTags == sio_E_HttpLanguageTags::ACCEPT_LANGUAGE) {
				sio_SS_HttpLanguageTags << "Accept-Language: " << sio_V_primaryTag << "-" << sio_V_subTag;
			}
			else if (*sio_PE_HttpLanguageTags == sio_E_HttpLanguageTags::CONTENT_LANGUAGE) {
				sio_SS_HttpLanguageTags << "Content-Language: " << sio_V_primaryTag << "-" << sio_V_subTag;
			}
			else {
				assert("No Language Tag specified");
			}
			sio_V_HttpLanguageTagsResult = sio_SS_HttpLanguageTags.str();
			delete sio_PE_HttpLanguageTags;
		}

		std::string sio_C_HttpLanguageTags::sio_FN_GetHttpLanguageTags()
		{
			return sio_V_HttpLanguageTagsResult;
		}

}// namespace httpParameters
}// namespace sio

