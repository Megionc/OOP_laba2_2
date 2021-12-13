#include<iostream>
#include <list>

using namespace std;

class Circle
{
protected:
	int x, y;
public: 
	int r;
	Circle()
	{
		printf("Конструктор без параметров. Класс Circle\n");
		x = 0;
		y = 0;
		r = 0;
	}
	Circle(int x, int y, int r)
	{
		printf("Конструктор с параметрами. Класс Circle\n");
		this->x = x;
		this->y = y;
		this->r = r;
	}
	Circle(const Circle& p)
	{
		printf("Конструктор с параметром-объектом того же класса. Класс Circle\n");
		x = p.x;
		y = p.y;
		r = p.r;
	}
	~Circle()
	{
		printf("Деструктор. Класс Circle\n");
		printf("%d, %d, %d\n", x, y, r);
	}

	
	//функция изменяет радиус объекта
	void changeRadius(int r)
	{
		this->r = r;
	}
	//функция сбрасывает значение радиуса
	void resetRadius();
	
};

void Circle::resetRadius() {
	r = 0;
}


class ColorCircle: public Circle
{

public:
	int color;
	ColorCircle():Circle()
	{
		printf("Конструктор без параметров. Класс ColorCircle\n");
		color = 40;
	}
	ColorCircle(int x, int y, int r, int color):Circle(x,y,r)
	{
		printf("Конструктор с параметрами. Класс ColorCircle\n");
		this->color = color;

	}
	ColorCircle(const ColorCircle& p):Circle(p)
	{
		printf("Конструктор с параметром-объектом того же класса. Класс ColorCircle\n");
		color = p.color;

	}
	~ColorCircle()
	{
		printf("Деструктор. Класс ColorCircle\n");
		printf("%d, %d, %d, %d \n", x, y, r, color);
	}
	//функция изменяет цвет объекта
	void changeColor(int color)
	{
		this->color = color;
	}

	
};



class ModelGlasses
{
public:
	Circle* p1;
	Circle* p2;
	ModelGlasses()
	{
		printf("Конструктор без параметров. Класс ModelGlasses\n");
		p1 = new Circle;
		p2 = new Circle;		
	}
	ModelGlasses(int x1, int x2 , int y1, int y2, int r1, int r2)
	{
		printf("Конструктор с параметрами. Класс ModelGlasses\n");
		p1 = new Circle(x1,y1,r1);
		p2 = new Circle(x2,y2,r2);
	}
	ModelGlasses(const ModelGlasses& w)
	{
		printf("Конструктор с параметром-объектом того же класса. Класс ModelGlasses\n");
		p1 = new Circle(*(w.p1));
		p2 = new Circle(*(w.p2));
	}
	~ModelGlasses()
	{
		printf("Деструктор. Класс ModelGlasses\n");		
		delete p1;
		delete p2;
	}


};




int main()
{
	setlocale(LC_ALL, "RUS");

	Circle *a = new Circle(3,5,8);
	// printf ("%d\n", a->x);
	printf ("%d\n", a->r);
	a->changeRadius(11);
	printf("радиус: %d\n", a->r);

	a->resetRadius();
	printf("радиус: %d\n", a->r);


	printf("\nДинамическое создание объектов ColorCircle: \n\n");
	// динамическое создание объектов ColorCircle
	ColorCircle* d = new ColorCircle;
	ColorCircle* f = new ColorCircle(5, 4, 9, 3);
	ColorCircle* g = new ColorCircle(*f);

	delete d;
	delete f;
	delete g;

	//Circle* b = new ColorCircle;

	printf("\nДинамическое создание объектов ModelGlasses: \n\n");

	ModelGlasses* q = new ModelGlasses;
	ModelGlasses* e = new ModelGlasses(6, 7, 8, 9, 0, 1);
	ModelGlasses* t = new ModelGlasses(*e); 

	return 0;
}

