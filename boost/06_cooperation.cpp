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

boost::mutex gui_mutex; 
boost::condition_variable_any cond; 
bool ready = false, shutdown = false;

void sys() 
{
	int loops = 10;
	for (int i = 0; i < loops; ++i) 
	{
		boost::unique_lock<boost::mutex> lock(gui_mutex); 
		ready = true;
		std::cout << "cmd gui refresh" << std::endl;
		cond.notify_all();
		cond.wait(gui_mutex);
	}
	
	boost::unique_lock<boost::mutex> lock(gui_mutex);
	cond.notify_all();
	
	std::cout << "sys exit" << std::endl;
	shutdown = true;
} 

void gui() 
{ 
	while (!shutdown) { 
		boost::unique_lock<boost::mutex> lock(gui_mutex); 
		if (!ready) 
			cond.wait(gui_mutex); 
		if (ready) {
			std::cout << "refresh gui" << std::endl;
			ready = false;
			cond.notify_all();
		}
	} 
	
	std::cout << "gui exit" << std::endl;
} 

int main() 
{ 
	boost::thread t1(sys); 
	boost::thread t2(gui); 
	t1.join(); 
	t2.join(); 
	
	std::cout << "main exit" << std::endl;
	
	return 0;
} 