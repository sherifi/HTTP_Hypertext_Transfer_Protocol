#pragma once
#include "Definitions.h"
#ifdef __H_DEFINITIONS__
#ifndef __H_BASE_RESULT__
#define __H_BASE_RESULT__
#ifdef __H_BASE_RESULT__

#include <stdexcept>

class __EXPORT_SOLUTION__ BaseResult {
//class BaseResult {
private:
	/*
	__PTR_STRING__ m_ptr_string;
	__PTR_STRING_UNIQUE__ m_ptr_string_unique;
	__PTR_STRING_SHARED__ m_ptr_string_shared;
	__PTR_C_STR__ m_ptr_c_str;
	__PTR_C_STR_UNIQUE__ m_ptr_c_str_unique;
	__PTR_C_STR_SHARED__ m_ptr_c_str_shared;
	*/
	__PTR_STRING_UNIQUE__ m_errMsg;
	friend void swap(BaseResult& destination, BaseResult& source);
protected:
public:
	//CONSTRUCTOR
	explicit BaseResult();

	//CONSTRUCTOR_SETTER

	//CONSTRUCTOR FOR ERRORA
	explicit BaseResult(__STRING__ errMsg);
	explicit BaseResult(__STR__ errMsg);

	//CONSTRUCTOR
	explicit BaseResult(const BaseResult& baseResult);
	explicit BaseResult(BaseResult&& baseResult);

	//OPERATORS for CONSTRUCTORS
	BaseResult& operator=(const BaseResult& baseResult);
	BaseResult& operator=(BaseResult&& baseResult);

	//DESTUCTOR
	virtual ~BaseResult();
		
	//UTILITY
	bool succeed() const noexcept;
	explicit operator bool() const noexcept;
	inline __STRING__ changeCase(__STRING__ str, bool to_upper = false);


	//GETTER
	inline __STRING__ get_errorMessage() const noexcept;

	//SETTER
	inline void set_errorMessage(__STRING__ errorMessage) ;
};

#endif // __H_BASE_RESULT__
#endif // __H_BASE_RESULT__
#endif // __H_DEFINITIONS__

