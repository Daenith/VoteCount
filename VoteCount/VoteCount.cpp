// author: Theresia Kosche
// project github repository: https://github.com/Daenith/VoteCount

#include "stdafx.h"
#include "VoteCounter.h"


int main() {
	VoteCounter *vc = new VoteCounter();
	vc->getWinner();

	system("pause");
	return 0;
}

