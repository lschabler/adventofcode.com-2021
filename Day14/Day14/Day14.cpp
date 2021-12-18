// Day14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    std::cout << "Hello Day14!\n"; 
	
	std::ifstream infile("input.txt");
	std::string line;

	std::map<std::string, string> pair_insertion_rules;
	std::map<std::string, long long> current_pairs;

	vector<string> input;
	while (std::getline(infile, line))
		input.push_back(line);

	string template_input = input[0];

	for (size_t i = 2; i < input.size(); i++)
	{
		string key = input[i].substr(0, 2);
		string value = input[i].substr(input[i].length()-1, 1);
		pair_insertion_rules[key] = value;
	}

	for (size_t i = 0; i < template_input.length()-1; i++)
	{
		string pair = template_input.substr(i, 2);
		if (current_pairs.count(pair))
			current_pairs[pair]++;
		else
			current_pairs[pair] = 1;
	}

	for (size_t iter = 0; iter < 40; iter++)
	{
		std::map<std::string, long long> map_iter;
		for (const auto &current_pair : current_pairs) 
		{
			string key = current_pair.first;
			long long count = current_pair.second;
				
			string rule = pair_insertion_rules[key];
			cout << key << ">" << rule << "=" << count << endl;

			string val1 = key[0] + rule;	
			if (map_iter.count(val1))
				map_iter[val1] += count;
			else
				map_iter[val1] = count;

			string val2 = rule + key[1];
			if (map_iter.count(val2))
				map_iter[val2] += count;
			else
				map_iter[val2] = count;
		}
		cout << "--------------------------" << endl;
		current_pairs = map<string, long long>(map_iter);
	}

	long long val_min = LLONG_MAX;
	long long val_max = LLONG_MIN;
	std::map<char, long long> map_char_final_1;
	std::map<char, long long> map_char_final_2;
	for (const auto &current_pair : current_pairs)
	{
		char key_1 = current_pair.first[0];
		//char key_2 = current_pair.first[1];
		long long  count = current_pair.second;
		
		if (map_char_final_1.count(key_1))
			map_char_final_1[key_1] += count;
		else
			map_char_final_1[key_1] = count;
	}

	char last = template_input.back();
	map_char_final_1[last] += 1;

	for (const auto &current_pair : map_char_final_1)
	{
		if (val_min > current_pair.second)
			val_min = current_pair.second;
		if (val_max < current_pair.second)
			val_max = current_pair.second;
	}

	cout << "part1: " << val_max - val_min << endl;
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
