// VoteCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BallotPaper.h"
#include "VoteCounter.h"


int main() {
	/*BallotPaper *paper = new BallotPaper();*/

	VoteCounter *vc = new VoteCounter();
	vc->getWinner();

	/*paper->addCandidate(*new Candidate("Hans", "SPD"), 3);
	paper->addCandidate(*new Candidate("Sara", "Linke"), 2);
	paper->addCandidate(*new Candidate("Heidi", "Grüne"), 1);

	paper->printBallotPaper();

	paper->setPreference(new Candidate("Ludwig", "CDU"), 4);
	paper->setPreference(new Candidate("Fabian", "CSU"), 1);

	paper->printBallotPaper();*/

	system("pause");
	return 0;
}

