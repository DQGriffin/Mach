#include "Application.h"

//==========================================================================
// Application constructor
//==========================================================================
Mach::Application::Application()
{
	//derivedRun = runFunc;

	memset(m_ConsoleInputBuffer, 0, sizeof(m_ConsoleInputBuffer));
	m_ShowConsole = false;
	m_MaxFrameRate = 60;
	m_UseVsync = false;
	m_Fullscreen = false;

	m_Window = Mach::Window(50, 50, 100, 100, "Mach");
	m_Window.revalidate();
	m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
	m_Window.m_RenderWindow.setFramerateLimit(60);

	Renderer::initialize(&m_Window.m_RenderWindow);
	Console::initialize(&consoleBuffer);
	inputThread = std::thread(std::bind(&InputEngine::poll, inputEngine));

	FontManager::add("Roboto", "dummypath");
	done = false;
	LOG << "Application::Application()";
}

//==========================================================================
// Application destructor
//==========================================================================
Mach::Application::~Application()
{
	LOG << "Application::~Application()";
}

//==========================================================================
// Currently unused
//==========================================================================
void Mach::Application::run()
{
	
}

//==========================================================================
// Exit the application with the given exit code
//==========================================================================
void Mach::Application::exit(int code)
{
	// Do something with the exit code
	done = true;
}

//==========================================================================
// Query whether or not there are events in the queue
//==========================================================================
bool Mach::Application::hasEvent()
{
	return EventManager::hasEvents();
}

//==========================================================================
// Get the event at the front of the queue
//==========================================================================
Mach::Event Mach::Application::getEvent()
{
	return EventManager::getEvent();
}

//==========================================================================
// Clear all events from the queue
//==========================================================================
void Mach::Application::clearEvents()
{
	EventManager::clearEvents();
}

void Mach::Application::updateDevTools()
{
	ImGui::SFML::Update(m_Window.m_RenderWindow, clock.restart());
	updateConsole();
	updateFrameRateDeck();
	updateWindowSettingsDeck();
	ImGui::SFML::Render(m_Window.m_RenderWindow);
}

//==========================================================================
// Update Mach's console
//==========================================================================
void Mach::Application::updateConsole()
{
	if (m_ShowConsole)
	{
		//ImGui::SFML::Update(m_Window.m_RenderWindow, clock.restart());
		ImGui::SetNextWindowBgAlpha(0.85f);
		ImGui::Begin("Mach Console");
		ImGui::BeginChild("Scrolling", sf::Vector2i(350, 150));
		for (std::string& line : consoleBuffer)
		{
			ImGui::Text(line.c_str());
		}
		ImGui::EndChild();
		ImGui::InputText("", m_ConsoleInputBuffer, IM_ARRAYSIZE(m_ConsoleInputBuffer));
		ImGui::SameLine();
		if (ImGui::Button("Go"))
		{
			if (m_ConsoleInputBuffer[0] != 0)
			{
				LOG << "Console Input: " << m_ConsoleInputBuffer;
				Event event;
				event.type = Event::Type::ConsoleInput;

				Console::push(m_ConsoleInputBuffer);
				//consoleBuffer.push_back(m_ConsoleInputBuffer);				

				for (unsigned int i = 0; i < 256; i++)
				{
					if (m_ConsoleInputBuffer[i] != 0)
					{
						event.consoleInput.input[i] = m_ConsoleInputBuffer[i];
						event.consoleInput.input[i + 1] = 0;
					}
				}
				EventManager::fireEvent(event);

				// Clear the console input buffet
				memset(m_ConsoleInputBuffer, 0, sizeof(m_ConsoleInputBuffer));
			}
		}
		ImGui::End();
		//ImGui::SFML::Render(m_Window.m_RenderWindow);
	}
}

void Mach::Application::updateFrameRateDeck()
{
	if (m_ShowConsole)
	{
		//ImGui::SFML::Update(m_Window.m_RenderWindow, clock.restart());
		ImGui::SetNextWindowBgAlpha(0.85f);
		ImGui::Begin("Performance");
		ImGui::BeginChild("fps");
		if (ImGui::SliderInt("Max Framerate", &m_MaxFrameRate, 1, 120))
		{
			m_Window.m_RenderWindow.setFramerateLimit(m_MaxFrameRate);
			m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
			m_UseVsync = false;
		}
		ImGui::Spacing();
		if (ImGui::Button("1", {60, 20}))
		{
			m_MaxFrameRate = 1;
			m_Window.m_RenderWindow.setFramerateLimit(m_MaxFrameRate);
			m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
			m_UseVsync = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("15", { 60, 20 }))
		{
			m_MaxFrameRate = 15;
			m_Window.m_RenderWindow.setFramerateLimit(m_MaxFrameRate);
			m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
			m_UseVsync = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("30", { 60, 20 }))
		{
			m_MaxFrameRate = 30;
			m_Window.m_RenderWindow.setFramerateLimit(m_MaxFrameRate);
			m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
			m_UseVsync = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("60", {60, 20}))
		{
			m_MaxFrameRate = 60;
			m_Window.m_RenderWindow.setFramerateLimit(m_MaxFrameRate);
			m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
			m_UseVsync = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("120", { 60, 20 }))
		{
			m_MaxFrameRate = 120;
			m_Window.m_RenderWindow.setFramerateLimit(m_MaxFrameRate);
			m_Window.m_RenderWindow.setVerticalSyncEnabled(false);
			m_UseVsync = false;
		}
		ImGui::Spacing();
		if (ImGui::Checkbox("Enable Vertical-Sync", &m_UseVsync))
		{
			m_Window.m_RenderWindow.setVerticalSyncEnabled(m_UseVsync);
		}
		ImGui::EndChild();
		ImGui::End();
		//ImGui::SFML::Render(m_Window.m_RenderWindow);
	}
}

void Mach::Application::updateWindowSettingsDeck()
{
	if (m_ShowConsole)
	{
		ImGui::SetNextWindowBgAlpha(0.85f);
		ImGui::Begin("Window");
		if (ImGui::InputInt("Width", &m_Width))
		{
			m_Window.setSize(m_Width, m_Height);
		}
		if (ImGui::InputInt("Height", &m_Height))
		{
			m_Window.setSize(m_Width, m_Height);
		}
		ImGui::Spacing();
		if (ImGui::Checkbox("Fullscreen", &m_Fullscreen))
		{
			m_Window.setFullScreen(m_Fullscreen);
		}
		ImGui::End();
	}
	else
	{
		m_Width = m_Window.getSize().x;
		m_Height = m_Window.getSize().y;
	}
}

void Mach::Application::setConsoleDisplayed(bool displayed)
{
	m_ShowConsole = displayed;
}

bool Mach::Application::getConsoleDisplayed()
{
	return m_ShowConsole;
}
