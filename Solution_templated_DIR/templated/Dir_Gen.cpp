#include "Dir_Gen.h"

template<typename T, typename M, typename M2>
void swap(DirGen<T, M, M2>& destination, DirGen<T, M, M2>& source)
{
	using std::swap;
	swap(static_cast<BaseResult&>(destination), static_cast<BaseResult&>(source));
	swap(destination.m_curr_PATH, source.m_curr_PATH);
	swap(destination.m_PATH, source.m_PATH);
	swap(destination.m_DIR, source.m_DIR);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
DirGen<T, M, M2>::DirGen() : BaseResult() {}

template<>
DirGen<__STR__, __STR__, size_t>::DirGen() : BaseResult{} {}

template<>
DirGen<__STRING__, __STRING__, size_t>::DirGen() : BaseResult{} {}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
DirGen<T, M, M2>::DirGen(M curr_PATH, M PATH, M DIR) : BaseResult{}
{
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
	m_DIR = { DIR };
}

template<>
DirGen<__STRING__, __STRING__, size_t>::DirGen(__STRING__ curr_PATH, __STRING__ PATH, __STRING__ DIR) : BaseResult{}
{
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
	m_DIR = { DIR };
}

template<>
DirGen<__STR__, __STR__, size_t>::DirGen(__STR__ curr_PATH, __STR__ PATH, __STR__ DIR) : BaseResult{}
{
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
	m_DIR = { DIR };
}

///////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
DirGen<T, M, M2>::DirGen(M errMsg) : BaseResult{errMsg} {}

template <>
DirGen<__STRING__, __STRING__, size_t>::DirGen(__STRING__ errMsg) : BaseResult{errMsg} {}

template <>
DirGen<__STR__, __STR__, size_t>::DirGen(__STR__ errMsg) : BaseResult{ errMsg } {}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
DirGen<T, M, M2>::DirGen(const DirGen<T, M, M2>& dir_gen) : BaseResult{ dir_gen }
{
	m_curr_PATH = { dir_gen.m_curr_PATH };
	m_PATH = { dir_gen.m_PATH };
	m_DIR = { dir_gen.m_DIR };
}

template<typename T, typename M, typename M2>
DirGen<T, M, M2>::DirGen(DirGen<T, M, M2>&& dir_gen) : DirGen<T, M, M2>{  }
{
	swap(*this, dir_gen);
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
DirGen<T, M, M2>& DirGen<T, M, M2>::operator=(const DirGen<T, M, M2>& dir_gen)
{
	DirGen<T, M, M2> copy{ dir_gen };
	swap(*this, copy);
	return *this;
}

template<typename T, typename M, typename M2>
DirGen<T, M, M2>& DirGen<T, M, M2>::operator=(DirGen<T, M, M2>&& dir_gen)
{
	swap(*this, dir_gen);
	DirGen<T, M, M2> temp{};
	swap(dir_gen, temp);
	return *this;
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
DirGen<T, M, M2>::~DirGen()
{
	delete ptr_d_STAGES;
	delete ptr_f_STAGES;
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T DirGen<T, M, M2>::get_curr_PATH()
{
	return m_curr_PATH;
}

template<>
inline __STRING__ DirGen<__STRING__, __STRING__, size_t>::get_curr_PATH()
{
	return m_curr_PATH;
}

template<>
inline __STR__ DirGen<__STR__, __STR__, size_t>::get_curr_PATH()
{
	return m_curr_PATH.c_str();
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T DirGen<T, M, M2>::get_PATH()
{
	return m_PATH;
}

template<>
inline __STRING__ DirGen<__STRING__, __STRING__, size_t>::get_PATH()
{
	return m_PATH;
}

template<>
inline __STR__ DirGen<__STR__, __STR__, size_t>::get_PATH()
{
	return m_PATH.c_str();
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T DirGen<T, M, M2>::get_DIR()
{
	return m_DIR;
}

template<>
inline __STRING__ DirGen<__STRING__, __STRING__, size_t>::get_DIR()
{
	return m_DIR;
}

template<>
inline __STR__ DirGen<__STR__, __STR__, size_t>::get_DIR()
{
	return m_DIR.c_str();
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void DirGen<T, M, M2>::set_curr_PATH(M curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

template<>
inline void DirGen<__STRING__, __STRING__, size_t>::set_curr_PATH(__STRING__ curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

template<>
inline void DirGen<__STR__, __STR__, size_t>::set_curr_PATH(__STR__ curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void DirGen<T, M, M2>::set_PATH(M PATH)
{
	m_PATH = { PATH };
}

template<>
inline void DirGen<__STRING__, __STRING__, size_t>::set_PATH(__STRING__ PATH)
{
	m_PATH = { PATH };
}

template<>
inline void DirGen<__STR__, __STR__, size_t>::set_PATH(__STR__ PATH)
{
	m_PATH = { PATH };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void DirGen<T, M, M2>::set_DIR(M DIR)
{
	m_DIR = { DIR };
}

template<>
inline void DirGen<__STRING__, __STRING__, size_t>::set_DIR(__STRING__ DIR)
{
	m_DIR = { DIR };
}

template<>
inline void DirGen<__STR__, __STR__, size_t>::set_DIR(__STR__ DIR)
{
	m_DIR = { DIR };
}

//GETTER
//////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_1_DIR(M2 a) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_1_DIR(size_t a) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_1_DIR(size_t a) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_2_DIR(M2 a, M2 b) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_2_DIR(size_t a, size_t b) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_2_DIR(size_t a, size_t b) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_3_DIR(M2 a, M2 b, M2 c) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_3_DIR(size_t a, size_t b, size_t c) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_3_DIR(size_t a, size_t b, size_t c) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_4_DIR(M2 a, M2 b, M2 c, M2 d) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_4_DIR(size_t a, size_t b, size_t c, size_t d) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_4_DIR(size_t a, size_t b, size_t c, size_t d) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_5_DIR(M2 a, M2 b, M2 c, M2 d, M2 e) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_5_DIR(size_t a, size_t b, size_t c, size_t d, size_t e) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_5_DIR(size_t a, size_t b, size_t c, size_t d, size_t e) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_6_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_6_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_6_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_7_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_7_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_7_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_8_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_8_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_8_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h) {
	return m_DIR.c_str();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T DirGen<T, M, M2>::get_STAGE_9_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i) {
	return m_DIR;
}
template<>
const std::string& DirGen<__STRING__, __STRING__, size_t>::get_STAGE_9_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i) {
	return m_DIR;
}
template<>
const char* DirGen<__STR__, __STR__, size_t>::get_STAGE_9_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i) {
	return m_DIR.c_str();
}

//SETTER
//////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_1_DIR(M2 a, bool print_DIR ) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_1_DIR(size_t a, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_1_DIR(size_t a, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_2_DIR(M2 a, M2 b, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_2_DIR(size_t a, size_t b, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_2_DIR(size_t a, size_t b, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_3_DIR(M2 a, M2 b, M2 c, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_3_DIR(size_t a, size_t b, size_t c, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_3_DIR(size_t a, size_t b, size_t c, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_4_DIR(M2 a, M2 b, M2 c, M2 d, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_4_DIR(size_t a, size_t b, size_t c, size_t d, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_4_DIR(size_t a, size_t b, size_t c, size_t d, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_5_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_5_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_5_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_6_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_6_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_6_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_7_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_7_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_7_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_8_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_8_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_8_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::set_STAGE_9_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << ptr_d_STAGES->Stage_9[i];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if(print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::set_STAGE_9_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << ptr_d_STAGES->Stage_9[i];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::set_STAGE_9_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i, bool print_DIR) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << ptr_d_STAGES->Stage_9[i];
	m_DIR.clear();
	m_str_STREAM >> m_DIR;
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}

//GENARATOR
//////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_1_DIR(M2 a, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_1_DIR(size_t a, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_1_DIR(size_t a, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_2_DIR(M2 a, M2 b, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_2_DIR(size_t a, size_t b, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_2_DIR(size_t a, size_t b, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_3_DIR(M2 a, M2 b, M2 c, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_3_DIR(size_t a, size_t b, size_t c, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_3_DIR(size_t a, size_t b, size_t c, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_4_DIR(M2 a, M2 b, M2 c, M2 d, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_4_DIR(size_t a, size_t b, size_t c, size_t d, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_4_DIR(size_t a, size_t b, size_t c, size_t d, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_5_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_5_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_5_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_6_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_6_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_6_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_7_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_7_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_7_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_8_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_8_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_8_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void DirGen<T, M, M2>::gen_STAGE_9_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STR__, __STR__, size_t>::gen_STAGE_9_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
template<>
void DirGen<__STRING__, __STRING__, size_t>::gen_STAGE_9_DIR(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i, bool print_DIR) {
	std::filesystem::create_directory(m_DIR);
	if (print_DIR == true)
		std::cout << m_DIR << std::endl;
}
//------------------------------------------------------------------------------


