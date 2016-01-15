
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
	
	int rounds = 20, aC = 20, aD = 20, tt = 20, t2 = 20, et = 20, gt = 20; //Initial playes. 
	int generations = 4; //Number of generations.
	int parameter = 300; //Parameter by which the points are going to be divided to calculate the offspring.

	score = scores(rounds); //The scores are calculated.
	for (int r = 0; r < 300; ++r) {
		//The experiment is done 300 times to get the average.

		players = initialplayers(aC, aD, tt, t2, et, gt); //Initialize players.
		for (int n = 1; n <= generations; ++n) {
			
			players = tournament(players, score); //They are matched, they play 10 rounds and gain utilities.
			players = reproduction(players, parameter); //They reproduce. The offspring is the new player matrix.
			
		}
		//The percentages are calculated.
		percentages(players, r, percentageaC, percentageaD, percentagett, percentaget2, percentageet, percentagegt);

	}
	
	//The results are writen in results.txt :  the average of the percentages and their standard deviation.
	results(percentageaC, percentageaD, percentagett, percentaget2, percentageet, percentagegt);
	
	return 0;

}

