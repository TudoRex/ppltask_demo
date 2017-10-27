// ppl_task_group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ppl.h>
#include <ppltasks.h>
#include <iostream>
#include <array>
#include <list>
#include <vector>

using namespace std;
using namespace Concurrency;


int _tmain(int argc, _TCHAR* argv[])
{
// 	array<task<int>, 3> tasks = {
// 		create_task([]() -> int { return 88; }),
// 		create_task([]() -> int { return 42; }),
// 		create_task([]() -> int { return 99; })
// 	};

	vector<task<int>> tasks = {
		create_task([]() -> int { return 88; }),
		create_task([]() -> int { return 42; }),
		create_task([]() -> int { return 99; })
	};


	// Select the first to finish.
	when_any(begin(tasks), end(tasks)).then([](pair<int, size_t> result)
	{
		cout << "First task to finish returns "
			<< result.first
			<< " and has index "
			<< result.second << endl;
	}).wait();


	
	//tasks.erase
	std::cout << "end." << endl;
	status;
// 	when_any(begin(tasks), end(tasks)).then([](pair<int, size_t> result)
// 	{
// 		cout << "First task to finish returns "
// 			<< result.first
// 			<< " and has index "
// 			<< result.second << endl;
// 	}).wait();
// 
// 	when_any(begin(tasks), end(tasks)).then([](pair<int, size_t> result)
// 	{
// 		cout << "First task to finish returns "
// 			<< result.first
// 			<< " and has index "
// 			<< result.second << endl;
// 	}).wait();
	return 0;
}

