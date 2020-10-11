#include "sio_http_header_fields.h"

namespace sio {
	namespace httpHeaderFields {
	
sio_C_HttpGeneralHeaderCacheControlRequestDirective::sio_C_HttpGeneralHeaderCacheControlRequestDirective(sio_E_HttpGeneralHeaderCacheControlRequestDirective* sio_PE_HttpGeneralHeaderCacheControlRequestDirective, uint32_t sec)
{
	sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "Cache-control: ";
	if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::NO_CACHE_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "no-cache";
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "A cache must not use the response to satisfy a subsequent request without successful revalidation with the origin server.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::NO_STORE_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "no-store";
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "The cache should not store anything about the client request or server response.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::MAX_AGE_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "max-age=" << sec;
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "Indicates that the client is willing to accept a response whose age is not greater than the specified time in seconds.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::MAX_STALE_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "max-stale[=" << sec << "]";
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "Indicates that the client is willing to accept a response that has exceeded its expiration time. If seconds are given, it must not be expired by more than that time.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::MIN_FRESH_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "min-refresh=" << sec;
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "Indicates that the client is willing to accept a response whose freshness lifetime is not less than its current age plus the specified time in seconds.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::NO_TRANSFORM_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "no-transform";
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "Does not convert the entity-body.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlRequestDirective == sio_E_HttpGeneralHeaderCacheControlRequestDirective::ONLY_IF_CACHED_REQ) {
		sio_SS_HttpGeneralHeaderCacheControlRequestDirective << "only-if-cached";
		sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription = "Does not retrieve new data. The cache can send a document only if it is in the cache, and should not contact the origin-server to see if a newer copy exists.";
	}
	else {
		assert("No Request cache directive providet");
	}
	delete sio_PE_HttpGeneralHeaderCacheControlRequestDirective;
	sio_V_HttpGeneralHeaderCacheControlRequestDirectiveResult = sio_SS_HttpGeneralHeaderCacheControlRequestDirective.str();
}

std::string sio_C_HttpGeneralHeaderCacheControlRequestDirective::sio_FN_GetHttpGeneralHeaderCacheControlRequestDirective()
{
	return sio_V_HttpGeneralHeaderCacheControlRequestDirectiveResult;
}

std::string sio_C_HttpGeneralHeaderCacheControlRequestDirective::sio_FN_GetHttpGeneralHeaderCacheControlRequestDirectiveDescription()
{
	return sio_V_HttpGeneralHeaderCacheControlRequestDirectiveDescription;
}

sio_C_HttpGeneralHeaderCacheControlResponseDirective::sio_C_HttpGeneralHeaderCacheControlResponseDirective(sio_E_HttpGeneralHeaderCacheControlResponseDirective* sio_PE_HttpGeneralHeaderCacheControlResponseDirective, uint32_t sec)
{
	sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "Cache-control: ";
	if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::PUBLIC_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "public";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "Indicates that the response may be cached by any cache.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::PRIVATE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "private";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "Indicates that all or part of the response message is intended for a single user and must not be cached by a shared cache.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::NO_CACHE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "no-cache";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "A cache must not use the response to satisfy a subsequent request without successful re-validation with the origin server.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::NO_STORE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "no-store";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "The cache should not store anything about the client request or server response.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::NO_TRANSFORM_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "no-transform";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "Does not convert the entity-body.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::MUST_REVALIDATE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "must-revalidate";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "The cache must verify the status of the stale documents before using it and expired ones should not be used.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::PROXY_REVALIDATE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "proxy-revalidate";
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "The proxy-revalidate directive has the same meaning as the must- revalidate directive, except that it does not apply to non-shared user agent caches.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::MAX_AGE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "max-age=" << sec;
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "Indicates that the client is willing to accept a response whose age is not greater than the specified time in seconds.";
	}
	else if (*sio_PE_HttpGeneralHeaderCacheControlResponseDirective == sio_E_HttpGeneralHeaderCacheControlResponseDirective::S_MAXAGE_RES) {
		sio_SS_HttpGeneralHeaderCacheControlResponseDirective << "s-maxage=" << sec;
		sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription = "The maximum age specified by this directive overrides the maximum age specified by either the max-age directive or the Expires header. The s-maxage directive is always ignored by a private cache.";
	}
	else {
		assert("No Response cache directive providet");
	}
	delete sio_PE_HttpGeneralHeaderCacheControlResponseDirective;
	sio_V_HttpGeneralHeaderCacheControlResponseDirectiveResult = sio_SS_HttpGeneralHeaderCacheControlResponseDirective.str();
}

std::string sio_C_HttpGeneralHeaderCacheControlResponseDirective::sio_FN_GetHttpGeneralHeaderCacheControlResponseDirective()
{
	return sio_V_HttpGeneralHeaderCacheControlResponseDirectiveResult;
}

std::string sio_C_HttpGeneralHeaderCacheControlResponseDirective::sio_FN_GetHttpGeneralHeaderCacheControlResponseDirectiveDescription()
{
	return sio_V_HttpGeneralHeaderCacheControlResponseDirectiveDescription;
}

sio_C_HttpGeneralHeaderConnection::sio_C_HttpGeneralHeaderConnection(sio_E_HttpGeneralHeaderConnection* sio_PE_HttpGeneralHeaderConnection)
{
	sio_SS_HttpGeneralHeaderConnection << "Connection: ";
	if (*sio_PE_HttpGeneralHeaderConnection == sio_E_HttpGeneralHeaderConnection::CLOSE) {
		sio_SS_HttpGeneralHeaderConnection << "close";
	}
	else if (*sio_PE_HttpGeneralHeaderConnection == sio_E_HttpGeneralHeaderConnection::KEEP_ALIVE) {
		sio_SS_HttpGeneralHeaderConnection << "keep-alive";
	}
	else {
		assert("No Connection method specified.");
	}
	delete sio_PE_HttpGeneralHeaderConnection;
	sio_V_HttpGeneralHeaderConnectionResult = sio_SS_HttpGeneralHeaderConnection.str();
}

std::string sio_C_HttpGeneralHeaderConnection::sio_FN_GetHttpGeneralHeaderConnection()
{
	return sio_V_HttpGeneralHeaderConnectionResult;
}

sio_C_HttpGeneralHeaderDate::sio_C_HttpGeneralHeaderDate(sio_E_HttpGeneralHeaderDate* sio_PE_HttpGeneralHeaderDate)
{
	now = time(0);
	if (*sio_PE_HttpGeneralHeaderDate == sio_E_HttpGeneralHeaderDate::RFC822) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpGeneralHeaderDate << TIME_BUFF;
	}
	else if (*sio_PE_HttpGeneralHeaderDate == sio_E_HttpGeneralHeaderDate::RFC850) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpGeneralHeaderDate << TIME_BUFF;
	}
	else if (*sio_PE_HttpGeneralHeaderDate == sio_E_HttpGeneralHeaderDate::ANSI) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
		sio_SS_HttpGeneralHeaderDate << TIME_BUFF;
	}
	else {
		assert("No Date Time Format specified");
	}
	delete sio_PE_HttpGeneralHeaderDate;
	sio_V_HttpGeneralHeaderDateResult = sio_SS_HttpGeneralHeaderDate.str();
}

std::string sio_C_HttpGeneralHeaderDate::sio_FN_GetHttpGeneralHeaderDate()
{
	return sio_V_HttpGeneralHeaderDateResult;
}

sio_C_HttpGeneralHeaderPragma::sio_C_HttpGeneralHeaderPragma(const char* sio_V_httpGeneralHeaderPragma, sio_E_HttpGeneralHeaderPragma* sio_PE_HttpGeneralHeaderPragma)
{
	sio_SS_HttpGeneralHeaderPragma << "Pragma: " << sio_V_httpGeneralHeaderPragma;
	delete sio_PE_HttpGeneralHeaderPragma;
	sio_V_HttpGeneralHeaderPragmaResult = sio_SS_HttpGeneralHeaderPragma.str();
}

sio_C_HttpGeneralHeaderPragma& sio_C_HttpGeneralHeaderPragma::Add(const char* sio_V_httpGeneralHeaderPragma, sio_E_HttpGeneralHeaderPragma* sio_PE_HttpGeneralHeaderPragma)
{
	sio_SS_HttpGeneralHeaderPragma << ", " << sio_V_httpGeneralHeaderPragma;
	delete sio_PE_HttpGeneralHeaderPragma;
	sio_V_HttpGeneralHeaderPragmaResult.append(sio_SS_HttpGeneralHeaderPragma.str());
	return *this;
}

std::string sio_C_HttpGeneralHeaderPragma::sio_FN_GetHttpGeneralHeaderPragma()
{
	return sio_V_HttpGeneralHeaderPragmaResult;
}

sio_C_HttpGeneralHeaderTrailer::sio_C_HttpGeneralHeaderTrailer(sio_E_HttpGeneralHeaderTrailer* sio_PE_HttpGeneralHeaderTrailer)
{
	delete sio_PE_HttpGeneralHeaderTrailer;
}

std::string sio_C_HttpGeneralHeaderTrailer::sio_FN_GetHttpGeneralHeaderTrailer()
{
	return sio_V_HttpGeneralHeaderTrailerResult;
}

