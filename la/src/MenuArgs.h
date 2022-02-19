#pragma once

namespace LA
{
	class MenuArgs
	{
	public:
		MenuArgs(const std::string& label, const std::string& args);
		MenuArgs(const MenuArgs& other);
		virtual ~MenuArgs() = default;

		inline std::string GetLabel() const { return m_Label; }
		inline std::string GetRawArgs() const { return m_RawArgs; }

		template<typename T>
		T NextOne()
		{
			m_Changed = !m_Args.eof() && !m_RawArgs.empty();
			T result;
			m_Args >> result;
			return result;
		}

		const std::string& FullLine() const;
		std::string NextLine();
		bool Empty() const;
		bool Done() const;
		bool Check() const;

		static Ref<MenuArgs> Create(const std::string& label, const std::string& args);

	private:
		std::string m_Label;
		std::string m_RawArgs;
		std::stringstream m_Args;

		bool m_Changed = false;
	};
}