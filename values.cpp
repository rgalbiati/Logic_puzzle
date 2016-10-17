/*
 * values.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: raina.galbiati
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "values.h"

/*
 * for each list of numbers, calls function to reverse the order
 */
void Values::flip_order()
{
	int k;
	for (int i = 0; i < (int)arr.size(); i++) {
		k = arr[i][arr[i].size()-1];
		rearrange(i, k);
	}
}

/*
 * reverses elements of the list in groups
 * args: the row of the list in the array containing all of the lists, and
 * 	the size of the grouping for reversals
 */
void Values::rearrange(int row, int k)
{
	int r, s;

	for (int i = 0; i+k < (int)arr[row].size(); i += k)  {
		r = i;
		s = i + k - 1;
		while (r < s) {
			int temp = arr[row][r];
			arr [row][r] = arr[row][s];
			arr [row][s] = temp;
			r++;
			s--;
		}
	}
}

/*
 * prints each list one at a time, not including k
 */
void Values::print()
{
	for (int i = 0; i < (int)arr.size(); i++) {
		for (int j = 0; j < (int)arr[i].size()-2; j++) {
			std::cout << arr[i][j] << ",";
		}
		std::cout <<arr[i][arr[i].size()-2] << std::endl;
	}
}
