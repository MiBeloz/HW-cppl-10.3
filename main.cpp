#include <iostream>
#include <memory>

#include "unique_ptr.h"

template<typename T>
void print_ptr(T& ptr, T& ptr2);

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tstd::unique_ptr своими руками\n" << std::endl;

	std::cout << "std::unique_ptr:" << std::endl;
	std::unique_ptr<int> orig_unique_ptr(new int(7));
	std::unique_ptr<int> orig_unique_ptr2(new int(5));
	print_ptr(orig_unique_ptr, orig_unique_ptr2);
	std::cout << std::endl << std::endl;

	std::cout << "unique_ptr(своя реализация):" << std::endl;
	unique_ptr<int> my_unique_ptr(new int(7));
	unique_ptr<int> my_unique_ptr2(new int(5));
	print_ptr(my_unique_ptr, my_unique_ptr2);

	system("pause > nul");
	return 0;
}

template<typename T>
void print_ptr(T& ptr, T& ptr2) {
	std::cout << "\tАдрес: " << ptr << std::endl;

	std::cout << "\tЗначение: " << *ptr << std::endl << std::endl;

	std::cout << "\tМетод 'get()': " << ptr.get() << " : " << *ptr << std::endl;
	std::cout << "\tМетод 'get()' у unique_prt2: " << ptr2.get() << " : " << *ptr2 << std::endl << std::endl;
	
	std::cout << "\tМетод 'swap()': " << std::endl;
	ptr.swap(ptr2);
	std::cout << "\tМетод 'get()': " << ptr.get() << " : " << *ptr << std::endl;
	std::cout << "\tМетод 'get()' у unique_prt2: " << ptr2.get() << " : " << *ptr2 << std::endl << std::endl;

	std::cout << "\tАдрес: " << ptr << std::endl;

	std::cout << "\tМетод 'operator bool()': " << std::boolalpha << ptr.operator bool() << std::endl;
	std::cout << "\tМетод 'reset()': " << std::endl;
	ptr.reset();
	std::cout << "\tМетод 'operator bool()': " << std::boolalpha << ptr.operator bool() << std::endl;
	std::cout << "\tАдрес: " << ptr << std::endl;
}
