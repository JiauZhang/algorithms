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

void parallel_thread_response() 
{ 
	try 
	{ 
		for (int i = 0; i < 5; ++i) 
		{ 
			wait(1); 
			std::cout << "parallel thread: " << i << std::endl; 
		} 
	} catch (boost::thread_interrupted&) { 
		std::cout << "thread is interrupted!" << std::endl;
	} 
} 

void parallel_thread_no_response() 
{ 
	for (int i = 0; i < 5; ++i) 
	{ 
		/* wait(1); */

		for (int j=0; j<=6000; j++) {
			for (int k=0; k<=6000; k++) {
				for (int m=0; m<=30; m++) {
					;
				}
			}
		}
		
		std::cout << "parallel thread: " << i << std::endl; 
	} 
} 

int main() 
{ 
	/* test #1 */
	boost::thread t_res(parallel_thread_response); 	
	wait(3); 

	std::cout << "start interrupting the thread!"<< std::endl;
	t_res.interrupt(); 
	t_res.join(); 
	
	/* test #2 */
	boost::thread t_no_res(parallel_thread_no_response);
	wait(3);
	
	std::cout << "start interrupting the thread!"<< std::endl;
	t_no_res.interrupt(); 
	t_no_res.join(); 

	return 0;
} 