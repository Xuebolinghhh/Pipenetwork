#include <Node.hpp>
/*
class Node
		{
		public:
			Node();
			Node(double x, double y, double flow, int id);
			~Node();
			double x() const;
			double y() const;
			double flow() const;
			int id() const;


		private:
			double x_;
			double y_;
			double flow_;
			int id_;
		};*/

cie::pipenetwork::Node::Node() :
	x_(0.0), y_(0.0), flow_(0.0), id_(0)
{};

cie::pipenetwork::Node::Node(double x, double y, double flow, int id) :
	x_(x), y_(y), flow_(flow), id_(id)
{};

cie::pipenetwork::Node::~Node() 
{};

double cie::pipenetwork::Node::x() const
{
	return x_;
}

double cie::pipenetwork::Node::y() const
{
	return y_;
}

double cie::pipenetwork::Node::flow() const
{
	return flow_;
}

int cie::pipenetwork::Node::id() const
{
	return id_;
}