
#include "pch.h"
#include <iostream>

using namespace std;
template<class T>
class arrayQueue
{
private:
	int length;
	int theFront;
	int theBack;
	T*  queue;
public:
	arrayQueue(int initialCapacity=10);
	~arrayQueue()
	{
		delete[] queue;
	}
	void pop()
	{
		//***
		theFront=(theFront+1)%length;
		queue[theFront].~T();
	}
	T& front()
	{
		return queue[(theFront+1)%length];
	}
	T& back()
	{
		return queue[(theBack+1)%length];
	}
	void push(const T& element)
	{
		theBack = (theBack + 1) % length;
		queue[theBack] = element;
	}
	bool empty() const
	{
		//***
		return theFront == theBack;
	}
	int size()
	{
		//***
		return (theBack-theFront+length)%length;
	}

};
template<class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
	length = initialCapacity;
	queue = new T[length];
	theFront = 0;
	theBack = 0;
}
int main()
{
	
	arrayQueue<int> q;
	for (int i = 0; i < 9; i++)
	{
		q.push(i);
		printf("%d",q.size());
	}
	while (!q.empty())
	{
		cout << q.front() << " " << q.size() << endl;
		q.pop();
	}
	
}
