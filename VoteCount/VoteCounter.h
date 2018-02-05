#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "BallotPaper.h"

class VoteCounter {
private:
	std::vector <BallotPaper> papers;
	std::vector <Candidate> candidates;
	std::map <int, int> count;
public:
	VoteCounter();
	~VoteCounter();
	void addBallotPaper(BallotPaper paper);
	Candidate *getWinner();
	unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch);
	void readInFile();
};

