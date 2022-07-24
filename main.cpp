#include"population.h"
#include<memory>

void printHelpMessage() {
	std::cout << "Please provide these arguments: \n"
				 "-i input file with a population\n"
				 "-o output file with a population\n"
				 "-w extinction threshold w ∈ [0, 1]\n"
				 "-r proliferation threshold r ∈ [0, 1]\n"
				 "-p number of generations p  \n"
				 "-k number k of pair to cross-over\n";
}



int main(int argc, char *argv[]) {


	if (argc < 13) {
		printHelpMessage();
		return 0;
	}


	string input_filename, output_filename;
	int GENERATIONS, NUMBER_OF_PAIRS;
	double EXTINCTION_THRESHOLD, PROLIFERATION_THRESHOLD;
	while ((++argv)[0]) {
		if (**argv == '-') {
			switch ((*argv)[1]) {

				default:
					printHelpMessage();
					break;
				case 'i':
					*argv++;
					input_filename = *argv;
					cout << "Input Filename: " << input_filename  << endl;
					break;
				case 'o':
					*argv++;
					output_filename = *argv;
					cout << "output  Filename: " << output_filename << endl;
					break;
				case 'w':
					*argv++;
					EXTINCTION_THRESHOLD = stod(*argv);
					cout << "W : " << EXTINCTION_THRESHOLD << "\n";

					break;
				case 'r':
					*argv++;
					PROLIFERATION_THRESHOLD = stod(*argv);
					cout << "R : " << PROLIFERATION_THRESHOLD << "\n";
					break;
				case 'p':
					*argv++;
					GENERATIONS = stoi(*argv);
					cout << "P : " << GENERATIONS << "\n";
					break;
				case 'k':
					*argv++;
					NUMBER_OF_PAIRS = stoi(*argv);
					cout << "K : " << NUMBER_OF_PAIRS << "\n";
					break;
			}
		}

		//printf("\n outside while : %s", *argv);

	}




	population _population;
	bool Read_FIle=_population.read_population_from_file(input_filename);

	if (!Read_FIle){return 0;}




	for (int i = 0; i <= GENERATIONS; i++) {
		_population.crossingover(NUMBER_OF_PAIRS);
		_population.fitnesscheckpopulation(EXTINCTION_THRESHOLD, PROLIFERATION_THRESHOLD);
	}



	_population.writeToFile(output_filename);


}









