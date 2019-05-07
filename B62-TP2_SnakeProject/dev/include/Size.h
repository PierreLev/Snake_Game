#ifndef SIZE_H
#define SIZE_H


#include "Point.h"


namespace bai {

	//! \brief Classe représentant une taille rectangulaire en 2d.
	template <typename t>
	class Size
	{
		static_assert(std::is_arithmetic<t>::value && !std::is_same<t, bool>::value, "Invalid template argument in Size : t must be arithmetic except bool");

	public:
		Size(t width = 0, t height = 0) : mWidth{ width }, mHeight{ height } {}
		~Size() = default;
		Size(Size const &) = default;
		Size& operator=(Size const &) = default;
		Size(Size &&) = default;
		Size& operator=(Size &&) = default;

		void setWidth(t width) { mWidth = width; }
		void setHeight(t height) { mHeight = height; }
		void set(t width, t height) { setWidth(width); setHeight(height); }
		t width() const { return mWidth; }
		t height() const { return mHeight; }

		void randomize(t minVal, t maxVal) { randomize(minVal, maxVal, minVal, maxVal); }
		void randomize(size_t minWidth, size_t maxWidth, size_t minHeight, size_t maxHeight);

		Point<t> center() const { return Point<t>(mWidth / t{ 2 }, mHeight / t{ 2 }); }
		t perimeter() const { return t{ 2 } *(mWidth + mHeight); }
		t area() const { return mWidth * mHeight; }

		template <typename u> operator Size<u>() { return Size<u>(static_cast<u>(mWidth), static_cast<u>(mHeight)); }

		Size<t> operator-() const { return Size<t>(-mWidth, -mHeight); }
		Size<t> operator+(Size<t> const & s) const { return Size<t>(mWidth + s.mWidth, mHeight + s.mHeight); }
		Size<t> operator-(Size<t> const & s) const { return Size<t>(mWidth - s.mWidth, mHeight - s.mHeight); }
		Size<t> operator*(t value) const { return Size<t>(mWidth * value, mHeight * value); }
		Size<t> operator/(t value) const { return Size<t>(mWidth / value, mHeight / value); }
		friend Size<t> operator*(t value, Size<t> const & s) { return Size<t>(value * s.mWidth, value * s.mHeight); }
		friend Size<t> operator/(t value, Size<t> const & s) { return Size<t>(value / s.mWidth, value / s.mHeight); }

		bool operator==(Size<t> const & s) const { return mWidth == s.mWidth && mHeight == s.mHeight; }
		bool operator!=(Size<t> const & s) const { return mWidth != s.mWidth || mHeight != s.mHeight; }

		std::string toString() const;

		static std::string const & prefix() { return sPrefix; }
		static std::string const & separator() { return sSeparator; }
		static std::string const & suffix() { return sSuffix; }
		static void setFormat(std::string const & prefix, std::string const & separator, std::string const & suffix) { sPrefix = prefix; sSeparator = separator; sSuffix = suffix; }

	private:
		t mWidth, mHeight;
		static std::string sPrefix, sSeparator, sSuffix;
	};

	template <typename t> std::string Size<t>::sPrefix("[");
	template <typename t> std::string Size<t>::sSeparator(", ");
	template <typename t> std::string Size<t>::sSuffix("]");

	using SizeReal = Size<float>;
	using SizeInt = Size<int>;


















	template <typename t> void Size<t>::randomize(size_t minWidth, size_t maxWidth, size_t minHeight, size_t maxHeight) {
		static std::mt19937 randomEngine((std::random_device())());
		if constexpr (std::is_integral<t>::value) {
			mWidth = std::uniform_int_distribution<t>(minWidth, maxWidth)(randomEngine);
			mHeight = std::uniform_int_distribution<t>(minHeight, maxHeight)(randomEngine);
		} else {
			mWidth = std::uniform_real_distribution<t>(minWidth, maxWidth)(randomEngine);
			mHeight = std::uniform_real_distribution<t>(minHeight, maxHeight)(randomEngine);
		}
	}

	template <typename t> std::string Size<t>::toString() const {
		char x[1024]{}, y[1024]{};
		if constexpr (std::is_integral<t>::value) {
			std::to_chars(x, x + 1023, mWidth);
			std::to_chars(y, y + 1023, mHeight);
		} else {
			std::to_chars(x, x + 1023, mWidth, chars_format::fixed, 3);
			std::to_chars(y, y + 1023, mHeight, chars_format::fixed, 3);
		}
		return sPrefix + x + sSeparator + y + sSuffix;
	}
}

#endif // SIZE_H