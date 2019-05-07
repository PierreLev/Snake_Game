#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
public:
	using coordinate_t = int;
	
	Coordinates() = default;
	Coordinates(coordinate_t x, coordinate_t y);
	Coordinates(bool valid);
	Coordinates(coordinate_t x, coordinate_t y, bool valid);
	~Coordinates() = default;

	coordinate_t getX();
	coordinate_t getY();

	bool isValid();

	void setX(coordinate_t x);
	void setY(coordinate_t y);
	void setCoords(coordinate_t x, coordinate_t y);
	void setValid(bool valid);

private:
	coordinate_t mX = 0;
	coordinate_t mY = 0;
	bool mValid = false;
};


#endif // !COORDINATES_H