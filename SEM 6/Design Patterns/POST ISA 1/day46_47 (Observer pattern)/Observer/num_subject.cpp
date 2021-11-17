#include "num_subject.h"

Num_Subject::Num_Subject(int val)
: val(val)
{
}

void Num_Subject::set_state(int val)
{
	this->val = val;
	notify();
}

int Num_Subject::get_state() const
{
	return this->val;
}

