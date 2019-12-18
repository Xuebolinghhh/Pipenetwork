#ifndef _TUBE_HPP_
#define _TUBE_HPP_
#include "Node.hpp"

namespace cie
{
	namespace pipenetwork
	{
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
	}
}

#endif