/******************************************************************************
filename RaceCondition.cpp
author Lian Yuhan
email yuhan.lian@digipen.edu
date created 09 Oct 2019
Brief Description: Assigment to solve Race Condition
******************************************************************************/
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

// Do not touch this function. Used for Single-Threaded Adding to Reference Variable
void AddFuncST(int& target, const unsigned int count)
{
	for (unsigned int i = 0; i < count; ++i)
	{
		++target;
	}
}


// ASSIGNMENT TODO : Fix this function to compute correctly in Multi-threaded use
void AddFuncMT(int& target, const unsigned int count)
{
	for (unsigned int i = 0; i < count; ++i)
	{
		static mutex g_num_mutex; 
		g_num_mutex.lock(); 
		++target;
		g_num_mutex.unlock(); 
	}
}

// DO NOT TOUCH THE MAIN FUNCTION!!!
int main(void)
{
	// Initializing Varibles needed...
	int totalSum = 0; // The counter to compute the total sum of the AddFunc
	const unsigned int TARGET = 100000000; // The target amount we want to add
	int numOfThreads = thread::hardware_concurrency(); // The number of hardware cores available
	unsigned int threadAddCount = TARGET / numOfThreads; // The amount to handle per thread (to get TARGET)
	vector<thread> threads; // The container of threads
	threads.resize(numOfThreads); // Resize to the number of cores available/threads we want to create

	// Single-Thread Segment
	cout << "TARGET is " << TARGET << endl;
	cout << "Starting Single-thread Computation..." << endl;
	auto start = chrono::high_resolution_clock::now(); // Get start time
	AddFuncST(totalSum, TARGET); // Invoke ST Function
	auto end = chrono::high_resolution_clock::now(); // Get end time
	chrono::duration<double> diff = end - start; // Compute time difference
	cout << "Result of Computation (Single-thread) : " << totalSum << endl;
	cout << "Single-thread Time Taken : " << diff.count() << " s" << endl;
	if (totalSum == TARGET)
		cout << "Computation is CORRECT!" << endl;
	else
		cout << "Computation is WRONG!" << endl;
	// End of ST Segment

	cout << endl;

	// Multi-Thread Segment
	totalSum = 0; // Reset the sum value
	cout << "Starting Multi-thread Computation on " << numOfThreads << " threads..." << endl;
	start = chrono::high_resolution_clock::now(); // Get the start time
	for (int i = 0; i < numOfThreads; ++i)
		threads[i] = thread(AddFuncMT, ref(totalSum), threadAddCount); // Start the threads
	for (auto& curr : threads)
		curr.join(); // Join the threads (wait for them to all finish)
	end = chrono::high_resolution_clock::now(); // Get the end time
	diff = end - start; // Compute time difference
	cout << "Result of Computation (Multi-thread) : " << totalSum << endl;
	cout << "Multi-thread Time Taken : " << diff.count() << " s" << endl;
	if (totalSum == TARGET)
		cout << "Computation is CORRECT!" << endl;
	else
		cout << "Computation is WRONG!" << endl;
	// End of MT Segment
	system("pause");
}