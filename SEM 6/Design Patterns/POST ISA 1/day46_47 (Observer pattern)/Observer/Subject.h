#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
using namespace std;

// abstract class :  polymorphic
class Observer;
class Subject
{
	public:
	virtual ~Subject() = 0;
	virtual void attach( Observer *ptr_ob);
	virtual void detach( Observer *ptr_ob);
	virtual void notify();
	private:
	vector<Observer*> v;
};
#endif

