#include "stdafx.h"
#include "VoteCounter.h"


VoteCounter::VoteCounter() {
	std::vector<Candidate>::iterator iterCand;

	// read in ballot papers from file
	readInFile();

	//initialize vote count for every candidate to 0
	for (iterCand = candidates.begin(); iterCand != candidates.end(); iterCand++) {
		count[iterCand - candidates.begin() + 1] = 0;
	}
}


VoteCounter::~VoteCounter() {

}

void VoteCounter::addBallotPaper(BallotPaper paper) {
	papers.push_back(paper);
}

void VoteCounter::readInFile() {
	int linecount = 0;
	std::vector <std::string> candTemp;
	std::vector <std::string> partyTemp;
	std::vector <std::string> prefTemp;

	std::vector<std::string>::iterator iterCanTemp;
	std::vector<std::string>::iterator iterPartyTemp;
	std::vector<std::string>::iterator iterPrefTemp;
	std::vector<Candidate>::iterator iterCandTemp;
	std::vector<BallotPaper>::iterator iterBall;

	std::string line;
	std::ifstream file;

	// open input file
	file.open("input.txt");

	// reading one line at a time and depending on line number add candidate or add ballot paper
	if (file.is_open()) {
		while (getline(file, line)) {
			switch (linecount) {
			case 0:				// candidates names
				split(line, candTemp, ' ');
				linecount++;
				break;
			case 1:				// candidates parties
				split(line, partyTemp, ' ');
				iterCanTemp = candTemp.begin();
				iterPartyTemp = partyTemp.begin();
				for (iterCanTemp = candTemp.begin(); iterCanTemp != candTemp.end(); iterCanTemp++, iterPartyTemp++) {
					candidates.push_back(*new Candidate(*iterCanTemp, *iterPartyTemp));
				}
				linecount++;
				break;
			default:			// ballot papers
				split(line, prefTemp, ' ');
				iterPrefTemp = prefTemp.begin();
				iterCandTemp = candidates.begin();
				BallotPaper *temp = new BallotPaper();
				for (iterCandTemp = candidates.begin(); iterCandTemp != candidates.end(); iterCandTemp++, iterPrefTemp++) {
					temp->addCandidate(*iterCandTemp, std::stoi(*iterPrefTemp, nullptr, 0));
				}
				papers.push_back(*temp);
				linecount++;
			}
		}
		file.close();
	}
}

Candidate *VoteCounter::getWinner() {
	std::vector<BallotPaper>::iterator iterBall;
	std::vector<Candidate>::iterator iterCand;
	std::map<int, int>::iterator iterCount;
	std::map<int, int>::iterator min;

	// write all number 1 votes to count
	for (iterBall = papers.begin(); iterBall != papers.end(); iterBall++) {
		for (iterCand = candidates.begin(); iterCand != candidates.end(); iterCand++) {
			if (iterBall->getPreference(1)->isEqual(*iterCand)) {
				count[iterCand - candidates.begin() + 1]++;
			}
		}
	}

	// print vote count with all number 1 votes
	for (iterCount = count.begin(); iterCount != count.end(); iterCount++) {
		std::cout << iterCount->first << ":\t" << iterCount->second << std::endl;
	}
	std::cout << "+++-----------------------------------+++" << std::endl;

	// while more than two candidates are in the short list
	while (count.size() > 2) {

		// find candidate with fewest votes 
		min = count.begin();
		for (iterCount = count.begin(); iterCount != count.end(); iterCount++) {
			if (iterCount->second < min->second) {
				min = iterCount;
			}
		}

		// if candidate with fewest votes has more than 0 votes
		if (count[min->first] > 0) {

			// find ballot papers with preferences for candidate with fewest votes
			for (int t_pref = 1; t_pref < candidates.size(); t_pref++) {

				for (iterBall = papers.begin(); iterBall != papers.end(); iterBall++) {

					if (iterBall->getPreference(t_pref)->isEqual(candidates[min->first - 1])) {
						bool flag = false;

						// find candidate with the next highest preference
						for (int t_pref2 = t_pref; t_pref2 < candidates.size(); t_pref2++) {

							for (iterCand = candidates.begin(); iterCand != candidates.end(); iterCand++) {

								if (iterCand->isEqual(*iterBall->getPreference(t_pref2 + 1))) {

									if (count.find(iterCand - candidates.begin() + 1) != count.end()) {

										// increase vote count for next higher preference and decrease vote count of current pref
										count[iterCand - candidates.begin() + 1]++;
										count[min->first]--;
										flag = true;
										break;
									}
									else {
										break;
									}
								}
							}
							if (flag) {
								break;
							}
						}

					}

					// break if vote count is 0
					if (count[min->first] == 0) {
						break;
					}
				}

				// if vote count is 0
				if (count[min->first] == 0) {
					// delete count element for candidate
					count.erase(min);
					break;
				}
			}
		}

		else {
			// delete count element for candidate
			count.erase(min);
		}

		// print current vote count
		for (iterCount = count.begin(); iterCount != count.end(); iterCount++) {
			std::cout << iterCount->first << ":\t" << iterCount->second << std::endl;
		}
		std::cout << "+++-----------------------------------+++" << std::endl;
	}

	// get winner of last two remaining candidates
	min = count.begin();
	for (iterCount = count.begin(); iterCount != count.end(); iterCount++) {
		if (iterCount->second > min->second) {
			min = iterCount;
		}
	}

	// print winner
	std::cout << "The winner is: " << candidates[min->first - 1].getName() << std::endl;

	// return winner
	return &candidates[min->first - 1];
}

// helper function to split strings by given seperator
unsigned int VoteCounter::split(const std::string &txt, std::vector<std::string> &strs, char ch) {
	unsigned int pos = txt.find(ch);
	unsigned int initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}