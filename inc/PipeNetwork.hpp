#ifndef _PIPENETWORK_HPP_
#define _PIPENETWORK_HPP_

#include <iostream>
#include <vector>
#include "Tube.hpp"
#include "Node.hpp"
#include "linalg.hpp"

namespace cie
{
	namespace pipenetwork
	{

		class PipeNetwork
		{
		public:
			PipeNetwork(const std::string& filename);
			~PipeNetwork();

			

			std::vector<double> computeFluxes() const;

		private:
			std::vector<Node> nodes_;
			std::vector<Tube> tubes_;
			int numberOfNodes_;
			int numberOfTubes_;



		};
	};
}

#endif