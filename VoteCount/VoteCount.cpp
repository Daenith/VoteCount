// VoteCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VoteCounter.h"


int main() {
	VoteCounter *vc = new VoteCounter();
	vc->getWinner();

	system("pause");
	return 0;
}