sio_C_HttpGeneralHeaderTransferEncoding::sio_C_HttpGeneralHeaderTransferEncoding(sio_E_HttpGeneralHeaderTransferEncoding* sio_PE_HttpGeneralHeaderTransferEncoding)
{
	sio_SS_HttpGeneralHeaderTransferEncoding << "Transfer-Encoding: ";
	if (*sio_PE_HttpGeneralHeaderTransferEncoding == sio_E_HttpGeneralHeaderTransferEncoding::CHUNKED) {
		sio_SS_HttpGeneralHeaderTransferEncoding << "chunked";
	}
	else {
		assert("No Transfer Encoding specified.");
	}
	delete sio_PE_HttpGeneralHeaderTransferEncoding;
	sio_V_HttpGeneralHeaderTransferEncodingResult = sio_SS_HttpGeneralHeaderTransferEncoding.str();
}

std::string sio_C_HttpGeneralHeaderTransferEncoding::sio_FN_GetHttpGeneralHeaderTransferEncoding()
{
	return sio_V_HttpGeneralHeaderTransferEncodingResult;
}

sio_C_HttpGeneralHeaderUpgrade::sio_C_HttpGeneralHeaderUpgrade(sio_E_HttpGeneralHeaderUpgrade* sio_PE_HttpGeneralHeaderUpgrade)
{
	sio_SS_HttpGeneralHeaderUpgrade << "Upgrade: ";
	if (*sio_PE_HttpGeneralHeaderUpgrade == sio_E_HttpGeneralHeaderUpgrade::HTTP_2_0) {
		sio_SS_HttpGeneralHeaderUpgrade << "HTTP/2.0";
	}
	else if (*sio_PE_HttpGeneralHeaderUpgrade == sio_E_HttpGeneralHeaderUpgrade::SHTTP_1_3) {
		sio_SS_HttpGeneralHeaderUpgrade << "SHTTP/1.3";
	}
	else if (*sio_PE_HttpGeneralHeaderUpgrade == sio_E_HttpGeneralHeaderUpgrade::IRC_6_9) {
		sio_SS_HttpGeneralHeaderUpgrade << "IRC/6.9";
	}
	else if (*sio_PE_HttpGeneralHeaderUpgrade == sio_E_HttpGeneralHeaderUpgrade::RTA_X11) {
		sio_SS_HttpGeneralHeaderUpgrade << "RTA/x11";
	}
	else {
		assert("No Connection method specified.");
	}
	delete sio_PE_HttpGeneralHeaderUpgrade;
	sio_V_HttpGeneralHeaderUpgradeResult = sio_SS_HttpGeneralHeaderUpgrade.str();
}

std::string sio_C_HttpGeneralHeaderUpgrade::sio_FN_GetHttpGeneralHeaderUpgrade()
{
	return sio_V_HttpGeneralHeaderUpgradeResult;
}

sio_C_HttpGeneralHeaderVia::sio_C_HttpGeneralHeaderVia(const char* sio_V_httpGeneralHeaderVia, sio_E_HttpGeneralHeaderVia* sio_PE_HttpGeneralHeaderVia)
{
	sio_SS_HttpGeneralHeaderVia << "Via: " << sio_V_httpGeneralHeaderVia;
	delete sio_PE_HttpGeneralHeaderVia;
	sio_V_HttpGeneralHeaderViaResult = sio_SS_HttpGeneralHeaderVia.str();
}

sio_C_HttpGeneralHeaderVia& sio_C_HttpGeneralHeaderVia::Add(const char* sio_V_httpGeneralHeaderVia, sio_E_HttpGeneralHeaderVia* sio_PE_HttpGeneralHeaderVia)
{
	sio_SS_HttpGeneralHeaderVia << ", " << sio_V_httpGeneralHeaderVia;
	delete sio_PE_HttpGeneralHeaderVia;
	sio_V_HttpGeneralHeaderViaResult.append(sio_SS_HttpGeneralHeaderVia.str());
	return *this;
}

std::string sio_C_HttpGeneralHeaderVia::sio_FN_GetHttpGeneralHeaderVia()
{
	return sio_V_HttpGeneralHeaderViaResult;
}

sio_C_HttpGeneralHeaderWarning::sio_C_HttpGeneralHeaderWarning(const char* sio_V_HttpGeneralHeaderWarnCode, const char* sio_V_HttpGeneralHeaderWarnAgent, const char* sio_V_HttpGeneralHeaderWarnText, const char* sio_V_HttpGeneralHeaderWarnData, sio_E_HttpGeneralHeaderWarning* sio_PE_HttpGeneralHeaderWarning)
{
	sio_SS_HttpGeneralHeaderWarning << sio_V_HttpGeneralHeaderWarnCode << " " << sio_V_HttpGeneralHeaderWarnAgent << " " << sio_V_HttpGeneralHeaderWarnText << " " << sio_V_HttpGeneralHeaderWarnData;
	delete sio_PE_HttpGeneralHeaderWarning;
	sio_V_HttpGeneralHeaderWarningResult = sio_SS_HttpGeneralHeaderWarning.str();
}

std::string sio_C_HttpGeneralHeaderWarning::sio_FN_GetHttpGeneralHeaderWarning()
{
	return sio_V_HttpGeneralHeaderWarningResult;
}

sio_C_HttpClientRequestHeaderAccept::sio_C_HttpClientRequestHeaderAccept(const char* sio_V_httpClientRequestHeaderAcceptType, const char* sio_V_httpClientRequestHeaderAcceptSubtype, float sio_V_httpClientRequestHeaderAcceptQvalue, sio_E_HttpClientRequestHeaderAccept* sio_PE_HttpClientRequestHeaderAccept)
{
	sio_SS_HttpClientRequestHeaderAccept << "Accept: " << sio_V_httpClientRequestHeaderAcceptType << "/" << sio_V_httpClientRequestHeaderAcceptSubtype << "; q=" << sio_V_httpClientRequestHeaderAcceptQvalue;
	delete sio_PE_HttpClientRequestHeaderAccept;
	sio_V_HttpClientRequestHeaderAcceptResult = sio_SS_HttpClientRequestHeaderAccept.str();
}

sio_C_HttpClientRequestHeaderAccept& sio_C_HttpClientRequestHeaderAccept::Add(const char* sio_V_httpClientRequestHeaderAcceptType, const char* sio_V_httpClientRequestHeaderAcceptSubtype, float sio_V_httpClientRequestHeaderAcceptQvalue, sio_E_HttpClientRequestHeaderAccept* sio_PE_HttpClientRequestHeaderAccept)
{
	sio_SS_HttpClientRequestHeaderAccept << ", " << sio_V_httpClientRequestHeaderAcceptType << "/" << sio_V_httpClientRequestHeaderAcceptSubtype << "; q=" << sio_V_httpClientRequestHeaderAcceptQvalue;
	delete sio_PE_HttpClientRequestHeaderAccept;
	sio_V_HttpClientRequestHeaderAcceptResult.append(sio_SS_HttpClientRequestHeaderAccept.str());
	return *this;
}

std::string sio_C_HttpClientRequestHeaderAccept::sio_FN_GetHttpClientRequestHeaderAccept()
{
	return sio_V_HttpClientRequestHeaderAcceptResult;
}

sio_C_HttpClientRequestHeaderAcceptCharset::sio_C_HttpClientRequestHeaderAcceptCharset(const char* sio_V_httpClientRequestHeaderAcceptCharsetCharacterSet, float sio_V_httpClientRequestHeaderAcceptCharsetQvalue, sio_E_HttpClientRequestHeaderAcceptCharset* sio_PE_HttpClientRequestHeaderAcceptCharset)
{
	sio_SS_HttpClientRequestHeaderAcceptCharset << "Accept-Charset: ";
	if (*sio_PE_HttpClientRequestHeaderAcceptCharset == sio_E_HttpClientRequestHeaderAcceptCharset::ISO_8859_5) {
		sio_SS_HttpClientRequestHeaderAcceptCharset << "iso-8859-5";
		if (sio_V_httpClientRequestHeaderAcceptCharsetQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptCharset << "; q=" << sio_V_httpClientRequestHeaderAcceptCharsetQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptCharset == sio_E_HttpClientRequestHeaderAcceptCharset::UNICODE_1_1) {
		sio_SS_HttpClientRequestHeaderAcceptCharset << "unicode-1-1";
		if (sio_V_httpClientRequestHeaderAcceptCharsetQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptCharset << "; q=" << sio_V_httpClientRequestHeaderAcceptCharsetQvalue;
		}
	}
	else {
		assert("No Accept Charset are specified.");
	}
	delete sio_PE_HttpClientRequestHeaderAcceptCharset;
	sio_V_HttpClientRequestHeaderAcceptCharsetResult = sio_SS_HttpClientRequestHeaderAcceptCharset.str();
}

std::string sio_C_HttpClientRequestHeaderAcceptCharset::sio_FN_GetHttpClientRequestHeaderAcceptCharset()
{
	return sio_V_HttpClientRequestHeaderAcceptCharsetResult;
}

sio_C_HttpClientRequestHeaderAcceptEncoding::sio_C_HttpClientRequestHeaderAcceptEncoding(float sio_V_httpClientRequestHeaderAcceptEncodingQvalue, sio_E_HttpClientRequestHeaderAcceptEncoding* sio_PE_HttpClientRequestHeaderAcceptEncoding)
{
	sio_SS_HttpClientRequestHeaderAcceptEncoding << "Accept-Encoding: ";
	if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::COMPRESS) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "compress";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::GZIP) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "gzip";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::IDENTITY) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "identity";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::ALL) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "*";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else {
		assert("No Accept Charset are specified.");
	}
	delete sio_PE_HttpClientRequestHeaderAcceptEncoding;
	sio_V_HttpClientRequestHeaderAcceptEncodingResult = sio_SS_HttpClientRequestHeaderAcceptEncoding.str();
}

