#include "sio_http_caching.h"
namespace sio {
	namespace httpCaching {

sio_C_HttpCachingRequestDirective::sio_C_HttpCachingRequestDirective(sio_E_HttpCachingRequestDirective* sio_PE_HttpCachingRequestDirective, uint32_t sec)
{
	sio_SS_HttpCachingRequestDirective << "Cache-control: ";
	if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::NO_CACHE_REQ) {
		sio_SS_HttpCachingRequestDirective << "no-cache";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::NO_STORE_REQ) {
		sio_SS_HttpCachingRequestDirective << "no-store";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::MAX_AGE_REQ) {
		sio_SS_HttpCachingRequestDirective << "max-age=" << sec;
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::MAX_STALE_REQ) {
		sio_SS_HttpCachingRequestDirective << "max-stale[=" << sec << "]";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::MIN_FRESH_REQ) {
		sio_SS_HttpCachingRequestDirective << "min-refresh=" << sec;
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::NO_TRANSFROM_REQ) {
		sio_SS_HttpCachingRequestDirective << "no-transform";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::ONLY_IF_CACHED_REQ) {
		sio_SS_HttpCachingRequestDirective << "only-if-cached";
	}
	else {
		assert("No Request cache directive providet");
	}
	delete sio_PE_HttpCachingRequestDirective;
	sio_V_HttpCachingRequestDirectiveResult = sio_SS_HttpCachingRequestDirective.str();
}

std::string sio_C_HttpCachingRequestDirective::sio_FN_GetHttpCachingRequestDirective()
{
	return sio_V_HttpCachingRequestDirectiveResult;
}

sio_C_HttpCachingResponseDirective::sio_C_HttpCachingResponseDirective(sio_E_HttpCachingResponseDirective* sio_PE_HttpCachingResponseDirective, uint32_t sec)
{
	sio_SS_HttpCachingResponseDirective << "Cache-control: ";
	if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::PUBLIC_RES) {
		sio_SS_HttpCachingResponseDirective << "public";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::PRIVATE_RES) {
		sio_SS_HttpCachingResponseDirective << "private";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::NO_CACHE_RES) {
		sio_SS_HttpCachingResponseDirective << "no-cache";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::NO_STORE_RES) {
		sio_SS_HttpCachingResponseDirective << "no-store";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::NO_TRANSFROM_RES) {
		sio_SS_HttpCachingResponseDirective << "no-transform";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::MUST_REVALIDATE_RES) {
		sio_SS_HttpCachingResponseDirective << "must-revalidate";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::PROXY_REVALIDATE_RES) {
		sio_SS_HttpCachingResponseDirective << "proxy-revalidate";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::MAX_AGE_RES) {
		sio_SS_HttpCachingResponseDirective << "max-age=" << sec;
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::S_MAXAGE_RES) {
		sio_SS_HttpCachingResponseDirective << "s-maxage=" << sec;
	}
	else {
		assert("No Response cache directive providet");
	}
	delete sio_PE_HttpCachingResponseDirective;
	sio_V_HttpCachingResponseDirectiveResult = sio_SS_HttpCachingResponseDirective.str();
}

std::string sio_C_HttpCachingResponseDirective::sio_FN_GetHttpCachingResponseDirective()
{
	return sio_V_HttpCachingResponseDirectiveResult;
}

	} //namespace httpCaching
} //namespace sio


