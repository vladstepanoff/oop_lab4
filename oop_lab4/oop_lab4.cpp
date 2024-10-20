// oop_lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Parallelepiped.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int n, m;

	cout << "Введите кол-во прямоугольников: "; cin >> n;
	cout << "Введите кол-во параллелепипедов: "; cin >> m;

	vector<Rectangle<double>*> rects;
	vector<Parallelepiped<double>*> parpeds;

	cout << "\nВведите данные для прямоугольников (длина и ширина через пробел)" << endl;
	for (int i = 0; i < n; i++) {
		int a, b;
		cout << i + 1 << ": ";
		cin >> a >> b;
		Rectangle<double>* rect = new Rectangle<double>(a, b);
		rects.push_back(rect);
	}
	cout << "\nВведите данные для параллелепипедов (длина, ширина, высота через пробел)" << endl;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cout << i + 1 << ": ";
		cin >> a >> b >> c;
		Parallelepiped<double>* parped = new Parallelepiped<double>(a, b, c);
		parpeds.push_back(parped);
	}

	cout << "\nПрямоугольники" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ": ";
		rects[i]->display();
	}

	cout << "\nПараллелепипеды" << endl;
	for (int i = 0; i < m; i++) {
		cout << i + 1 << ": ";
		parpeds[i]->display();
	}

	double avg_rect_square = 0;
	for (int i = 0; i < n; i++) {
		avg_rect_square += rects[i]->area() / n;
	}
	cout << "\nСредняя площадь прямоугольников: " << avg_rect_square << endl;

	int larger_rects = 0;
	for (int i = 0; i < n; i++) {
		if (rects[i]->area() > avg_rect_square) {
			larger_rects++;
		}
	}
	cout << "Кол-во прямоугольник, с площадью больше средней: " << larger_rects << endl;

	int cubes_number = 0;
	for (int i = 0; i < m; i++) {
		if (parpeds[i]->get_length() == parpeds[i]->get_width() and parpeds[i]->get_width() == parpeds[i]->get_height()) {
			cubes_number++;
		}
	}
	cout << "Кол-во кубов: " << cubes_number << endl;

	for (int i = 0; i < rects.size(); i++) {
		delete rects[i];
	}
	for (int i = 0; i < parpeds.size(); i++) {
		delete parpeds[i];
	}

	return 0;
}
