#include "InputEngine.h"

//==========================================================================
// Create an InputEngine object
//==========================================================================
Mach::InputEngine::InputEngine(int tickRate)
{
	this->tickRate = tickRate;
	isPolling = true;
	previousMousePosition.x = 0;
	previousMousePosition.y = 0;
	initializeKeyMap();
	initializeMouseButtonMap();
}

//==========================================================================
// Poll for input
//==========================================================================
void Mach::InputEngine::pollInput()
{
}

//==========================================================================
// Poll for keyboard input
//==========================================================================
void Mach::InputEngine::pollKeyInput()
{
#if MACH_WINDOWS
	std::map<Keyboard::Key, int>::iterator iterator = keyMap.begin();

	while (iterator != keyMap.end())
	{
		if (GetKeyState(iterator->second) & 0x8000)
		{
			LOG << "Key pressed";
			Event event;
			event.keyEvent.key = iterator->first;
			event.type = Event::Type::KeyEvent;
			EventManager::fireEvent(event);
		}
		iterator++;
	}
#endif;
}

void Mach::InputEngine::pollKeysDown()
{
}

//==========================================================================
// Poll for mouse input
//==========================================================================
void Mach::InputEngine::pollMouseInput()
{
	std::map<Mouse::Button, int>::iterator iterator = mouseButtonMap.begin();

	while (iterator != mouseButtonMap.end())
	{
		if (GetKeyState(iterator->second) & 0x8000)
		{
			POINT position;
			GetCursorPos(&position);
			Event event;
			event.type = Event::Type::MouseClickEvent;
			event.mouseClickEvent.button = iterator->first;
			event.mouseClickEvent.x = position.x;
			event.mouseClickEvent.y = position.y;
			LOG << "Mouse clicked: " << position.x << ", " << position.y;
		}
		iterator++;
	}

	POINT position;
	GetCursorPos(&position);
	if (previousMousePosition.x != static_cast<int>(position.x)|| previousMousePosition.y != static_cast<int>(position.y))
	{
		// The mouse has moved, fire and event
		previousMousePosition.x = position.x;
		previousMousePosition.y = position.y;
		LOG << "Mouse moving";
	}
}

//==========================================================================
// Poll for input
//==========================================================================
void Mach::InputEngine::poll()
{
	while (isPolling)
	{
		//LOG << "Input Engine polling";
		pollKeyInput();
		pollMouseInput();
		std::this_thread::sleep_for(std::chrono::milliseconds(tickRate));
	}
}

