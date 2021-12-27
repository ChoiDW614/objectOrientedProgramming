/*
#include <iostream>
#include <memory>

int main() {
	std::shared_ptr<int> ptr(new int(3));
	*ptr = 10;
	std::cout << *ptr << std::endl;

	std::shared_ptr<int> ptr1 = ptr;
	std::cout << ptr.use_count() << std::endl;
	ptr.reset();
	ptr1.reset();
	return 0;

	std::unique_ptr<int> ptr2 = std::make_unique<int>(3);
	std::unique_ptr<int> ptr3 = std::move(ptr2);
	ptr2.reset();
	ptr3.reset();
	return 0;
}
*/