sio_C_HttpClientRequestHeaderAcceptEncoding& sio_C_HttpClientRequestHeaderAcceptEncoding::Add(float sio_V_httpClientRequestHeaderAcceptEncodingQvalue, sio_E_HttpClientRequestHeaderAcceptEncoding* sio_PE_HttpClientRequestHeaderAcceptEncoding)
{
	sio_SS_HttpClientRequestHeaderAcceptEncoding << ", ";
	if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::COMPRESS) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "compress";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::GZIP) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "gzip";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::IDENTITY) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "identity";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptEncoding == sio_E_HttpClientRequestHeaderAcceptEncoding::ALL) {
		sio_SS_HttpClientRequestHeaderAcceptEncoding << "*";
		if (sio_V_httpClientRequestHeaderAcceptEncodingQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptEncoding << "; q=" << sio_V_httpClientRequestHeaderAcceptEncodingQvalue;
		}
	}
	else {
		assert("No Accept Charset are specified.");
	}
	delete sio_PE_HttpClientRequestHeaderAcceptEncoding;
	sio_V_HttpClientRequestHeaderAcceptEncodingResult.append(sio_SS_HttpClientRequestHeaderAcceptEncoding.str());
	return *this;
}

std::string sio_C_HttpClientRequestHeaderAcceptEncoding::sio_FN_GetHttpClientRequestHeaderAcceptEncoding()
{
	return sio_V_HttpClientRequestHeaderAcceptEncodingResult;
}

sio_C_HttpClientRequestHeaderAcceptLanguage::sio_C_HttpClientRequestHeaderAcceptLanguage(float sio_V_httpClientRequestHeaderAcceptLanguageQvalue, sio_E_HttpClientRequestHeaderAcceptLanguage* sio_PE_HttpClientRequestHeaderAcceptLanguage)
{
	sio_SS_HttpClientRequestHeaderAcceptLanguage << "Accept-Language: ";
	if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::EN_US) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "en-us";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::EN) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "en";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::EN_GB) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "en-gb";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::DA) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "da";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else {
		assert("No Accept Language are specified.");
	}
	delete sio_PE_HttpClientRequestHeaderAcceptLanguage;
	sio_V_HttpClientRequestHeaderAcceptLanguageResult = sio_SS_HttpClientRequestHeaderAcceptLanguage.str();
}

sio_C_HttpClientRequestHeaderAcceptLanguage& sio_C_HttpClientRequestHeaderAcceptLanguage::Add(float sio_V_httpClientRequestHeaderAcceptLanguageQvalue, sio_E_HttpClientRequestHeaderAcceptLanguage* sio_PE_HttpClientRequestHeaderAcceptLanguage)
{
	sio_SS_HttpClientRequestHeaderAcceptLanguage << ", ";
	if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::EN_US) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "en-us";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::EN) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "en";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::EN_GB) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "en-gb";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderAcceptLanguage == sio_E_HttpClientRequestHeaderAcceptLanguage::DA) {
		sio_SS_HttpClientRequestHeaderAcceptLanguage << "da";
		if (sio_V_httpClientRequestHeaderAcceptLanguageQvalue != 0) {
			sio_SS_HttpClientRequestHeaderAcceptLanguage << "; q=" << sio_V_httpClientRequestHeaderAcceptLanguageQvalue;
		}
	}
	else {
		assert("No Accept Language are specified.");
	}
	delete sio_PE_HttpClientRequestHeaderAcceptLanguage;
	sio_V_HttpClientRequestHeaderAcceptLanguageResult.append(sio_SS_HttpClientRequestHeaderAcceptLanguage.str());
	return *this;
}

std::string sio_C_HttpClientRequestHeaderAcceptLanguage::sio_FN_GetHttpClientRequestHeaderAcceptLanguage()
{
	return sio_V_HttpClientRequestHeaderAcceptLanguageResult;
}

sio_C_HttpClientRequestHeaderAuthorization::sio_C_HttpClientRequestHeaderAuthorization(const char* sio_V_HttpClientRequestHeaderAuthorizationType, const unsigned char* sio_V_HttpClientRequestHeaderAuthorizationUsername, const unsigned char* sio_V_HttpClientRequestHeaderAuthorizationPassword, sio_E_HttpClientRequestHeaderAuthorization* sio_PE_HttpClientRequestHeaderAuthorization)
{
	sio_SS_HttpClientRequestHeaderAuthorization << "Authorization : " << sio_V_HttpClientRequestHeaderAuthorizationType << " ";
	 sio_V_HttpClientRequestHeaderAuthorizationResult = sio_SS_HttpClientRequestHeaderAuthorization.str();

	std::stringstream* temp = new std::stringstream;
	*temp << sio_V_HttpClientRequestHeaderAuthorizationUsername << ":" << sio_V_HttpClientRequestHeaderAuthorizationPassword;
	std::string* encode_in = new std::string;
	*encode_in = (*temp).str();
	delete temp;
	std::string result = sio::utility::Base64::encode(reinterpret_cast<const unsigned char*>((*encode_in).c_str()), static_cast<unsigned int>(sizeof(*encode_in)));
	sio_V_HttpClientRequestHeaderAuthorizationResult.append(result);

	delete encode_in;
	delete sio_PE_HttpClientRequestHeaderAuthorization;
}

std::string sio_C_HttpClientRequestHeaderAuthorization::sio_FN_GetHttpClientRequestHeaderAuthorization()
{
	return sio_V_HttpClientRequestHeaderAuthorizationResult;
}

sio_C_HttpClientRequestHeaderCookie::sio_C_HttpClientRequestHeaderCookie(const char* sio_V_HttpClientRequestHeaderCookieName, const char* sio_V_HttpClientRequestHeaderCookieValue, sio_E_HttpClientRequestHeaderCookie* sio_PE_HttpClientRequestHeaderCookie)
{
	sio_SS_HttpClientRequestHeaderCookie << "Cookie: " << sio_V_HttpClientRequestHeaderCookieName << "=" << sio_V_HttpClientRequestHeaderCookieValue;
	delete sio_PE_HttpClientRequestHeaderCookie;
	sio_V_HttpClientRequestHeaderCookieResult = sio_SS_HttpClientRequestHeaderCookie.str();
}

sio_C_HttpClientRequestHeaderCookie& sio_C_HttpClientRequestHeaderCookie::Add(const char* sio_V_HttpClientRequestHeaderCookieName, const char* sio_V_HttpClientRequestHeaderCookieValue, sio_E_HttpClientRequestHeaderCookie* sio_PE_HttpClientRequestHeaderCookie)
{
	sio_SS_HttpClientRequestHeaderCookie << ", " << sio_V_HttpClientRequestHeaderCookieName << "=" << sio_V_HttpClientRequestHeaderCookieValue;
	delete sio_PE_HttpClientRequestHeaderCookie;
	sio_V_HttpClientRequestHeaderCookieResult.append(sio_SS_HttpClientRequestHeaderCookie.str());
	return *this;
}

std::string sio_C_HttpClientRequestHeaderCookie::sio_FN_GetHttpClientRequestHeaderCookie()
{
	return sio_V_HttpClientRequestHeaderCookieResult;
}

sio_C_HttpClientRequestHeaderFrom::sio_C_HttpClientRequestHeaderFrom(const char* sio_V_HttpClientRequestHeaderFromEmail, sio_E_HttpClientRequestHeaderFrom* sio_PE_HttpClientRequestHeaderFrom)
{
	sio_SS_HttpClientRequestHeaderFrom << "From: " << sio_V_HttpClientRequestHeaderFromEmail;
	delete sio_PE_HttpClientRequestHeaderFrom;
	sio_V_HttpClientRequestHeaderFromResult = sio_SS_HttpClientRequestHeaderFrom.str();
}

std::string sio_C_HttpClientRequestHeaderFrom::sio_FN_GetHttpClientRequestHeaderFrom()
{
	return sio_V_HttpClientRequestHeaderFromResult;
}

sio_C_HttpClientRequestHeaderHost::sio_C_HttpClientRequestHeaderHost(const char* sio_V_HttpClientRequestHeaderHostName, uint16_t sio_V_HttpClientRequestHeaderHostPort, sio_E_HttpClientRequestHeaderHost* sio_PE_HttpClientRequestHeaderHost)
{
	sio_SS_HttpClientRequestHeaderHost << "Host: ";
	if (sio_V_HttpClientRequestHeaderHostPort == 80) {
		sio_SS_HttpClientRequestHeaderHost << sio_V_HttpClientRequestHeaderHostName;
	}
	else if (sio_V_HttpClientRequestHeaderHostPort != 0) {
		sio_SS_HttpClientRequestHeaderHost << sio_V_HttpClientRequestHeaderHostName << ":" << sio_V_HttpClientRequestHeaderHostPort;
	}
	else {
		assert("Wrong header request HOST field providert.");
	}
	delete sio_PE_HttpClientRequestHeaderHost;
	sio_V_HttpClientRequestHeaderHostResult = sio_SS_HttpClientRequestHeaderHost.str();
}

std::string sio_C_HttpClientRequestHeaderHost::sio_FN_GetHttpClientRequestHeaderHost()
{
	return sio_V_HttpClientRequestHeaderHostResult;
}

