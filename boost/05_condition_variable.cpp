/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <boost/thread.hpp> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <ctime> 

boost::mutex mutex; 
boost::condition_variable_any cond; 
std::vector<int> random_numbers; 

void fill() 
{ 
	std::srand(static_cast<unsigned int>(std::time(0))); 
	for (int i = 0; i < 3; ++i) 
	{ 
		boost::unique_lock<boost::mutex> lock(mutex); 
		random_numbers.push_back(std::rand()); 
		/* 唤醒 condition_variable 中等待的线程 */
		cond.notify_all(); 
		/* 
			释放互斥锁，并进去等待队列 
			等待 condition_variable 的唤醒
			唤醒后加入到 condition_variable 互斥锁队列
		*/
		cond.wait(mutex); 
	} 
} 

void print() 
{ 
	std::size_t next_size = 1; 
	for (int i = 0; i < 3; ++i) 
	{ 
		boost::unique_lock<boost::mutex> lock(mutex); 
		while (random_numbers.size() != next_size) 
		/* 
			获得锁之后，当不满足执行条件时 
			使用 condition_variable 释放已持有的信号量
			并将自身挂起加入到 condition_variable 等待队列中
			等待 condition_variable 的唤醒
			唤醒后加入到 condition_variable 互斥锁队列
		*/
		  cond.wait(mutex); 
		std::cout << random_numbers.back() << std::endl; 
		++next_size; 
		cond.notify_all(); 
	} 
} 

/*
from: http://www.cplusplus.com/reference/condition_variable/condition_variable/wait/
	The execution of the current thread 
	(which shall have locked lck's mutex) is blocked until notified.
	At the moment of blocking the thread, the function automatically calls lck.unlock(), 
	allowing other locked threads to continue.
	Once notified (explicitly, by some other thread), 
	the function unblocks and calls lck.lock(), leaving lck in the same state 
	as when the function was called. Then the function returns 
	(notice that this last mutex locking may block again the thread before returning).
*/

int main() 
{ 
	boost::thread t1(fill); 
	boost::thread t2(print); 
	t1.join(); 
	t2.join(); 
	
	return 0;
} 