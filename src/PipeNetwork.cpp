#include <iostream>

#include <fstream>
#include <vector>
#include "PipeNetwork.hpp"

cie::pipenetwork::PipeNetwork::PipeNetwork(const std::string& filename)
{
	std::ifstream infile(filename);
	//std::ifstream infile;
	//infile.open("C:\\Users\\lingx\\OneDrive - Business\\c++\\Hausaufgabe\\Pipenetwor2019\\pipedata.txt");
	
	

	infile >> numberOfNodes_;
	infile >> numberOfTubes_;

	nodes_.reserve(numberOfNodes_);
	tubes_.reserve(numberOfTubes_);

	while (!infile.eof())
	{
		for (int i = 0; i < numberOfNodes_;i++)
		{
			double x, y, flow;
			infile >> x >> y >> flow;

			Node node(x, y, flow, i);

			nodes_.push_back(node);
		}

		
		for (int i = 0; i < numberOfTubes_;i++)
		{
			int id1, id2;
			double diameter;
			infile >> id1 >> id2 >> diameter;
			
			Tube tube(&nodes_[id1], &nodes_[id2], diameter);
			tubes_.push_back(tube);
		}
		break;
	}

	
}

std::vector<double> cie::pipenetwork::PipeNetwork::computeFluxes() const
{

	linalg::Matrix Matrix_B(numberOfNodes_,numberOfNodes_,0.0);  //create zero-initialized permeability matrix B
	

	for (size_t i = 0; i < numberOfTubes_;i++)
	{
		int id1 = tubes_[i].node1()->id();
		int id2 = tubes_[i].node2()->id();

		Matrix_B(id1,id1) += tubes_[i].permeability();
		Matrix_B(id2, id2) += tubes_[i].permeability();
		Matrix_B(id1,id2) -= tubes_[i].permeability();
		Matrix_B(id2,id1) -= tubes_[i].permeability();
	}
	
	cie::linalg::Vector Q;
	Q.reserve(numberOfNodes_);
	for (size_t i = 0; i < numberOfNodes_; i++)
	{
		Q.push_back(-1*nodes_[i].flow());
	}

	for (size_t i = 0; i < numberOfNodes_; i++)
	{
		Matrix_B(i, 0) = 0;
		Matrix_B(0, i) = 0;
	}

	Matrix_B(0, 0) = 1;
	Q[0] = 0;

	cie::linalg::Vector h;

	h = solve(Matrix_B, Q);

	cie::linalg::Vector q(numberOfTubes_,0);

	for (size_t i = 0; i < numberOfTubes_;i++)
	{
		int id1 = tubes_[i].node1()->id();
		int id2 = tubes_[i].node2()->id();
		q[i] = tubes_[i].permeability() * (h[id1] - h[id2]);
	}



	return q;
}

cie::pipenetwork::PipeNetwork::~PipeNetwork()
{}

