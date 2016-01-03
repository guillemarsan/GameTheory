

#include "Functions.h"
#include "Types.h"
#include "Strategies.h"

vector <vector <int>> scores(int rounds) {

	vector <tPlayer> players(7);
	vector <vector <int>> scores(6, vector<int>(6));
	vector <tPlayer> result;

	players[0].type = taC;
	players[1].type = taD;
	players[2].type = ttt;
	players[3].type = tt2;
	players[4].type = tet;
	players[5].type = tgt;



	for (int n = 0; n <= 5; ++n) {
		for (int m = 0; m <= 5; ++m) {
			for (int r = 1; r <= rounds; ++r) {
				result = play(players[n], players[m]);
				players[n] = result[0];
				players[m] = result[1];
			}
			scores[n][m] = players[n].score;
			players[n].score = 0;
			players[m].score = 0;
		}
	}

	return scores;

}

vector <tPlayer> initialplayers(int aC, int aD, int tt, int t2, int et, int gt) {


	vector <tPlayer> players;
	tPlayer p;

	for (int a = 1; a <= aC; ++a) {

		p.type = taC;
		players.push_back(p);
	}

	for (int a = 1; a <= aD; ++a) {

		p.type = taD;
		players.push_back(p);
	}

	for (int a = 1; a <= tt; ++a) {

		p.type = ttt;
		players.push_back(p);
	}

	for (int a = 1; a <= t2; ++a) {

		p.type = tt2;
		players.push_back(p);
	}

	for (int a = 1; a <= et; ++a) {

		p.type = tet;
		players.push_back(p);
	}

	for (int a = 1; a <= aC; ++a) {

		p.type = tgt;
		players.push_back(p);
	}

	return players;

}

void percentages(vector <tPlayer> & players, int r, vector <double> & percentageaC, vector <double> & percentageaD,
	vector <double> & percentagett, vector <double> & percentaget2, vector <double> & percentageet, vector <double> & percentagegt) {
	double counteraC = 0, counteraD = 0, countertt = 0, countert2 = 0, counteret = 0, countergt = 0;
	int l = 0;
	tpersonality type;

	l = players.size();
	for (int a = 0; a < l; ++a) {
		type = players[a].type;

		switch (type) {
		case taC: ++counteraC; break;
		case taD: ++counteraD; break;
		case ttt: ++countertt; break;
		case tt2: ++countert2; break;
		case tet: ++counteret; break;
		case tgt: ++countergt; break;
		}
	}

	if (counteraC != 0) percentageaC.push_back(counteraC / l);
	else percentageaC.push_back(0);
	if (counteraD != 0) percentageaD.push_back(counteraD / l);
	else percentageaD.push_back(0);
	if (countertt != 0) percentagett.push_back(countertt / l);
	else percentagett.push_back(0);
	if (countert2 != 0) percentaget2.push_back(countert2 / l);
	else percentaget2.push_back(0);
	if (counteret != 0) percentageet.push_back(counteret / l);
	else percentageet.push_back(0);
	if (countergt != 0) percentagegt.push_back(countergt / l);
	else percentagegt.push_back(0);

}