//==========================================================================
// Initialize the key map
// See pollKeyInput()
//==========================================================================
void Mach::InputEngine::initializeKeyMap()
{
	// Letters
	keyMap[Keyboard::Key::A] = 0x41;
	keyMap[Keyboard::Key::B] = 0x42;
	keyMap[Keyboard::Key::C] = 0x43;
	keyMap[Keyboard::Key::D] = 0x44;
	keyMap[Keyboard::Key::E] = 0x45;
	keyMap[Keyboard::Key::F] = 0x46;
	keyMap[Keyboard::Key::G] = 0x47;
	keyMap[Keyboard::Key::H] = 0x48;
	keyMap[Keyboard::Key::I] = 0x49;
	keyMap[Keyboard::Key::J] = 0x4A;
	keyMap[Keyboard::Key::K] = 0x4B;
	keyMap[Keyboard::Key::L] = 0x4C;
	keyMap[Keyboard::Key::M] = 0x4D;
	keyMap[Keyboard::Key::N] = 0x4E;
	keyMap[Keyboard::Key::O] = 0x4F;
	keyMap[Keyboard::Key::P] = 0x50;
	keyMap[Keyboard::Key::Q] = 0x51;
	keyMap[Keyboard::Key::R] = 0x52;
	keyMap[Keyboard::Key::S] = 0x53;
	keyMap[Keyboard::Key::T] = 0x54;
	keyMap[Keyboard::Key::U] = 0x55;
	keyMap[Keyboard::Key::V] = 0x56;
	keyMap[Keyboard::Key::W] = 0x57;
	keyMap[Keyboard::Key::X] = 0x58;
	keyMap[Keyboard::Key::Y] = 0x59;
	keyMap[Keyboard::Key::Z] = 0x5A;

	// Numbers
	keyMap[Keyboard::Key::Num0] = 0x30;
	keyMap[Keyboard::Key::Num1] = 0x31;
	keyMap[Keyboard::Key::Num2] = 0x32;
	keyMap[Keyboard::Key::Num3] = 0x33;
	keyMap[Keyboard::Key::Num4] = 0x34;
	keyMap[Keyboard::Key::Num5] = 0x35;
	keyMap[Keyboard::Key::Num6] = 0x36;
	keyMap[Keyboard::Key::Num7] = 0x37;
	keyMap[Keyboard::Key::Num8] = 0x38;
	keyMap[Keyboard::Key::Num9] = 0x39;
	keyMap[Keyboard::Key::Numpad0] = 0x60;
	keyMap[Keyboard::Key::Numpad1] = 0x61;
	keyMap[Keyboard::Key::Numpad2] = 0x62;
	keyMap[Keyboard::Key::Numpad3] = 0x63;
	keyMap[Keyboard::Key::Numpad4] = 0x64;
	keyMap[Keyboard::Key::Numpad5] = 0x65;
	keyMap[Keyboard::Key::Numpad6] = 0x66;
	keyMap[Keyboard::Key::Numpad7] = 0x67;
	keyMap[Keyboard::Key::Numpad8] = 0x68;
	keyMap[Keyboard::Key::Numpad9] = 0x69;

	// Function Keys
	keyMap[Keyboard::Key::F1] = 0x70;
	keyMap[Keyboard::Key::F2] = 0x71;
	keyMap[Keyboard::Key::F3] = 0x72;
	keyMap[Keyboard::Key::F4] = 0x73;
	keyMap[Keyboard::Key::F5] = 0x74;
	keyMap[Keyboard::Key::F6] = 0x75;
	keyMap[Keyboard::Key::F7] = 0x76;
	keyMap[Keyboard::Key::F8] = 0x77;
	keyMap[Keyboard::Key::F9] = 0x78;
	keyMap[Keyboard::Key::F10] = 0x79;
	keyMap[Keyboard::Key::F11] = 0x7A;
	keyMap[Keyboard::Key::F12] = 0x7B;

	// Action keys
	keyMap[Keyboard::Key::Backspace] = VK_BACK;
	keyMap[Keyboard::Key::Tab] = VK_TAB;
	keyMap[Keyboard::Key::Enter] = VK_RETURN;
	keyMap[Keyboard::Key::LShift] = VK_LSHIFT;
	keyMap[Keyboard::Key::RShift] = VK_RSHIFT;
	keyMap[Keyboard::Key::Menu] = VK_MENU;
	keyMap[Keyboard::Key::LControl] = VK_LCONTROL;
	keyMap[Keyboard::Key::RControl] = VK_RCONTROL;
	keyMap[Keyboard::Key::Pause] = VK_PAUSE;
	keyMap[Keyboard::Key::Caps] = VK_CAPITAL;
	keyMap[Keyboard::Key::Escape] = VK_ESCAPE;
	keyMap[Keyboard::Key::Space] = VK_SPACE;
	keyMap[Keyboard::Key::PageDown] = VK_PRIOR;
	keyMap[Keyboard::Key::PageUp] = VK_NEXT;
	keyMap[Keyboard::Key::End] = VK_END;
	keyMap[Keyboard::Key::Home] = VK_HOME;
	keyMap[Keyboard::Key::Left] = VK_LEFT;
	keyMap[Keyboard::Key::Right] = VK_RIGHT;
	keyMap[Keyboard::Key::Up] = VK_UP;
	keyMap[Keyboard::Key::Down] = VK_DOWN;
	keyMap[Keyboard::Key::Insert] = VK_INSERT;
	keyMap[Keyboard::Key::Delete] = VK_DELETE;
	keyMap[Keyboard::Key::LSystem] = VK_LWIN;
	keyMap[Keyboard::Key::RSystem] = VK_RWIN;
	keyMap[Keyboard::Key::LBracket] = VK_OEM_4;
	keyMap[Keyboard::Key::RBracket] = VK_OEM_6;
	keyMap[Keyboard::Key::Quote] = VK_OEM_7;
	keyMap[Keyboard::Key::Multiply] = VK_MULTIPLY;
	keyMap[Keyboard::Key::Divide] = VK_DIVIDE;
	keyMap[Keyboard::Key::Subtract] = VK_SUBTRACT;
	keyMap[Keyboard::Key::Add] = VK_ADD;
	keyMap[Keyboard::Key::Period] = VK_OEM_PERIOD;
}

//==========================================================================
// Initialize the mouse button map
// See pollMouseInput()
//==========================================================================
void Mach::InputEngine::initializeMouseButtonMap()
{
	mouseButtonMap[Mouse::Button::LeftButton] = VK_LBUTTON;
	mouseButtonMap[Mouse::Button::RightButton] = VK_RBUTTON;
	mouseButtonMap[Mouse::Button::MiddleButton] = VK_MBUTTON;
	mouseButtonMap[Mouse::Button::Extra1] = VK_XBUTTON1;
	mouseButtonMap[Mouse::Button::Extra2] = VK_XBUTTON2;
}
