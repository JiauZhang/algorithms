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