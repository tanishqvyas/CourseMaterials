#include <iostream>
using namespace std;

#include "cube_observer.h"
#include "num_subject.h"

void Cube_Observer::update(Subject *ptr_sub) 
{
	int x = (dynamic_cast<Num_Subject*>(ptr_sub))->get_state();
	cube = x * x * x;
}

void Cube_Observer::disp() const
{
	cout << "cube : " << cube << "\n";
}
