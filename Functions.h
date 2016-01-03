#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Types.h"

using namespace std;

vector <tPlayer> play(tPlayer a, tPlayer b);
vector <vector<int>> scores(int rounds);
vector <tPlayer> initialplayers(int aC, int aD, int tt, int t2, int et, int gt);
vector <tPlayer> tournament(vector <tPlayer> & players, vector <vector<int>> & score);
vector <tPlayer> reproduction(vector <tPlayer> & parents, int parameter);

void percentages(vector <tPlayer> & players, int p, vector <double> & percentageaC, vector <double> & percentageaD,
	vector <double> & percentagett, vector <double> & percentaget2, vector <double> & percentageet, vector <double> & percentagegt);
void results(vector <double> & percentageaC, vector <double> & percentageaD, vector <double> & percentagett, vector <double> & percentaget2, vector <double> & percentageet, vector <double> & percentagegt);

#endif

