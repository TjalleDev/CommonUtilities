#pragma once
#include "Vector.h"
#include <array>

namespace CommonUtilities
{
	enum class KeyCode
	{
		Left = 0x25,
		Right = 0x27,
		Up = 0x26,
		Down = 0x28,
		Escape = 0x1B,
		Delete = 0x2E,
		Backspace = 0x08,
		Tab = 0x09,
		Clear = 0x0C,
		Enter = 0x0D,
		LShift = 0xA0,
		RShift = 0xA1,
		Shift = 0x10,
		Ctrl = 0x11,
		LCtrl = 0xA2,
		RCtrl = 0xA3,
		Alt = 0x12,
		Pause = 0x13,
		CapsLock = 0x14,
		Spacebar = 0x20,
		PageUp = 0x21,
		PageDown = 0x22,
		End = 0x23,
		Home = 0x24,
		Select = 0x29,
		Print = 0x2A,
		Execute = 0x2B,
		PrintScreen = 0x2C,
		Insert = 0x2D,
		Help = 0x2F,
		NumPadPlus = 0x6B,
		NumPadMinus = 0x6D,
		NumPadForwardSlash = 0x6F,
		NumPadAsterisk = 0x6A,
		F1 = 0x70,
		F2 = 0x71,
		F3 = 0x72,
		F4 = 0x73,
		F5 = 0x74,
		F6 = 0x75,
		F7 = 0x76,
		F8 = 0x77,
		F9 = 0x78,
		F10 = 0x79,
		F11 = 0x7A,
		F12 = 0x7B,
		Numlock = 0x90,
		Num0 = 0x30,
		Num1 = 0x31,
		Num2 = 0x32,
		Num3 = 0x33,
		Num4 = 0x34,
		Num5 = 0x35,
		Num6 = 0x36,
		Num7 = 0x37,
		Num8 = 0x38,
		Num9 = 0x39,
		NumPad0 = 0x60,
		NumPad1 = 0x61,
		NumPad2 = 0x62,
		NumPad3 = 0x63,
		NumPad4 = 0x64,
		NumPad5 = 0x65,
		NumPad6 = 0x66,
		NumPad7 = 0x67,
		NumPad8 = 0x68,
		NumPad9 = 0x69,
		A = 0x41,
		B = 0x42,
		C = 0x43,
		D = 0x44,
		E = 0x45,
		F = 0x46,
		G = 0x47,
		H = 0x48,
		I = 0x49,
		J = 0x4A,
		K = 0x4B,
		L = 0x4C,
		M = 0x4D,
		N = 0x4E,
		O = 0x4F,
		P = 0x50,
		Q = 0x51,
		R = 0x52,
		S = 0x53,
		T = 0x54,
		U = 0x55,
		V = 0x56,
		W = 0x57,
		X = 0x58,
		Y = 0x59,
		Z = 0x5A
	};
	enum class MouseButton
	{
		Left = 0x01,
		Right = 0x02,
		Middle = 0x04
	};

	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void Update();

		void HandleInput(unsigned int message, unsigned int wParam);
		bool InputManager::IsKeyDown(KeyCode aKeyToCompareWith) const;
		bool InputManager::IsKeyPressed(KeyCode aKeyToCompareWith) const;
		bool InputManager::IsKeyReleased(KeyCode aKeyToCompareWith) const;

		bool InputManager::IsMouseButtonClicked(MouseButton aButtonToCompareWith) const;
		bool InputManager::IsMouseButtonDown(MouseButton aButtonToCompareWith) const;
		bool InputManager::IsMouseButtonReleased(MouseButton aButtonToCompareWith) const;

		Vector2f GetCursorPositionOnScreen() const;
		Vector2f GetCursorPositionOnScreenLastUpdate() const;

		void SetCursorPositionOnScreen(int aX, int aY);
		short GetWheelDeltaSinceLastFrame() const;

	private:
		void UpdateCursorPosition();
		Vector2f myCursorPositionOnScreen;
		Vector2f myCursorPositionOnScreenLastUpdate;
		short myWheelDeltaSinceLastFrame;

		struct State
		{
			std::array<bool, 256> myVirtualKeys;
		};
		State myCurrentState;
		State myPreviousState;
	};
}

namespace CU = CommonUtilities;