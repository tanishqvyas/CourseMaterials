#include <iostream>
using namespace std;
#include <vector>
// 4. pure composition

class Stack 
{
	public:
	void push(int e);
	int peek();
	void pop();
	private:
	vector<int> v;
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
	Stack s;
	s.push(100);
	s.push(200);
	cout << s.peek() << "\n";
	s.pop();
	cout << s.peek() << "\n";
	s.pop();
}

