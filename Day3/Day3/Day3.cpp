// Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

int CommonValues(std::vector<std::string> vec, int position);
std::vector<std::string> RemoveAll(std::vector<std::string> vec, int position, char value);

int main()
{
	std::cout << "Hello Day3!\n";
	std::vector<int> nr_of_ones;
	std::vector<int> nr_of_zeros;
	std::vector<std::string> lines;
	
	std::ifstream infile("input.txt");
	std::string line = "";

	std::string gamma_rate = "";
	std::string epsilon_rate = "";
	int line_length = 0;

	while (std::getline(infile, line))
	{
		lines.push_back(line);

		if (nr_of_ones.empty())
		{
			line_length = line.length();
			nr_of_ones = std::vector<int>(line.length(), 0);
			nr_of_zeros = std::vector<int>(line.length(), 0);
		}

		// Part 1
		for (size_t i = 0; i < line.length(); i++)
		{
			//std::cout << line.at(i);
			if (line.at(i) == '1')
				nr_of_ones[i]++;
			else 
				nr_of_zeros[i]++;
		}
	}

	// Part 1
	for (size_t i = 0; i < nr_of_ones.size(); i++)
	{
		if (nr_of_ones[i] > nr_of_zeros[i])
		{
			gamma_rate += "1";
			epsilon_rate += "0";
		}
		else
		{
			gamma_rate += "0";
			epsilon_rate += "1";
		}
		
	}

	int gamma = std::stoi(gamma_rate, 0, 2);
	int epsilon = std::stoi(epsilon_rate, 0, 2);

	std::cout << "part1: " << gamma * epsilon << std::endl;

	// part2
	std::vector<std::string> oxygen_candidates(lines);
	std::vector<std::string> co2_scrubber_candidates(lines);
	
	int pos = 0;
	while (oxygen_candidates.size() > 1)
	{
		int common = CommonValues(oxygen_candidates, pos);
		char keep = '0';
		if (common == 0)
			keep = '1';
		if (common == 1)
			keep = '1';
		if (common == -1)
			keep = '0';

		oxygen_candidates = RemoveAll(oxygen_candidates, pos, keep);
		pos++;
	}

	pos = 0;
	while (co2_scrubber_candidates.size() > 1)
	{
		int common = CommonValues(co2_scrubber_candidates, pos);
		char keep = '0';
		if (common == 0)
			keep = '0';
		if (common == 1)
			keep = '0';
		if (common == -1)
			keep = '1';
		co2_scrubber_candidates = RemoveAll(co2_scrubber_candidates, pos, keep);
		pos++;
	}
	
	std::cout << "oxygen_candidates: " << oxygen_candidates.at(0) << std::endl;
	std::cout << "co2_scrubber_candidates: " << co2_scrubber_candidates.at(0) << std::endl;

	int oxygen = std::stoi(oxygen_candidates.at(0), 0, 2);
	int co2 = std::stoi(co2_scrubber_candidates.at(0), 0, 2);

	std::cout << "oxygen: " << oxygen << std::endl;
	std::cout << "co2: " << co2 << std::endl;

	std::cout << "part2: " << oxygen * co2 << std::endl;

}

// return 1 or 0 most common or -1 equal
int CommonValues(std::vector<std::string> vec, int position)
{
	int middle = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i][position] == '1')
			middle++;
		else
			middle--;
	}

	if (middle > 0)
		return 1;
	else if (middle < 0)
		return -1;
	else
		return 0;

}


std::vector<std::string> RemoveAll(std::vector<std::string> vec, int position, char keep_value)
{
	std::vector<std::string> return_values;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i][position] == keep_value)
			return_values.push_back(vec[i]);
	}
	return return_values;
}

