#include <iostream>
using namespace std;

#include "square_observer.h"
#include "num_subject.h"

void Square_Observer::update(Subject *ptr_sub) 
{
	int x = (dynamic_cast<Num_Subject*>(ptr_sub))->get_state();
	sq = x * x;
}

void Square_Observer::disp() const
{
	cout << "square : " << sq << "\n";
}