sio_C_HttpClientRequestHeaderIfMatch::sio_C_HttpClientRequestHeaderIfMatch(const char* sio_V_HttpClientRequestHeaderIfMatchEntityTag, sio_E_HttpClientRequestHeaderIfMatch* sio_PE_HttpClientRequestHeaderIfMatch)
{
	sio_SS_HttpClientRequestHeaderIfMatch << "If-Match: " << "\"" << sio_V_HttpClientRequestHeaderIfMatchEntityTag << "\"";
	sio_V_HttpClientRequestHeaderIfMatchResult = sio_SS_HttpClientRequestHeaderIfMatch.str();
	delete sio_PE_HttpClientRequestHeaderIfMatch;
}

sio_C_HttpClientRequestHeaderIfMatch& sio_C_HttpClientRequestHeaderIfMatch::Add(const char* sio_V_HttpClientRequestHeaderIfMatchEntityTag, sio_E_HttpClientRequestHeaderIfMatch* sio_PE_HttpClientRequestHeaderIfMatch)
{
	sio_SS_HttpClientRequestHeaderIfMatch << ", " << "\"" << sio_V_HttpClientRequestHeaderIfMatchEntityTag << "\"";
	delete sio_PE_HttpClientRequestHeaderIfMatch;
	sio_V_HttpClientRequestHeaderIfMatchResult.append(sio_SS_HttpClientRequestHeaderIfMatch.str());
	return *this;
}

std::string sio_C_HttpClientRequestHeaderIfMatch::sio_FN_GetHttpClientRequestHeaderIfMatch()
{
	return sio_V_HttpClientRequestHeaderIfMatchResult;
}

sio_C_HttpClientRequestHeaderIfModifiedSince::sio_C_HttpClientRequestHeaderIfModifiedSince(sio_E_HttpClientRequestHeaderIfModifiedSince* sio_PE_HttpClientRequestHeaderIfModifiedSince)
{
	sio_SS_HttpClientRequestHeaderIfModifiedSince << "If-Modified-Since: ";
	now = time(0);
	if (*sio_PE_HttpClientRequestHeaderIfModifiedSince == sio_E_HttpClientRequestHeaderIfModifiedSince::RFC822) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpClientRequestHeaderIfModifiedSince << TIME_BUFF;
	}
	else if (*sio_PE_HttpClientRequestHeaderIfModifiedSince == sio_E_HttpClientRequestHeaderIfModifiedSince::RFC850) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpClientRequestHeaderIfModifiedSince << TIME_BUFF;
	}
	else if (*sio_PE_HttpClientRequestHeaderIfModifiedSince == sio_E_HttpClientRequestHeaderIfModifiedSince::ANSI) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
		sio_SS_HttpClientRequestHeaderIfModifiedSince << TIME_BUFF;
	}
	else {
		assert("No Date Time Format specified");
	}
	delete sio_PE_HttpClientRequestHeaderIfModifiedSince;
	sio_V_HttpClientRequestHeaderIfModifiedSinceResult = sio_SS_HttpClientRequestHeaderIfModifiedSince.str();
}

std::string sio_C_HttpClientRequestHeaderIfModifiedSince::sio_FN_GetHttpClientRequestHeaderIfModifiedSince()
{
	return sio_V_HttpClientRequestHeaderIfModifiedSinceResult;
}

sio_C_HttpClientRequestHeaderIfNotMatch::sio_C_HttpClientRequestHeaderIfNotMatch(const char* sio_V_HttpClientRequestHeaderIfNotMatchEntityTag, sio_E_HttpClientRequestHeaderIfNotMatch* sio_PE_HttpClientRequestHeaderIfNotMatchEntityTag)
{
	sio_SS_HttpClientRequestHeaderIfNotMatch << "If-Not-Match :" << sio_V_HttpClientRequestHeaderIfNotMatchEntityTag;
	delete sio_PE_HttpClientRequestHeaderIfNotMatchEntityTag;
	sio_V_HttpClientRequestHeaderIfNotMatchResult = sio_SS_HttpClientRequestHeaderIfNotMatch.str();
}

std::string sio_C_HttpClientRequestHeaderIfNotMatch::sio_FN_GetHttpClientRequestHeaderIfNotMatch()
{
	return sio_V_HttpClientRequestHeaderIfNotMatchResult;
}

sio_C_HttpClientRequestHeaderIfRange::sio_C_HttpClientRequestHeaderIfRange(const char* sio_V_HttpClientRequestHeaderIfRangeEntityTag, sio_E_HttpClientRequestHeaderIfRange* sio_PE_HttpClientRequestHeaderIfRange, sio_E_HttpClientRequestHeaderIfRangeDateType* sio_PE_HttpClientRequestHeaderIfRangeDateType)
{
	sio_SS_HttpClientRequestHeaderIfRange << "If-Modified-Since: ";
	if (*sio_PE_HttpClientRequestHeaderIfRange == sio_E_HttpClientRequestHeaderIfRange::DATE) {
		now = time(0);
		if (*sio_PE_HttpClientRequestHeaderIfRangeDateType == sio_E_HttpClientRequestHeaderIfRangeDateType::RFC822) {
			char TIME_BUFF[64];
			tm* t_m_f = gmtime(&now);
			strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
			sio_SS_HttpClientRequestHeaderIfRange << TIME_BUFF;
		}
		else if (*sio_PE_HttpClientRequestHeaderIfRangeDateType == sio_E_HttpClientRequestHeaderIfRangeDateType::RFC850) {
			char TIME_BUFF[64];
			tm* t_m_f = gmtime(&now);
			strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
			sio_SS_HttpClientRequestHeaderIfRange << TIME_BUFF;
		}
		else if (*sio_PE_HttpClientRequestHeaderIfRangeDateType == sio_E_HttpClientRequestHeaderIfRangeDateType::ANSI) {
			char TIME_BUFF[64];
			tm* t_m_f = gmtime(&now);
			strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
			sio_SS_HttpClientRequestHeaderIfRange << TIME_BUFF;
		}
		else {
			assert("No Date Time Format specified");
		}
		delete sio_PE_HttpClientRequestHeaderIfRangeDateType;
	}
	else if (*sio_PE_HttpClientRequestHeaderIfRange == sio_E_HttpClientRequestHeaderIfRange::ENTITY_TAG) {
		sio_SS_HttpClientRequestHeaderIfRange << sio_V_HttpClientRequestHeaderIfRangeEntityTag;
	}
	delete sio_PE_HttpClientRequestHeaderIfRange;
	sio_V_HttpClientRequestHeaderIfRangeResult = sio_SS_HttpClientRequestHeaderIfRange.str();
}

std::string sio_C_HttpClientRequestHeaderIfRange::sio_FN_GetHttpClientRequestHeaderIfRange()
{
	return sio_V_HttpClientRequestHeaderIfRangeResult;
}

sio_C_HttpClientRequestHeaderIfUnmodifiedSince::sio_C_HttpClientRequestHeaderIfUnmodifiedSince(sio_E_HttpClientRequestHeaderIfUnmodifiedSince* sio_PE_HttpClientRequestHeaderIfUnmodifiedSince)
{
	sio_SS_HttpClientRequestHeaderIfUnmodifiedSince << "If-Unmodified-Since: ";
	now = time(0);
	if (*sio_PE_HttpClientRequestHeaderIfUnmodifiedSince == sio_E_HttpClientRequestHeaderIfUnmodifiedSince::RFC822) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpClientRequestHeaderIfUnmodifiedSince << TIME_BUFF;
	}
	else if (*sio_PE_HttpClientRequestHeaderIfUnmodifiedSince == sio_E_HttpClientRequestHeaderIfUnmodifiedSince::RFC850) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpClientRequestHeaderIfUnmodifiedSince << TIME_BUFF;
	}
	else if (*sio_PE_HttpClientRequestHeaderIfUnmodifiedSince == sio_E_HttpClientRequestHeaderIfUnmodifiedSince::ANSI) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
		sio_SS_HttpClientRequestHeaderIfUnmodifiedSince << TIME_BUFF;
	}
	else {
		assert("No Date Time Format specified");
	}
	delete sio_PE_HttpClientRequestHeaderIfUnmodifiedSince;
	sio_V_HttpClientRequestHeaderIfUnmodifiedSinceResult = sio_SS_HttpClientRequestHeaderIfUnmodifiedSince.str();
}

std::string sio_C_HttpClientRequestHeaderIfUnmodifiedSince::sio_FN_GetHttpClientRequestHeaderIfUnmodifiedSince()
{
	return sio_V_HttpClientRequestHeaderIfUnmodifiedSinceResult;
}

sio_C_HttpClientRequestHeaderMaxForwards::sio_C_HttpClientRequestHeaderMaxForwards(uint16_t sio_V_HttpClientRequestHeaderMaxForwardsNumber, sio_E_HttpClientRequestHeaderMaxForwards* sio_PE_HttpClientRequestHeaderMaxForwards)
{
	sio_SS_HttpClientRequestHeaderMaxForwards << "Max-Forwards: " << sio_V_HttpClientRequestHeaderMaxForwardsNumber;
	sio_V_HttpClientRequestHeaderMaxForwardsResult = sio_SS_HttpClientRequestHeaderMaxForwards.str();
	delete sio_PE_HttpClientRequestHeaderMaxForwards;
}

std::string sio_C_HttpClientRequestHeaderMaxForwards::sio_FN_GetHttpClientRequestHeaderMaxForwards()
{
	return sio_V_HttpClientRequestHeaderMaxForwardsResult;
}

