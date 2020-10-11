#include "sio_http_status_code.h"

namespace sio
{
	namespace httpStatusCode
	{
		sio::httpStatusCode::sio_C_HttpStatusCodeInformation::sio_C_HttpStatusCodeInformation(sio_E_HttpStatusCodeInformation* sio_PE_HttpStatusCodeInformation)
		{
			if(*sio_PE_HttpStatusCodeInformation == sio_E_HttpStatusCodeInformation::CONTINUE){
				sio_V_HttpStatusCodeInformationResultNum = 100;
				sio_V_HttpStatusCodeInformationResultStr = "100 Continue";
				sio_V_HttpStatusCodeInformationDescription = "Only a part of the request has been received by the server, but as long as it has not been rejected, the client should continue with the request.";
			}
			else if (*sio_PE_HttpStatusCodeInformation == sio_E_HttpStatusCodeInformation::SWITCHING_PROTOCOLS) {
				sio_V_HttpStatusCodeInformationResultNum = 101;
				sio_V_HttpStatusCodeInformationResultStr = "101 Switching Protocols";
				sio_V_HttpStatusCodeInformationDescription = "The server switches protocol.";
			}
			else {
				assert("No http status code information specified.");
			}
		}

		sio_C_HttpStatusCodeSuccessful::sio_C_HttpStatusCodeSuccessful(sio_E_HttpStatusCodeSuccessful* sio_PE_HttpStatusCodeSuccessful)
		{
			if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::OK) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 200;
				sio_V_HttpStatusCodeSuccessfulResultStr = "200 OK";
				sio_V_HttpStatusCodeSuccessfulDescription = "The request is OK.";
			}
			else if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::CREATED) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 201;
				sio_V_HttpStatusCodeSuccessfulResultStr = "201 Created";
				sio_V_HttpStatusCodeSuccessfulDescription = "The request is complete, and a new resource is created .";
			}
			else if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::ACCEPTED) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 202;
				sio_V_HttpStatusCodeSuccessfulResultStr = "202 Accepted";
				sio_V_HttpStatusCodeSuccessfulDescription = "The request is accepted for processing, but the processing is not complete.";
			}
			else if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::NON_AUTHORITATIVE_INFROMATION) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 203;
				sio_V_HttpStatusCodeSuccessfulResultStr = "203 Non-authoritative Information";
				sio_V_HttpStatusCodeSuccessfulDescription = "The information in the entity header is from a local or third-party copy, not from the original server.";
			}
			else if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::NO_CONTENT) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 204;
				sio_V_HttpStatusCodeSuccessfulResultStr = "204 No Content";
				sio_V_HttpStatusCodeSuccessfulDescription = "A status code and a header are given in the response, but there is no entity-body in the reply.";
			}
			else if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::RESET_CONTENT) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 205;
				sio_V_HttpStatusCodeSuccessfulResultStr = "205 Reset Content";
				sio_V_HttpStatusCodeSuccessfulDescription = "The browser should clear the form used for this transaction for additional input.";
			}
			else if (*sio_PE_HttpStatusCodeSuccessful == sio_E_HttpStatusCodeSuccessful::PARTIAL_CONTENT) {
				sio_V_HttpStatusCodeSuccessfulResultNum = 206;
				sio_V_HttpStatusCodeSuccessfulResultStr = "206 Partial Content";
				sio_V_HttpStatusCodeSuccessfulDescription = "The server is returning partial data of the size requested. Used in response to a request specifying a Range header. The server must specify the range included in the response with the Content-Range header.";
			}
			else {
				assert("No http status code information specified.");
			}
		}

		sio_C_HttpStatusCodeRedirection::sio_C_HttpStatusCodeRedirection(sio_E_HttpStatusCodeRedirection* sio_PE_HttpStatusCodeRedirection)
		{
			if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::MULTIPLE_CHOICES) {
				sio_V_HttpStatusCodeRedirectionResultNum = 300;
				sio_V_HttpStatusCodeRedirectionResultStr = "300 Multiple Choices";
				sio_V_HttpStatusCodeRedirectionDescription = "A link list. The user can select a link and go to that location. Maximum five addresses.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::MOVED_PERMANENTLY) {
				sio_V_HttpStatusCodeRedirectionResultNum = 301;
				sio_V_HttpStatusCodeRedirectionResultStr = "301 Moved Permanently";
				sio_V_HttpStatusCodeRedirectionDescription = "The requested page has moved to a new url.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::FOUND) {
				sio_V_HttpStatusCodeRedirectionResultNum = 302;
				sio_V_HttpStatusCodeRedirectionResultStr = "302 Found";
				sio_V_HttpStatusCodeRedirectionDescription = "The requested page has moved temporarily to a new url.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::SEE_OTHER) {
				sio_V_HttpStatusCodeRedirectionResultNum = 303;
				sio_V_HttpStatusCodeRedirectionResultStr = "303 See Other";
				sio_V_HttpStatusCodeRedirectionDescription = "The requested page can be found under a different url.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::NOT_MODIFIED) {
				sio_V_HttpStatusCodeRedirectionResultNum = 304;
				sio_V_HttpStatusCodeRedirectionResultStr = "304 Not Modified";
				sio_V_HttpStatusCodeRedirectionDescription = "This is the response code to an If-Modified-Since or If-None-Match header, where the URL has not been modified since the specified date.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::USE_PROXY) {
				sio_V_HttpStatusCodeRedirectionResultNum = 305;
				sio_V_HttpStatusCodeRedirectionResultStr = "305 Use Proxy";
				sio_V_HttpStatusCodeRedirectionDescription = "The requested URL must be accessed through the proxy mentioned in the Location header.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::UNUSED) {
				sio_V_HttpStatusCodeRedirectionResultNum = 306;
				sio_V_HttpStatusCodeRedirectionResultStr = "306 Unused";
				sio_V_HttpStatusCodeRedirectionDescription = "This code was used in a previous version. It is no longer used, but the code is reserved.";
			}
			else if (*sio_PE_HttpStatusCodeRedirection == sio_E_HttpStatusCodeRedirection::TEMPORARY_REDIRECT) {
				sio_V_HttpStatusCodeRedirectionResultNum = 307;
				sio_V_HttpStatusCodeRedirectionResultStr = "307 Temporary Redirect";
				sio_V_HttpStatusCodeRedirectionDescription = "The requested page has moved temporarily to a new url.";
			}
			else {
				assert("No http status code redirection specified.");
			}
		}

		sio_C_HttpStatusCodeClientError::sio_C_HttpStatusCodeClientError(sio_E_HttpStatusCodeClientError* sio_PE_HttpStatusCodeClientError)
		{
			if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::BAD_REQUEST) {
				sio_V_HttpStatusCodeClientErrorResultNum = 400;
				sio_V_HttpStatusCodeClientErrorResultStr = "400 Bad Request";
				sio_V_HttpStatusCodeClientErrorDescription = "The server did not understand the request.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::UNAUTHORIZED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 401;
				sio_V_HttpStatusCodeClientErrorResultStr = "401 Unauthorized";
				sio_V_HttpStatusCodeClientErrorDescription = "The requested page needs a username and a password.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::PAYMENT_REQUIRED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 402;
				sio_V_HttpStatusCodeClientErrorResultStr = "402 Payment Required";
				sio_V_HttpStatusCodeClientErrorDescription = "You can not use this code yet.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::FORBIDDEN) {
				sio_V_HttpStatusCodeClientErrorResultNum = 403;
				sio_V_HttpStatusCodeClientErrorResultStr = "403 Forbidden";
				sio_V_HttpStatusCodeClientErrorDescription = "Access is forbidden to the requested page.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::NOT_FOUND) {
				sio_V_HttpStatusCodeClientErrorResultNum = 404;
				sio_V_HttpStatusCodeClientErrorResultStr = "404 Not Found";
				sio_V_HttpStatusCodeClientErrorDescription = "The server can not find the requested page.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::METHOD_NOT_ALLOWED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 405;
				sio_V_HttpStatusCodeClientErrorResultStr = "405 Method Not Allowed";
				sio_V_HttpStatusCodeClientErrorDescription = "The method specified in the request is not allowed.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::NOT_ACCEPTABLE) {
				sio_V_HttpStatusCodeClientErrorResultNum = 406;
				sio_V_HttpStatusCodeClientErrorResultStr = "406 Not Acceptable";
				sio_V_HttpStatusCodeClientErrorDescription = "The server can only generate a response that is not accepted by the client.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::PROXY_AUTHENTICATION_REQUIRED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 407;
				sio_V_HttpStatusCodeClientErrorResultStr = "407 Proxy Authentication Required";
				sio_V_HttpStatusCodeClientErrorDescription = "You must authenticate with a proxy server before this request can be served.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::REQUEST_TIMEOUT) {
				sio_V_HttpStatusCodeClientErrorResultNum = 408;
				sio_V_HttpStatusCodeClientErrorResultStr = "408 Request Timeout";
				sio_V_HttpStatusCodeClientErrorDescription = "The request took longer than the server was prepared to wait.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::CONFLICT) {
				sio_V_HttpStatusCodeClientErrorResultNum = 409;
				sio_V_HttpStatusCodeClientErrorResultStr = "409 Conflict";
				sio_V_HttpStatusCodeClientErrorDescription = "The request could not be completed because of a conflict.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::GONE) {
				sio_V_HttpStatusCodeClientErrorResultNum = 410;
				sio_V_HttpStatusCodeClientErrorResultStr = "410 Gone";
				sio_V_HttpStatusCodeClientErrorDescription = "The requested page is no longer available.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::LENGTH_REQUIRED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 411;
				sio_V_HttpStatusCodeClientErrorResultStr = "411 Length Required";
				sio_V_HttpStatusCodeClientErrorDescription = "The Content - Length is not defined. The server will not accept the request without it.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::PRECONDITION_FAILED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 412;
				sio_V_HttpStatusCodeClientErrorResultStr = "412 Precondition Failed";
				sio_V_HttpStatusCodeClientErrorDescription = "The pre condition given in the request evaluated to false by the server.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::REQUEST_ENTITY_TOO_LARGE) {
				sio_V_HttpStatusCodeClientErrorResultNum = 413;
				sio_V_HttpStatusCodeClientErrorResultStr = "413 Request Entity Too Large";
				sio_V_HttpStatusCodeClientErrorDescription = "The server will not accept the request, because the request entity is too large.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::REQUEST_URL_TOO_LONG) {
				sio_V_HttpStatusCodeClientErrorResultNum = 414;
				sio_V_HttpStatusCodeClientErrorResultStr = "414 Request-url Too Long";
				sio_V_HttpStatusCodeClientErrorDescription = "The server will not accept the request, because the url is too long. Occurs when you convert a post request to a get request with a long query information .";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::UNSUPPORTED_MEDIA_TYPE) {
				sio_V_HttpStatusCodeClientErrorResultNum = 415;
				sio_V_HttpStatusCodeClientErrorResultStr = "415 Unsupported Media Type";
				sio_V_HttpStatusCodeClientErrorDescription = "The server will not accept the request, because the mediatype is not supported.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::REQUESTED_RANGE_NOT_SATISFIABLE) {
				sio_V_HttpStatusCodeClientErrorResultNum = 416;
				sio_V_HttpStatusCodeClientErrorResultStr = "416 Requested Range Not Satisfiable";
				sio_V_HttpStatusCodeClientErrorDescription = "The requested byte range is not available and is out of bounds.";
			}
			else if (*sio_PE_HttpStatusCodeClientError == sio_E_HttpStatusCodeClientError::EXPECTATION_FAILED) {
				sio_V_HttpStatusCodeClientErrorResultNum = 417;
				sio_V_HttpStatusCodeClientErrorResultStr = "417 Expectation Failed";
				sio_V_HttpStatusCodeClientErrorDescription = "The expectation given in an Expect request-header field could not be met by this server.";
			}
			else {
				assert("No Client Error specified.");
			}
		}

		sio_C_HttpStatusCodeServerError::sio_C_HttpStatusCodeServerError(sio_E_HttpStatusCodeServerError* sio_PE_HttpStatusCodeServerError)
		{
			if (*sio_PE_HttpStatusCodeServerError == sio_E_HttpStatusCodeServerError::INTERNAL_SERVER_ERROR) {
				sio_V_HttpStatusCodeServerErrorResultNum = 500;
				sio_V_HttpStatusCodeServerErrorResultStr = "500 Internal Server Error";
				sio_V_HttpStatusCodeServerErrorDescription = "The request was not completed. The server met an unexpected condition.";
			}
			else if (*sio_PE_HttpStatusCodeServerError == sio_E_HttpStatusCodeServerError::NOT_IMPLEMENTED) {
				sio_V_HttpStatusCodeServerErrorResultNum = 501;
				sio_V_HttpStatusCodeServerErrorResultStr = "501 Not Implemented";
				sio_V_HttpStatusCodeServerErrorDescription = "The request was not completed. The server did not support the functionality required.";
			}
			else if (*sio_PE_HttpStatusCodeServerError == sio_E_HttpStatusCodeServerError::BAD_GATEWAY) {
				sio_V_HttpStatusCodeServerErrorResultNum = 502;
				sio_V_HttpStatusCodeServerErrorResultStr = "502 Bad Gateway";
				sio_V_HttpStatusCodeServerErrorDescription = "The request was not completed. The server received an invalid response from the upstream server.";
			}
			else if (*sio_PE_HttpStatusCodeServerError == sio_E_HttpStatusCodeServerError::SERVICE_UNAVAILABLE) {
				sio_V_HttpStatusCodeServerErrorResultNum = 503;
				sio_V_HttpStatusCodeServerErrorResultStr = "503 Service Unavailable";
				sio_V_HttpStatusCodeServerErrorDescription = "The request was not completed. The server is temporarily overloading or down.";
			}
			else if (*sio_PE_HttpStatusCodeServerError == sio_E_HttpStatusCodeServerError::GATEWAY_TIMEOUT) {
				sio_V_HttpStatusCodeServerErrorResultNum = 504;
				sio_V_HttpStatusCodeServerErrorResultStr = "504 Gateway Timeout";
				sio_V_HttpStatusCodeServerErrorDescription = "The gateway has timed out.";
			}
			else if (*sio_PE_HttpStatusCodeServerError == sio_E_HttpStatusCodeServerError::HTTP_VERSION_NOT_SUPPORTED) {
				sio_V_HttpStatusCodeServerErrorResultNum = 505;
				sio_V_HttpStatusCodeServerErrorResultStr = "505 HTTP Version Not Supported";
				sio_V_HttpStatusCodeServerErrorDescription = "The server does not support the http protocol version.";
			}
			else {
				assert("No Server Error specified.");
			}
		}


} // namespace httpStatusCode
} // namespace sio
