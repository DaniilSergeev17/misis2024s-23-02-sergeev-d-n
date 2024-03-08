#include <stackarr/stackarr.hpp>
#include <stdexcept>
#include <iostream>

StackArr::~StackArr() {
	delete[] elements_ptr;
	size = 16;
	head_idx = -1;
	elements_ptr = nullptr;
}

StackArr::StackArr(int size_) :
	size(size_), head_idx(-1)
{
	elements_ptr = new Complex[size];
}

StackArr& StackArr::operator=(const StackArr& another) {
	if (&another != this) {
		delete[] elements_ptr;
		size = another.size;
		head_idx = another.head_idx;
		elements_ptr = new Complex[size*2];
		size *= 2;
		for (int i = 0; i <= another.head_idx; i += 1) {
			elements_ptr[i] = another.elements_ptr[i];
		}
	}
	return *this;
}

StackArr::StackArr(const StackArr& another) :
	size(another.size), head_idx(another.head_idx)
{
	elements_ptr = new Complex[size * 2];
	size *= 2;
	if (another.head_idx != -1) {
		for (int i = 0; i <= another.head_idx; i+=1) {
			elements_ptr[i] = another.elements_ptr[i];
		}
	}
}

void StackArr::Push(Complex value) {
	if (size - 1 == head_idx) {
		Complex* new_elements_ptr = new Complex[size*4];
		for (int i = 0; i <= head_idx; i += 1) {
			new_elements_ptr[i] = elements_ptr[i];
		}
		size *= 4;
		delete[] elements_ptr;
		elements_ptr = new_elements_ptr;
	}
	head_idx += 1;
	elements_ptr[head_idx] = value;
}

bool StackArr::IsEmpty() const {
	return head_idx == -1;
}

int StackArr::Size() const {
	return head_idx+1;
}

Complex& StackArr::Top() const {
	if (IsEmpty()) {
		throw std::out_of_range("Stack is empty");
	}
	return elements_ptr[head_idx];
}

void StackArr::Pop() {
	if (!IsEmpty()) {
		head_idx -= 1;
	}
}