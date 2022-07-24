//
// Created by youssef albali on 02-Nov-21.
//

#include "population.h"

#include <utility>



population::population() {
	cout << "object created" << endl;
}



bool population::read_population_from_file(const string &filename) {
	ifstream inFile;
	inFile.open(filename);
	string line;
	vector<int> CHRS;
	if (inFile) {
		while (getline(inFile, line)) {

			if (!line.empty()) {
				std::istringstream iss(line);
				int tmp;
				while (iss >> tmp) {
					CHRS.push_back(tmp);
				}


				POPULATION.push_back(new individual(CHRS));
				CHRS.clear();
			}
		}
		inFile.close();
	} else {
		std::cout << "Failed to open input file: " << filename << "\n";
		return false;
	}

	return true;
}


int population::randomInteger(const int begin, const int end) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static default_random_engine gen(seed);
	std::uniform_int_distribution<int> distribution(begin, end);
	return distribution(gen);
}

void population::crossingover(int k) {

	std::vector<individual *> children;
	vector<int> tmp;



	for (int i = 0; i < k; i++) {

		int index1 = randomInteger(0, POPULATION.size() - 1);
		int chromosomes_divider_1 = randomInteger(1, POPULATION[index1]->chrs.size() - 1);

		tmp.insert(tmp.begin(), POPULATION[index1]->chrs.begin(),POPULATION[index1]->chrs.begin() + chromosomes_divider_1);

		int index2 = randomInteger(0, POPULATION.size() - 1);


		int chromosomes_divider_2 = randomInteger(1, POPULATION[index2]->chrs.size() - 1);

		tmp.insert(tmp.end(), POPULATION[index2]->chrs.begin() + chromosomes_divider_2, POPULATION[index2]->chrs.end());

		children.push_back(new individual(tmp));

		tmp.clear();

		tmp.insert(tmp.begin(), POPULATION[index2]->chrs.begin(),POPULATION[index2]->chrs.begin() + chromosomes_divider_2);
		tmp.insert(tmp.end(), POPULATION[index1]->chrs.begin() + chromosomes_divider_1, POPULATION[index1]->chrs.end());
		children.push_back(new individual(tmp));
		tmp.clear();

	}

	clear();


	POPULATION = std::move(children);

}


void population::fitnesscheckpopulation(double extinction_threshold, double proliferation_threshold) {
	int size = POPULATION.size();

	for (int i = size - 1; i >= 0; i--) {
		double f = POPULATION[i]->fitness_check();
		if (f < extinction_threshold) {
			POPULATION.erase(POPULATION.begin() + i);
		} else if (f > proliferation_threshold) {
			POPULATION.insert(POPULATION.end(), POPULATION[i]);
		}
	}
}


void population::writeToFile(const string& OutputFile) {
	ofstream OutFile;
	OutFile.open(OutputFile);
	if (OutFile) {
		for (auto &i: POPULATION) {
			OutFile << *i << endl;
		}
		OutFile.close();

	}

}


population::~population() {
	 clear();
}


















