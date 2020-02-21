#include "BaseResult.h"

///////////////////////////////////////////////////////////////////////
void swap(BaseResult& destination, BaseResult& source)
{
	using std::swap;
	swap(destination.m_errMsg, source.m_errMsg);
}

///////////////////////////////////////////////////////////////////////
BaseResult::BaseResult() {}

///////////////////////////////////////////////////////////////////////
BaseResult::BaseResult(__STR__ errMsg)
{
	if (errMsg == nullptr) {
		throw std::invalid_argument("errMsg can't be nullptr");
	}
	m_errMsg = std::make_unique<std::string>(errMsg);
}

BaseResult::BaseResult(__STRING__ errMsg)
{
	m_errMsg = std::make_unique<std::string>(errMsg);
}

///////////////////////////////////////////////////////////////////////
BaseResult::BaseResult(const BaseResult& baseResult)
{
	if (baseResult.m_errMsg)
		m_errMsg = std::make_unique<std::string>(*baseResult.m_errMsg);
}

BaseResult::BaseResult(BaseResult&& baseResult) : BaseResult{}
{
	swap(*this, baseResult);
}

///////////////////////////////////////////////////////////////////////
BaseResult& BaseResult::operator=(const BaseResult& baseResult)
{
	BaseResult copy{ baseResult };
	swap(*this, copy);
	return *this;
}

BaseResult& BaseResult::operator=(BaseResult&& baseResult)
{
	swap(*this, baseResult);
	BaseResult temp{};
	swap(baseResult, temp);
	return *this;
}

///////////////////////////////////////////////////////////////////////
BaseResult::~BaseResult(){}

///////////////////////////////////////////////////////////////////////
bool BaseResult::succeed() const noexcept
{
	return m_errMsg == nullptr;
}

BaseResult::operator bool() const noexcept
{
	return succeed();
}

///////////////////////////////////////////////////////////////////////
inline __STRING__ BaseResult::changeCase(__STRING__ str, bool to_upper)
{
	std::string result{ str };
	std::transform(result.begin(), result.end(), result.begin(), to_upper ? ::toupper : ::tolower);
	return result;
}

///////////////////////////////////////////////////////////////////////
inline __STRING__ BaseResult::get_errorMessage() const noexcept
{
	const std::string emptyError{ "" };
	return m_errMsg ? *m_errMsg : emptyError;
}

///////////////////////////////////////////////////////////////////////
inline void BaseResult::set_errorMessage(__STRING__ errorMessage)
{
	m_errMsg = std::make_unique<std::string>(errorMessage);
}

