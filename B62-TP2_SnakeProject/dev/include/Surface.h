#ifndef SURFACE_H
#define SURFACE_H


#include <string>
#include <vector>
#include <utility>

//#include "Color.h"
//#include "Size.h"
//#include "Rect.h"
#include "Resources.h"


namespace bai {
	class BasicApplicationInterface;

	//! \brief Classe utilitaire permettant d'interagir avec le canvas de l'application.
	//!
	//! \detail Donne accès à toutes les fonctions d'affichage sur la surface graphique de l'application.
	//! Trois accesseurs donnent accès aux informations de la surface :
	//!	 - largeur
	//!  - hauteur
	//!  - possède le focus
	//! Il existe plusieurs fonctions de dessin :
	//!  - point
	//!  - ligne
	//!  - cercle
	//!  - rectangle
	//!  - polygone régulier
	//!  - polygone convexe
	//!  - image
	//!  - texte
	class Surface
	{
	private:
		friend class BasicApplicationInterface;
		Surface(BasicApplicationInterface & application);
		~Surface() = default;
		Surface(Surface const &) = delete;
		Surface& operator=(Surface const &) = delete;
		Surface(Surface &&) = delete;
		Surface& operator=(Surface &&) = delete;

		BasicApplicationInterface & mApplication;

	public:
		//! \brief Retourne la largeur de la surface.
		size_t width() const;
		//! \brief Retourne la hauteur de la surface.
		size_t height() const;
		//! \brief Retourne la taille de la surface
		SizeInt size() const;
		//! \brief Retourne si l'application a le focus.
		bool hasFocus() const;

		//! \brief Efface toute la surface avec une couleur uniforme.
		//! \param color Couleur du fond de l'application.
		void clear(Color const & color = Color::black);

		//! \brief Dessine un point.
		//! \param point Coordonnée du point.
		//! \param color Couleur du point.
		void drawPoint(PointReal const & point, Color const & color);
		//! \brief Dessine plusieurs points.
		//! \param points Liste de points.
		//! \param color Couleur des points.
		void drawPoints(std::vector<PointReal> const & points, Color const & color);

		//! \brief Dessine une ligne.
		//! \param p1 Premier point de la ligne.
		//! \param p2 Deuxième point de la ligne.
		//! \param color Couleur de la ligne.
		void drawLine(PointReal const & p1, PointReal const & p2, Color const & color);
		//! \brief Dessine plusieurs lignes les unes à la suite des autres.
		//! \param lines série de points correspondant à la série de ligne à dessiner.
		//! \param color Couleur des lignes.
		void drawLines(std::vector<PointReal> const & lines, Color const & color);
		//! \brief Dessine plusieurs lignes distinctes.
		//! \param lines série de 2 points correspondant aux deux points de chaque ligne.
		//! \param color Couleur des lignes.
		void drawLines(std::vector<std::pair<PointReal, PointReal>> const & lines, Color const & color);

		//! \brief Dessine un cercle.
		//! \param center Coordonnée du centre.
		//! \param radius Rayon.
		//! \param fillColor Couleur de remplissage.
		void drawCircle(PointReal const & center, float radius, Color const & fillColor);
		//! \brief Dessine un cercle.
		//! \param center Coordonnée du centre.
		//! \param radius Rayon.
		//! \param fillColor Couleur de remplissage.
		//! \param outlineColor Couleur de la bordure.
		//! \param outlineThickness Taille de la bordure en pixel.
		void drawCircle(PointReal const & center, float radius, Color const & fillColor, Color const & outlineColor, float outlineThickness = 1.0f);

		//! \brief Dessine un rectangle aligné sur les axes.
		//! \param topLeft Coin supérieur gauche du rectangle.
		//! \param bottom Coin inférieur droit du rectangle.
		//! \param fillColor Couleur de remplissage.
		void drawRectangle(RectReal const & rect, Color const & fillColor);
		//! \brief Dessine un rectangle aligné sur les axes.
		//! \param topLeft Coin supérieur gauche du rectangle.
		//! \param bottom Coin inférieur droit du rectangle.
		//! \param fillColor Couleur de remplissage.
		//! \param outlineColor Couleur de la bordure.
		//! \param outlineThickness Taille de la bordure en pixel.
		void drawRectangle(RectReal const & rect, Color const & fillColor, Color const & outlineColor, float outlineThickness = 1.0f);
		//! \brief Dessine un rectangle libre de rotation.
		//! \param center Centre du rectangle.
		//! \param rotation Angle de rotation en degrés.
		//! \param size Taille du rectangle.
		//! \param fillColor Couleur de remplissage.
		void drawRectangle(PointReal const & center, SizeReal const & size, float rotation, Color const & fillColor);
		//! \brief Dessine un rectangle libre de rotation.
		//! \param center Centre du rectangle.
		//! \param size Taille du rectangle.
		//! \param rotation Angle de rotation en degrés.
		//! \param fillColor Couleur de remplissage.
		//! \param outlineColor Couleur de la bordure.
		//! \param outlineThickness Taille de la bordure en pixel.
		void drawRectangle(PointReal const & center, SizeReal const & size, float rotation, Color const & fillColor, Color const & outlineColor, float outlineThickness = 1.0f);

