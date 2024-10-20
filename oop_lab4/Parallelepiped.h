#pragma once
#include "Rectangle.h"

template <typename T>
class Parallelepiped :public Rectangle<T>
{
private:
	T height;

public:
	Parallelepiped(T length, T width, T height);
	T volume();
	void display();
	T get_height();
};

template <typename T>
Parallelepiped<T>::Parallelepiped(T length, T width, T height) : Rectangle<T>(length, width)
{
	this->height = height;
}

template <typename T>
T Parallelepiped<T>::volume()
{
	return this->area() * height;
}

template <typename T>
void Parallelepiped<T>::display()
{
	std::cout << "Длина осн: " << this->length << ", ширина осн: " << this->width << ", высота: " << height << ", объем: " << volume() << std::endl;
}

template<typename T>
T Parallelepiped<T>::get_height()
{
	return height;
}