sio_C_HttpClientRequestHeaderProxyAuthorization::sio_C_HttpClientRequestHeaderProxyAuthorization(const char* sio_V_HttpClientRequestHeaderProxyAuthorization, sio_E_HttpClientRequestHeaderProxyAuthorization* sio_PE_HttpClientRequestHeaderProxyAuthorization)
{
	sio_SS_HttpClientRequestHeaderProxyAuthorization << "Proxy-Authorization: " << sio_V_HttpClientRequestHeaderProxyAuthorization;
	delete sio_PE_HttpClientRequestHeaderProxyAuthorization;
	sio_V_HttpClientRequestHeaderProxyAuthorizationResult = sio_SS_HttpClientRequestHeaderProxyAuthorization.str();
}

std::string sio_C_HttpClientRequestHeaderProxyAuthorization::sio_FN_GetHttpClientRequestHeaderProxyAuthorization()
{
	return sio_V_HttpClientRequestHeaderProxyAuthorizationResult;
}

sio_C_HttpClientRequestHeaderRange::sio_C_HttpClientRequestHeaderRange(uint32_t sio_V_HttpClientRequestHeaderRangeFirstBytePos, uint32_t sio_V_HttpClientRequestHeaderRangeLastBytePos, sio_E_HttpClientRequestHeaderRange* sio_PE_HttpClientRequestHeaderRange)
{
	sio_SS_HttpClientRequestHeaderRange << "Range: bytes=" << sio_V_HttpClientRequestHeaderRangeFirstBytePos << "-" << sio_V_HttpClientRequestHeaderRangeLastBytePos;
	delete sio_PE_HttpClientRequestHeaderRange;
	sio_V_HttpClientRequestHeaderRangeResult = sio_SS_HttpClientRequestHeaderRange.str();
}

std::string sio_C_HttpClientRequestHeaderRange::sio_FN_GetHttpClientRequestHeaderRange()
{
	return sio_V_HttpClientRequestHeaderRangeResult;
}

sio_C_HttpClientRequestHeaderRefere::sio_C_HttpClientRequestHeaderRefere(const char* sio_V_HttpClientRequestHeaderRefereUrl, sio_E_HttpClientRequestHeaderRefere* sio_PE_HttpClientRequestHeaderRefere)
{
	sio_SS_HttpClientRequestHeaderRefere << "Referer : " << sio_V_HttpClientRequestHeaderRefereUrl;
	delete sio_PE_HttpClientRequestHeaderRefere;
	sio_V_HttpClientRequestHeaderRefereResult = sio_SS_HttpClientRequestHeaderRefere.str();
}

std::string sio_C_HttpClientRequestHeaderRefere::sio_FN_GetHttpClientRequestHeaderRefere()
{
	return sio_V_HttpClientRequestHeaderRefereResult;
}

sio_C_HttpClientRequestHeaderTe::sio_C_HttpClientRequestHeaderTe(float sio_V_HttpClientRequestHeaderTeQvalue, const char* sio_V_HttpClientRequestHeaderTeCoding, sio_E_HttpClientRequestHeaderTe* sio_PE_HttpClientRequestHeaderTe)
{
	sio_SS_HttpClientRequestHeaderTe << "TE: ";
	if (*sio_PE_HttpClientRequestHeaderTe == sio_E_HttpClientRequestHeaderTe::DEFLATE) {
		sio_SS_HttpClientRequestHeaderTe << "deflate";
		if (sio_V_HttpClientRequestHeaderTeQvalue != 0) {
			sio_SS_HttpClientRequestHeaderTe << "; q=" << sio_V_HttpClientRequestHeaderTeQvalue;
		}
	}
	else if (*sio_PE_HttpClientRequestHeaderTe == sio_E_HttpClientRequestHeaderTe::TRAILERS) {
		sio_SS_HttpClientRequestHeaderTe << "trailers";
		if (sio_V_HttpClientRequestHeaderTeQvalue != 0) {
			sio_SS_HttpClientRequestHeaderTe << "; q=" << sio_V_HttpClientRequestHeaderTeQvalue;
		}
	}
	else {
		assert("No Te value are specified.");
	}
	delete sio_PE_HttpClientRequestHeaderTe;
	sio_V_HttpClientRequestHeaderTeResult = sio_SS_HttpClientRequestHeaderTe.str();
}

std::string sio_C_HttpClientRequestHeaderTe::sio_FN_GetHttpClientRequestHeaderTe()
{
	return sio_V_HttpClientRequestHeaderTeResult;
}

sio_C_HttpClientRequestHeaderUserAgent::sio_C_HttpClientRequestHeaderUserAgent(const char* sio_V_HttpClientRequestHeaderUserAgentProduct, const char* sio_V_HttpClientRequestHeaderUserAgentComment, sio_E_HttpClientRequestHeaderUserAgent* sio_PE_HttpClientRequestHeaderUserAgent)
{
	sio_SS_HttpClientRequestHeaderUserAgent << "User-Agent: ";
	if (sio_V_HttpClientRequestHeaderUserAgentComment != 0) {
		sio_SS_HttpClientRequestHeaderUserAgent << sio_V_HttpClientRequestHeaderUserAgentProduct << "|" << sio_V_HttpClientRequestHeaderUserAgentComment;
	}
	else if(sio_V_HttpClientRequestHeaderUserAgentComment == 0){
		sio_SS_HttpClientRequestHeaderUserAgent << sio_V_HttpClientRequestHeaderUserAgentProduct;
	}
	else { assert("No User Agent value aren't specified."); }
	delete sio_PE_HttpClientRequestHeaderUserAgent;
	sio_V_HttpClientRequestHeaderUserAgentResult = sio_SS_HttpClientRequestHeaderUserAgent.str();
}

std::string sio_C_HttpClientRequestHeaderUserAgent::sio_FN_GetHttpClientRequestHeaderUserAgent()
{
	return sio_V_HttpClientRequestHeaderUserAgentResult;
}

sio_C_HttpServerResponseHeaderAcceptRanges::sio_C_HttpServerResponseHeaderAcceptRanges(sio_E_HttpServerResponseHeaderAcceptRanges* sio_PE_HttpServerResponseHeaderAcceptRanges)
{
	sio_SS_HttpServerResponseHeaderAcceptRanges << "Accept-Ranges: ";
	if (*sio_PE_HttpServerResponseHeaderAcceptRanges == sio_E_HttpServerResponseHeaderAcceptRanges::BYTE) {
		sio_SS_HttpServerResponseHeaderAcceptRanges << "bytes";
	}
	else if (*sio_PE_HttpServerResponseHeaderAcceptRanges == sio_E_HttpServerResponseHeaderAcceptRanges::NONE) {
		sio_SS_HttpServerResponseHeaderAcceptRanges << "none";
	}
	delete sio_PE_HttpServerResponseHeaderAcceptRanges;
	sio_V_HttpServerResponseHeaderAcceptRangesResult = sio_SS_HttpServerResponseHeaderAcceptRanges.str();
}

std::string sio_C_HttpServerResponseHeaderAcceptRanges::sio_FN_GetHttpServerResponseHeaderAcceptRanges()
{
	return sio_V_HttpServerResponseHeaderAcceptRangesResult;
}

sio_C_HttpServerResponseHeaderAge::sio_C_HttpServerResponseHeaderAge(uint32_t sio_V_HttpServerResponseHeaderAgeDeltaSeconds, sio_E_HttpServerResponseHeaderAge* sio_PE_HttpServerResponseHeaderAge)
{
	sio_SS_HttpServerResponseHeaderAge << "Age: " << sio_V_HttpServerResponseHeaderAgeDeltaSeconds;
	delete sio_PE_HttpServerResponseHeaderAge;
	sio_V_HttpServerResponseHeaderAgeResult = sio_SS_HttpServerResponseHeaderAge.str();
}

std::string sio_C_HttpServerResponseHeaderAge::sio_FN_GetHttpServerResponseHeaderAge()
{
	return sio_V_HttpServerResponseHeaderAgeResult;
}

sio_C_HttpServerResponseHeaderEtag::sio_C_HttpServerResponseHeaderEtag(const char* sio_V_HttpServerResponseHeaderEtagEntityTag, sio_E_HttpServerResponseHeaderEtag* sio_PE_HttpServerResponseHeaderEtag)
{
	sio_SS_HttpServerResponseHeaderEtag << "ETag: " << sio_V_HttpServerResponseHeaderEtagEntityTag;
	delete sio_PE_HttpServerResponseHeaderEtag;
	sio_V_HttpServerResponseHeaderEtagResult = sio_SS_HttpServerResponseHeaderEtag.str();
}

std::string sio_C_HttpServerResponseHeaderEtag::sio_FN_GetHttpServerResponseHeaderEtag()
{
	return sio_V_HttpServerResponseHeaderEtagResult;
}

sio_C_HttpServerResponseHeaderLocation::sio_C_HttpServerResponseHeaderLocation(const char* sio_V_HttpServerResponseHeaderLocationAbsoluteURL, sio_E_HttpServerResponseHeaderLocation* sio_PE_HttpServerResponseHeaderLocation)
{
	sio_SS_HttpServerResponseHeaderLocation << "Location: " << sio_V_HttpServerResponseHeaderLocationAbsoluteURL;
	delete sio_PE_HttpServerResponseHeaderLocation;
	sio_V_HttpServerResponseHeaderLocationResult = sio_SS_HttpServerResponseHeaderLocation.str();
}

std::string sio_C_HttpServerResponseHeaderLocation::sio_FN_GetHttpServerResponseHeaderLocation()
{
	return sio_V_HttpServerResponseHeaderLocationResult;
}

