// Day15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>


using namespace std;

void printmap(vector<vector<long>> map)
{
	std::cout << "--------------------------\n";
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
			cout << map[i][j] << ",";
		cout << endl;
	}
}

int main()
{
    std::cout << "Hello Day15!\n"; 

	std::ifstream infile("input.txt");
	std::string line;

	vector<string> input;
	vector<vector<long>> map;
	while (std::getline(infile, line))
		input.push_back(line);

	for (size_t i = 0; i < input.size(); i++)
	{
		vector<long> tmp;
		for (size_t j = 0; j < input[i].length(); j++)
		{
			int num = stoi(input[i].substr(j,1));
			tmp.push_back(num);
		}
		map.push_back(tmp);
	}


	vector<vector<long>> big_map;
	vector<vector<long>> risk_map;
	for (int risk_y = 0; risk_y < 5; risk_y++)
	{
			for (size_t i = 0; i < map.size(); i++)
			{
				vector<long> tmp;
				vector<long> tmp_risk;
				for (int risk_x = 0; risk_x < 5; risk_x++)
				{
					int risk_level = risk_y + risk_x;
					//cout <<  risk_level;
					for (size_t j = 0; j < map[i].size(); j++)
					{
						//long val = (map[i][j] + risk_level);
						long val = (map[i][j] + risk_level) % 10;
						if ((map[i][j] + risk_level) >= 10)
							val +=1 ;
						//cout << val << ",";
						tmp.push_back(val);
						tmp_risk.push_back(map[i][j]);
					}
				}
				big_map.push_back(tmp);
				risk_map.push_back(tmp_risk);
				//cout << endl;
			}
		
		//cout << endl;
	}
	//printmap(big_map);

	//printmap(risk_map);

	map = vector<vector<long>>(big_map);

	vector<vector<long>> map_route = vector<vector<long>>(map);
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			long left = LONG_MAX;
			long top = LONG_MAX;
			// compare with top
			if (i > 0)
			{
				top = map_route[i - 1][j];
			}

			// compare with left
			if (j > 0)
			{
				left = map_route[i][j-1];
			}
			
			if (left > top)
				map_route[i][j] += top;
			else if (left < top || (left == top && left < LONG_MAX))
				map_route[i][j] += left;
		}

	}

	//printmap(map);
	printmap(map_route);
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
