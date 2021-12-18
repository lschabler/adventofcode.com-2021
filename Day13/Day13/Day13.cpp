// Day13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> fold(vector<vector<char>> input, char fold_dir, int fold_val);
void print(vector<vector<char>> input);
int count(vector<vector<char>> input);

int main()
{
    std::cout << "Hello Day 13!\n";

	std::ifstream infile("input.txt");
	std::string line;
	bool isfold = false;

	auto fold_dir = vector<char>();
	auto fold_value = vector<int>();
	auto in_x = vector<int>();
	auto in_y = vector<int>();

	while (std::getline(infile, line))
	{
		if (line == "")
		{
			isfold = true;
			continue;
		}

		if (isfold)
		{
			fold_dir.push_back(line[11]);
			fold_value.push_back(stoi(line.substr(13)));
		}
		else
		{
			auto index = line.find_first_of(',');
			in_x.push_back(stoi(line.substr(0, index)));
			in_y.push_back(stoi(line.substr(index+1)));
		}
		cout << line << endl;
	}

	int xmax = *max_element(in_x.begin(), in_x.end()) +1;
	int ymax = *max_element(in_y.begin(), in_y.end()) +1;

	auto paper = vector<vector<char>>(ymax, std::vector<char>(xmax, '.'));

	for (size_t i = 0; i < in_x.size(); i++)
	{
		//cout  << in_x[i] << " " << in_y[i] << endl;
		paper[in_y[i]][in_x[i]] = '#';
	}

	//print(paper);
	auto part1 = fold(paper, fold_dir[0], fold_value[0]);
	
	//print(part1);
	int num = count(part1);
	cout << "part1: " << num << endl;

	auto part2(paper);

	for (size_t i = 0; i < fold_dir.size(); i++)
	{
		part2 = fold(part2, fold_dir[i], fold_value[i]);
	}

	//auto part2 = fold(part1, fold_dir[1], fold_value[1]);
	print(part2);

}

void print(vector<vector<char>> input)
{
	cout << endl;
	for (size_t y = 0; y < input.size(); y++)
	{
		for (size_t x = 0; x < input[0].size(); x++)
		{
			cout << input[y][x];
		}
		cout << endl;
	}
}

int count(vector<vector<char>> input)
{
	int count = 0;
	for (size_t y = 0; y < input.size(); y++)
	{
		for (size_t x = 0; x < input[0].size(); x++)
		{
			if (input[y][x] == '#')
				count++;
		}
	}
	return count;
}

vector<vector<char>> fold(vector<vector<char>> input, char fold_dir, int fold_val)
{
	vector<vector<char>> folded;
	if (fold_dir == 'y')
	{
		int fold_y = input.size() - fold_val-1;
		folded = vector<vector<char>>(fold_y, std::vector<char>(input[0].size(), '.'));
		// copy
		for (size_t y = 0; y < fold_y; y++)
		{
			for (size_t x = 0; x < input[0].size(); x++)
				if (input[y][x] == '#')
					folded[y][x] = '#';
		}
		
		// copy folded
		int rev_y = fold_y;
		for (size_t y = fold_y+1; y < input.size(); y++)
		{
			rev_y--;
			for (size_t x = 0; x < input[0].size(); x++)
				if (input[y][x] == '#')
				{
					//cout << rev_y << " " << x << endl;
					folded[rev_y][x] = '#';
				}
					
		}
	}
	else
	{
		int fold_x = fold_val;
		folded = vector<vector<char>>(input.size(), std::vector<char>(fold_x, '.'));
		// copy
		for (size_t y = 0; y < input.size(); y++)
		{
			for (size_t x = 0; x < fold_x; x++)
				if (input[y][x] == '#')
					folded[y][x] = '#';
		}
		// copy folded
		int rev_x = 0;
		for (size_t y = 0; y < input.size(); y++)
		{
			rev_x = fold_x;
			for (size_t x = fold_x + 1; x < input[0].size(); x++)
			{
				rev_x--;
				if (rev_x < 0)
				{
					cout << y << " " << x << " / " << rev_x << " / " << fold_x << endl;
					continue;
				}

				if (input[y][x] == '#')
				{
					
					folded[y][rev_x] = '#';
				}
			}
		}
	}
	return folded;
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
