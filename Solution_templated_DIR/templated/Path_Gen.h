#pragma once
#include "BaseResult.h"
#ifdef __H_BASE_RESULT__
#ifndef __H_PATH_DIR__
#define __H_PATH_DIR__
#ifdef __H_PATH_DIR__

template<typename T, typename M>
class __EXPORT_SOLUTION__ PathGen : public BaseResult{
//class PathGen : public BaseResult {
private:
	std::stringstream m_temp_STREAM{};

	std::string m_curr_PATH = { "" };
	std::string m_PATH = { "" };

	friend void swap(PathGen& destination, PathGen& source);

public:
	//CONSTRUCTOR
	explicit PathGen();

	//CONSTRUCTOR_SETTER
	explicit PathGen(M curr_PATH, M PATH);

	//CONSTRUCTOR FOR ERRORA
	explicit PathGen(M errMsg);

	//CONSTRUCTOR
	explicit PathGen(const PathGen& path_gen);
	explicit PathGen(PathGen&& path_gen);

	//OPERATORS for CONSTRUCTORS
	PathGen& operator=(const PathGen& path_gen);
	PathGen& operator=(PathGen&& path_gen);

	//DESTUCTOR
	~PathGen();

	//GETTER_SECTIONS
	inline T get_curr_PATH();
	inline T get_PATH();
	
	//SETTER_SECTIONS
	inline void set_curr_PATH(M curr_PATH);
	inline void set_PATH(M PATH);
	
	//UTILITY

};

#endif // __H_PATH_DIR__
#endif // __H_PATH_DIR__
#endif // __H_BASE_RESULT__

