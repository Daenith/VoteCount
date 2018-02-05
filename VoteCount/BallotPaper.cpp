#include "stdafx.h"
#include "BallotPaper.h"


BallotPaper::BallotPaper() {
}


BallotPaper::~BallotPaper() {
}

void BallotPaper::setPreference(Candidate *c, int n) {
	candidates[n] = *c;
}

Candidate *BallotPaper::getPreference(int n) {
	Candidate *temp = &candidates[n];
	return temp;
}

void BallotPaper::addCandidate(Candidate cand, int pref) {
	candidates[pref] = cand;
}

void BallotPaper::printBallotPaper() {
	std::map<int, Candidate>::iterator iterCand = candidates.begin();

	for (iterCand = candidates.begin(); iterCand != candidates.end(); iterCand++) {
		std::cout << iterCand->first << ":\t" << iterCand->second.getName() << std::endl;
	}
}