sio_C_HttpServerResponseHeaderProxyAuthorization::sio_C_HttpServerResponseHeaderProxyAuthorization(const char* sio_V_HttpServerResponseHeaderProxyAuthorizationChallenge, sio_E_HttpServerResponseHeaderProxyAuthorization* sio_PE_HttpServerResponseHeaderProxyAuthorization)
{
	sio_SS_HttpServerResponseHeaderProxyAuthorization << "Location: " << sio_V_HttpServerResponseHeaderProxyAuthorizationChallenge;
	delete sio_PE_HttpServerResponseHeaderProxyAuthorization;
	sio_V_HttpServerResponseHeaderProxyAuthorizationResult = sio_SS_HttpServerResponseHeaderProxyAuthorization.str();
}

std::string sio_C_HttpServerResponseHeaderProxyAuthorization::sio_FN_GetHttpServerResponseHeaderProxyAuthorization()
{
	return sio_V_HttpServerResponseHeaderProxyAuthorizationResult;
}

sio_C_HttpServerResponseHeaderRetryAfter::sio_C_HttpServerResponseHeaderRetryAfter(uint32_t sio_V_HttpServerResponseHeaderRetryAfterDeltaSeconds, sio_E_HttpServerResponseHeaderRetryAfter* sio_PE_HttpServerResponseHeaderRetryAfter, sio_E_HttpServerResponseHeaderRetryAfterHttpDate* sio_PE_HttpServerResponseHeaderRetryAfterHttpDate)
{
	sio_SS_HttpServerResponseHeaderRetryAfter << "Retry-After: ";
	if (*sio_PE_HttpServerResponseHeaderRetryAfter == sio_E_HttpServerResponseHeaderRetryAfter::HTTP_DATE) {
		now = time(0);
		if (*sio_PE_HttpServerResponseHeaderRetryAfterHttpDate == sio_E_HttpServerResponseHeaderRetryAfterHttpDate::RFC822) {
			char TIME_BUFF[64];
			tm* t_m_f = gmtime(&now);
			strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
			sio_SS_HttpServerResponseHeaderRetryAfter << TIME_BUFF;
		}
		else if (*sio_PE_HttpServerResponseHeaderRetryAfterHttpDate == sio_E_HttpServerResponseHeaderRetryAfterHttpDate::RFC850) {
			char TIME_BUFF[64];
			tm* t_m_f = gmtime(&now);
			strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
			sio_SS_HttpServerResponseHeaderRetryAfter << TIME_BUFF;
		}
		else if (*sio_PE_HttpServerResponseHeaderRetryAfterHttpDate == sio_E_HttpServerResponseHeaderRetryAfterHttpDate::ANSI) {
			char TIME_BUFF[64];
			tm* t_m_f = gmtime(&now);
			strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
			sio_SS_HttpServerResponseHeaderRetryAfter << TIME_BUFF;
		}
		else {
			assert("No Date Time Format specified");
		}
		delete sio_PE_HttpServerResponseHeaderRetryAfterHttpDate;
	}
	if (*sio_PE_HttpServerResponseHeaderRetryAfter == sio_E_HttpServerResponseHeaderRetryAfter::DELTA_SECONDS) {
		sio_SS_HttpServerResponseHeaderRetryAfter << sio_V_HttpServerResponseHeaderRetryAfterDeltaSeconds;
	}
	delete sio_PE_HttpServerResponseHeaderRetryAfter;
	sio_V_HttpServerResponseHeaderRetryAfterResult = sio_SS_HttpServerResponseHeaderRetryAfter.str();
}

std::string sio_C_HttpServerResponseHeaderRetryAfter::sio_FN_GetHttpServerResponseHeaderRetryAfter()
{
	return sio_V_HttpServerResponseHeaderRetryAfterResult;
}

sio_C_HttpServerResponseHeaderServer::sio_C_HttpServerResponseHeaderServer(const char* sio_V_HttpServerResponseHeaderServerProduct, const char* sio_V_HttpServerResponseHeaderServerComment, sio_E_HttpServerResponseHeaderServer* sio_PE_HttpServerResponseHeaderServer)
{
	sio_SS_HttpServerResponseHeaderServer << "Server: ";
	if (sio_V_HttpServerResponseHeaderServerComment != 0) {
		sio_SS_HttpServerResponseHeaderServer << sio_V_HttpServerResponseHeaderServerProduct << "|" << sio_V_HttpServerResponseHeaderServerComment;
	}
	else if (sio_V_HttpServerResponseHeaderServerComment == 0) {
		sio_SS_HttpServerResponseHeaderServer << sio_V_HttpServerResponseHeaderServerProduct;
	}
	else {
		assert("No Server specified");
	}
	delete sio_PE_HttpServerResponseHeaderServer;
	sio_V_HttpServerResponseHeaderServerResult = sio_SS_HttpServerResponseHeaderServer.str();
}

std::string sio_C_HttpServerResponseHeaderServer::sio_FN_GetHttpServerResponseHeaderServer()
{
	return sio_V_HttpServerResponseHeaderServerResult;
}

sio_C_HttpServerResponseHeaderSetCookie::sio_C_HttpServerResponseHeaderSetCookie(const char* sio_V_HttpServerResponseHeaderSetCookieName, const char* sio_V_HttpServerResponseHeaderSetCookieValue, bool sio_V_HttpServerResponseHeaderSetCookieOptionsExits, const char* sio_V_HttpServerResponseHeaderSetCookieOptionsName, const char* sio_V_HttpServerResponseHeaderSetCookieOptionsvalue, sio_E_HttpServerResponseHeaderSetCookie* sio_PE_HttpServerResponseHeaderSetCookie, sio_E_HttpServerResponseHeaderSetCookieOptions* sio_pE_HttpServerResponseHeaderSetCookieOptions)
{
	sio_SS_HttpServerResponseHeaderSetCookie << "Set-Cookie: " ;
	if (sio_V_HttpServerResponseHeaderSetCookieOptionsExits == true) {
		if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::COMMENT) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Comment= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::COOKIE_DOMAIN) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Domain= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::EXPIRES) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Expires= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::PATH) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Path= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::SECURE) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Secure= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else {
			assert("No Set-Cookies specified.");
		}
		delete sio_pE_HttpServerResponseHeaderSetCookieOptions;
	}
	else if (sio_V_HttpServerResponseHeaderSetCookieOptionsExits == false) {
		sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue;
	}
	else {
		assert("No Comment for SetCookie specified");
	}
	delete sio_PE_HttpServerResponseHeaderSetCookie;
	sio_V_HttpServerResponseHeaderSetCookieResult = sio_SS_HttpServerResponseHeaderSetCookie.str();
}

sio_C_HttpServerResponseHeaderSetCookie& sio_C_HttpServerResponseHeaderSetCookie::Add(const char* sio_V_HttpServerResponseHeaderSetCookieName, const char* sio_V_HttpServerResponseHeaderSetCookieValue, bool sio_V_HttpServerResponseHeaderSetCookieOptionsExits, const char* sio_V_HttpServerResponseHeaderSetCookieOptionsName, const char* sio_V_HttpServerResponseHeaderSetCookieOptionsvalue, sio_E_HttpServerResponseHeaderSetCookie* sio_PE_HttpServerResponseHeaderSetCookie, sio_E_HttpServerResponseHeaderSetCookieOptions* sio_pE_HttpServerResponseHeaderSetCookieOptions)
{
	sio_SS_HttpServerResponseHeaderSetCookie << ", " ;
	if (sio_V_HttpServerResponseHeaderSetCookieOptionsExits == true) {
		if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::COMMENT) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Comment= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::COOKIE_DOMAIN) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Domain= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::EXPIRES) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Expires= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::PATH) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Path= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else if (*sio_pE_HttpServerResponseHeaderSetCookieOptions == sio_E_HttpServerResponseHeaderSetCookieOptions::SECURE) {
			sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue << "; " << "Secure= " << sio_V_HttpServerResponseHeaderSetCookieOptionsvalue;
		}
		else {
			assert("No Set-Cookies specified.");
		}
		delete sio_pE_HttpServerResponseHeaderSetCookieOptions;
	}
	else if (sio_V_HttpServerResponseHeaderSetCookieOptionsExits == false) {
		sio_SS_HttpServerResponseHeaderSetCookie << sio_V_HttpServerResponseHeaderSetCookieName << "=" << sio_V_HttpServerResponseHeaderSetCookieValue;
	}
	else {
		assert("No Comment for SetCookie specified");
	}
	delete sio_PE_HttpServerResponseHeaderSetCookie;
	sio_V_HttpServerResponseHeaderSetCookieResult.append(sio_SS_HttpServerResponseHeaderSetCookie.str());
	return *this;
}

std::string sio_C_HttpServerResponseHeaderSetCookie::sio_FN_GetHttpServerResponseHeaderSetCookie()
{
	return sio_V_HttpServerResponseHeaderSetCookieResult;
}

sio_C_HttpServerResponseHeaderVary::sio_C_HttpServerResponseHeaderVary(const char* sio_V_HttpServerResponseHeaderVaryFieldName, sio_E_HttpServerResponseHeaderVary* sio_PE_HttpServerResponseHeaderVary)
{
	sio_SS_HttpServerResponseHeaderVary << "Vary: " << sio_V_HttpServerResponseHeaderVaryFieldName;
}

sio_C_HttpServerResponseHeaderVary& sio_C_HttpServerResponseHeaderVary::Add(const char* sio_V_HttpServerResponseHeaderVaryFieldName, sio_E_HttpServerResponseHeaderVary* sio_PE_HttpServerResponseHeaderVary)
{
	sio_SS_HttpServerResponseHeaderVary << ", " << sio_V_HttpServerResponseHeaderVaryFieldName;
	delete sio_PE_HttpServerResponseHeaderVary;
	sio_V_HttpServerResponseHeaderVaryResult.append(sio_SS_HttpServerResponseHeaderVary.str());
	return *this;
}

