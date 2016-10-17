/*
 * main.cpp
 *
 *  Created on: Jul 18, 2016
 *          By: Raina Galbiati
 *
 *     Purpose: reads in a list of numbers and reverses the elements of the
 *     		list k items at a time, where k is it last number in the list
 *     	  NOTE: If the number of elements is not a multiple of k, then the
 *     		remainder elements will be left as is
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "values.h"

void read_file(char * argv[], Values &v);


int main(int argc, char * argv[])
{
	//ensure correct file ussage
	if (argc != 2) {
		std::cerr << "usage program file" << std::endl;
		exit(1);
	}

	Values v;
	read_file(argv, v);
	v.flip_order();
	v.print();
	return 0;
}

void read_file(char * argv[], Values &v)
{
	std::ifstream file (argv[1]);

	if (!file)
	{
	    std::cerr << "unable to open file" << std::endl;
	    exit(1);
	}

	int i = 0;
	int row = 0;
	std::string num = "";
	std::string input;

	//reads file word by word.  >> stops reading at each space or \n
	while  (file >> input) {
		std::vector<int> newRow;
		v.arr.push_back(newRow);
		while (i < (int)input.length()) {
			while(input[i] != ',' and input[i] != ';' and
					i < (int)input.length()) {
				num += input[i];
				i++;
			}
			v.arr[row].push_back(atoi(num.c_str()));
			num = "";
			i++;
		}
		i = 0;
		row++;
	}
	file.close();
}

