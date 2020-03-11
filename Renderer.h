#pragma once

#include "api.h"

#include <iostream>

class Renderer{
private:
	Data							*		p_Data;
	User_data						*		p_User_data;


	void									m_Init_Renderer();
	void									m_DeInit_Renderer();
public:
	Renderer();
	~Renderer();
}
