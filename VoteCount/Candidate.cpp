#include "stdafx.h"
#include "Candidate.h"


Candidate::Candidate() {
	name = "";
	party = "";
}

Candidate::Candidate(std::string t_name, std::string t_party) {
	name = t_name;
	party = t_party;
}


Candidate::~Candidate() {
}

void Candidate::setName(std::string t_name) {
	name = t_name;
}

std::string Candidate::getName() {
	return name;
}

void Candidate::setParty(std::string t_party) {
	party = t_party;
}

std::string Candidate::getParty() {
	return party;
}

bool Candidate::isEqual(Candidate &cand) {
	return this->getName() == cand.getName() && this->getParty() == cand.getParty();
}

