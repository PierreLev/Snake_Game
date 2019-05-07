#ifndef POINT_H
#define POINT_H


#include <type_traits>
#include <string>
#include <charconv>
#include <random>

namespace bai {
	//! \brief Classe représentant un point 2d.
	template <typename t>
	class Point
	{
		static_assert(std::is_arithmetic<t>::value && !std::is_same<t, bool>::value, "Invalid template argument in Point : t must be arithmetic except bool");

	public:
		Point(t x = t{}, t y = t{}) : mX{ x }, mY{ y } {}
		~Point() = default;
		Point(Point const &) = default;
		Point& operator=(Point const &) = default;
		Point(Point &&) = default;
		Point& operator=(Point &&) = default;

		void setX(t x) { mX = x; }
		void setY(t y) { mY = y; }
		void set(t x, t y) { setX(x); setY(y); }
		t x() const { return mX; }
		t y() const { return mY; }

		void randomize(t minVal, t maxVal) { randomize(minVal, maxVal, minVal, maxVal); }
		void randomize(t minX, t maxX, t minY, t maxY);

		template <typename u> operator Point<u>() { return Point<u>(static_cast<u>(mX), static_cast<u>(mY)); }

		Point<t> operator-() const { return Point<t>(-mX, -mY); }
		Point<t> operator+(Point<t> const & p) const { return Point<t>(mX + p.mX, mY + p.mY); }
		Point<t> operator-(Point<t> const & p) const { return Point<t>(mX - p.mX, mY - p.mY); }
		Point<t> operator*(t value) const { return Point<t>(mX * value, mY * value); }
		Point<t> operator/(t value) const { return Point<t>(mX / value, mY / value); }
		friend Point<t> operator*(t value, Point<t> const & p) { return Point<t>(value * p.mX, value * p.mY); }
		friend Point<t> operator/(t value, Point<t> const & p) { return Point<t>(value / p.mX, value / p.mY); }

		bool operator==(Point<t> const & p) const { return mX == p.mX && mY == p.mY; }
		bool operator!=(Point<t> const & p) const { return mX != p.mX || mY != p.mY; }

		std::string toString() const;

		static std::string const & prefix() { return sPrefix; }
		static std::string const & separator() { return sSeparator; }
		static std::string const & suffix() { return sSuffix; }
		static void setFormat(std::string const & prefix, std::string const & separator, std::string const & suffix) { sPrefix = prefix; sSeparator = separator; sSuffix = suffix; }

	private:
		t mX, mY;
		static std::string sPrefix, sSeparator, sSuffix;
	};

	template <typename t> std::string Point<t>::sPrefix("(");
	template <typename t> std::string Point<t>::sSeparator(", ");
	template <typename t> std::string Point<t>::sSuffix(")");

	using PointReal = Point<float>;
	using PointInt = Point<int>;
















	template <typename t> void Point<t>::randomize(t minX, t maxX, t minY, t maxY) {
		static std::mt19937 randomEngine((std::random_device())());
		if constexpr (std::is_integral<t>::value) {
			mX = std::uniform_int_distribution<t>(minX, maxX)(randomEngine);
			mY = std::uniform_int_distribution<t>(minY, maxY)(randomEngine);
		} else {
			mX = std::uniform_real_distribution<t>(minX, maxX)(randomEngine);
			mY = std::uniform_real_distribution<t>(minY, maxY)(randomEngine);
		}
	}

	template <typename t> std::string Point<t>::toString() const {
		char x[1024]{}, y[1024]{};
		if constexpr (std::is_integral<t>::value) {
			std::to_chars(x, x + 1023, mX);
			std::to_chars(y, y + 1023, mY);
		} else {
			std::to_chars(x, x + 1023, mX, chars_format::fixed, 3);
			std::to_chars(y, y + 1023, mY, chars_format::fixed, 3);
		}
		return sPrefix + x + sSeparator + y + sSuffix;
	}
}

#endif // POINT_H

