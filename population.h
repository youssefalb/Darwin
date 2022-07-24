//
// Created by youssef albali on 02-Nov-21.
//

#ifndef DARWIN_PROJECT_POPULATION_H
#define DARWIN_PROJECT_POPULATION_H

#include "individual.h"

/**
 * Class of population.
 * Contains vector of individuals.
 */

class population{
	std::vector<individual *> POPULATION{}; /**< Vector of individuals */


public:

	/**
* Default constructor
*/
	population();
	/**
* Boolean Function that reads individuals from the file and assign them to POPULATION vector
* @param filename Input file name
*/

	bool read_population_from_file(const string& filename);


	/**
* Function that crosses over pairs of individual
* @param k Number of pairs
*/
	void crossingover(int k);

	/**
* Function that does the fitness check of population after the crossing_over.
* @param extinction_threshold Extinction threshold "w"
	 * @param proliferation_threshold Proliferation threshold "r"
*/

	void fitnesscheckpopulation(double extinction_threshold, double proliferation_threshold);

	/**
* Function that writes the individuals to the file.
* @param OutputFIle Output file name
*/

	void writeToFile(const std::string& OutputFIle);

	/**
* Function that generates a random variable depending on the range
* @param begin beginning of the range
 * @param end The end of the range
*/

	static int randomInteger(int begin, int end);

	/**
 * Default destructor of the class population.
 * Clearing memory.
 */
	~population();

	void clear(){
		for (auto &x: POPULATION) {
			delete x;
		}}
};

#endif //DARWIN_PROJECT_POPULATION_H
