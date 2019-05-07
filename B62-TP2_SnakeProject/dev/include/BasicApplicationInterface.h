

#ifndef BASIC_APPLICATION_INTERFACE_H
#define BASIC_APPLICATION_INTERFACE_H


#include <string>
#include <memory>
#include <functional>
#include "Size.h"


namespace sf {
	class RenderWindow;
}

namespace bai {

	class Surface;
	class InputManager;

	//! \brief Classe faisant une gestion simplifiée d'une application Windows.
	//!
	//! \detail Cette classe permet de créer une application Windows simple où seul le clavier est géré.
	//! La stratégie consiste à :
	//! -# créer une fonction de rappel (callback function) qui servira à l'exécution de l'application.
	//!	-# créer un objet de type `ElementaryWindowApplication` (`bai`).
	//!	-# assigner la function de rappel à l'objet `bai`
	//!	-# optionnellement, charger les ressources requises (images et police de caractères)
	//!	-# exécuter l'application par la fonction `run`
	//!
	//! La fonction de rappel est appelée le plus rapidement possible et c'est la responsabilité du programmeur 
	//! d'application de réaliser la tâche souhaitée. Principalement, ces trois tâches sont réalisées :
	//!	- gestion des entrées du clavier
	//!	- gestion de la logique de l'application
	//! - affichage
	//!
	//! La fonction de rappel :
	//!	- retourne un booléan indiquant si l'application doit poursuivre ou terminer.
	//!	- prend un premier paramètre `elapsedTime` indiquant le temps écoulé depuis le dernier appel
	//!	- prend une référence d'un objet de type `Surface`
	//!
	//! Il existe deux types de fonction de rappel pouvant être assignée avec la fonction `registerLoop` :
	//!	- fonction standard
	//!	- fonction de classe ainsi qu'un objet de cette classe
	//!
	//! Les classes utilitaires suivantes sont utilisées :
	//!	- `Surface` sert à l'affichage
	//!	- `KeyReader` sert à connaître l'état du clavier
	//!
	//! Deux types de ressources doivent être chargée avant de pouvoir les utiliser par une `surface` :
	//!	- les images requises pour les fonctions Surface::drawImage(...)
	//!	- police de caractère requises pour les fonctions :
	//!		- Surface::textMetric(...)
	//!		- Surface::drawText(...)
	//!		- Surface::drawCenteredText(...)
	class BasicApplicationInterface
	{
		friend class Surface;
		friend class InputManager;
		friend class ResourceManager;

	public:
		//! Constructeur.
		//! \param screenWidth La largeur de l'application en pixels (immuable).
		//! \param screenHeight La hauteur de l'application en pixels (immuable).
		//! \param title Le titre de l'application.
		//! \param appIconFileName Optionnellement, le fichier image représentant l'icône de l'application (seul ces formats sont supportés : bmp, png, tga, jpg, gif, psd, hdr et pic - les fichiers ico ne sont pas supportés).
		BasicApplicationInterface(size_t screenWidth = 640, size_t screenHeight = 480, std::string const & title = "bai", std::string const & appIconFileName = "");
		//! Destructeur.
		~BasicApplicationInterface();

		//! Type de la fonction de rappel (pour une fonction standard).
		using loop_f = bool(float elapsedTime, InputManager & reader, Surface & surface);
		//! Type de la fonction de rappel (pour une fonction membre de classe).
		template <typename T> using loop_mf = bool(T::*)(float elapsedTime, InputManager & reader, Surface & surface);

		//! Accesseur de la taille de l'application.
		SizeInt size() const;

		//! Détermine la fonction de rappel (pour une fonction standard).
		void registerLoop(loop_f loop);
		//! Détermine la fonction de rappel (pour une fonction membre de classe).
		template <typename T> void registerLoop(T & obj, loop_mf<T> objFunction) { mLoop = std::bind(objFunction, std::ref(obj), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3); }

		//! Exécution du programme.
		void run();

	private:
		bool mHasFocus{ true };
		std::function<loop_f> mLoop;
		std::unique_ptr<sf::RenderWindow> mRenderWindow;
	};
}

#endif // BASIC_APPLICATION_INTERFACE_H
