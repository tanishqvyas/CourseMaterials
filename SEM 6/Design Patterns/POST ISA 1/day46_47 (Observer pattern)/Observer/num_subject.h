#ifndef NUM_SUBJECT_H
#define NUM_SUBJECT_H
#include "Subject.h"

class Num_Subject : public Subject
{
	public:
	Num_Subject(int val);
	void set_state(int val);
	int get_state() const;
	private:
	int val;
};
#endif
