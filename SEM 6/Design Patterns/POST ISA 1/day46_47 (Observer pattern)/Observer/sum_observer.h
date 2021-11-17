#ifndef SUM_OBSERVER
#define SUM_OBSERVER
#include "observer.h"

class Sum_Observer : public Observer
{
	public:
	virtual void update(Subject *ptr_sub) ;
	virtual void disp() const;
	private:
	int sum;
	
};
#endif
