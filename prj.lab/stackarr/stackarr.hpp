#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackArr {
private:
	int size = 16;
	Complex* elements_ptr = nullptr;
	int head_idx = -1;
public:
	explicit StackArr(int size_ = 16);
	StackArr(const StackArr& another);
	~StackArr();

	StackArr& operator=(const StackArr& another);

	void Push(Complex value);
	bool IsEmpty() const;
	int Size() const;
	Complex& Top() const;
	void Pop();
};

#endif