#include <boost/thread.hpp> 
#include <boost/thread/mutex.hpp>
#include <iostream> 
#include <vector>

void wait(int seconds) 
{ 
	boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
} 

boost::mutex mutex; 
boost::timed_mutex timed_mutex;

boost::shared_mutex shared_mutex; 
std::vector<int> random_numbers; 

void thread_lock_guard() 
{ 
	for (int i = 0; i < 5; ++i) 
	{ 
		wait(1); 
		boost::lock_guard<boost::mutex> lock(mutex); 
		std::cout << "Thread " << boost::this_thread::get_id() 
				  << ": " << i << std::endl; 
	} 
}

void thread_unique_lock()
{
	for (int i = 0; i < 5; ++i) 
	{ 
		wait(1); 
		boost::unique_lock<boost::timed_mutex> lock(timed_mutex, boost::try_to_lock); 
		if (!lock.owns_lock()) {
			std::cout << "try to lock failed! wait less than 1 second!" << std::endl;
			lock.timed_lock(boost::get_system_time() + boost::posix_time::seconds(1)); 
		}
		std::cout << "Thread " << boost::this_thread::get_id() << ": " << i << std::endl; 
		boost::timed_mutex *m = lock.release(); 
		m->unlock(); 
	}
}

void fill() 
{ 
	std::srand(static_cast<unsigned int>(std::time(0))); 
	for (int i = 0; i < 3; ++i) 
	{ 
		boost::unique_lock<boost::shared_mutex> lock(shared_mutex); 
		/* 写操作使用 独占锁 unique_lock */
		random_numbers.push_back(3*i); 
		std::cout << "random_numbers back: " << random_numbers.back() << std::endl;
		lock.unlock(); 
		wait(1); 
	} 
} 

void print() 
{ 
	for (int i = 0; i < 3; ++i) 
	{ 
		wait(1); 
		/* 只读操作使用 shared_lock */
		boost::shared_lock<boost::shared_mutex> lock(shared_mutex); 
		std::cout << "print: " << random_numbers.back() << std::endl; 
	} 
} 

int sum = 0; 

void count() 
{ 
	for (int i = 0; i < 3; ++i) 
	{ 
		wait(1); 
		/* 只读操作使用 shared_lock */
		boost::shared_lock<boost::shared_mutex> lock(shared_mutex); 
		std::cout << "sum add: " << random_numbers.back() << std::endl;
		sum += random_numbers.back(); 
	} 
} 

int main() 
{ 
	std::cout << "test lock_guard" << std::endl;
	boost::thread t1(thread_lock_guard); 
	boost::thread t2(thread_lock_guard); 
	t1.join(); 
	t2.join(); 
	
	std::cout << "test unique_lock" << std::endl;
	boost::thread t3(thread_unique_lock); 
	boost::thread t4(thread_unique_lock); 
	t3.join(); 
	t4.join(); 
	
	std::cout << "test shared_lock" << std::endl;
	random_numbers.clear();
	boost::thread t5(fill); 
	boost::thread t6(print); 
	boost::thread t7(count); 
	t5.join(); 
	t6.join(); 
	t7.join(); 
	/* 
		这个和并不一定就是 random_numbers 中三个元素的和
		因为是并行的，所以可能重复取其中的某个元素
		因为只取三次，所以三次之后就退出了，故很大概率不是
		其中所有元素的和
	*/
	std::cout << "Sum: " << sum << std::endl; 
	
	return 0;
} 