#include <algorithm>
using namespace std;
#include "Subject.h"
#include "observer.h"


Subject::~Subject()
{
}

void Subject::attach( Observer *ptr_ob)
{
	v.push_back(ptr_ob); // no duplicate attach called
	ptr_ob->update(this);
}


void Subject::detach( Observer *ptr_ob)
{
	// Observer exists
	erase(v, ptr_ob);
}

void Subject::notify()
{
	for(auto o : v)
	{
		o->update(this);
	}
}
