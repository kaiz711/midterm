#include "Box.h"
#include "Circle.h"
#include "Geometric.h"
#include "FunctionDraw.h"
#include <vector>

using namespace std;

template<class T_CLASS> // Problem 1
void print(const T_CLASS& i)
{
	cout << i << endl;
}

template<class T_A> // Problem 2
class Vector2D
{
public:
	T_A x, y;

	void draw()
	{
		cout << x << endl;
		cout << y << endl;
	}
};

template<class T>
class Geometric : public GeometricObject
{
public:
	void draw()
	{
		T drawShape;
		drawShape.draw();
	}
};

int main()
{
	vector<GeometricObject*> ob_list;

	GeometricObject ob;

	ob_list.push_back(new GeometricObject);
	ob_list.push_back(new Box);
	ob_list.push_back(new Circle);
	ob_list.push_back(ob.getGeometricObject("Box"));
	ob_list.push_back(ob.getGeometricObject("Circle"));

	for (auto itr : ob_list)
		itr->draw();

	for (auto itr : ob_list)
		delete itr;

	FunctionDraw my_function;

	vector<FunctionDraw*> draw_list;

	draw_list.push_back(my_function.decideShape("Square"));
	draw_list.push_back(my_function.decideShape("Circle"));
	draw_list.push_back(my_function.decideShape("circle"));

	for (auto itr : draw_list)
	{
		itr->exec();
	}

	for (auto itr : draw_list)
	{
		delete itr;
	}

	print(1);
	print(2.345f);
	print("Hello World");

	Vector2D<int> ex_vector;		// VectorInt2D
	Vector2D<float> ex_vector2;		// VectorFloat2D
	Vector2D<double> ex_vector3;	// VectorDouble2D

	ex_vector.x = 1;
	ex_vector.y = 2;
	ex_vector.draw();

	ex_vector2.x = 3.33f;
	ex_vector2.y = 4.44f;
	ex_vector2.draw();

	ex_vector3.x = 5.5555;
	ex_vector3.y = 6.6666;
	ex_vector3.draw();

	std::vector<GeometricObject*> obj_list;

	obj_list.push_back(new Geometric<Box>);
	obj_list.push_back(new Geometric<Circle>);
	obj_list.push_back(new Geometric<GeometricObject>);
	obj_list.push_back(new Geometric<GeometricObject>);
	obj_list.push_back(new Geometric<GeometricObject>);
	obj_list.push_back(new Geometric<GeometricObject>);
	obj_list.push_back(new Geometric<GeometricObject>);

	for (auto itr : obj_list)
		itr->draw();

	for (auto itr : obj_list)
		delete itr;

	GeometricObject *my_geo = new GeometricObject;
	my_geo->draw();

	GeometricObject *my_box = new Box;
	my_box->draw();

	GeometricObject **geo_list = new GeometricObject*[10];

	for (int i = 0; i < 10; i++)
	{
		geo_list[i] = new Box;
		geo_list[i]->draw();
		geo_list[i] = new Circle;
		geo_list[i]->draw();
	}

	delete[] geo_list;

	return 0;
}

//struct Vector2D
//{
//	int x;
//	int y;
//
//	void print()
//	{
//		printf("%d %d", x, y);
//	}
//};
//
//std::ostream &operator << (std::ostream &stream, Vector2D obj)
//{
//	stream << obj.x << " " << obj.y;
//
//	return stream;
//}
//
//void main()
//{
//	Vector2D my_vector;
//
//	my_vector.x = 1;
//	my_vector.y = 2;
//
//	my_vector.print();
//
//	using namespace std;
//
//	std::cout << my_vector << std::endl;
//
//	ofstream ofile("cppstyle.txt");
//	ofile << my_vector << endl;
//}