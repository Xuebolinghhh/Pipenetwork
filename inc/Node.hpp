#ifndef _NODE_HPP_
#define _NODE_HPP_

namespace cie
{
	namespace pipenetwork
	{
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
		};
	}
}

#endif