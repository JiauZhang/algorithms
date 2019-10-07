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

void wait(int seconds) 
{ 
	boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
} 

void show_info()
{
	std::cout << "thread id: "
			  << boost::this_thread::get_id() << std::endl; 
	std::cout << "hardware cores: "
			  << boost::thread::hardware_concurrency() << std::endl;
}

boost::mutex mutex; 

void thread() 
{ 
	show_info();
	
	for (int i = 0; i < 5; ++i) 
	{ 
		wait(1); 
		mutex.lock(); 
		std::cout << "Thread " << boost::this_thread::get_id() << ": " << i << std::endl; 
		mutex.unlock(); 
	} 
} 

int main() 
{ 
	show_info();

	boost::thread t1(thread); 
	boost::thread t2(thread); 
	t1.join(); 
	t2.join(); 
	
	return 0;
}