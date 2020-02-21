#pragma once
#include "Dir_Gen.h"
#ifdef __H_BASE_RESULT__
#ifndef __H_FILE_GEN__
#define __H_FILE_GEN__
#ifdef __H_FILE_GEN__

template<typename T, typename M, typename M2>
class __EXPORT_SOLUTION__ FileGen : public BaseResult{
private:
	std::string m_file_NAME{ "PROJECT_DIR" };
	std::string m_file_EXTENSION{ "" };

	std::string m_curr_PATH{ "" };
	std::string m_PATH{ "" };

	std::string m_DIR{ "" };
	std::string m_FILE{ "" };

	std::stringstream m_str_STREAM{};

	std::fstream m_file_STREAM {};

	friend void swap(FileGen& destination, FileGen& source);
public:
	d_STAGES* ptr_d_STAGES = new d_STAGES();
	f_STAGES* ptr_f_STAGES = new f_STAGES();
public:
	//CONSTRUCTOR
	explicit FileGen();

	//CONSTRUCTOR_SETTER
	explicit FileGen(M file_NAME, M file_EXTENSION, M curr_PATH, M PATH, M DIR, M FILE);

	explicit FileGen(M errMsg);

	//CONSTRUCTOR
	explicit FileGen(const FileGen& file_gen);
	explicit FileGen(FileGen&& file_gen);

	//OPERATORS for CONSTRUCTORS
	FileGen& operator=(const FileGen& file_gen);
	FileGen& operator=(FileGen&& file_gen);

	//DESTRUCTOR
	~FileGen();

	//GETTER_SECTIONS
	inline T get_file_NAME();
	inline T get_file_EXTENSION();
	inline T get_curr_PATH();
	inline T get_PATH();
	inline T get_DIR();
	inline T get_FILE();

	//SETTER_SECTIONS
	inline void set_file_NAME(M file_NAME);
	inline void set_file_EXTENSION(M file_EXTENSION);
	inline void set_curr_PATH(M curr_PATH);
	inline void set_PATH(M PATH);
	inline void set_DIR(M DIR);
	inline void set_FILE(M FILE);

	//UTILITY

	//GETTER
	T get_STAGE_1_FILE();
	T get_STAGE_2_FILE();
	T get_STAGE_3_FILE();
	T get_STAGE_4_FILE();
	T get_STAGE_5_FILE();
	T get_STAGE_6_FILE();
	T get_STAGE_7_FILE();
	T get_STAGE_8_FILE();
	T get_STAGE_9_FILE();

	//SETTER
	void set_STAGE_1_FILE(M2 a, bool print_FILE);
	void set_STAGE_2_FILE(M2 a, M2 b, bool print_FILE);
	void set_STAGE_3_FILE(M2 a, M2 b, M2 c, bool print_FILE);
	void set_STAGE_4_FILE(M2 a, M2 b, M2 c, M2 d, bool print_FILE);
	void set_STAGE_5_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, bool print_FILE);
	void set_STAGE_6_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, bool print_FILE);
	void set_STAGE_7_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, bool print_FILE);
	void set_STAGE_8_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, bool print_FILE);
	void set_STAGE_9_FILE(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i, bool print_FILE);

	//GENARATOR
	void gen_STAGE_1_FILE(bool print_FILE);
	void gen_STAGE_2_FILE(bool print_FILE);
	void gen_STAGE_3_FILE(bool print_FILE);
	void gen_STAGE_4_FILE(bool print_FILE);
	void gen_STAGE_5_FILE(bool print_FILE);
	void gen_STAGE_6_FILE(bool print_FILE);
	void gen_STAGE_7_FILE(bool print_FILE);
	void gen_STAGE_8_FILE(bool print_FILE);
	void gen_STAGE_9_FILE(bool print_FILE);

};

#endif // __H_FILE_GEN__
#endif // __H_FILE_GEN__
#endif // __H_BASE_RESULT__


