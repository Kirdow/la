#pragma once

namespace LA
{
	class MenuArgs;
	class MenuScene;
	class App
	{
	public:
		App() = default;
		virtual ~App() {};

		void Stop();

		void Init();
		void Run();

		Ref<MenuArgs> Next();

		static App* Get();
		static void Destroy();
	private:

		Ref<MenuScene> m_Scene;
		bool m_Running;
	};
}