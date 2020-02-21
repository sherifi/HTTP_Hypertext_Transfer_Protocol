#pragma once
#include "Path_Gen.h"
#ifdef __H_PATH_DIR__
#ifndef __H_DIR_GEN__
#define __H_DIR_GEN__
#ifdef __H_DIR_GEN__
#include "STAGES.h"

template<typename T, typename M, typename M2>
class __EXPORT_SOLUTION__ DirGen : public BaseResult{
//class DirGen : public BaseResult {
private:

	std::stringstream m_temp_STREAM{};

	std::string m_curr_PATH { "" };
	std::string m_PATH { "" };
	std::string m_DIR { "" };
	std::stringstream m_str_STREAM {};


	friend void swap(DirGen& destination, DirGen& source);
public:
	d_STAGES* ptr_d_STAGES = new d_STAGES();
	f_STAGES* ptr_f_STAGES = new f_STAGES();
public:
	//CONSTRUCTOR
	explicit DirGen();

	//CONSTRUCTOR_SETTER
	explicit DirGen(M curr_PATH, M PATH, M DIR);

	//CONSTRUCTOR FOR ERRORA
	explicit DirGen(M errMsg);

	//CONSTRUCTOR
	explicit DirGen(const DirGen& dir_gen);
	explicit DirGen(DirGen&& dir_gen);

	//OPERATORS for CONSTRUCTORS
	DirGen& operator=(const DirGen& dir_gen);
	DirGen& operator=(DirGen&& dir_gen);

	//DESTUCTOR
	~DirGen();

	//GETTER_SECTIONS
	inline T get_curr_PATH();
	inline T get_PATH();
	inline T get_DIR();

	//SETTER_SECTIONS
	inline void set_curr_PATH(M curr_PATH);
	inline void set_PATH(M PATH);
	inline void set_DIR(M DIR);

	//UTILITY

	//GETTER
	T get_STAGE_1_DIR(M2 a);
	T get_STAGE_2_DIR(M2 a, M2 b);
	T get_STAGE_3_DIR(M2 a, M2 b, M2 c);
	T get_STAGE_4_DIR(M2 a, M2 b, M2 c, M2 d);
	T get_STAGE_5_DIR(M2 a, M2 b, M2 c, M2 d, M2 e);
	T get_STAGE_6_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f);
	T get_STAGE_7_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g);
	T get_STAGE_8_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h);
	T get_STAGE_9_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i);

	//SETTER
	void set_STAGE_1_DIR(M2 a, bool print_DIR);
	void set_STAGE_2_DIR(M2 a, M2 b, bool print_DIR);
	void set_STAGE_3_DIR(M2 a, M2 b, M2 c, bool print_DIR);
	void set_STAGE_4_DIR(M2 a, M2 b, M2 c, M2 d, bool print_DIR);
	void set_STAGE_5_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, bool print_DIR);
	void set_STAGE_6_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, bool print_DIR);
	void set_STAGE_7_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, bool print_DIR);
	void set_STAGE_8_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, bool print_DIR);
	void set_STAGE_9_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i, bool print_DIR);

	//GENARATOR
	void gen_STAGE_1_DIR(M2 a, bool print_DIR);
	void gen_STAGE_2_DIR(M2 a, M2 b, bool print_DIR);
	void gen_STAGE_3_DIR(M2 a, M2 b, M2 c, bool print_DIR);
	void gen_STAGE_4_DIR(M2 a, M2 b, M2 c, M2 d, bool print_DIR);
	void gen_STAGE_5_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, bool print_DIR);
	void gen_STAGE_6_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, bool print_DIR);
	void gen_STAGE_7_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, bool print_DIR);
	void gen_STAGE_8_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, bool print_DIR);
	void gen_STAGE_9_DIR(M2 a, M2 b, M2 c, M2 d, M2 e, M2 f, M2 g, M2 h, M2 i, bool print_DIR);
};

#endif // __H_DIR_GEN__
#endif // __H_DIR_GEN__
#endif // __H_BASE_RESULT__

