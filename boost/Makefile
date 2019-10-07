all:
	@echo "please specity the specific target"

BOOST_LIB_COMMON = -lboost_system -lboost_thread

01_basic_thread: 01_basic_thread.cpp
	g++ -o 01_basic_thread.o $^ $(BOOST_LIB_COMMON)

02_interrupt_thread: 02_interrupt_thread.cpp
	g++ -o 02_interrupt_thread.o $^ $(BOOST_LIB_COMMON)

03_mutex: 03_mutex.cpp
	g++ -o 03_mutex.o $^ $(BOOST_LIB_COMMON)

# -lpthread used for boost::timed_mutex
LOCK_LIB = -lpthread $(BOOST_LIB_COMMON)

04_lock: 04_lock.cpp
	g++ -o 04_lock.o $^ $(LOCK_LIB)

05_condition_variable: 05_condition_variable.cpp
	g++ -o 05_condition_variable.o $^ $(BOOST_LIB_COMMON)

06_cooperation: 06_cooperation.cpp
	g++ -o 06_cooperation.o $^ $(BOOST_LIB_COMMON)