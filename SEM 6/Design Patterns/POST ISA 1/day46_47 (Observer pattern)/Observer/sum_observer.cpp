#include <iostream>
using namespace std;

#include "sum_observer.h"
#include "num_subject.h"

void Sum_Observer::update(Subject *ptr_sub) 
{
	int x = (dynamic_cast<Num_Subject*>(ptr_sub))->get_state();
	int s = 0;
	while(x)
	{
		s += x % 10;
		x /= 10;
	}
	sum = s;
}

void Sum_Observer::disp() const
{
	cout << "sum of digits : " << sum << "\n";
}
