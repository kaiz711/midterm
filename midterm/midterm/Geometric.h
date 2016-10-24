#pragma once
#include <iostream>
#include <string>

class GeometricObject
{
public:
	GeometricObject* GeometricObject::getGeometricObject(const std::string& name);

	virtual void draw()
	{
		std::cout << "Mother" << std::endl;
	}
};