#pragma once
#include <iostream>
#include <string>

class FunctionDraw
{
public:
	void(FunctionDraw::*callback_)() = nullptr;

	void exec()
	{
		if (callback_ != nullptr)
			(this->*callback_)();
		else
			std::cout << "Warning" << std::endl;
	}

	void drawaroundSquare()
	{
		std::cout << "Square::aroundDraw" << std::endl;
	}

	void drawaroundCircle()
	{
		std::cout << "Circle::aroundDraw" << std::endl;
	}

	FunctionDraw* decideShape(const std::string& name)
	{
		auto Shape = new FunctionDraw;

		if (name == "Circle")
		{
			Shape->callback_ = &FunctionDraw::drawaroundCircle;
		}

		else if (name == "Square")
		{
			Shape->callback_ = &FunctionDraw::drawaroundSquare;
		}

		return Shape;
	}
};