#include <iostream>
using namespace std;
#include <vector>
// 3. multiple inheritance
class IStack // target : abstract
{
	public:
	virtual ~IStack() { }
	virtual void push(int e) = 0;
	virtual int peek() = 0;
	virtual void pop() = 0;
};
class Stack : public IStack , private vector<int>
{
	public:
	virtual void push(int e);
	virtual int peek();
	virtual void pop();
};

void Stack::push(int e)
{
	push_back(e); // pushback on unnamed subobject of vector in Stack
}

int Stack::peek()
{
	return back();
}
void Stack::pop()
{
	pop_back();
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

	Stack s;
	s.push(100);
	s.push(200);
	cout << s.peek() << "\n";
	s.pop();
	cout << s.peek() << "\n";
	s.pop();
	
	
}

