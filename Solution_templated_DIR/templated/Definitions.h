#pragma once
#ifndef __H_DEFINITIONS__
#define __H_DEFINITIONS__

#define oprintf(...) fprintf (stdout, __VA_ARGS__)
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
	//eprintf("%s:%d: ", input_file, lineno)
		//fprintf(stderr, "%s:%d: ", input_file, lineno)
//#define eprintf(args...) fprintf (stderr, args)
//#define eprintf(format, ...) fprintf (stderr, format, __VA_ARGS__)
//#define eprintf(format, ...) fprintf (stderr, format, ##__VA_ARGS__)
//#define eprintf(format, args...) fprintf (stderr, format , ##args)


#if __cplusplus == 201703L
	#message "You are using right version of cpp (-std=c++17)"
#endif

#if (!__cplusplus) == 201703L
	#error (You are not using right version of cpp. Need to be compiled with "-std=c++17")
	oprintf(You are not using right version of cpp. Need to be compiled with "-std=c++17")
#endif

	#undef __PROGRAM_FULL_NAME__
	#undef __PROGRAM_NAME__
	#undef __PROGRAM_VERSION__
	#undef __PROGRAM_MAJOR__
	#undef __PROGRAM_MINOR__

	#ifndef __PROGRAM_NAME__
		#define __PROGRAM_NAME__ "SOLUTION DIR"
	#endif // !__PROGRAM_NAME__
	#ifndef __PROGRAM_VERSION__
		#define __PROGRAM_VERSION__ 1
	#endif // !__PROGRAM_VERSION__
	#ifndef __PROGRAM_MAJOR__
		#define __PROGRAM_MAJOR__ 01
	#endif // !__PROGRAM_MAJOR__
	#ifndef __PROGRAM_MINOR__
		#define __PROGRAM_MINOR__ 001
	#endif // !__PROGRAM_MINOR__
	
	#define __PROGRAM_FULL_NAME__ __PROGRAM_NAME__##__PROGRAM_VERSION__##__PROGRAM_MAJOR__##__PROGRAM_MINOR__

// GCC supports "pragma once" correctly since 3.4
#if defined(_MSC_VER) ||                                            \
	(defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
	(__GNUC__ >= 4))
#pragma once
#endif

// This is here for compatibility with older versions of Visual Studio
// which don't support noexcept
#if defined(_MSC_VER) && _MSC_VER < 1900
	#define CPP_NOEXCEPT _NOEXCEPT
#else
	#define CPP_NOEXCEPT noexcept
#endif

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdexcept>
	
	#include <filesystem>
	#include <string>
	#include <vector>
	#include <iostream>
	#include <sstream>
	#include <fstream>
	#include <typeinfo>
	#include <memory>
	#include <algorithm>

	#define __START__ fprintf(stdout, "\tAPP_start\n")
	#define __END__ fprintf(stdout, "\tAPP_end\n")

	//=================TYPE SECTIONS=================
	#define __STRING__ const std::string&
	#define __STR__ const char*
	#define __VEC_STR__ std::vector <std::string>
	#define __FS_ERROR__ std::filesystem::filesystem_error
	//=================TYPE SECTIONS=================

	//=================POINTERS SECTIONS=================
	#define __PTR_STRING__ std::string*
	#define __PTR_STRING_SHARED__ std::shared_ptr<std::string>
	#define __PTR_STRING_UNIQUE__ std::unique_ptr<std::string>
	#define __PTR_C_STR__ __STR__
	#define __PTR_C_STR_SHARED__ std::shared_ptr<__STR__>
	#define __PTR_C_STR_UNIQUE__ std::unique_ptr<__STR__>
	#define __PTR__VECTOR_STRING__ std::vector<std::string>*
	#define __PTR__VECTOR_STRING_SHARED__ std::shared_ptr<std::vector<std::string>>
	#define __PTR__VECTOR_STRING_UNIQUE__ std::shared_ptr<std::vector<std::string>>
	#define __PTR__VECTOR_C_STR__ std::vector<__STR__>*
	#define __PTR__VECTOR_C_STR_SHARED__ std::shared_ptr<std::vector<__STR__>>
	#define __PTR__VECTOR_C_STR_UNIQUE__ std::unique_ptr<std::vector<__STR__>>
	//=================POINTERS SECTIONS=================
	#define __WIN64__
	#define __EXPORT__

	#ifdef __WIN32__
		#define __SLASH__ "\\"
		#undef max
		#undef DELETE
		#ifdef __EXPORT__
			#define __EXPORT_SOLUTION__ __declspec(dllexport)
			#define TEM_EXPORT_SOLUTION extern "C"
		#else
			#define __EXPORT_SOLUTION__ __declspec(dllimport)
			#define TEM_EXPORT_SOLUTION
		#endif // __EXPORT__
	#endif // __WIN32__
	#ifdef __WIN64__
		#define __SLASH__ "\\"
		#undef max
		#undef DELETE
		#ifdef __EXPORT__
			#define __EXPORT_SOLUTION__ __declspec(dllexport)
			#define TEM_EXPORT_SOLUTION extern "C"
		#else
			#define __EXPORT_SOLUTION__ __declspec(dllimport)
			#define TEM_EXPORT_SOLUTION
		#endif // __EXPORT__
	#endif // __WIN64__
	#ifdef __MACOS__
		#define __SLASH__ "/"
		#undef max
		#undef DELETE
		#ifdef __EXPORT__
			#define __EXPORT_SOLUTION__ __declspec(dllexport)
			#define TEM_EXPORT_SOLUTION extern "C"
		#else
			#define __EXPORT_SOLUTION__ __declspec(dllimport)
			#define TEM_EXPORT_SOLUTION
		#endif // __EXPORT__
	#endif // __MACOS__
	#ifdef __LINUX__
		#define __SLASH__ "/"
		#undef max
		#undef DELETE
		#ifdef __EXPORT__
			#define __EXPORT_SOLUTION__ __declspec(dllexport)
			#define __TEMP_EXPORT_SOLUTION__ extern "C"
		#else
			#define __EXPORT_SOLUTION__ __declspec(dllimport)
			#define __TEMP_EXPORT_SOLUTION__
	#endif // __EXPORT__
	#endif // __LINUX__

/*
#undef __SLASH__
#undef __EXPORT__
#undef __EXPORT_SOLUTION__
#undef __TEMP_EXPORT_SOLUTION__
#undef CPP_NOEXCEPT
*/


#endif // !__H_DEFINITIONS__

