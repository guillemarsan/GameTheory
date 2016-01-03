
#include <cmath>
#include <ctime>

#include "Types.h"
#include "Functions.h"
#include "Strategies.h"

using namespace std;



int main() {
	vector <tPlayer> players;
	vector <vector<int>> score;
	vector <double> percentageaC, percentageaD, percentagett, percentaget2, percentageet, percentagegt;
	int rounds = 20, aC = 20, aD = 20, tt = 20, t2 = 20, et = 20, gt = 20;
	int generations = 4;
	int parameter = 300;

	score = scores(rounds);
	time_t tstart, tend;
	tstart = time(0);
	for (int r = 0; r < 300; ++r) {

		players = initialplayers(aC, aD, tt, t2, et, gt);
		for (int n = 1; n <= generations; ++n) {
			
			players = tournament(players, score);
			players = reproduction(players, parameter);
			
		}
		percentages(players, r, percentageaC, percentageaD, percentagett, percentaget2, percentageet, percentagegt);

	}
	tend = time(0);
	cout << "It took " << difftime(tend, tstart) << " second(s)." << endl;

	results(percentageaC, percentageaD, percentagett, percentaget2, percentageet, percentagegt);
	
	return 0;

}

