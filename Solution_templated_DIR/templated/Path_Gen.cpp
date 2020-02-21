#include "Path_Gen.h"

///////////////////////////////////////////////////////////////////////
template<typename T, typename M>
void swap(PathGen<T, M>& destination, PathGen<T, M>& source)
{
	using std::swap;
	swap(static_cast<BaseResult&>(destination), static_cast<BaseResult&>(source));
	swap(destination.m_curr_PATH, source.m_curr_PATH);
	swap(destination.m_PATH, source.m_PATH);
}

///////////////////////////////////////////////////////////////////////
template<typename T, typename M>
PathGen<T, M>::PathGen() : BaseResult() {}

template<>
PathGen<__STR__, __STR__>::PathGen() : BaseResult{} {}

template<>
PathGen<__STRING__, __STRING__>::PathGen() : BaseResult{} {}
///////////////////////////////////////////////////////////////////////

template<typename T, typename M>
PathGen<T, M>::PathGen(M curr_PATH, M PATH) : BaseResult{}
{
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
}

template <>
PathGen<__STRING__, __STRING__>::PathGen(__STRING__ curr_PATH, __STRING__ PATH) : BaseResult{}
{
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
}

template <>
PathGen<__STR__, __STR__>::PathGen(__STR__ curr_PATH, __STR__ PATH) : BaseResult{}
{
	m_curr_PATH = { curr_PATH };
	m_PATH = { PATH };
}


///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
PathGen<T, M>::PathGen(M errMsg) : BaseResult{errMsg} {}


template <>
PathGen<__STRING__, __STRING__>::PathGen(__STRING__ errMsg) : BaseResult{errMsg} {}

template <>
PathGen<__STR__, __STR__>::PathGen(__STR__ errMsg) : BaseResult{ errMsg } {}


///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
PathGen<T, M>::PathGen(const PathGen<T, M>& path_gen) : BaseResult{ path_gen }
{
	m_curr_PATH = { path_gen.m_curr_PATH };
	m_PATH = { path_gen.m_PATH };
}

template <typename T, typename M>
PathGen<T, M>::PathGen(PathGen<T, M>&& path_gen) : PathGen<T, M>{  }
{
	swap(*this, path_gen);
}

///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
PathGen<T, M>& PathGen<T, M>::operator=(const PathGen<T, M>& path_gen)
{
	PathGen<T, M> copy{ path_gen };
	swap(*this, copy);
	return *this;
}

template <typename T, typename M>
PathGen<T, M>& PathGen<T, M>::operator=(PathGen<T, M>&& path_gen)
{
	swap(*this, path_gen);
	PathGen<T, M> temp{};
	swap(path_gen, temp);
	return *this;
}

///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
PathGen<T, M>::~PathGen() {}

///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
inline T PathGen<T, M>::get_curr_PATH()
{
	return m_curr_PATH;
}

template<>
inline __STRING__ PathGen<__STRING__, __STRING__>::get_curr_PATH()
{
	return m_curr_PATH;
}

template<>
inline __STR__ PathGen<__STR__, __STR__>::get_curr_PATH()
{
	return m_curr_PATH.c_str();
}

///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
inline T PathGen<T, M>::get_PATH()
{
	return m_PATH;
}

template<>
inline __STRING__ PathGen<__STRING__, __STRING__>::get_PATH()
{
	return m_PATH;
}

template<>
inline __STR__ PathGen<__STR__, __STR__>::get_PATH()
{
	return m_PATH.c_str();
}

///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
inline void PathGen<T, M>::set_curr_PATH(M curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

template<>
inline void PathGen<__STRING__, __STRING__>::set_curr_PATH(__STRING__ curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

template<>
inline void PathGen<__STR__, __STR__>::set_curr_PATH(__STR__ curr_PATH)
{
	m_curr_PATH = { curr_PATH };
}

///////////////////////////////////////////////////////////////////////
template <typename T, typename M>
inline void PathGen<T, M>::set_PATH(M PATH)
{
	m_PATH = { PATH };
}

template<>
inline void PathGen<__STRING__, __STRING__>::set_PATH(__STRING__ PATH)
{
	m_PATH = { PATH };
}

template<>
inline void PathGen<__STR__, __STR__>::set_PATH(__STR__ PATH)
{
	m_PATH = { PATH };
}

