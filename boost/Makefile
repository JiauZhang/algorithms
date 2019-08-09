all:
	@echo "please specity the specific target"

BOOST_LIB_COMMON = -lboost_system -lboost_thread

01_basic_thread: 01_basic_thread.cpp
	g++ -o 01_basic_thread.o $^ $(BOOST_LIB_COMMON)

02_interrupt_thread: 02_interrupt_thread.cpp
	g++ -o 02_interrupt_thread.o $^ $(BOOST_LIB_COMMON)