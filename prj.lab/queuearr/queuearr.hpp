#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class QueueArr {
private:	
	int size = 16;
	Complex* elements_ptr = nullptr;
	int head_idx = -1;
	int tail_idx = -1;
public:
	explicit QueueArr(int size_ = 16);
	QueueArr(const QueueArr& another);
	~QueueArr();

	QueueArr& operator=(const QueueArr& another);

	void Push(Complex value);
	bool IsEmpty() const;
	int Size() const;
	Complex& Top() const;
	void Pop();
};


#endif