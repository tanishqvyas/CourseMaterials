#ifndef OBSERVER_H
#define OBSERVER_H
class Subject;
class Observer
{
	public:
	virtual ~Observer();
	virtual void update(Subject*)  = 0;
	virtual void disp() const = 0;
};
#endif

