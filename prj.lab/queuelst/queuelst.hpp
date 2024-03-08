#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class QueueLst {
private:
	struct Node {
		Complex v;
		Node* next = nullptr;
		Node(const Complex& value, Node* n = nullptr) : v(value), next(n) {}
	};
	Node* head_idx;
	Node* tail_idx;

public:
	QueueLst();
	QueueLst(const QueueLst& another);
	~QueueLst();

	QueueLst& operator=(const QueueLst& another);

	void Push(Complex value);
	bool IsEmpty() const;
	int Size() const;
	Complex& Top() const;
	void Pop();
};

#endif