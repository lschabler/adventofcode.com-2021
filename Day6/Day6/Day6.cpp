// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void printfisch(int day, vector<int> fishes)
{
	cout << "Day " << day << ": ";
	for (size_t i = 0; i < fishes.size(); i++)
	{
		cout << fishes[i];
	}
	cout << endl;
}

int main()
{
    std::cout << "Hello Day 6!\n"; 
	//std::ifstream infile("input_small.txt");
	std::ifstream infile("input.txt");
	std::string input;
	auto lanternfishes = vector<int>();

	while (std::getline(infile, input, ','))
		lanternfishes.push_back(stoi(input));

	//// Days
	//for (size_t day = 1; day <= 80; day++)
	//{
	//	for (size_t i = 0; i < lanternfishes.size(); i++)
	//	{
	//		lanternfishes[i]--;
	//		if (lanternfishes[i] == -1)
	//		{
	//			lanternfishes[i] = 6;
	//			lanternfishes.push_back(9);
	//		}
	//	}
	//	//printfisch(day, lanternfishes);
	//}

	//cout << "Part1: " << lanternfishes.size() <<  endl;

	auto age_fishes = vector<unsigned long long int>(9, 0);
	for (size_t i = 0; i < lanternfishes.size(); i++)
		age_fishes[lanternfishes[i]]++;

	//cout << "Age:" << endl;
	//for (size_t i = 0; i < age_fishes.size(); i++)
	//	cout << i << " " << age_fishes[i] << endl;

	//Days

	//int sum_of_fish_2 = std::accumulate(age_fishes.begin(), age_fishes.end(),
	//	decltype(age_fishes)::value_type(0));

	//cout << "Part2: " << sum_of_fish_2 << endl;

	for (size_t day = 1; day <= 256; day++)
	{
		unsigned long long int newfishes = age_fishes[0];
		std::rotate(age_fishes.begin(), age_fishes.begin() + 1, age_fishes.end());
		age_fishes[6] += newfishes;
	}

	cout << "Age:" << endl;
	for (size_t i = 0; i < age_fishes.size(); i++)
	{
		cout << i << " " << age_fishes[i] << endl;
	}
	long long sum_of_fish = std::accumulate(age_fishes.begin(), age_fishes.end(),
		decltype(age_fishes)::value_type(0));
		
	cout << "Part2: " << sum_of_fish << endl;
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
