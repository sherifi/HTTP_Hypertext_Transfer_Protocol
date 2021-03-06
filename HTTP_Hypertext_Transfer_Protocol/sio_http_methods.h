/*
**copyright (C) 2020 "SHERIFI" Shkelqim Sherifi <sherifi_co@yahoo.com>.
**Boost Software License - Version 1.0 - December 21th, 2019
**
** Licensed under the SHERIFI Inc Private License, Version 1.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.sherifiIO.org/licenses/LICENSE-1.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
**The copyright notices in the Software and this entire statement, including
**the above license grant, this restriction and the following disclaimer,
**must be included in all copies of the Software, in whole or in part, and
**all derivative works of the Software, unless such copies or derivative
**works are solely in the form of machine-executable object code generated by
**a source language processor.
**
**THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
**IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**FITNESS FOR PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
**AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
**LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
**SOFTWARE.
**
** This header is generated from the SHERIFI HTTPHypertextTransferProtocol XML API Registry.
**
*/

////////////////////////////////////////////////////////////////////////////////
//        NAME: sio_http_methods.h
// DESCRIPTION: This is the root of HTTPHypertextTransferProtocol parameters
//   ARGUMENTS: N/A
// USES GLOBAL: N/A
// MODIFIES GL: N/A
//     RETURNS: N/A
//      AUTHOR: SHERIFI
// AUTHOR/DATE: GMT Saturday, July 12, 2020
////////////////////////////////////////////////////////////////////////////////
#ifndef SIO_HTTP_METHODS_H_
#define SIO_HTTP_METHODS_H_ 1

#include <string>
#include <sstream>
#include <assert.h>

#include "sio_http.h"

namespace sio {
	namespace httpMethods {

#define sio_MAX_HTTP_METHODS_CHAR								64
#define sio_MAX_HTTP_METHODS_INFO_CHAR							sio_MAX_HTTP_METHODS_CHAR

		////////////////////////////////////////////////////////////////////////////////
		//        NAME: sio_S_HttpControlers
		// DESCRIPTION: This is the structure create to hold all the NAME related .
		//   ARGUMENTS: N/A
		// USES GLOBAL: N/A
		// MODIFIES GL: N/A
		//     RETURNS: N/A
		//      AUTHOR: SHERIFI
		// AUTHOR/DATE: GMT Saturday, July 12, 2020
		////////////////////////////////////////////////////////////////////////////////
		typedef struct sio_S_HttpControlers {
		public:
			void* sio_P_start;
			void* sio_P_privious;
			void* sio_P_current;
			void* sio_P_next;
			void* sio_P_end;
			uint8_t sio_V_count;
			char** sio_PP_list[sio_MAX_HTTP_METHODS_INFO_CHAR];
		}sio_S_HttpControlers;

		////////////////////////////////////////////////////////////////////////////////
		//        NAME: sio_C_HttpMethods
		// DESCRIPTION: This is the structure create to hold all the NAME related .
		//   ARGUMENTS: N/A
		// USES GLOBAL: N/A
		// MODIFIES GL: N/A
		//     RETURNS: N/A
		//      AUTHOR: SHERIFI
		// AUTHOR/DATE: GMT Saturday, July 12, 2020
		////////////////////////////////////////////////////////////////////////////////
		typedef enum sio_E_HttpMethods {
			NONE =							0x00000000,
			GET =							0x00000001,
			HEAD =							0x00000002,
			POST =							0x00000004,
			PUT =							0x00000008,
			DELETE =						0x00000010,
			CONNECT =						0x00000020,
			OPTIONS =						0x00000040,
			TRACE =							0x00000080,
		}sio_E_HttpMethods;

		typedef class sio_C_HttpMethods : sio_S_HttpControlers {
		private:
			const char* sio_V_name;
			std::string sio_V_HttpMethodsDescription;
			std::string sio_V_HttpMethodsResult;
			std::stringstream sio_SS_HttpMethods;
		public:
			sio_C_HttpMethods() = delete;
			sio_C_HttpMethods(sio_E_HttpMethods* sio_PE_HttpMethods);
			std::string sio_FN_GetHttpMethods();
		}sio_C_HttpMethods;

		/*
		typedef void(sio_API_PTR* sio_PFN_WriteInfo)(sio_S_Info* sio_PS_Info);

		sio_API_ATTR void sio_API_CALL sio_FN_WriteInfo(
			sio_S_Info* sio_PS_Info
		);

		typedef sio_Result(sio_API_PTR* sio_PFN_DeleteInfo)(sio_S_Info* sio_PS_Info, sio_S_Company* sio_PS_Company, sio_S_Management* sio_PS_Managemnet);

		sio_API_ATTR sio_Result sio_API_CALL sio_FN_DeleteInfo(
			sio_S_Info* sio_PS_Info,
			sio_S_Company* sio_PS_Company,
			sio_S_Management* sio_PS_Managemnet
		);
		*/
	} //namespace httpMethods
}//namespace sio

#endif // !SIO_HTTP_METHODS_H_