std::string sio_C_HttpServerResponseHeaderVary::sio_FN_GetHttpServerResponseHeaderVary()
{
	return sio_V_HttpServerResponseHeaderVaryResult;
}

sio_C_HttpServerResponseHeaderWwwAuthentication::sio_C_HttpServerResponseHeaderWwwAuthentication(const char* sio_V_HttpServerResponseHeaderWwwAuthenticationChallenge, sio_E_HttpServerResponseHeaderWwwAuthentication* sio_PE_HttpServerResponseHeaderWwwAuthentication)
{
	sio_SS_HttpServerResponseHeaderWwwAuthentication << "WWW-Authenticate: ";
	if (*sio_PE_HttpServerResponseHeaderWwwAuthentication == sio_E_HttpServerResponseHeaderWwwAuthentication::NONE) {
		sio_SS_HttpServerResponseHeaderWwwAuthentication << sio_V_HttpServerResponseHeaderWwwAuthenticationChallenge;
	}
	else if (*sio_PE_HttpServerResponseHeaderWwwAuthentication == sio_E_HttpServerResponseHeaderWwwAuthentication::BASIC) {
		sio_SS_HttpServerResponseHeaderWwwAuthentication << "BASIC" << sio_V_HttpServerResponseHeaderWwwAuthenticationChallenge;
	}
	else {
		assert("No WwwAuthentications is specified. ");
	}
	delete sio_PE_HttpServerResponseHeaderWwwAuthentication;
	sio_V_HttpServerResponseHeaderWwwAuthenticationResult = sio_SS_HttpServerResponseHeaderWwwAuthentication.str();
}

sio_C_HttpServerResponseHeaderWwwAuthentication& sio_C_HttpServerResponseHeaderWwwAuthentication::Add(const char* sio_V_HttpServerResponseHeaderWwwAuthenticationChallenge, sio_E_HttpServerResponseHeaderWwwAuthentication* sio_PE_HttpServerResponseHeaderWwwAuthentication)
{
	sio_SS_HttpServerResponseHeaderWwwAuthentication << ", ";
	if (*sio_PE_HttpServerResponseHeaderWwwAuthentication == sio_E_HttpServerResponseHeaderWwwAuthentication::NONE) {
		sio_SS_HttpServerResponseHeaderWwwAuthentication << sio_V_HttpServerResponseHeaderWwwAuthenticationChallenge;
	}
	else if (*sio_PE_HttpServerResponseHeaderWwwAuthentication == sio_E_HttpServerResponseHeaderWwwAuthentication::BASIC) {
		sio_SS_HttpServerResponseHeaderWwwAuthentication << "BASIC" << sio_V_HttpServerResponseHeaderWwwAuthenticationChallenge;
	}
	else {
		assert("No WwwAuthentications is specified. ");
	}
	delete sio_PE_HttpServerResponseHeaderWwwAuthentication;
	sio_V_HttpServerResponseHeaderWwwAuthenticationResult.append(sio_SS_HttpServerResponseHeaderWwwAuthentication.str());
	return *this;
}

std::string sio_C_HttpServerResponseHeaderWwwAuthentication::sio_FN_GetHttpServerResponseHeaderWwwAuthentication()
{
	return sio_V_HttpServerResponseHeaderWwwAuthenticationResult;
}

sio_C_HttpEntityHeaderAllow::sio_C_HttpEntityHeaderAllow(sio_E_HttpEntityHeaderAllow* sio_PE_HttpEntityHeaderAllow)
{
	sio_SS_HttpEntityHeaderAllow << "Allow: ";
	if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::GET) {
		sio_SS_HttpEntityHeaderAllow << "GET";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::HEAD) {
		sio_SS_HttpEntityHeaderAllow << "HEAD";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::POST) {
		sio_SS_HttpEntityHeaderAllow << "POST";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::PUT) {
		sio_SS_HttpEntityHeaderAllow << "PUT";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::DELETE) {
		sio_SS_HttpEntityHeaderAllow << "DELETE";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::CONNECT) {
		sio_SS_HttpEntityHeaderAllow << "CONNECT";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::OPTIONS) {
		sio_SS_HttpEntityHeaderAllow << "OPTIONS";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::TRACE) {
		sio_SS_HttpEntityHeaderAllow << "TRACE";
	}
	else {
		assert("No Allow is specified.");
	}
	delete sio_PE_HttpEntityHeaderAllow;
	sio_V_HttpEntityHeaderAllowResult = sio_SS_HttpEntityHeaderAllow.str();
}

sio_C_HttpEntityHeaderAllow& sio_C_HttpEntityHeaderAllow::Add(sio_E_HttpEntityHeaderAllow* sio_PE_HttpEntityHeaderAllow)
{
	sio_SS_HttpEntityHeaderAllow << ", ";
	if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::GET) {
		sio_SS_HttpEntityHeaderAllow << "GET";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::HEAD) {
		sio_SS_HttpEntityHeaderAllow << "HEAD";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::POST) {
		sio_SS_HttpEntityHeaderAllow << "POST";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::PUT) {
		sio_SS_HttpEntityHeaderAllow << "PUT";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::DELETE) {
		sio_SS_HttpEntityHeaderAllow << "DELETE";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::CONNECT) {
		sio_SS_HttpEntityHeaderAllow << "CONNECT";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::OPTIONS) {
		sio_SS_HttpEntityHeaderAllow << "OPTIONS";
	}
	else if (*sio_PE_HttpEntityHeaderAllow == sio_E_HttpEntityHeaderAllow::TRACE) {
		sio_SS_HttpEntityHeaderAllow << "TRACE";
	}
	else {
		assert("No Allow is specified.");
	}
	delete sio_PE_HttpEntityHeaderAllow;
	sio_V_HttpEntityHeaderAllowResult.append(sio_SS_HttpEntityHeaderAllow.str());
	return *this;
}

std::string sio_C_HttpEntityHeaderAllow::sio_FN_GetHttpEntityHeaderAllow()
{
	return sio_V_HttpEntityHeaderAllowResult;
}

sio_C_HttpEntityHeaderContentEncoding::sio_C_HttpEntityHeaderContentEncoding(sio_E_HttpEntityHeaderContentEncoding* sio_PE_HttpEntityHeaderContentEncoding)
{
	sio_SS_HttpEntityHeaderContentEncoding << "Content-Encoding: ";
	if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::COMPRESS) {
		sio_SS_HttpEntityHeaderContentEncoding << "compress";
	}
	else if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::GZIP) {
		sio_SS_HttpEntityHeaderContentEncoding << "gzip";
	}
	else if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::IDENTITY) {
		sio_SS_HttpEntityHeaderContentEncoding << "identity";
	}
	else if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::ALL) {
		sio_SS_HttpEntityHeaderContentEncoding << "*";
	}
	else {
		assert("No Content Encoding specifeid.");
	}
	delete sio_PE_HttpEntityHeaderContentEncoding;
	sio_V_HttpEntityHeaderContentEncodingResult = sio_SS_HttpEntityHeaderContentEncoding.str();
}

sio_C_HttpEntityHeaderContentEncoding& sio_C_HttpEntityHeaderContentEncoding::Add(sio_E_HttpEntityHeaderContentEncoding* sio_PE_HttpEntityHeaderContentEncoding)
{
	sio_SS_HttpEntityHeaderContentEncoding << ", ";
	if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::COMPRESS) {
		sio_SS_HttpEntityHeaderContentEncoding << "compress";
	}
	else if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::GZIP) {
		sio_SS_HttpEntityHeaderContentEncoding << "gzip";
	}
	else if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::IDENTITY) {
		sio_SS_HttpEntityHeaderContentEncoding << "identity";
	}
	else if (*sio_PE_HttpEntityHeaderContentEncoding == sio_E_HttpEntityHeaderContentEncoding::ALL) {
		sio_SS_HttpEntityHeaderContentEncoding << "*";
	}
	else {
		assert("No Content Encoding specifeid.");
	}
	delete sio_PE_HttpEntityHeaderContentEncoding;
	sio_V_HttpEntityHeaderContentEncodingResult.append(sio_SS_HttpEntityHeaderContentEncoding.str());
	return *this;
}

std::string sio_C_HttpEntityHeaderContentEncoding::sio_FN_GetHttpEntityHeaderContentEncoding()
{
	return sio_V_HttpEntityHeaderContentEncodingResult;
}

sio_C_HttpEntityHeaderContentLanguage::sio_C_HttpEntityHeaderContentLanguage(sio_E_HttpEntityHeaderContentLanguage* sio_PE_HttpEntityHeaderContentLanguage)
{
	sio_SS_HttpEntityHeaderContentLanguage << "Content-Language: ";
	if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::EN_US) {
		sio_SS_HttpEntityHeaderContentLanguage << "en-us";
	}
	else if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::EN) {
		sio_SS_HttpEntityHeaderContentLanguage << "en";
	}
	else if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::EN_GB) {
		sio_SS_HttpEntityHeaderContentLanguage << "en-gb";
	}
	else if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::DA) {
		sio_SS_HttpEntityHeaderContentLanguage << "da";
	}
	else {
		assert("No Content-Language is specified.");
	}
	delete sio_PE_HttpEntityHeaderContentLanguage;
	sio_V_HttpEntityHeaderContentLanguageResult = sio_SS_HttpEntityHeaderContentLanguage.str();
}

