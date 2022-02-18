#pragma once

namespace LA
{
	class MenuArgs
	{
	public:
		MenuArgs(const std::string& label, const std::string& args)
			: m_Label(label), m_RawArgs(args), m_Args(args) {}
		MenuArgs(const MenuArgs& other)
			: m_Label(other.m_Label), m_RawArgs(other.m_RawArgs), m_Args(other.m_RawArgs) {}
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

		const std::string& FullLine() const
		{
			return m_RawArgs;
		}

		std::string NextLine()
		{
			return Utils::ReadLine(m_Args);
		}

		bool Empty() const
		{
			return m_RawArgs.empty();
		}

		bool Done() const
		{
			return !m_Changed;
		}

		bool Check() const
		{
			if (m_Changed)
				return false;

			std::cout << "Not enough args!\n";
			return true;
		}

		static Ref<MenuArgs> Create(const std::string& label, const std::string& args);

	private:
		std::string m_Label;
		std::string m_RawArgs;
		std::stringstream m_Args;

		bool m_Changed = false;
	};
}