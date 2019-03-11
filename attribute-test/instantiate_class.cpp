#include <iostream>
#include <cassert>

#include <string>
#include <vector>
#include <map>

using namespace std;

//template <typename T>
class SolverParameter
{
public:
	SolverParameter() {cout << "SolverParameter constructor" << endl;}
};

template <typename T>
class SolverRegistry
{
public:
	SolverRegistry(const string& type, int* (*creator)(const SolverParameter&));
	static void AddCreator(const string& type, int* (*creator)(const SolverParameter&))
	{
		cout << "AddCreator" << endl;
	}
};

template <typename T>
class SolverRegisterer
{
public:
	SolverRegisterer(const string& type, int* (*creator)(const SolverParameter&));
};

// Instantiate a class with float and double specifications.
#define INSTANTIATE_CLASS(classname) \
  char gInstantiationGuard##classname; \
  template class classname<float>; \
  template class classname<double>

template <typename Dtype>
SolverRegisterer<Dtype>::SolverRegisterer(
    const string& type, int* (*creator)(const SolverParameter&)) {
  SolverRegistry<Dtype>::AddCreator(type, creator);
  cout << "SolverRegisterer constructor" << endl;
}

INSTANTIATE_CLASS(SolverRegistry);
INSTANTIATE_CLASS(SolverRegisterer);

int *test_func(const SolverParameter&)
{
	cout << test_func << endl;
	int *test_int = new int;
}

class private_class
{
public:
	int count;
	//static int count;
	//static int static_int;
	//static 函数中不可再用static变量了 
	static private_class &get_private_class() {
		static private_class *private_class_ = new private_class;
		//cout << "count = " << (*private_class_).count << endl;
		cout << "count = " << private_class_->count++ << endl;
		//private_class::count++;
		//(*private_class_).count++;
		return *private_class_;
	}
	
private:
	private_class(): count(0){
		cout << "private_class" << endl;
	}
};

int main(int argc, char **argv)
{
	class SolverRegisterer<float> test("alsd", test_func);
	
	private_class::get_private_class();
	private_class::get_private_class();
	private_class::get_private_class();
	private_class::get_private_class();
	
	return 0;
}
