#include <iostream>
#include <vector>
#include <fstream> //std::ifstream
//#include "PipeNetwork.hpp"
#include "Node.hpp"
#include "Tube.hpp"
#include <vector>
#include "PipeNetwork.hpp"

int main()
{

	/*cie::pipenetwork::PipeNetwork pipenetwork("pipedata.txt");

	pipenetwork.print();*/


	
	/*std::ifstream infile;
	infile.open("C:\\Users\\lingx\\OneDrive - Business\\c++\\Hausaufgabe\\Pipenetwor2019\\pipedata.txt");
*/
	
	cie::pipenetwork::PipeNetwork file("pipedata.txt");

	std::vector<double> output = file.computeFluxes();

	std::cout << "the fluxes of the pipenetwork is" << std::endl;

	for (size_t i = 0; i < output.size();++i)
	{
		std::cout << output[i] << std::endl;
	}


	system("pause");
	return 0;
}

