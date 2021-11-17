#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
// 5.  composition with generics for flexibility

template<typename T, typename C = deque<T>>
class Stack 
{
	public:
	void push(T e);
	T peek();
	void pop();
	private:
	C v;
};

template<typename T, typename C>
void Stack<T, C>::push(T e)
{
	v.push_back(e); 
}

template<typename T, typename C>
T Stack<T, C>::peek()
{
	return v.back();
}

template<typename T, typename C>
void Stack<T, C>::pop()
{
	v.pop_back();
}


int main()
{
#if 0
	Stack<int, vector<int>> s;
	s.push(100);
	s.push(200);
	cout << s.peek() << "\n";
	s.pop();
	cout << s.peek() << "\n";
	s.pop();
#endif
	{
		Stack<int, list<int>> s;
		s.push(100);
		s.push(200);
		cout << s.peek() << "\n";
		s.pop();
		cout << s.peek() << "\n";
		s.pop();
	}
	{
		Stack<int> s;
		s.push(100);
		s.push(200);
		cout << s.peek() << "\n";
		s.pop();
		cout << s.peek() << "\n";
		s.pop();
	}
}

