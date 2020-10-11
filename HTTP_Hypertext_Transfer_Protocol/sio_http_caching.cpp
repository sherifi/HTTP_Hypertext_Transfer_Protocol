#include "sio_http_caching.h"
namespace sio {
	namespace httpCaching {

sio_C_HttpCachingRequestDirective::sio_C_HttpCachingRequestDirective(sio_E_HttpCachingRequestDirective* sio_PE_HttpCachingRequestDirective, uint32_t sec)
{
	sio_SS_HttpCachingRequestDirective << "Cache-control: ";
	if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::NO_CACHE_REQ) {
		sio_SS_HttpCachingRequestDirective << "no-cache";
		sio_V_HttpCachingRequestDirectiveDescription = "A cache must not use the response to satisfy a subsequent request without successful revalidation with the origin server.";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::NO_STORE_REQ) {
		sio_SS_HttpCachingRequestDirective << "no-store";
		sio_V_HttpCachingRequestDirectiveDescription = "The cache should not store anything about the client request or server response.";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::MAX_AGE_REQ) {
		sio_SS_HttpCachingRequestDirective << "max-age=" << sec;
		sio_V_HttpCachingRequestDirectiveDescription = "Indicates that the client is willing to accept a response whose age is not greater than the specified time in seconds.";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::MAX_STALE_REQ) {
		sio_SS_HttpCachingRequestDirective << "max-stale[=" << sec << "]";
		sio_V_HttpCachingRequestDirectiveDescription = "Indicates that the client is willing to accept a response that has exceeded its expiration time. If seconds are given, it must not be expired by more than that time.";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::MIN_FRESH_REQ) {
		sio_SS_HttpCachingRequestDirective << "min-refresh=" << sec;
		sio_V_HttpCachingRequestDirectiveDescription = "Indicates that the client is willing to accept a response whose freshness lifetime is not less than its current age plus the specified time in seconds.";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::NO_TRANSFROM_REQ) {
		sio_SS_HttpCachingRequestDirective << "no-transform";
		sio_V_HttpCachingRequestDirectiveDescription = "Does not convert the entity-body.";
	}
	else if (*sio_PE_HttpCachingRequestDirective == sio_E_HttpCachingRequestDirective::ONLY_IF_CACHED_REQ) {
		sio_SS_HttpCachingRequestDirective << "only-if-cached";
		sio_V_HttpCachingRequestDirectiveDescription = "Does not retrieve new data. The cache can send a document only if it is in the cache, and should not contact the origin-server to see if a newer copy exists.";
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
		sio_V_HttpCachingResponseDirectiveDescription = "Indicates that the response may be cached by any cache.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::PRIVATE_RES) {
		sio_SS_HttpCachingResponseDirective << "private";
		sio_V_HttpCachingResponseDirectiveDescription = "Indicates that all or part of the response message is intended for a single user and must not be cached by a shared cache.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::NO_CACHE_RES) {
		sio_SS_HttpCachingResponseDirective << "no-cache";
		sio_V_HttpCachingResponseDirectiveDescription = "A cache must not use the response to satisfy a subsequent request without successful re-validation with the origin server.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::NO_STORE_RES) {
		sio_SS_HttpCachingResponseDirective << "no-store";
		sio_V_HttpCachingResponseDirectiveDescription = "The cache should not store anything about the client request or server response.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::NO_TRANSFROM_RES) {
		sio_SS_HttpCachingResponseDirective << "no-transform";
		sio_V_HttpCachingResponseDirectiveDescription = "Does not convert the entity-body.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::MUST_REVALIDATE_RES) {
		sio_SS_HttpCachingResponseDirective << "must-revalidate";
		sio_V_HttpCachingResponseDirectiveDescription = "The cache must verify the status of the stale documents before using it and expired ones should not be used.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::PROXY_REVALIDATE_RES) {
		sio_SS_HttpCachingResponseDirective << "proxy-revalidate";
		sio_V_HttpCachingResponseDirectiveDescription = "The proxy-revalidate directive has the same meaning as the must- revalidate directive, except that it does not apply to non-shared user agent caches.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::MAX_AGE_RES) {
		sio_SS_HttpCachingResponseDirective << "max-age=" << sec;
		sio_V_HttpCachingResponseDirectiveDescription = "Indicates that the client is willing to accept a response whose age is not greater than the specified time in seconds.";
	}
	else if (*sio_PE_HttpCachingResponseDirective == sio_E_HttpCachingResponseDirective::S_MAXAGE_RES) {
		sio_SS_HttpCachingResponseDirective << "s-maxage=" << sec;
		sio_V_HttpCachingResponseDirectiveDescription = "The maximum age specified by this directive overrides the maximum age specified by either the max-age directive or the Expires header. The s-maxage directive is always ignored by a private cache.";
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


