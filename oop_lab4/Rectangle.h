#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

template <typename T>
class Rectangle
{
protected:
	T length;
	T width;

public:
	Rectangle(T length, T width);
	T perimeter();
	T area();
	void display();
	T get_length();
	T get_width();
};

template <typename T>
Rectangle<T>::Rectangle(T length, T width)
{
	this->length = length;
	this->width = width;
}

template <typename T>
T Rectangle<T>::perimeter()
{
	return 2 * (width + length);
}

template <typename T>
T Rectangle<T>::area()
{
	return width * length;
}

template <typename T>
void Rectangle<T>::display()
{
	std::cout << "Длина: " << length << ", ширина: " << width << ", периметр: " << perimeter() << ", площадь: " << area() << std::endl;
}

template<typename T>
T Rectangle<T>::get_length()
{
	return length;
}

template<typename T>
T Rectangle<T>::get_width()
{
	return width;
}
