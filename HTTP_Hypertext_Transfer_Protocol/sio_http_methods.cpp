#include "sio_http_methods.h"

namespace sio {
	namespace httpMethods {
		sio_C_HttpMethods::sio_C_HttpMethods(sio_E_HttpMethods* sio_PE_HttpMethods)
		{
			if (*sio_PE_HttpMethods == sio_E_HttpMethods::GET) {
				sio_V_HttpMethodsResult = "GET";
				sio_V_HttpMethodsDescription = "The GET method is used to retrieve information from the given server using a given URI. Requests using GET should only retrieve data and should have no other effect on the data.";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::HEAD) {
				sio_V_HttpMethodsResult = "HEAD";
				sio_V_HttpMethodsDescription = "Same as GET, but transfers the status line and header section only.";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::POST) {
				sio_V_HttpMethodsResult = "POST";
				sio_V_HttpMethodsDescription = "A POST request is used to send data to the server, for example, customer information, file upload, etc. using HTML forms.";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::PUT) {
				sio_V_HttpMethodsResult = "PUT";
				sio_V_HttpMethodsDescription = "Replaces all current representations of the target resource with the uploaded content.";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::DELETE) {
				sio_V_HttpMethodsResult = "DELETE";
				sio_V_HttpMethodsDescription = "Removes all current representations of the target resource given by a URI.";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::CONNECT) {
				sio_V_HttpMethodsResult = "CONNECT";
				sio_V_HttpMethodsDescription = "Establishes a tunnel to the server identified by a given URI";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::OPTIONS) {
				sio_V_HttpMethodsResult = "OPTIONS";
				sio_V_HttpMethodsDescription = "Describes the communication options for the target resource.";
			}
			else if (*sio_PE_HttpMethods == sio_E_HttpMethods::TRACE) {
				sio_V_HttpMethodsResult = "TRACE";
				sio_V_HttpMethodsDescription = "Performs a message loop-back test along the path to the target resource.";
			}
			else {
				assert("No http Method specified.");
			}
			delete sio_PE_HttpMethods;
		}

		std::string sio_C_HttpMethods::sio_FN_GetHttpMethods()
		{
			return sio_V_HttpMethodsResult;
		}


	} //namespace httpMethods
} //namespace sio