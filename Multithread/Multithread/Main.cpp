#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;
//call the threads
void CallThread(int id)
{
	//lock it so only one can display
	mtx.lock();
	//display
	cout << "Launched by thread" << id << endl;
	//unlock so more can run
	mtx.unlock();
}
int main()
{
	//number of threads is 10
	thread threads[10];
	//create the threads
	for (int i = 0; i < 10; i++)
	{
		//add the thread create to the for loop
		threads[i] = thread(CallThread, i + 1);
	}
	cout << "Launched from main" << endl;
	//join everything back together
	for (auto& t : threads) t.join();
	system("pause");
	return 0;
}