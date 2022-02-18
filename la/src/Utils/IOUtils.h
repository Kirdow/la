#pragma once

namespace LA::Utils
{
	template<typename T>
	static T ReadOne(std::istream& istr)
	{
		T result;
		istr >> result;
		return result;
	}

	template<typename T>
	static T ReadOne()
	{
		return ReadOne<T>(std::cin);
	}

	static std::string ReadLine(std::istream& istr)
	{
		std::string line;
		std::getline(istr, line);
		return line;
	}

	static std::string ReadLine(std::istream& istr, const std::string& prompt)
	{
		std::cout << prompt;
		return ReadLine(istr);
	}

	static std::string ReadLine()
	{
		return ReadLine(std::cin);
	}

	static std::string ReadLine(const std::string& prompt)
	{
		return ReadLine(std::cin, prompt);
	}
}