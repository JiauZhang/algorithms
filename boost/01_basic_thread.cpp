#include <boost/thread.hpp> 
#include <iostream> 

/*
	主线程:
		boost::thread::sleep(boost::get_system_time() 
							+ boost::posix_time::seconds(5)); 
	子线程:
		boost::this_thread::sleep(boost::get_system_time() 
								+ boost::posix_time::seconds(2));
*/

void wait(int seconds) 
{ 
	boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(seconds)); 
} 

void parallel_thread() 
{ 
	for (int i = 0; i < 5; ++i) 
	{ 
		wait(1); 
		std::cout << "parallel thread: " << i << std::endl; 
	} 
} 

void current_thread()
{
	for (int i = 0; i < 5; ++i) 
	{ 
		wait(1); 
		std::cout << "current thread: " << i << std::endl; 
	} 
}

/*
	输出结果：
		start mian function
		thread has instanced
		parallel thread: current thread: 0
		0
		current thread: 1
		parallel thread: 1
		current thread: parallel thread: 22

		parallel thread: 3
		current thread: 3
		parallel thread: 4
		current thread: 4
		thread has exit
	结果分析：
		可以看出，两个线程的输出混在了一起，这是因为它们在抢占同一个资源
		即输出资源，为了避免这种情况，就需要使用信号量了
*/

int main() 
{ 
	std::cout << "start mian function" << std::endl;

	boost::thread t(parallel_thread); 	
	std::cout << "thread has instanced" << std::endl;
	
	current_thread();
	
	t.join(); 	
	std::cout << "thread has exit" << std::endl;
	
	return 0;
}