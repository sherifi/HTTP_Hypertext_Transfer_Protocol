
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

typedef enum sio_E_HttpEncoding {

}sio_E_HttpEncoding;

typedef class sio_C_HttpEncoding {
private:
	std::string sio_V_HttpEncodingRESULT;
	std::stringstream sio_SS_HttpEncoding;
public:
	sio_C_HttpEncoding() = delete;
	sio_C_HttpEncoding(const char* sio_V_HttpEncodingString, sio_E_HttpEncoding* sio_PE_HttpEncoding);
	std::string sio_C_GetHttpEncoding();
}sio_C_HttpEncoding;

sio_C_HttpEncoding::sio_C_HttpEncoding(const char* sio_V_HttpEncodingString, sio_E_HttpEncoding* sio_PE_HttpEncoding)
{
	sio_SS_HttpEncoding << sio_V_HttpEncodingString;
	char c;
	while (sio_SS_HttpEncoding.get(c)) {
		if (isalnum(c) || c == '*' || c == '-' || c == '.' || c == '_') {
			sio_V_HttpEncodingRESULT += c;
		}
		else {
			std::stringstream tem;
			tem << std::hex;
			tem << "%" << std::setw(2) << int(unsigned char(c));
			sio_V_HttpEncodingRESULT += tem.str();
			tem.flush();
		}
	}
}

std::string sio_C_HttpEncoding::sio_C_GetHttpEncoding()
{
	return sio_V_HttpEncodingRESULT;
}

using std::cout;
using std::endl;

int main() {

	std::stringstream* ss = new std::stringstream;
	std::string a;

	*ss << "Hello World.";
	(*ss).flush();

	cout << (*ss).str() << endl;

	//delete ss;
	ss = new std::stringstream;
	*ss << "Next Line";
	cout << (*ss).str() << endl;


	/*
	sio_E_HttpEncoding a;
	sio_C_HttpEncoding encoding("abbababdjfldhfowu1234567890{|}~", &a);
	cout << encoding.sio_C_GetHttpEncoding() << endl;
	*/
	
	/*
	std::string a = "Welcome Hello World.";
	std::stringstream* ss = new std::stringstream;
	std::string* s = new std::string;
	*ss << a;
	while ((*ss).get()) {
		*ss >> *s;
	}
	delete ss;
	cout << *s << endl;
	delete s;
	*/

	//std::string a = "Welcome Hello World.";
	//std::stringstream ss;
	//std::string s ;
	//char* d = new char;
	//ss << a;

	//char* c = new char;
	//while (ss.get(*c)) {
	//	if (*c == 'W') {
	//		*c = '0';
	//	}
	//	s += *c;
	//}

	//while (ss.getline(d, sizeof(a))) {
	//	s += d;
	//	s.append(d);
	//	cout << d;
	//}

	//cout << s << endl;



	//sio_C_HttpGeneralHeader_Pragma a;
	//a.sio_FN_GetHttpGeneralHeader_PragmaAdd("no-cache").sio_FN_GetHttpGeneralHeader_PragmaAdd/(", /").sio_FN_GetHttpGeneralHeader_PragmaAdd("age = 35");
	//std::cout << a.sio_FN_GetHttpGeneralHeader_Pragma() << std::endl;

	char buff[64];
	time_t now = time(0);

	//char* c_time = ctime(&now);
	//sprintf(buff, "%s\n", c_time);
	//printf("%s", &buff);
	//
	//tm* loc_time = localtime(&now);
	//char* asc_localtime = asctime(loc_time);
	//sprintf(buff, "%s\n", asc_localtime);
	//printf("%s", &buff);
	//
	//tm* gm_time = gmtime(&now);
	//char* asc_gmtime = asctime(gm_time);
	//sprintf(buff, "%s\n", asc_gmtime);
	//printf("%s", &buff);

	//tm* mk_time = localtime(&now);
	//mk_time->tm_mon = 0;
	//mk_time->tm_mday = 10;
	//mk_time->tm_hour = 0;
	//mk_time->tm_min = 0;
	//mk_time->tm_sec = 0;

	//time_t f = mktime(mk_time);
	//tm* c_time_maker = localtime(&f);
	//char* maked_time = asctime(c_time_maker);
	//char buff_holder[128];
	//sprintf(buff_holder, "%s\n", maked_time);
	//printf("%s", &buff_holder);

	//char buff_3[128];
	//auto aaa = asctime(mk_time);
	//sprintf(buff_3, "%s\n", aaa);
	//printf("%s", &buff_3);

	//time_t gen_time = mktime(mk_time);
	//double diff_time = difftime(now, gen_time);
	//printf("%.5f\n", diff_time);
	

	//char BUFF[128];
	//auto G = strftime(BUFF, 128, "%I:%M%p", mk_time);
	//printf("%s", BUFF);

	//time_t now2 = time(0);
	//tm* t_m = localtime(&now2);
	//t_m->tm_year = t_m->tm_year - 49;
	//t_m->tm_mon = 0;
	//t_m->tm_mday = 1;
	//t_m->tm_hour = 0;
	//t_m->tm_min = 0;
	//t_m->tm_sec = 0;
	//
	//time_t x2 = mktime(t_m);
	//tm* x3 = localtime(&x2);
	//char* x4 = asctime(x3);
	
	//time_t now3 = time(0);
	//tm* t_m_f = gmtime(&now3);
	//t_m_f->tm_mday = t_m_f->tm_mday - 3;

	//char BUFF[128];
	//RFC 822, updated by RFC 1123
	//strftime(BUFF, sizeof(BUFF), "%a, %d %b %Y %H:%M:%S GMT", t_m_f);
	//RFC 850, obsoleted by RFC 1036
	//strftime(BUFF, sizeof(BUFF), "%A, %d-%b-%y %H:%M:%S GMT", t_m_f);
	//ANSI C's asctime() format
	//strftime(BUFF, sizeof(BUFF), "%a %b %e %H:%M:%S %Y", t_m_f);
	//printf("%s", BUFF);

	return 0;
}

