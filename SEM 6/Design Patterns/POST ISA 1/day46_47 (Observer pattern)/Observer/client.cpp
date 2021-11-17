#include <iostream>
using namespace std;
#include "num_subject.h"
#include "square_observer.h"
#include "cube_observer.h"
#include "sum_observer.h"

int main()
{
	Num_Subject s(25);
	Square_Observer sq_o;
	Cube_Observer cube_o;
	Sum_Observer sum_o;
	s.attach(&sq_o);
	s.attach(&cube_o);
	s.attach(&sum_o);
	
	sq_o.disp();
	cube_o.disp();
	sum_o.disp();
	
	s.set_state(12);
	sq_o.disp();
	cube_o.disp();
	sum_o.disp();
	
	
}
