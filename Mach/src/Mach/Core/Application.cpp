#include "Application.h"

//==========================================================================
// Application constructor
//==========================================================================
Mach::Application::Application()
{
	//derivedRun = runFunc;

	memset(m_ConsoleInputBuffer, 0, sizeof(m_ConsoleInputBuffer));

	m_Window = Mach::Window(50, 50, 100, 100, "Mach");
	m_Window.revalidate();

	Renderer::initialize(&m_Window.m_RenderWindow);
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

//==========================================================================
// Update Mach's console
//==========================================================================
void Mach::Application::updateConsole()
{
	ImGui::SFML::Update(m_Window.m_RenderWindow, clock.restart());
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

			consoleBuffer.push_back(m_ConsoleInputBuffer);

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
	ImGui::SFML::Render(m_Window.m_RenderWindow);
}
