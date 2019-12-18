#include <iostream>
#include "Tube.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
/*
class Tube
		{
		public:
			Tube();
			Tube(Node* node1, Node* node2, double diameter);
			~Tube();
			double length() const;
			double permeability() const;
			const Node* node1() const;
			const Node* node2() const;

		private:
			//const double length_;
			//const double permeability_;
			double diameter_;
			const Node* node1_;
			const Node* node2_;

		};


		};*/

cie::pipenetwork::Tube::Tube():
	node1_(0),node2_(0),diameter_(0.0) //
{}

cie::pipenetwork::Tube::Tube(Node* node1, Node* node2, double diameter) :
	node1_(node1), node2_(node2), diameter_(diameter)
{}

cie::pipenetwork::Tube::~Tube()
{}

const cie::pipenetwork::Node* cie::pipenetwork::Tube::node1() const
{
	return node1_;
}

const cie::pipenetwork::Node* cie::pipenetwork::Tube::node2() const
{
	return node2_;
}

double cie::pipenetwork::Tube::permeability() const
{  
	double B;

	double pi = 3.14159265358979323846;

	B = pi * 9.81 * std::pow(diameter_, 4) / (128 * 1e-6 * length());
	// = pi * 9.81 * std::pow( 0.3, 4 ) / ( 128 * 1e-6 * 2.5 );

	return B;

}

double cie::pipenetwork::Tube::length() const
{
	double l;
	l = std::sqrt(std::pow((node1_->x() - node2_->x()), 2) + std::pow((node1_->y() - node2_->y()), 2));
	return l;
}