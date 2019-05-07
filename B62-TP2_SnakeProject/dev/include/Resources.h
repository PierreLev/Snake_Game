#ifndef RESOURCES_H
#define RESOURCES_H


#include "Rect.h"
#include "Color.h"

namespace sf {
	class Font;
	class Text;
	class Texture;
	class Sprite;
	//class Sound;
	//class Music;
};

namespace bai {
	//! \brief Classe gérant une resource. 
	//! Cette classe n'est pas destinée à être utilisée directement.
	template <typename T>
	class Resource
	{
		friend class Surface;

	protected:
		std::shared_ptr<T> mResource;
		Resource() : mResource(std::make_shared<T>()) {}
		~Resource() = default;

		T & operator*() { return *mResource; }
		T const & operator*() const { return *mResource; }

		std::shared_ptr<T>& operator->() { return mResource; }
		std::shared_ptr<T> const & operator->() const { return mResource; }

	public:
		Resource(Resource<T> const & resource) = default;
		Resource& operator=(Resource const & font) = default;

		operator bool() const { return mResource; }
	};

	//! \brief Police de caractère.
	class Font final : public Resource<sf::Font>
	{
		friend class TextStyle;

	public:
		Font(std::string const & fileName);
		Font(Font const & font) = default;
		~Font() = default;
		Font& operator=(Font const & font) = default;
	};

	//! \brief Caractéristiques visuelles d'un texte.
	class TextStyle final : public Resource<sf::Text>
	{
	public:
		TextStyle(Font const & font);
		TextStyle(Font const & font, size_t size, Color const & color, bool bold = false, bool italic = false, bool underlined = false, bool strikeThrough = false);
		TextStyle(TextStyle const & font) = default;
		~TextStyle() = default;
		TextStyle& operator=(TextStyle const & font) = default;

		void setSize(size_t size);
		void setFillColor(Color const & fillColor);
		void setOutline(Color const & outlineColor, float outlineTickness = 1.0f);
		void setBold(bool bold = true);
		void setItalic(bool italic = true);
		void setUnderline(bool underlined = true);
		void setStrikeThrough(bool strikeThrough = true);
		void set(size_t size, Color const & color, bool bold = false, bool italic = false, bool underlined = false, bool strikeThrough = false);

		size_t size() const;
		Color fillColor() const;
		Color outlineColor() const;
		float outlineThickness() const;
		bool bold() const;
		bool italic() const;
		bool underlined() const;
		bool strikeTrough() const;

		float heightMetric() const;
		float widthMetric(std::string const & text) const;
		RectReal boundsMetric(std::string const & text) const;
	};

	//! \brief Image.
	class Image final : public Resource<sf::Texture>
	{
		friend class Sprite;

	public:
		Image(std::string const & fileName);
		Image(Image const & font) = default;
		~Image() = default;
		Image& operator=(Image const & font) = default;

		SizeInt size() const;
	};

	//! \brief Représente la sous-image d'une image.
	class Sprite : public Resource<sf::Sprite>
	{
	public:
		Sprite(Image const & image);
		Sprite(Image const & image, RectInt const & subImageRect, Color const & color = Color::white);
		~Sprite() = default;
		Sprite(Sprite const & font) = default;
		//Sprite& operator=(Sprite const & font) = default;

		void resetColorBlend();
		void setColorBlend(Color const & colorBlend);

		void resetSubImage();
		void setSubImage(RectInt const & subImageRect);

		Color colorBlend() const;
		RectInt subImage() const;
	};
}



#endif // RESOURCES_H
