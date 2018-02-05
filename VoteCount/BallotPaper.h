#pragma once
#include <map>
#include <algorithm>
#include <iostream>
#include "Candidate.h"

class BallotPaper {
private:
	std::map <int, Candidate>candidates;
public:
	BallotPaper();
	~BallotPaper();
	void setPreference(Candidate *c, int n);
	Candidate *getPreference(int n);
	void addCandidate(Candidate cand, int pref);
	void printBallotPaper();
};