sio_C_HttpEntityHeaderContentLanguage& sio_C_HttpEntityHeaderContentLanguage::Add(sio_E_HttpEntityHeaderContentLanguage* sio_PE_HttpEntityHeaderContentLanguage)
{
	sio_SS_HttpEntityHeaderContentLanguage << ", ";
	if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::EN_US) {
		sio_SS_HttpEntityHeaderContentLanguage << "en-us";
	}
	else if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::EN) {
		sio_SS_HttpEntityHeaderContentLanguage << "en";
	}
	else if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::EN_GB) {
		sio_SS_HttpEntityHeaderContentLanguage << "en-gb";
	}
	else if (*sio_PE_HttpEntityHeaderContentLanguage == sio_E_HttpEntityHeaderContentLanguage::DA) {
		sio_SS_HttpEntityHeaderContentLanguage << "da";
	}
	else {
		assert("No Content-Language is specified.");
	}
	delete sio_PE_HttpEntityHeaderContentLanguage;
	sio_V_HttpEntityHeaderContentLanguageResult.append(sio_SS_HttpEntityHeaderContentLanguage.str());
	return *this;
}

std::string sio_C_HttpEntityHeaderContentLanguage::sio_FN_GetHttpEntityHeaderContentLanguage()
{
	return sio_V_HttpEntityHeaderContentLanguageResult;
}

sio_C_HttpEntityHeaderContentLength::sio_C_HttpEntityHeaderContentLength(uint32_t sio_V_HttpEntityHeaderContentLengthDigit, sio_E_HttpEntityHeaderContentLength* sio_PE_HttpEntityHeaderContentLength)
{
	sio_SS_HttpEntityHeaderContentLength << "Content-Length: " << sio_V_HttpEntityHeaderContentLengthDigit;
	delete sio_PE_HttpEntityHeaderContentLength;
	sio_V_HttpEntityHeaderContentLengthResult = sio_SS_HttpEntityHeaderContentLength.str();
}

std::string sio_C_HttpEntityHeaderContentLength::sio_FN_GetHttpEntityHeaderContentLength()
{
	return sio_V_HttpEntityHeaderContentLengthResult;
}

sio_C_HttpEntityHeaderContentLocation::sio_C_HttpEntityHeaderContentLocation(const char* sio_V_HttpEntityHeaderContentLocationUrl, sio_E_HttpEntityHeaderContentLocation* sio_PE_HttpEntityHeaderContentLocation)
{
	sio_SS_HttpEntityHeaderContentLocation << "Content-Location: ";
	if (*sio_PE_HttpEntityHeaderContentLocation == sio_E_HttpEntityHeaderContentLocation::ABSOLUTE_URI) {
		sio_SS_HttpEntityHeaderContentLocation << sio_V_HttpEntityHeaderContentLocationUrl;
	}
	else if (*sio_PE_HttpEntityHeaderContentLocation == sio_E_HttpEntityHeaderContentLocation::ABSOLUTE_URI) {
		sio_SS_HttpEntityHeaderContentLocation << sio_V_HttpEntityHeaderContentLocationUrl;
	}
	else {
		assert("No Content Location specified.");
	}
	delete sio_PE_HttpEntityHeaderContentLocation;
	sio_V_HttpEntityHeaderContentLocationResult = sio_SS_HttpEntityHeaderContentLocation.str();
}

std::string sio_C_HttpEntityHeaderContentLocation::sio_FN_GetHttpEntityHeaderContentLocation()
{
	return sio_V_HttpEntityHeaderContentLocationResult;
}


sio_C_HttpEntityHeaderContentRange::sio_C_HttpEntityHeaderContentRange(const char* sio_V_HttpEntityHeaderContentRangeFirstBytePos, const char* sio_V_HttpEntityHeaderContentRangeLastBytePos, sio_E_HttpEntityHeaderContentRange* sio_PE_HttpEntityHeaderContentRange)
{
	sio_SS_HttpEntityHeaderContentRange << "Content-Range: " << "bytes " << sio_V_HttpEntityHeaderContentRangeFirstBytePos << "-" << sio_V_HttpEntityHeaderContentRangeLastBytePos;
	sio_V_HttpEntityHeaderContentRangeResult = sio_SS_HttpEntityHeaderContentRange.str();
}

std::string sio_C_HttpEntityHeaderContentRange::sio_FN_GetHttpEntityHeaderContentRange()
{
	return sio_V_HttpEntityHeaderContentRangeResult;
}

sio_C_HttpEntityHeaderContentType::sio_C_HttpEntityHeaderContentType(const char* sio_V_HttpEntityHeaderContentType, const char* sio_V_HttpEntityHeader_ContentSubType, const char* sio_V_HttpEntityHeaderContentTypeOptions, sio_E_HttpEntityHeaderContentType* sio_PE_HttpEntityHeaderContentType)
{
	sio_SS_HttpEntityHeaderContentType << "Content-Type: ";
	if (sio_V_HttpEntityHeaderContentTypeOptions == 0) {
		if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_PLAIN) {
			sio_SS_HttpEntityHeaderContentType << "text/plan";
		}
		else if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_HTML) {
			sio_SS_HttpEntityHeaderContentType << "text/html";
		}
		else if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_XDVI) {
			sio_SS_HttpEntityHeaderContentType << "text/x-dvi";
		}
		else if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_XC) {
			sio_SS_HttpEntityHeaderContentType << "text/x-c";
		}
		else {
			assert("No Content Type providet.");
		}
	}
	else if (sio_V_HttpEntityHeaderContentTypeOptions != 0) {
		if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_PLAIN) {
			sio_SS_HttpEntityHeaderContentType << "text/plan" << "; " << sio_V_HttpEntityHeaderContentTypeOptions;
		}
		else if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_HTML) {
			sio_SS_HttpEntityHeaderContentType << "text/html" << "; " << sio_V_HttpEntityHeaderContentTypeOptions;
		}
		else if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_XDVI) {
			sio_SS_HttpEntityHeaderContentType << "text/x-dvi" << "; " << sio_V_HttpEntityHeaderContentTypeOptions;
		}
		else if (*sio_PE_HttpEntityHeaderContentType == sio_E_HttpEntityHeaderContentType::TEXT_XC) {
			sio_SS_HttpEntityHeaderContentType << "text/x-c" << "; " << sio_V_HttpEntityHeaderContentTypeOptions;
		}
		else {
			assert("No Content Type providet.");
		}
	}
	delete sio_PE_HttpEntityHeaderContentType;
	sio_V_HttpEntityHeaderContentTypeResult = sio_SS_HttpEntityHeaderContentType.str();
}

std::string sio_C_HttpEntityHeaderContentType::sio_FN_GetHttpEntityHeaderContentType()
{
	return sio_V_HttpEntityHeaderContentTypeResult;
}

sio_C_HttpEntityHeaderExpires::sio_C_HttpEntityHeaderExpires(sio_E_HttpEntityHeaderExpires* sio_PE_HttpEntityHeaderExpires)
{
	now = time(0);
	if (*sio_PE_HttpEntityHeaderExpires == sio_E_HttpEntityHeaderExpires::RFC822) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpEntityHeaderExpires << TIME_BUFF;
	}
	else if (*sio_PE_HttpEntityHeaderExpires == sio_E_HttpEntityHeaderExpires::RFC850) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpEntityHeaderExpires << TIME_BUFF;
	}
	else if (*sio_PE_HttpEntityHeaderExpires == sio_E_HttpEntityHeaderExpires::ANSI) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
		sio_SS_HttpEntityHeaderExpires << TIME_BUFF;
	}
	else {
		assert("No Expires specified");
	}
	delete sio_PE_HttpEntityHeaderExpires;
	sio_V_HttpEntityHeaderExpiresResult = sio_SS_HttpEntityHeaderExpires.str();
}

std::string sio_C_HttpEntityHeaderExpires::sio_FN_GetHttpEntityHeaderExpires()
{
	return sio_V_HttpEntityHeaderExpiresResult;
}

sio_C_HttpEntityHeaderLastModified::sio_C_HttpEntityHeaderLastModified(sio_E_HttpEntityHeaderLastModified* sio_PE_HttpEntityHeaderLastModified)
{
	now = time(0);
	if (*sio_PE_HttpEntityHeaderLastModified == sio_E_HttpEntityHeaderLastModified::RFC822) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpEntityHeaderLastModified << TIME_BUFF;
	}
	else if (*sio_PE_HttpEntityHeaderLastModified == sio_E_HttpEntityHeaderLastModified::RFC850) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
		sio_SS_HttpEntityHeaderLastModified << TIME_BUFF;
	}
	else if (*sio_PE_HttpEntityHeaderLastModified == sio_E_HttpEntityHeaderLastModified::ANSI) {
		char TIME_BUFF[64];
		tm* t_m_f = gmtime(&now);
		strftime(TIME_BUFF, sizeof(TIME_BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
		sio_SS_HttpEntityHeaderLastModified << TIME_BUFF;
	}
	else {
		assert("No Last Modified specified");
	}
	delete sio_PE_HttpEntityHeaderLastModified;
	sio_V_HttpEntityHeaderLastModifiedResult = sio_SS_HttpEntityHeaderLastModified.str();
}

std::string sio_C_HttpEntityHeaderLastModified::sio_FN_GetHttpEntityHeaderLastModified()
{
	return sio_V_HttpEntityHeaderLastModifiedResult;
}

} // namespace httpHeaderFields	
} // namespace sio


