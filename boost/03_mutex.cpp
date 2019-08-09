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