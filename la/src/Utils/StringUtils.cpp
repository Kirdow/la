#include "pch.h"
#include "StringUtils.h"

namespace LA::Utils
{
	std::string& LTrim(std::string& str)
	{
		auto it2 = std::find_if(str.begin(), str.end(), [](char ch) { return !std::isspace(ch); });
		str.erase(str.begin(), it2);
		return str;
	}

	std::string& RTrim(std::string& str)
	{
		auto it1 = std::find_if(str.rbegin(), str.rend(), [](char ch) { return !std::isspace(ch); });
		str.erase(it1.base(), str.end());
		return str;
	}

	std::string& Trim(std::string& str)
	{
		return LTrim(RTrim(str));
	}

	std::string TrimCopy(const std::string& str)
	{
		auto tmp = str;
		return LTrim(RTrim(tmp));
	}
}
