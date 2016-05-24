#pragma once

#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

using namespace std;

/* Dining Philisophers
*
* Usage:
* Bowl bowl(5);
* thread t0(&Bowl::eat, &bowl, 0);
*	...
* thread t4(&Bowl::eat, &bowl, 4);
*/
class Bowl {
public:
	Bowl(int _n) : n(_n), sticks(vector<mutex>(n)) {}
	void eat(int p)
	{
		if (p >= n)
		{
			cerr << "philosopher out of bounf" << endl;
			return;
		}
		//while (true)
		//{
		yummy:
			unique_lock<mutex> right(sticks[p%n], defer_lock);
			unique_lock<mutex> left(sticks[(p+1)%n], defer_lock);
			if (!right.try_lock())
			{
				this_thread::sleep_for(50ms); // Taking a break
				goto yummy;
			}
			this_thread::sleep_for(5ms); // Simulate picking time
			if (!left.try_lock())
			{
				right.unlock();
				this_thread::sleep_for(50ms); // Taking a break
				goto yummy;
			}
			cout << "Philosopher " << p << " is eating" << endl;
			this_thread::sleep_for(600ms); // Eating
			cout << "Philosopher " << p << " paused eating" << endl;
			left.unlock();
			right.unlock();
		//	this_thread::sleep_for(300ms); // Taking a break
		//}
	}

private:
	int n;
	vector<mutex> sticks;
};

/* For deadlock avoidance
* Exception thown if a function requests mutexes in non-increasing order
*/
class MutexFactory {
public:
	static MutexFactory& getInstance() { static MutexFactory mf; return mf; }
	mutex& getMutex(string uid, int muid);
private:
	MutexFactory() { cout << "constr"; }
	mutex mus[5];
	unordered_map<string, int> currentMax;
};

mutex& MutexFactory::getMutex(string uid, int muid)
{
	int muidx = muid + 1;
	if (currentMax[uid] < muidx)
	{
		currentMax[uid] = muidx;
		return mus[muid];
	}
	else
	{
		throw "Possible Deadlok";
	}
}
