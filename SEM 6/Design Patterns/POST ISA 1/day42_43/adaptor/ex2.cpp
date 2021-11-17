#include <iostream>
using namespace std;
#include <vector>
// 2. Composition

class IStack // target : abstract
{
	public:
	virtual ~IStack() { }
	virtual void push(int e) = 0;
	virtual int peek() = 0;
	virtual void pop() = 0;
};
class Stack : public IStack // Adaptor
{
	public:
	virtual void push(int e);
	virtual int peek();
	virtual void pop();
	private:
	vector<int> v; // Adaptee
};

void Stack::push(int e)
{
	v.push_back(e);
}

int Stack::peek()
{
	return v.back();
}
void Stack::pop()
{
	v.pop_back();
}


int main()
{
	IStack* ptr_stack = new Stack();
	ptr_stack->push(10);
	ptr_stack->push(20);
	cout << ptr_stack->peek() << "\n";
	ptr_stack->pop();
	cout << ptr_stack->peek() << "\n";
	ptr_stack->pop();

	
	

	
	
}

