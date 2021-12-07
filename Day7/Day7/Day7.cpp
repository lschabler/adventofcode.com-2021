// Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main()
{
	std::cout << "Hello Day 7!\n";
	//std::ifstream infile("input_small.txt");
	std::ifstream infile("input.txt");
	std::string input;
	auto positions = vector<int>();

	while (std::getline(infile, input, ','))
		positions.push_back(stoi(input));

	auto crabs_pos = std::map<int, int>();
	for (size_t i = 0; i < positions.size(); i++)
	{
		if (crabs_pos.find(positions[i]) != crabs_pos.end())
			crabs_pos[positions[i]]++;
		else
			crabs_pos[positions[i]] = 1;
	}

	int min_fuel = INT_MAX;
	int cur_fuel = INT_MAX-1;
	int pos = 0;
	while (min_fuel > cur_fuel)
	{
		min_fuel = cur_fuel;
		cur_fuel = 0;
		for (auto iter = crabs_pos.begin(); iter != crabs_pos.end(); ++iter)
		{
			// Part 1
			//cur_fuel += abs(iter->first - pos) * iter->second;
			// Part 2
			int n = abs(iter->first - pos);
			int triangular = ((n*(n + 1)) / 2);
			cur_fuel += triangular * iter->second;
		}

		cout << "pos=" << pos << ", fuel=" << cur_fuel << endl;
		pos++;
	}
	cout << "fuel=" << min_fuel << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
