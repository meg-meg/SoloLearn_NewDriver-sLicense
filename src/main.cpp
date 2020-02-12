#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <math.h>

const int PROCESS_TIME = 20;

int main()
{
	std::string myName, numAgentsString;
	int placeInLine = 1, totalTime;
	double myGroup;
	std::string person[4];

	/*
		Receive input in this form:
	
		Eric						//myName
		2							//numAgents
		Adam Caroline Rebecca Frank	//person[4]
	*/

	/*
		std::cin was including the "\n" so I used getline instead
		and then converted the string to a double for numAgents.
	*/

	std::getline(std::cin, myName, '\n');
	std::getline(std::cin, numAgentsString, '\n');
	std::string::size_type sz;
	double numAgents = std::stod(numAgentsString, &sz);
	for (int i = 0; i < 3; i++)
	{
		std::getline(std::cin, person[i], ' ');
	}
	std::getline(std::cin, person[3], '\n');

	/*
		Compare names alphabetically.
		Move myName from front to back of line depending on order.
	*/

	for (int i = 0; i < 4; i++)
	{
		if ((strcmp(myName.c_str(), person[i].c_str())) < 0)
		{
							//If myName is earlier alphabetically, do not change place in line.
		}
		else
		{
			placeInLine++;  //If myName is later alphabetically, move back one spot.
		}
	}

	/*
		Calculate which group myName is in, round up if not a whole number.
		Multiply group by PROCESS TIME of 20 min to calculate the totalTime to get new license.
		Print totalTime.
	*/

	myGroup = ceil(placeInLine / numAgents);
	totalTime = myGroup * PROCESS_TIME;
	std::cout << totalTime;
	return 0;
}
