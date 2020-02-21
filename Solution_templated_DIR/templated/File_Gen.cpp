#include "File_Gen.h"

template<typename T, typename M, typename M2>
void swap(FileGen<T, M, M2>& destination, FileGen<T, M, M2>& source)
{
	using std::swap;
	swap(static_cast<BaseResult&>(destination), static_cast<BaseResult&> (source));
	swap(destination.m_file_NAME, source.m_file_NAME);
	swap(destination.m_file_EXTENSION, source.m_file_EXTENSION);
	swap(destination.m_curr_PATH, source.m_curr_PATH);
	swap(destination.m_PATH, source.m_PATH);
	swap(destination.m_DIR, source.m_DIR);
	swap(destination.m_FILE, source.m_FILE);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
FileGen<T, M, M2>::FileGen () {}

template<>
FileGen<__STR__, __STR__, size_t>::FileGen() : BaseResult{} {}

template<>
FileGen<__STRING__, __STRING__, size_t>::FileGen() : BaseResult{} {}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
FileGen<T, M, M2>::FileGen(M file_NAME, M file_EXTENSION, M curr_PATH, M PATH, M DIR, M FILE) : BaseResult{}
{
	m_file_NAME = { file_NAME };
	m_file_EXTENSION = { file_EXTENSION };
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
	m_DIR = { DIR };
	m_FILE = { FILE };
}

template<>
FileGen<__STRING__, __STRING__, size_t>::FileGen <__STRING__, __STRING__, size_t>(__STRING__ file_NAME, __STRING__ file_EXTENSION, __STRING__ curr_PATH, __STRING__ PATH, __STRING__ DIR, __STRING__ FILE) : BaseResult{}
{
	m_file_NAME = { file_NAME };
	m_file_EXTENSION = { file_EXTENSION };
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
	m_DIR = { DIR };
	m_FILE = { FILE };
}

template<>
FileGen<__STR__, __STR__, size_t>::FileGen <__STR__, __STR__, size_t>(__STR__ file_NAME, __STR__ file_EXTENSION, __STR__ curr_PATH, __STR__ PATH, __STR__ DIR, __STR__ FILE) : BaseResult{}
{
	m_file_NAME = { file_NAME };
	m_file_EXTENSION = { file_EXTENSION };
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
	m_DIR = { DIR };
	m_FILE = { FILE };
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
FileGen<T, M, M2>::FileGen(M errMsg) : BaseResult{ errMsg } {};

template <>
FileGen<__STRING__, __STRING__, size_t>::FileGen<__STRING__, __STRING__, size_t>(__STRING__ errMsg) : BaseResult{ errMsg } {};

template <>
FileGen<__STR__, __STR__, size_t>::FileGen<__STR__, __STR__, size_t>(__STR__ errMsg) : BaseResult{ errMsg } {};

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
FileGen<T, M, M2>::FileGen(const FileGen& file_gen) : BaseResult{ file_gen }
{
	m_file_NAME = { file_gen.m_file_NAME };
	m_file_EXTENSION = { file_gen.m_file_EXTENSION };
	m_curr_PATH = { file_gen.m_curr_PATH };
	m_PATH = { file_gen.m_PATH };
	m_DIR = { file_gen.m_DIR };
	m_FILE = { file_gen.m_FILE };
}

template<typename T, typename M, typename M2>
FileGen<T, M, M2>::FileGen(FileGen&& file_gen) : FileGen<T, M, M2>{  }
{
	swap(*this, file_gen);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
FileGen<T, M, M2>& FileGen<T, M, M2>::operator=(const FileGen& file_gen)
{
	FileGen<T, M, M2> copy{ file_gen };
	swap(*this, copy);
	return *this;

}

template<typename T, typename M, typename M2>
FileGen<T, M, M2>& FileGen<T, M, M2>::operator=(FileGen&& file_gen)
{
	swap(*this, file_gen);
	FileGen<T, M, M2> temp{};
	swap(file_gen, temp);
	return *this;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
FileGen<T, M, M2>::~FileGen()
{
	delete ptr_d_STAGES;
	delete ptr_f_STAGES;
}

//GETTER
////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T FileGen<T, M, M2>::get_file_NAME()
{
	return m_file_NAME;
}

template<>
inline __STRING__ FileGen<__STRING__, __STRING__, size_t>::get_file_NAME()
{
	return m_file_NAME;
}

template<>
inline __STR__ FileGen<__STR__, __STR__, size_t>::get_file_NAME()
{
	return m_file_NAME.c_str();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T FileGen<T, M, M2>::get_file_EXTENSION()
{
	return m_file_EXTENSION;
}

template<>
inline __STRING__ FileGen<__STRING__, __STRING__, size_t>::get_file_EXTENSION()
{
	return m_file_EXTENSION;
}

template<>
inline __STR__ FileGen<__STR__, __STR__, size_t>::get_file_EXTENSION()
{
	return m_file_EXTENSION.c_str();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T FileGen<T, M, M2>::get_curr_PATH()
{
	return m_curr_PATH;
}

template<>
inline __STRING__ FileGen<__STRING__, __STRING__, size_t>::get_curr_PATH()
{
	return m_curr_PATH;
}

template<>
inline __STR__ FileGen<__STR__, __STR__, size_t>::get_curr_PATH()
{
	return m_curr_PATH.c_str();
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T FileGen<T, M, M2>::get_PATH()
{
	return m_PATH;
}

template<>
inline __STRING__ FileGen<__STRING__, __STRING__, size_t>::get_PATH()
{
	return m_PATH;
}

template<>
inline __STR__ FileGen<__STR__, __STR__, size_t>::get_PATH()
{
	return m_PATH.c_str();
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T FileGen<T, M, M2>::get_DIR()
{
	return m_DIR;
}

template<>
inline __STRING__ FileGen<__STRING__, __STRING__, size_t>::get_DIR()
{
	return m_DIR;
}

template<>
inline __STR__ FileGen<__STR__, __STR__, size_t>::get_DIR()
{
	return m_DIR.c_str();
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline T FileGen<T, M, M2>::get_FILE()
{
	return m_FILE;
}

template<>
inline __STRING__ FileGen<__STRING__, __STRING__, size_t>::get_FILE()
{
	return m_FILE;
}

template<>
inline __STR__ FileGen<__STR__, __STR__, size_t>::get_FILE()
{
	return m_FILE.c_str();
}

//SETTER
/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void FileGen<T, M, M2>::set_file_NAME(M file_NAME)
{
	m_file_NAME = { file_NAME };
}

template<>
inline void FileGen<__STRING__, __STRING__, size_t>::set_file_NAME(__STRING__ file_NAME)
{
	m_file_NAME = { file_NAME };
}

template<>
inline void FileGen<__STR__, __STR__, size_t>::set_file_NAME(__STR__ file_NAME)
{
	m_file_NAME = { file_NAME };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void FileGen<T, M, M2>::set_file_EXTENSION(M file_EXTENSION)
{
	m_file_EXTENSION = { file_EXTENSION };
}

template<>
inline void FileGen<__STRING__, __STRING__, size_t>::set_file_EXTENSION(__STRING__ file_EXTENSION)
{
	m_file_EXTENSION = { file_EXTENSION };
}

template<>
inline void FileGen<__STR__, __STR__, size_t>::set_file_EXTENSION(__STR__ file_EXTENSION)
{
	m_file_EXTENSION = { file_EXTENSION };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void FileGen<T, M, M2>::set_curr_PATH(M curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

template<>
inline void FileGen<__STRING__, __STRING__, size_t>::set_curr_PATH(__STRING__ curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

template<>
inline void FileGen<__STR__, __STR__, size_t>::set_curr_PATH(__STR__ curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void FileGen<T, M, M2>::set_PATH(M PATH)
{
	m_PATH = { PATH };
}

template<>
inline void FileGen<__STRING__, __STRING__, size_t>::set_PATH(__STRING__ PATH)
{
	m_PATH = { PATH };
}

template<>
inline void FileGen<__STR__, __STR__, size_t>::set_PATH(__STR__ PATH)
{
	m_PATH = { PATH };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void FileGen<T, M, M2>::set_DIR(M DIR)
{
	m_DIR = { DIR };
}

template<>
inline void FileGen<__STRING__, __STRING__, size_t>::set_DIR(__STRING__ DIR)
{
	m_DIR = { DIR };
}

template<>
inline void FileGen<__STR__, __STR__, size_t>::set_DIR(__STR__ DIR)
{
	m_DIR = { DIR };
}

/////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
inline void FileGen<T, M, M2>::set_FILE(M FILE)
{
	m_FILE = { FILE };
}

template<>
inline void FileGen<__STRING__, __STRING__, size_t>::set_FILE(__STRING__ FILE)
{
	m_FILE = { FILE };
}

template<>
inline void FileGen<__STR__, __STR__, size_t>::set_FILE(__STR__ FILE)
{
	m_FILE = { FILE };
}

//GETTER
//////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_1_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_1_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_1_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_2_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_2_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_2_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_3_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_3_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_3_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_4_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_4_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_4_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_5_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_5_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_5_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_6_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_6_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_6_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_7_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_7_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_7_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_8_FILE() {
	return m_FILE;
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_8_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_8_FILE() {
	return m_FILE;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
T FileGen<T, M, M2>::get_STAGE_9_FILE() {
	return m_FILE.c_str();
}
template<>
__STR__ FileGen<__STR__, __STR__, size_t>::get_STAGE_9_FILE() {
	return m_FILE.c_str();
}
template<>
__STRING__ FileGen<__STRING__, __STRING__, size_t>::get_STAGE_9_FILE() {
	return m_FILE;
}

//SETTER
//////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_1_FILE(M2 a, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_1_FILE(size_t a, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_1_FILE(size_t a, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_2_FILE(M2 a, M2 b, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_2_FILE(size_t a, size_t b, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_2_FILE(size_t a, size_t b, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_3_FILE(M2 a, M2 b, M2 c, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_3_FILE(size_t a, size_t b, size_t c, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_3_FILE(size_t a, size_t b, size_t c, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_4_FILE(M2 a, M2 b, M2 c, M2 d, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_4_FILE(size_t a, size_t b, size_t c, size_t d, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_4_FILE(size_t a, size_t b, size_t c, size_t d, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_5_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_5_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_5_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_6_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_6_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_6_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_7_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_7_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_7_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_8_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_8_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_8_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::set_STAGE_9_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << ptr_d_STAGES->Stage_9[i] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STR__, __STR__, size_t>::set_STAGE_9_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << ptr_d_STAGES->Stage_9[i] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::set_STAGE_9_FILE(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h, size_t i, bool print_FILE) {
	m_str_STREAM.clear();
	m_str_STREAM << m_PATH << __SLASH__ << ptr_d_STAGES->Stage_1[a] << __SLASH__ << ptr_d_STAGES->Stage_2[b] << __SLASH__ << ptr_d_STAGES->Stage_3[c] << __SLASH__ << ptr_d_STAGES->Stage_4[d] << __SLASH__ << ptr_d_STAGES->Stage_5[e] << __SLASH__ << ptr_d_STAGES->Stage_6[f] << __SLASH__ << ptr_d_STAGES->Stage_7[g] << __SLASH__ << ptr_d_STAGES->Stage_8[h] << ptr_d_STAGES->Stage_9[i] << __SLASH__ << m_file_NAME << m_file_EXTENSION;
	m_FILE.clear();
	m_str_STREAM >> m_FILE;
	if (print_FILE == true)
		std::cout << m_FILE << std::endl;
}

//GENARATOR
//////////////////////////////////////////////////////////////////////////
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_1_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_1_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_1_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_2_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_2_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_2_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_3_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_3_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_3_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_4_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_4_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_4_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_5_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_5_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_5_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_6_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_6_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_6_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_7_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_7_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_7_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_8_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_8_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_8_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
//------------------------------------------------------------------------------
template<typename T, typename M, typename M2>
void FileGen<T, M, M2>::gen_STAGE_9_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STR__, __STR__, size_t>::gen_STAGE_9_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}
template<>
void FileGen<__STRING__, __STRING__, size_t>::gen_STAGE_9_FILE(bool print_FILE) {
	m_file_STREAM.open(m_FILE, std::ios::out);
	if (!m_file_STREAM) {
		fprintf(stderr, "Error creating file\n");
	}
	if (print_FILE == true)
		std::cout << "Sucessfully creating file:\t" << m_FILE << std::endl;
	m_file_STREAM.close();
}