void results(vector <double> & percentageaC, vector <double> & percentageaD,
	vector <double> & percentagett, vector <double> & percentaget2, vector <double> & percentageet, vector <double> & percentagegt) {
	double xaC = 0, saC = 0, xaD = 0, saD = 0, xtt = 0, stt = 0, xt2 = 0, st2 = 0, xet = 0, set = 0, xgt = 0, sgt = 0;
	double sumx = 0.0, sums = 0.0;

	for (int a = 0; a < percentageaC.size(); ++a)	sumx += percentageaC[a];
	xaC = sumx / 300;
	sumx = 0;

	for (int i = 0; i < percentageaC.size(); ++i) sums += ((percentageaC[i] - xaC) * (percentageaC[i] - xaC));
	saC = sqrt(sums) / (percentageaC.size() - 1);
	sums = 0;

	for (int a = 0; a < percentageaD.size(); ++a) sumx += percentageaD[a];
	xaD = sumx / 300;
	sumx = 0;

	for (int i = 0; i < percentageaD.size(); ++i) sums += ((percentageaD[i] - xaD) * (percentageaD[i] - xaD));
	saD = sqrt(sums) / (percentageaD.size() - 1);
	sums = 0;

	for (int a = 0; a < percentagett.size(); ++a)	sumx += percentagett[a];
	xtt = sumx / 300;
	sumx = 0;

	for (int i = 0; i < percentagett.size(); ++i) sums += ((percentagett[i] - xtt) * (percentagett[i] - xtt));
	stt = sqrt(sums) / (percentagett.size() - 1);
	sums = 0;

	for (int a = 0; a < percentaget2.size(); ++a)	sumx += percentaget2[a];
	xt2 = sumx / 300;
	sumx = 0;

	for (int i = 0; i < percentaget2.size(); ++i) sums += ((percentaget2[i] - xt2) * (percentaget2[i] - xt2));
	st2 = sqrt(sums) / (percentaget2.size() - 1);
	sums = 0;

	for (int a = 0; a < percentaget2.size(); ++a)	sumx += percentaget2[a];
	xet = sumx / 300;
	sumx = 0;

	for (int i = 0; i < percentageet.size(); ++i) sums += ((percentageet[i] - xet) * (percentageet[i] - xet));
	set = sqrt(sums) / (percentageet.size() - 1);
	sums = 0;

	for (int a = 0; a < percentagegt.size(); ++a)	sumx += percentagegt[a];
	xgt = sumx / 300;
	sumx = 0;

	for (int i = 0; i < percentagegt.size(); ++i) sums += ((percentagegt[i] - xgt) * (percentagegt[i] - xgt));
	sgt = sqrt(sums) / (percentagegt.size() - 1);
	sums = 0;

	ofstream data;
	data.open("results.txt");
	data << " xaC = " << xaC << " xaD = " << xaD << " xtt = " << xtt << " xt2 = " << xt2 << " xet = " << xet << " xgt = " << xgt << "\n";
	data << " saC = " << saC << " saD = " << saD << " stt = " << stt << " st2 = " << st2 << " set = " << set << " sgt = " << sgt << "\n";
	data.close();

}


vector <tPlayer> play(tPlayer a, tPlayer b) {
	tPlayer A, B;
	vector <tPlayer> newplayers(2);

	switch (a.type) {
	case taC: A = aC(a); break;
	case taD: A = aD(a); break;
	case ttt: A = tt(a); break;
	case tt2: A = t2(a); break;
	case tet: A = et(a); break;
	case tgt: A = gt(a); break;
	}

	switch (b.type) {
	case taC: B = aC(b); break;
	case taD: B = aD(b); break;
	case ttt: B = tt(b); break;
	case tt2: B = t2(b); break;
	case tet: B = et(b); break;
	case tgt: B = gt(b); break;
	}

	A.previous = B.movement;
	B.previous = A.movement;

	if (A.movement == "C" && B.movement == "C") {
		A.score = A.score + 3;
		B.score = B.score + 3;
	}
	else if (A.movement == "C" && B.movement == "D") {
		A.score = A.score + 0;
		B.score = B.score + 5;
	}
	else if (A.movement == "D" && B.movement == "C") {
		A.score = A.score + 5;
		B.score = B.score + 0;
	}
	else {
		A.score = A.score + 1;
		B.score = B.score + 1;
	}

	newplayers[0] = A;
	newplayers[1] = B;

	return newplayers;
}

vector <tPlayer> tournament(vector <tPlayer> & players, vector <vector <int>> & score) {
	int l = players.size(), f = 0, g = 0;
	vector <int> in;

	for (int m = 0; m < l; ++m) in.push_back(m);
	random_shuffle(in.begin(), in.end());

	if (l % 2 != 0) {
		in.pop_back();
		--l;
	}
	for (int i = 0; i < 10; ++i) {
		for (int n = 0; n < l; n += 2) {

			f = in[n];
			g = in[n + 1];


			players[f].score += score[int(players[f].type)][int(players[g].type)];
			players[g].score += score[int(players[g].type)][int(players[f].type)];
		}

	}

	return players;
}

vector <tPlayer> reproduction(vector <tPlayer> & parents, int parameter) {
	int birthsaux = 0, k = 0;
	vector <tPlayer> sons;
	tPlayer newson;
	vector <double> births;

	for (int a = 0; a < parents.size(); ++a) {
		births.push_back(round(parents[a].score / parameter));
	}

	for (int a = 0; a < births.size(); ++a) {
		birthsaux = births[a];
		for (int n = 0; n < birthsaux; ++n) {

			newson.previous = "I";
			newson.score = 0;
			newson.counter = 0;
			newson.movement = "I";
			newson.type = parents[a].type;

			sons.push_back(newson);
		}
	}

	return sons;

}


