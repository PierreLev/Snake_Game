#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H


#include "Point.h"
#include <array>
#include <string>


namespace bai {
	class BasicApplicationInterface;

	//! \brief Classe gérant simplement les entrées de la souris et du clavier.
	class InputManager
	{
	private:
		friend class BasicApplicationInterface;
		InputManager(BasicApplicationInterface & application);
		~InputManager() = default;
		InputManager(InputManager const &) = delete;
		InputManager& operator=(InputManager const &) = delete;
		InputManager(InputManager &&) = delete;
		InputManager& operator=(InputManager &&) = delete;

		BasicApplicationInterface & mApplication;

	public:
		//! \brief Retourne si l'application a le focus.
		bool hasFocus() const;

		//! \brief Énumération identifiant les référentiels disponibles
		enum class CoordinateSystem {
			Local,	//!< Référentiel local - coordonnées selon la fenêtre de l'application
			Global	//!< Référentiel global - coordonnées selon le bureau
		};

		//! \brief Énumération identifiant les boutons de la souris
		enum class MouseButton {
			Left,		//!< Bouton de gauche
			Right,		//!< Bouton de droite
			Middle,		//!< Bouton du centre
			X1,			//!< Premier bouton extra (s'il existe, sinon retoure faux)
			X2,			//!< Deuxième bouton extra (s'il existe, sinon retoure faux)
			key_count,
		};
		//! \brief Retourne la position de la souris selon le référenciel donné.
		PointInt mousePosition(CoordinateSystem coordinateSystem = CoordinateSystem::Local) const;
		//! \brief Retourne la position de la souris selon le référenciel du bureau.
		bool isMouseButtonPressed(MouseButton mouseButton) const;
		//! \brief Retourne le nombre de boutton de la souris activés
		size_t buttonPressedCount() const;

		//! \brief Énumération identifiant les touches du clavier.
		enum class Key {
			Unknown = -1,
			A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
			Escape,
			LControl, LShift, LAlt, LSystem,
			RControl, RShift, RAlt, RSystem,
			Menu,
			LBracket, RBracket,
			Semicolon, Comma, Period,
			Quote, Slash, Backslash, Tilde,
			Equal, Hyphen, Space, Enter, Backspace, Tab, PageUp, PageDown, End, Home,
			Insert, Delete,
			Add, Subtract, Multiply, Divide,
			Left, Right, Up, Down,
			Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
			Pause,
			key_count,
		};
		//! \brief Retourne si la touche indiquée est activée.
		bool isKeyPressed(Key key) const;
		size_t keyPressedCount() const;
		static std::string const & keyText(Key key);
		static std::string const & mouseButtonText(MouseButton button);

		private:
			size_t mKeyPressedCount{};
			std::array<bool, (int)Key::key_count> mKeyState;
			static const std::array<std::string, (int)Key::key_count> KeyText;
			void setKeyState(Key key);
			void resetKeyState(Key key);

			size_t mButtonPressedCount{};
			std::array<bool, (int)MouseButton::key_count> mMouseButtonState;
			static const std::array<std::string, (int)MouseButton::key_count> MouseButtonText;
			void setMouseButtonState(MouseButton button);
			void resetMouseButtonState(MouseButton button);
			void lostFocus();
	};
}


#endif // INPUT_MANAGER_H
