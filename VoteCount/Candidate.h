#pragma once
#include <string>

class Candidate {
private:
	std::string party;
	std::string name;

public:
	Candidate();
	Candidate(std::string t_name, std::string t_party);
	~Candidate();
	void setName(std::string t_name);
	std::string getName();
	void setParty(std::string t_party);
	std::string getParty();
	bool isEqual(Candidate &cand);
};

