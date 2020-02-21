#pragma once
#include "File_Gen.h"
#ifdef __H_FILE_GEN__
#ifndef __H_APP__
#define __H_APP__
#ifdef __H_APP__
#undef main


int main(int argc, char** argv, char** envp) {
	__START__;
	////////////////////////////////////////
	std::string string;
	std::stringstream test_STREAM;

	try {
		//USING POINTER INSTATION
		DirGen<__STRING__, __STRING__, size_t>* ptr_to_DirGen =  new DirGen<__STRING__, __STRING__, size_t>{};
		test_STREAM << std::filesystem::current_path().string();
		test_STREAM >> string;
		std::cout << string << std::endl;
		ptr_to_DirGen->set_PATH(string);


		for (size_t a = 0; a <= ptr_to_DirGen->ptr_d_STAGES->Stage_1.size() - 1; ++a) {
			ptr_to_DirGen->set_STAGE_1_DIR(a, false);
			ptr_to_DirGen->gen_STAGE_1_DIR(a, true);
			for (size_t b = 0; b <= ptr_to_DirGen->ptr_d_STAGES->Stage_2.size() - 1; ++b) {
				ptr_to_DirGen-> set_STAGE_2_DIR(a, b, false);
				ptr_to_DirGen-> gen_STAGE_2_DIR(a, b, true);
				for (size_t c = 0; c <= ptr_to_DirGen->ptr_d_STAGES->Stage_3.size() - 1; ++c) {
					ptr_to_DirGen-> set_STAGE_3_DIR(a, b, c, false);
					ptr_to_DirGen-> gen_STAGE_3_DIR(a, b, c, true);
					for (size_t d = 0; d <= ptr_to_DirGen->ptr_d_STAGES->Stage_4.size() - 1; ++d) {
						ptr_to_DirGen-> set_STAGE_4_DIR(a, b, c, d, false);
						ptr_to_DirGen-> gen_STAGE_4_DIR(a, b, c, d, true);
						for (size_t e = 0; e <= ptr_to_DirGen->ptr_d_STAGES->Stage_5.size() - 1; ++e) {
							ptr_to_DirGen->set_STAGE_5_DIR(a, b, c, d, e, false);
							ptr_to_DirGen->gen_STAGE_5_DIR(a, b, c, d, e, true);
			//				for (size_t f = 0; f <= ptr_to_DirGen->ptr_d_STAGES->Stage_6.size() - 1; ++f) {
			//					ptr_to_DirGen->set_STAGE_6_DIR(a, b, c, d, e, f, false);
			//					ptr_to_DirGen->gen_STAGE_6_DIR(a, b, c, d, e, f, true);
			//					for (size_t g = 0; g <= ptr_to_DirGen->ptr_d_STAGES->Stage_7.size() - 1; ++g) {
			//						ptr_to_DirGen->set_STAGE_7_DIR(a, b, c, d, e, f, g, false);
			//						ptr_to_DirGen->gen_STAGE_7_DIR(a, b, c, d, e, f, g, true);
			//						for (size_t h = 0; h <= ptr_to_DirGen->ptr_d_STAGES->Stage_8.size() - 1; ++h) {
			//							ptr_to_DirGen->set_STAGE_8_DIR(a, b, c, d, e, f, g, h, false);
			//							ptr_to_DirGen->gen_STAGE_8_DIR(a, b, c, d, e, f, g, h, true);
			//							for (size_t i = 0; i <= ptr_to_DirGen->ptr_d_STAGES->Stage_9.size() - 1; ++i) {
			//								ptr_to_DirGen->set_STAGE_9_DIR(a, b, c, d, e, f, g, h, i, false);
			//								ptr_to_DirGen->gen_STAGE_9_DIR(a, b, c, d, e, f, g, h, i, true);
			//							}
			//						}
			//					}
			//				}
						}
					}
				}
			}
		}
		delete ptr_to_DirGen;

		FileGen<__STRING__, __STRING__, size_t>* ptr_to_FILE = new FileGen<__STRING__, __STRING__, size_t>{};
		test_STREAM << std::filesystem::current_path().string();
		test_STREAM >> string;

		ptr_to_FILE->set_PATH(string);
		ptr_to_FILE->set_file_NAME(ptr_to_FILE->ptr_f_STAGES->Stage_1[1]);
		ptr_to_FILE->set_file_EXTENSION(".txt");

		ptr_to_FILE->set_STAGE_5_FILE(0, 0, 0, 0, 0, false);
		ptr_to_FILE->gen_STAGE_5_FILE(true);

		delete ptr_to_FILE;
		

		////////////////////////////////////////////////////////////////
		/////////////////////////END SECTION/////////////////////////
		////////////////////////////////////////////////////////////////
	}

	catch(const std::filesystem::filesystem_error & e) {
		std::cout << e.what() << std::endl;
	}
	////////////////////////////////////////
	__END__;
	return 0;

}

#endif // __H_APP__
#endif // !__H_APP__
#endif //__H_DIR_GEN__