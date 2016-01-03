#ifndef TYPES_H
#define TYPES_H

#include <string>
 
using namespace std;

enum tpersonality { taC, taD, ttt, tt2, tet, tgt };

struct tPlayer {

	int score = 0, counter = 0;
	string previous = "I", movement = "I";
	tpersonality type;

};

#endif



