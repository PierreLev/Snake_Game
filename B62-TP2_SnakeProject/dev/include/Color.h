#ifndef COLOR_H
#define COLOR_H


#include <cstdint>


namespace bai {
	//! \brief Classe représentant la couleur. 
	//!
	//! \detail La classe Color représente une couleur par ses 4 constituants fondamentaux :
	//!  - rouge	: 0 - 255
	//!  - vert		: 0 - 255
	//!  - bleu		: 0 - 255
	//!  - alpha	: 0 - 255
	//!
	//! La transparence est gérée par le canal alpha 0 représente une couleur complètement transparente et 255 une couleur complètement opaque.
	//!
	//! Les couleurs suivantes sont disponibles sous forme de variables statiques :
	//!	 - primaires : rouge, vert et bleu
	//!	 - secondaires : jaune, cyan et magenta
	//!  - autres : orange
	//!	 - monochromatique : noir, blanc et plusieurs nuance de gris (interval de 12.5%)
	//!  - selon un certain niveau d'intensité (0, 255) : rouge, vert, bleu, jaune, cyan, magenta et gris
	//!
	//! Par exemple :
	//! \code{.cpp}
	//!	Color myColor1(Color::red);
	//!	Color myColor2(Color::greenChroma<128>);
	//! surface.clear(Color::grey<128>);
	//! \endcode
	class Color
	{
	public:
		//! Constructeur. La couleur est noire opaque par défaut.
		Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255);

		//! \brief Retourne la composante rouge de la couleur.
		uint8_t getRed() const;
		//! \brief Retourne la composante verte de la couleur.
		uint8_t getGreen() const;
		//! \brief Retourne la composante bleue de la couleur.
		uint8_t getBlue() const;
		//! \brief Retourne la composante de transparence de la couleur.
		uint8_t getAlpha() const;

		//! \brief Détermine la composante rouge de la couleur.
		void setRed(uint8_t r);
		//! \brief Détermine la composante verte de la couleur.
		void setGreen(uint8_t g);
		//! \brief Détermine la composante bleue de la couleur.
		void setBlue(uint8_t b);
		//! \brief Détermine la composante de transparence de la couleur.
		void setAlpha(uint8_t a);

		//! \brief Génération d'une couleur aléatoire
		//! \param opaque détermine si la couleur est opaque (alpha = 255) ou avec une transparence générée aléatoirement
		void randomize(bool opaque);
		//! \brief Génération d'une couleur aléatoire
		//! \param minVal détermine la valeur minimum de la plage des nombres aléatoires pour chacune des composantes de la couleur
		//! \param maxVal détermine la valeur maximum de la plage des nombres aléatoires pour chacune des composantes de la couleur
		//! \param opaque détermine si la couleur est opaque (alpha = 255) ou avec une transparence générée aléatoirement
		void randomize(uint8_t minVal, uint8_t maxVal, bool opaque);
		//! \brief Génération d'une couleur aléatoire
		//! \param minR détermine la valeur minimum pour le rouge
		//! \param maxR détermine la valeur maximum pour le rouge
		//! \param minG détermine la valeur minimum pour le vert
		//! \param maxG détermine la valeur maximum pour le vert
		//! \param minB détermine la valeur minimum pour le bleu
		//! \param maxB détermine la valeur maximum pour le bleu
		//! \param opaque détermine si la couleur est opaque (alpha = 255) ou avec une transparence générée aléatoirement
		void randomize(uint8_t minR, uint8_t maxR, uint8_t minG, uint8_t maxG, uint8_t minB, uint8_t maxB, uint8_t minA = 255, uint8_t maxA = 255);

		template <uint8_t value> inline static const Color redChroma{ Color(value, 0, 0) };				//!< Intensité de rouge défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 
		template <uint8_t value> inline static const Color greenChroma{ Color(0, value, 0) };			//!< Intensité de vert défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 
		template <uint8_t value> inline static const Color blueChroma{ Color(0, 0, value) };			//!< Intensité de bleu défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 
		template <uint8_t value> inline static const Color yellowChroma{ Color(value, value, 0) };		//!< Intensité de jaune défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 
		template <uint8_t value> inline static const Color cyanChroma{ Color(0, value, value) };		//!< Intensité de cyan défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 
		template <uint8_t value> inline static const Color magentaChroma{ Color(value, 0, value) };		//!< Intensité de magenta défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 
		template <uint8_t value> inline static const Color grey{ Color(value, value, value) };			//!< Intensité de gris défini dans l'espace de couleur RGB spécifié par le paramètre template value (0-255) 

		static const Color red;					//!< Rouge
		static const Color green;				//!< Vert
		static const Color blue;				//!< Bleu
		static const Color magenta;				//!< Magenta
		static const Color cyan;				//!< Cyan
		static const Color yellow;				//!< Jaune
		static const Color orange;				//!< Orange
		static const Color black;				//!< Noir
		static const Color white;				//!< Blanc
		static const Color veryDarkGrey;		//!< Gris 12.5%
		static const Color darkGrey;			//!< Gris 25.0%
		static const Color mediumDarkGrey;		//!< Gris 37.5%
		static const Color mediumGrey;			//!< Gris 50.0%
		static const Color mediumLightGrey;		//!< Gris 62.5%
		static const Color lightGrey;			//!< Gris 75.0%
		static const Color veryLightGrey;		//!< Gris 87.5%

	private:
		uint8_t mRed;
		uint8_t mGreen;
		uint8_t mBlue;
		uint8_t mAlpha;
	};
}


#endif // COLOR_H
