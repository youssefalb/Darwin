//
// Created by youssef albali on 21-Oct-21.
//

#include "individual.h"


ostream &operator<<(ostream &os, const individual& ind) {

	for (auto &chr: ind.chrs) {
		os << chr <<" ";
	}
	return os;
}


individual::individual(vector<int> &_chrs) {

	chrs=_chrs;

}

double individual::fitness_check() {
	double pts=0;
	for (auto &chr : chrs) {
		if (chr % 2 == 0) {
			pts += 1;
		}

	}

	return (pts/chrs.size());
}


