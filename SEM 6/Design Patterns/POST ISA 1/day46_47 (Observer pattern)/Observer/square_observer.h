#ifndef SQUARE_OBSERVER
#define SQUARE_OBSERVER
#include "observer.h"

class Square_Observer : public Observer
{
	public:
	virtual void update(Subject *ptr_sub) ;
	virtual void disp() const;
	private:
	int sq;
	
};
#endif

