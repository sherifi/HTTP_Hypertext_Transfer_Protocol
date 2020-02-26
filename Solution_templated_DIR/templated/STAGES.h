#pragma once
#ifndef __H_STAGES__
#define __H_STAGES__
#ifdef __H_STAGES__

#include <vector>
#include <string>
#define __VEC__ std::vector<std::string>

typedef struct __EXPORT_SOLUTION__ d_STAGES {
public:
	__VEC__ Stage_1 = { "PROJECT_DIR" };
	__VEC__ Stage_2 = { "00_Code", "01_Research", "02_Work_DIR", "03_Assets", "04_Export" };
	__VEC__ Stage_3 = { "01_Design", "02_Engineering", "03_Study" };
	__VEC__ Stage_4 = { "CLASS" };
	__VEC__ Stage_5 = { "A", "B", "C", "D", "E", "F" };
	__VEC__ Stage_6 = { "A" };
	__VEC__ Stage_7 = { "A" };
	__VEC__ Stage_8 = { "A" };
	__VEC__ Stage_9 = { "A" };
}; d_STAGES;

typedef struct __EXPORT_SOLUTION__ f_STAGES {
public:
	__VEC__ Stage_1 = { "00_Code", "01_Research", "02_Work_DIR", "03_Assets", "04_Export" };
	__VEC__ Stage_2 = { "A" };
	__VEC__ Stage_3 = { "A" };
	__VEC__ Stage_4 = { "A" };
	__VEC__ Stage_5 = { "A" };
	__VEC__ Stage_6 = { "A" };
	__VEC__ Stage_7 = { "A" };
	__VEC__ Stage_8 = { "A" };
	__VEC__ Stage_9 = { "A" };
}; f_STAGES;

#endif // __H_STAGES__
#endif // __H_STAGES__

