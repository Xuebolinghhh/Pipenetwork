#include <iostream>
#include <vector>
#include <fstream> //std::ifstream
//#include "PipeNetwork.hpp"
#include "Node.hpp"
#include "Tube.hpp"
#include <vector>

int main()
{

	/*cie::pipenetwork::PipeNetwork pipenetwork("pipedata.txt");

	pipenetwork.print();*/


	std::ifstream infile("pipedata.txt");
	/*std::ifstream infile;
	infile.open("C:\\Users\\lingx\\OneDrive - Business\\c++\\Hausaufgabe\\Pipenetwor2019\\pipedata.txt");
*/
	int numberOfNodes;
	int numberOfTubes;

	infile >> numberOfNodes;
	infile >> numberOfTubes;

	std::cout << "numberOfNodes" << numberOfNodes;
	std::cout << "numberOfTubes" << numberOfTubes;
 
	std::vector<cie::pipenetwork::Node> nodes;
	std::vector<cie::pipenetwork::Tube> tubes;
	nodes.resize(numberOfNodes);
	tubes.resize(numberOfTubes);

	while (!infile.eof())
	{
		for (int i = 0; i < numberOfNodes;i++)
		{
			double x(0.0), y(0.0), flow(0.0);
			infile >> x >> y >> flow;

			cie::pipenetwork::Node node(x, y, flow, i);

			nodes[i] = node;
		}


		for (int i = 0; i < numberOfTubes;i++)
		{
			int id1(0), id2(0);
			double diameter(0.0);
			infile >> id1 >> id2 >> diameter;

			cie::pipenetwork::Tube tube(&nodes[id1], &nodes[id2], diameter);
			tubes.push_back(tube);
		}
	}


	//std::ifstream infile;
	//infile.open("C:\\Users\\lingx\\OneDrive - Business\\c++\\Hausaufgabe\\Pipenetwor2019\\pipedata.txt");
	//std::ifstream infile("pipedata.txt");
	//
	//if (infile)
	//{
	//	std::cout << "file opens sucessfully" << std::endl;
	//}

	//int numberOfValues = 59;
	//std::vector<double> data;
	//data.reserve(numberOfValues);

	//for (int i = 0; i < numberOfValues; ++i)
	//{
	//	double value;
	//	infile >> value;

	//	data.push_back(value);
	//	std::cout << data[i]<<' ';
	//}

	//infile.close();

	//int numberOfNodes = data[0];
	//int numberOfTubes = data[1];

	//std::cout << "numberOfNodes is: " << numberOfNodes << std::endl;
	//std::cout << "numberOfTubes is: " << numberOfTubes << std::endl;

	//std::vector<double> x_node;
	//x_node.reserve(numberOfNodes);

	//std::vector<double> y_node;
	//y_node.reserve(numberOfNodes);

	//std::vector<double> Volume;
	//Volume.reserve(numberOfNodes); // reserve 后面 用 push_back 添加

	//for (size_t i = 0; i < numberOfNodes; ++i)
	//{
	//	x_node.push_back(data[i*3+2]);
	//	y_node.push_back(data[i*3+3]);
	//	Volume.push_back(data[i*3+4]);
	//}

	////print out the coordinate of Nodes and its volume
	//for (size_t i = 0; i < numberOfNodes; ++i)
	//{
	//	std::cout << "[" << x_node[i] << "," << y_node[i] << "," << Volume[i] << "] ";
	//}
	//std::cout << std::endl;

	//std::vector<int> begin_nodeIdOfTube;
	//begin_nodeIdOfTube.reserve(numberOfTubes);

	//std::vector<int> end_nodeIdOfTube;
	//end_nodeIdOfTube.reserve(numberOfTubes);

	//std::vector<double> diameter;
	//diameter.reserve(numberOfTubes);

	//for (size_t i = 0; i < numberOfTubes; ++i)
	//{
	//	begin_nodeIdOfTube.push_back(data[i * 3 + 2+3 * numberOfNodes]);
	//    end_nodeIdOfTube.push_back(data[i * 3 +3+3 * numberOfNodes]);
	//	diameter.push_back(data[i * 3 + 4+3 * numberOfNodes]);
	//}
	//

	//
	////print out the corresponding nodes of the tubes
	//for (size_t i = 0; i < numberOfTubes; ++i)
	//{
	//	std::cout << "[" << begin_nodeIdOfTube[i] << "-->" << end_nodeIdOfTube[i] << "] with diameter" << diameter[i] << "[m]" << std::endl;
	//}

	system("pause");
	return 0;
}

