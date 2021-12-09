// Day9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <list>

using namespace std;

int RecursiveBasin(vector<vector<int>>& map, int x, int y);

vector<int> FindBasin(vector<vector<int>> map, vector<vector<int>> map_min)
{
	auto ret = vector<int>();

	for (size_t y = 0; y < map.size(); y++)
	{
		for (size_t x = 0; x < map[y].size(); x++)
		{
			if (map_min[y][x] == 0) continue;
			
			int basin_size = RecursiveBasin(map, x, y);
			ret.push_back(basin_size);
			cout << x << " " << y << " " << basin_size << endl;
		}
	}
	return ret;
}

int RecursiveBasin(vector<vector<int>>& map, int x, int y)
{


	if (x == -1 || y == -1)
		return 0;

	//cout << x << " " << y << endl;
	//cout << map[y].size() << " " << map.size() << endl;

	if (x == (map[0].size()) || y == (map.size()))
		return 0;

	if (map[y][x] == 9)
		return 0;

	map[y][x] = 9;

	int sum = 1;
	sum += RecursiveBasin(map, x + 1, y);
	sum += RecursiveBasin(map, x - 1, y);
	sum += RecursiveBasin(map, x, y + 1);
	sum += RecursiveBasin(map, x, y - 1);

	return sum;
}


int main()
{
    std::cout << "Hello Day9!\n"; 

	//ifstream infile("input_small.txt");
	ifstream infile("input.txt");
	string line;

	auto height_map = vector<vector<int>>();
	int heigth = 0;
	while (getline(infile, line))
	{
		height_map.push_back(vector<int>());

		//cout << line << endl;
		for (size_t i = 0; i < line.size(); i++)
		{
			height_map[heigth].push_back(line[i]-'0');
		}
		heigth++;
	}

	auto min_map = vector<vector<int>>();
	for (size_t y = 0; y < height_map.size(); y++)
	{
		min_map.push_back(vector<int>());
		for (size_t x = 0; x < height_map[y].size(); x++)
		{
			int risk_value = height_map[y][x] + 1;
			// check suroundings
			if (x > 0 && height_map[y][x - 1] < risk_value)
			{
				risk_value = 0;
			}	
			else if (x < height_map[y].size()-1 && height_map[y][x + 1] < risk_value)
			{
				risk_value = 0;
			}
			else if (y > 0 && height_map[y-1][x] < risk_value)
			{
				risk_value = 0;
			}
			else if (y < height_map.size() - 1 && height_map[y+1][x] < risk_value)
			{
				risk_value = 0;
			}

			min_map[y].push_back(risk_value);
		}
	}

	int sum = 0;
	for (size_t y = 0; y < min_map.size(); y++)
	{
		sum += accumulate(min_map[y].begin(), min_map[y].end(), 0);
		//for (size_t x = 0; x < min_map[y].size(); x++)
		//{
		//	cout << to_string(min_map[y][x]);
		//}
		//cout << endl;
	}
	cout << "part1: " << sum << endl;

	auto sum2 = FindBasin(height_map, min_map);
	

	std::list<int> mylist{ 0,0,0 };

	for (size_t i = 0; i < sum2.size(); i++)
	{
		if (sum2[i] > mylist.front())
		{
			mylist.pop_front();
			mylist.push_back(sum2[i]);
			mylist.sort();
		}
		
	}
	int multi = accumulate(mylist.begin(), mylist.end(), 1, std::multiplies<int>());

	cout << "part2: " << multi << endl;
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