		//! \brief Dessine un polygone régulier.
		//! \param center Centre du polygone.
		//! \param radius Distance entre le centre et un sommet (rayon circonscrit).
		//! \param nSides Nombre de sommets du polygone régulier.
		//! \param rotation Angle de rotation en degrés.
		//! \param fillColor Couleur de remplissage.
		void drawRegularPolygon(PointReal const & center, float radius, size_t nSides, float rotation, Color const & fillColor);
		//! \brief Dessine un polygone régulier.
		//! \param center Centre du polygone.
		//! \param radius Distance entre le centre et un sommet (rayon circonscrit).
		//! \param nSides Nombre de sommets du polygone régulier.
		//! \param rotation Angle de rotation en degrés.
		//! \param fillColor Couleur de remplissage.
		//! \param outlineColor Couleur de la bordure.
		//! \param outlineThickness Taille de la bordure en pixel.
		void drawRegularPolygon(PointReal const & center, float radius, size_t nSides, float rotation, Color const & fillColor, Color const & outlineColor, float outlineThickness = 1.0f);

		//! \brief Dessine un polygone convexe. Le polygone doit être convexe et défini dans le même sens horaire. Le sens n'est pas important en autant que tous les points sont définis de façon consistante (horaire ou anti horaire).
		//! \param vertices Tous les sommets du polygone. Les sommets sont définis selon les coordonnées du polygone et non pas de la surface.
		//! \param center Position sur la surface.
		//! \param rotation Angle de rotation en degrés.
		//! \param fillColor Couleur de remplissage.
		void drawConvexPolygon(std::vector<PointReal> const & vertices, PointReal const & center, float rotation, Color const & fillColor);
		//! \brief Dessine un polygone convexe. Le polygone doit être convexe et défini dans le même sens horaire. Le sens n'est pas important en autant que tous les points sont définis de façon consistante (horaire ou anti horaire).
		//! \param vertices Tous les sommets du polygone. Les sommets sont définis selon les coordonnées du polygone et non pas de la surface.
		//! \param center Position sur la surface.
		//! \param rotation Angle de rotation en degrés.
		//! \param fillColor Couleur de remplissage.
		//! \param outlineColor Couleur de la bordure.
		//! \param outlineThickness Taille de la bordure en pixel.
		void drawConvexPolygon(std::vector<PointReal> const & vertices, PointReal const & center, float rotation, Color const & fillColor, Color const & outlineColor, float outlineThickness = 1.0f);

		//! \brief Dessine une image complète. L'image affichée doit être préalablement chargée et disponible par son index (voir : ElementaryWindowApplication::loadImage).
		//! \param imageId Index de l'image déjà chargée.
		//! \param toTopLeft Position de destination sur la surface.
		//! \param rotation Angle de rotation en degrés.
		//! \param origin Position relative du point central sur l'image source (donne un décalage et détermine le point de rotation).
		void drawImage(Image const & image, PointReal const & target, float rotation = 0.0f, PointInt const & origin = PointInt());
		//! \brief Dessine une partie d'une image. L'image affichée doit être préalablement chargée et disponible par son index (voir : ElementaryWindowApplication::loadImage).
		//! \param imageId Index de l'image déjà chargée.
		//! \param fromTopLeft Position d'extraction de l'image source.
		//! \param fromSize Taille d'extraction de l'image source.
		//! \param toTopLeft Position de destination sur la surface.
		//! \param rotation Angle de rotation en degrés.
		//! \param origin Position relative du point central sur l'image source (donne un décalage et détermine le point de rotation).
		void drawImage(Sprite const & sprite, PointReal const & target, float rotation = 0.0f, PointInt const & origin = PointInt());

		// //! \brief Détermine la taille d'un texte à l'écran. La police de caractère utilisée doit être préalablement chargée et disponible par son index (voir : ElementaryWindowApplication::loadFont).
		// //! \param topLeft Retourne la position du texte.
		// //! \param size Retourne la taille du texte.
		// //! \param fontId Index de la police de caractère déjà chargée.
		// //! \param str Texte affiché.
		// //! \param pixelSize Taille du texte en pixel (pas en point).
		// //! \param bold Mise en caractère gras.
		// //! \param italic Mise en italique.
		// //! \param underlined Soulignement du texte.
		// void textMetric(PointReal & topLeft, SizeReal & size, Font const & font, std::string const & str, size_t pixelSize, bool bold = false, bool italic = false, bool underlined = false);
		//! \brief Dessine un texte. La police de caractère utilisée doit être préalablement chargée et disponible par son index (voir : ElementaryWindowApplication::loadFont).
		//! \param fontId Index de la police de caractère déjà chargée.
		//! \param str Texte affiché.
		//! \param pixelSize Taille du texte en pixel (pas en point).
		//! \param pos Position du texte.
		//! \param rotation Rotation du texte.
		//! \param color Couleur du texte.
		//! \param bold Mise en caractère gras.
		//! \param italic Mise en italique.
		//! \param underlined Soulignement du texte.
		void drawText(TextStyle & textStyle, std::string const & str, PointReal const & pos, float rotation = 0.0f);
		//! \brief Dessine un texte centré. La police de caractère utilisée doit être préalablement chargée et disponible par son index (voir : ElementaryWindowApplication::loadFont).
		//! \param fontId Index de la police de caractère déjà chargée.
		//! \param str Texte affiché.
		//! \param pixelSize Taille du texte en pixel (pas en point).
		//! \param pos Position du texte.
		//! \param rotation Rotation du texte.
		//! \param color Couleur du texte.
		//! \param bold Mise en caractère gras.
		//! \param italic Mise en italique.
		//! \param underlined Soulignement du texte.
		void drawCenteredText(TextStyle & textStyle, std::string const & str, PointReal const & pos, float rotation = 0.0f);
	};
}

#endif // SURFACE_H