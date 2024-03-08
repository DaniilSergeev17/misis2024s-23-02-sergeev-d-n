#include <stackarr/stackarr.hpp>
#include <stdexcept>
#include <iostream>

QueueArr::~QueueArr() {
	delete[] elements_ptr;
}

QueueArr::QueueArr(int size_) :
	size(size_), head_idx(-1), tail_idx(-1)
{
	elements_ptr = new Complex[size];
}

QueueArr& QueueArr::operator=(const QueueArr& another) {
	if (&another != this) { // проверка на самоприсваивание
		delete[] elements_ptr;
		size = another.size;
		head_idx = another.head_idx;
		tail_idx = another.tail_idx;
		elements_ptr = new Complex[size];

		int current_idx = head_idx;
		while (current_idx != tail_idx) {
			elements_ptr[current_idx] = another.elements_ptr[current_idx];
			current_idx = (current_idx + 1) % size;
		}
	}
	return *this;
}


QueueArr::QueueArr(const QueueArr& another) :
	size(another.size), head_idx(another.head_idx),
	tail_idx(another.tail_idx), elements_ptr(new Complex[size])
{
	int current_idx = head_idx;
	while (current_idx != tail_idx) {
		elements_ptr[current_idx] = another.elements_ptr[current_idx];
		current_idx = (current_idx + 1) % size;
	}
}

void QueueArr::Push(Complex value) {
	int new_tail_idx = (tail_idx + 1) % size;
	if (new_tail_idx != head_idx) {
		elements_ptr[tail_idx] = value;
		tail_idx = new_tail_idx;
	}
	else {
		// буфер полон
		// поэтому выделим новый буфер большего размера
		int new_size = size * 2;
		Complex* new_elements_ptr = new Complex[new_size];

		// копируем элементы из старого буфера в новый
		int current_idx = head_idx;
		for (int i = 0; i < size; i += 1) {
			new_elements_ptr[i] = elements_ptr[current_idx];
			current_idx = (current_idx + 1) % size;
		}

		delete[] elements_ptr;
		elements_ptr = new_elements_ptr;
		size = new_size;

		head_idx = 0;
		tail_idx = size / 2; // так как размер * 2, то хвост будет в середине

		elements_ptr[tail_idx] = value;
		tail_idx += 1;
	}
}

bool QueueArr::IsEmpty() const {
	return head_idx == -1;
}

int QueueArr::Size() const {
	if (head_idx == tail_idx) {
		return 0;
	}
	else if (tail_idx > head_idx) {
		return tail_idx - head_idx + 1;
	}
	else {
		return size - head_idx + tail_idx + 1;
	}
}

Complex& QueueArr::Top() const {
	if (IsEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return elements_ptr[head_idx];
}

void QueueArr::Pop() {
	if (!IsEmpty()) {
		head_idx = (head_idx + 1) % size;
	}
}