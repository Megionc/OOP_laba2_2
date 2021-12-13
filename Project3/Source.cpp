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
		printf("����������� ��� ����������. ����� Circle\n");
		x = 0;
		y = 0;
		r = 0;
	}
	Circle(int x, int y, int r)
	{
		printf("����������� � �����������. ����� Circle\n");
		this->x = x;
		this->y = y;
		this->r = r;
	}
	Circle(const Circle& p)
	{
		printf("����������� � ����������-�������� ���� �� ������. ����� Circle\n");
		x = p.x;
		y = p.y;
		r = p.r;
	}
	~Circle()
	{
		printf("����������. ����� Circle\n");
		printf("%d, %d, %d\n", x, y, r);
	}

	
	//������� �������� ������ �������
	void changeRadius(int r)
	{
		this->r = r;
	}
	//������� ���������� �������� �������
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
		printf("����������� ��� ����������. ����� ColorCircle\n");
		color = 40;
	}
	ColorCircle(int x, int y, int r, int color):Circle(x,y,r)
	{
		printf("����������� � �����������. ����� ColorCircle\n");
		this->color = color;

	}
	ColorCircle(const ColorCircle& p):Circle(p)
	{
		printf("����������� � ����������-�������� ���� �� ������. ����� ColorCircle\n");
		color = p.color;

	}
	~ColorCircle()
	{
		printf("����������. ����� ColorCircle\n");
		printf("%d, %d, %d, %d \n", x, y, r, color);
	}
	//������� �������� ���� �������
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
		printf("����������� ��� ����������. ����� ModelGlasses\n");
		p1 = new Circle;
		p2 = new Circle;		
	}
	ModelGlasses(int x1, int x2 , int y1, int y2, int r1, int r2)
	{
		printf("����������� � �����������. ����� ModelGlasses\n");
		p1 = new Circle(x1,y1,r1);
		p2 = new Circle(x2,y2,r2);
	}
	ModelGlasses(const ModelGlasses& w)
	{
		printf("����������� � ����������-�������� ���� �� ������. ����� ModelGlasses\n");
		p1 = new Circle(*(w.p1));
		p2 = new Circle(*(w.p2));
	}
	~ModelGlasses()
	{
		printf("����������. ����� ModelGlasses\n");		
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
	printf("������: %d\n", a->r);

	a->resetRadius();
	printf("������: %d\n", a->r);


	printf("\n������������ �������� �������� ColorCircle: \n\n");
	// ������������ �������� �������� ColorCircle
	ColorCircle* d = new ColorCircle;
	ColorCircle* f = new ColorCircle(5, 4, 9, 3);
	ColorCircle* g = new ColorCircle(*f);

	delete d;
	delete f;
	delete g;

	//Circle* b = new ColorCircle;

	printf("\n������������ �������� �������� ModelGlasses: \n\n");

	ModelGlasses* q = new ModelGlasses;
	ModelGlasses* e = new ModelGlasses(6, 7, 8, 9, 0, 1);
	ModelGlasses* t = new ModelGlasses(*e); 

	return 0;
}

