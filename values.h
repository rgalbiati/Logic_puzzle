/*
 * values.h
 *
 *  Created on: Jul 18, 2016
 *      Author: raina.galbiati
 */

#ifndef VALUES_H_
#define VALUES_H_

#include <iostream>
#include <vector>

class Values {
public:
	std::vector<std::vector<int> > arr;
	void flip_order();
	void print();
private:
	void rearrange(int row, int k);
};

#endif /* VALUES_H_ */
