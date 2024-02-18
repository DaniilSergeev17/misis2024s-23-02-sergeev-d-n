#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackLst {
private:
	struct Node {
		Complex v;
		Node* next = nullptr;
		Node(const Complex& value, Node* n = nullptr) : v(value), next(n) {}
	};
	Node* head_idx;

public:
	StackLst();
	StackLst(const StackLst& another);
	~StackLst();

	StackLst& operator=(const StackLst& another);

	void push(Complex value);
	bool is_empty() const;
	int get_size() const;
	Complex& top() const;
	void pop();
};

#endif