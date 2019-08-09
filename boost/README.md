### Boost 多线程编程
#### boost 路径
```c++
/usr/lib/x86_64-linux-gnu/libboost_*
```

#### 01_basic_thread
1. 知识点
```c++
创建新的线程 boost::thread t(new_thread_function_name)
阻塞当前线程以等待新创建线程退出 t.join()
解除两个线程间的联系 t.detach()
```

2. 输出结果分析
```c++
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
```

#### 02_interrupt_thread
1. 知识点
```c++
在一个线程对象上调用 interrupt() 会中断相应的线程。 
在这方面，中断意味着一个类型为 boost::thread_interrupted 的异常，它会在这个线程中抛出。 
然后这只有在线程达到中断点时才会发生。

如果给定的线程不包含任何中断点，简单调用 interrupt() 就不会起作用。 
每当一个线程中断点，它就会检查 interrupt() 是否被调用过。 
只有被调用过了， boost::thread_interrupted 异常才会相应地抛出。

Boost.Thread定义了一系列的中断点，例如 sleep() 函数。 
由于 sleep() 在这个例子里被调用了五次，该线程就检查了五次它是否应该被中断。 
然而 sleep() 之间的调用，却不能使线程中断。

通俗的理解，可以把 interrupt 看做是软中断，来终结对应的线程
但是软中断的执行需要有 接收软中断的 函数存在才能够响应
正如例程中给出的结果一样，*_response 函数中 sleep 响应 interrupt
所以该线程确实会被终止掉
而 *_no_response 函数中并没有响应 interrupt 的函数存在，故并不对
中断做出任何响应，线程正常执行，正常结束
```

2. 输出结果分析
```c++
输出结果
	/* test #1 response interrupt */
	parallel thread: 0
	parallel thread: 1
	start interrupting the thread!
	thread is interrupted!
	/* test #2 no response */
	parallel thread: 0
	start interrupting the thread!
	parallel thread: 1
	parallel thread: 2
	parallel thread: 3
	parallel thread: 4
```
如果需要线程响应 interrupt ，那么该线程中必须存在能够响应 interrupt 的函数才可以。

#### 03_mutex
1. 知识点
```c++
互斥信号量 boost::mutex mutex;
获得信号量 mutex.lock();
释放信号量 mutex.unlock();

标准输出流是一个 全局性的 被所有线程共享的对象。 
该标准不提供任何保证 std::cout 可以安全地从多个线程访问。 
因此，访问标准输出流必须同步：在任何时候，只有一个线程可以访问 std::cout。
```

#### 04_lock
1. 知识点
```c++
boost::lock_guard<boost::mutex> lock(mutex);
boost::lock_guard 在其内部构造和析构函数分别自动调用 lock() 和 unlock()
故不需要手动进行 lock() 和 unlock() 操作

boost::timed_mutex 需要额外的动态链接库 -lpthread

boost::unique_lock<boost::shared_mutex> unique_lock;
boost::shared_lock<boost::shared_mutex> 类型的非独占锁可以在线程只对某个资源读访问的情况下使用。 
一个线程修改的资源需要写访问，因此需要一个独占锁；
只需要读访问的线程不需要知道同一时间其他线程是否访问，因此非独占锁可以共享一个互斥体。
```

#### 05_condition_variable
1. 知识点
```c++
from: http://www.cplusplus.com/reference/condition_variable/condition_variable/wait/
	The execution of the current thread 
	(which shall have locked lck's mutex) is blocked until notified.
	At the moment of blocking the thread, the function automatically calls lck.unlock(), 
	allowing other locked threads to continue.
	Once notified (explicitly, by some other thread), 
	the function unblocks and calls lck.lock(), leaving lck in the same state 
	as when the function was called. Then the function returns 
	(notice that this last mutex locking may block again the thread before returning).
```
