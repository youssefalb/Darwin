//
// Created by youssef albali on 21-Oct-21.
//

#ifndef DARWIN_PROJECT_INDIVIDUAL_H
#define DARWIN_PROJECT_INDIVIDUAL_H



#include <iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include<chrono>
#include<random>
#include <algorithm>

using namespace std;

class individual {



public:
	vector<int> chrs;/**< Vector of chromosomes for each individual  */

	/**
 * Constructor that assigns chromosomes to individuals .
 * @param inds individuals
 */

	explicit individual(vector<int> &_chrs);

	/**
* Function that does the fitness check for each individuals
*/
	double fitness_check();

	/**
* output overload operator
* @param ostream
* @param individual object
*/
	friend ostream &operator<<(ostream &os, const individual& ind);
	~individual()=default;
};


#endif //DARWIN_PROJECT_INDIVIDUAL_H
