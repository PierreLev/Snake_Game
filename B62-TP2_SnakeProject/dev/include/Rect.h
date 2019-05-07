#ifndef RECT_H
#define RECT_H


#include "Point.h"
#include "Size.h"


namespace bai {
	//! \brief Classe représentant un rectangle 2d.
	//! 
	//! Cette classe template ne supporte que les types numériques (sauf bool).
	//!
	//! Sont disponibles les class RectInt pour des int et RectReal pour des float.
	template <typename t>
	class Rect
	{
		static_assert(std::is_arithmetic<t>::value && !std::is_same<t, bool>::value, "Invalid template argument in Rect : t must be arithmetic except bool");

	public:
		Rect(Point<t> const & topLeft = Point<t>(), Size<t> const & size = Size<t>()) : mTopLeft(topLeft), mSize(size) {}
		Rect(Size<t> const & size) : Rect(Point<t>(), size) {}
		Rect(t top, t left, t width, t height) : Rect(Point<t>(top, left), Size<t>(width, height)) {}
		~Rect() = default;
		Rect(Rect const &) = default;
		Rect& operator=(Rect const &) = default;
		Rect(Rect &&) = default;
		Rect& operator=(Rect &&) = default;

		void setTopLeft(Point<t> const & topLeft) { mTopLeft = topLeft; }
		void setTopLeft(t top, t left) { mTopLeft = Point<t>(top, left); }
		void setSize(Size<t> const & size) { mSize = size; }
		void setSize(t width, t height) { mSize = Size<t>(width, height); }
		void set(Point<t> const & topLeft, Size<t> const & size) { setTopLeft(topLeft); setSize(size); }
		void set(t top, t left, t width, t height) { setTopLeft(top, left); setSize(width, height); }

		Point<t> topLeft() const { return mTopLeft; }
		Point<t> topRight() const { return mTopLeft + Point<t>(mSize.width(), t{}); }
		Point<t> bottomLeft() const { return mTopLeft + Point<t>(t{}, mSize.height()); }
		Point<t> bottomRight() const { return mTopLeft + Point<t>(mSize.width(), mSize.height()); }
		Size<t> size() const { return mSize; }

		Point<t> center() const { return mTopLeft + mSize.center(); }
		t perimeter() const { return mSize.perimeter(); }
		t area() const { return mSize.area(); }

		template <typename u> operator Rect<u>() { return Rect<u>(static_cast<Point<u>>(mTopLeft), static_cast<Size<u>>(mSize)); }

		Rect<t> operator+(Point<t> const & point) const { return Rect<t>(mTopLeft + point, mSize); }
		Rect<t> operator-(Point<t> const & point) const { return Rect<t>(mTopLeft - point, mSize); }
		bool operator==(Rect<t> const & rect) const { return mTopLeft == rect.mTopLeft && mSize == rect.mSize; }
		bool operator!=(Rect<t> const & rect) const { return mTopLeft != rect.mTopLeft || mSize != rect.mSize; }

		std::string toString() const { mTopLeft.toString() + sSeparator + mSize.toString(); }

		static std::string const & separator() { return sSeparator; }
		static void setFormat(std::string const & separator) { sSeparator = separator; }

	private:
		Point<t> mTopLeft;
		Size<t> mSize;
		static std::string sSeparator;
	};

	template <typename t> std::string Rect<t>::sSeparator("-");

	using RectReal = Rect<float>;
	using RectInt = Rect<int>;
}

#endif // RECT_H

