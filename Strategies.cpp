
#include "Types.h"


tPlayer aC(tPlayer oldplayer) {
	tPlayer newplayer;

	newplayer.movement = "C";
	newplayer.score = oldplayer.score;
	newplayer.counter = oldplayer.counter;
	newplayer.previous = "I";
	newplayer.type = oldplayer.type;

	return newplayer;

}

tPlayer aD(tPlayer oldplayer) {
	tPlayer newplayer;

	newplayer.movement = "D";
	newplayer.score = oldplayer.score;
	newplayer.counter = oldplayer.counter;
	newplayer.previous = "I";
	newplayer.type = oldplayer.type;

	return newplayer;
}

tPlayer tt(tPlayer oldplayer) {
	tPlayer newplayer;

	if (oldplayer.previous == "I") {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = oldplayer.counter;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else {
		newplayer.movement = oldplayer.previous;
		newplayer.score = oldplayer.score;
		newplayer.counter = oldplayer.counter;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}

	return newplayer;
}

tPlayer t2(tPlayer oldplayer) {
	tPlayer newplayer;

	if (oldplayer.previous == "I") {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = 0;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else if (oldplayer.previous == "D" && (oldplayer.counter % 2) == 0) {
		newplayer.movement = "D";
		newplayer.score = oldplayer.score;
		newplayer.counter = (oldplayer.counter + 1);
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else if (oldplayer.previous == "D" && (oldplayer.counter % 2) == 1) {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = (oldplayer.counter + 1);
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = 0;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}

	return newplayer;

}

tPlayer et(tPlayer oldplayer) {
	tPlayer newplayer;

	if (oldplayer.previous == "I") {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = 0;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else if (oldplayer.previous == "C" && (oldplayer.counter % 3) == 0 && oldplayer.counter != 0) {
		newplayer.movement = "D";
		newplayer.score = oldplayer.score;
		newplayer.counter = oldplayer.counter;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else if (oldplayer.previous == "C" && ((oldplayer.counter % 3) != 0 || oldplayer.counter == 0)) {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.previous = "I";
		newplayer.counter = (oldplayer.counter + 1);
		newplayer.type = oldplayer.type;
	}
	else {
		newplayer.movement = "D";
		newplayer.score = oldplayer.score;
		newplayer.counter = 0;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}

	return newplayer;

}

tPlayer gt(tPlayer oldplayer) {
	tPlayer newplayer;


	if (oldplayer.previous == "I") {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = 0;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else if (oldplayer.previous == "D" && (oldplayer.counter % 3) == 0 && oldplayer.counter != 0) {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = (oldplayer.counter + 1);
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}
	else if (oldplayer.previous == "D" && ((oldplayer.counter % 3) != 0 || oldplayer.counter == 0)) {
		newplayer.movement = "D";
		newplayer.score = oldplayer.score;
		newplayer.previous = "I";
		newplayer.counter = (oldplayer.counter + 1);
		newplayer.type = oldplayer.type;
	}
	else {
		newplayer.movement = "C";
		newplayer.score = oldplayer.score;
		newplayer.counter = 0;
		newplayer.previous = "I";
		newplayer.type = oldplayer.type;
	}

	return newplayer;

}