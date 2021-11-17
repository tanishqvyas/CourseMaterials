#ifndef CUBE_OBSERVER
#define CUBE_OBSERVER
#include "observer.h"

class Cube_Observer : public Observer
{
	public:
	virtual void update(Subject *ptr_sub) ;
	virtual void disp() const;
	private:
	int cube;
	
};
#endif
