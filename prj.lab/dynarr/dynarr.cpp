#include <dynarr/dynarr.hpp>
#include <stdexcept>
#include <iostream>
/*DynArr::DynArr(const DynArr& x)
	: size_(x.size_) {
	data_ = new float[x.size_];
	for (int i = 0; i < x.size_; i++) {
		*(data_ + i) = *(x.data_ + i);
	}
	capacity_ = size_;
}*/

DynArr::~DynArr() {
	delete[] data_;
	data_ = nullptr;
	capacity_ = 0;
}


DynArr::DynArr(const std::ptrdiff_t size) {
	if (size <= 0) {
		throw std::invalid_argument("Size cannot be negative");
	}
	else {
		size_ = size;
		capacity_ = size;
		data_ = new float[size];
		for (std::ptrdiff_t i = 0; i < size; ++i) {
			data_[i] = 0.0;
		}
	}
}

std::ptrdiff_t DynArr::Size() const { 
	return size_;
}


/*DynArr::DynArr(const DynArr& arr) {
	capacity_ = arr.Size();
	size_ = arr.Size();
	data_ = new float [size_];	
	for (std::ptrdiff_t i = 0; i < arr.size_; i++) {
		data_[i] = arr.data_[i];
	}
}*/

DynArr& DynArr::operator=(const DynArr& rhs) {
	if (&rhs != this) {
		delete[] data_;
		size_ = rhs.Size();
		capacity_ = rhs.Size();
		data_ = new float[size_];
		for (std::ptrdiff_t i = 0; i < size_; ++i) {
			data_[i] = rhs[i];
		}
	}
	return *this;
}

float& DynArr::operator[](const std::ptrdiff_t i) {
	if (0 <= i && i < size_) {
		return data_[i];
	}
	else {
		throw std::out_of_range("Out of range");
	}
}

const float& DynArr::operator[](const std::ptrdiff_t i) const {
	if (0 <= i && i < size_) {
		return data_[i];
	}
	else {
		throw std::out_of_range("Out of range");
	}
}

void DynArr::Resize(const std::ptrdiff_t size) {
	if (size < 1) {
		throw std::invalid_argument("Size cannot be negative");
	}
	else if (capacity_ <= size) {
		float* temp = new float[size * 2];
		for (std::ptrdiff_t i = 0; i < size * 2; i++) {
			temp[i] = 0;
		}
		for (std::ptrdiff_t i = 0; i < size_; i++) {
			temp[i] = data_[i];
		}
		size_ = size;
		capacity_ = size * 2;
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
	else {
		size_ = size;
		for (std::ptrdiff_t i = size; i < capacity_; i++) {
			data_[i] = 0.0;
		}
	}
}


/*void DynArr::Remove(std::ptrdiff_t index) {
	if (index<0 || index>size_) {
		throw out_of_range;
	}
	else {
		float last = data_[size_ - 1];
		this->Resize(size_ - 1);
		float* temp = new float[size_];
		for (std::ptrdiff_t i = 0; i < index; i++) {
			temp[i] = data_[i];
		}
		for (std::ptrdiff_t i = index; i < size_ - 1; i++) {
			temp[i] = data_[i + 1];
		}
		temp[size_ - 1] = last;
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
}

void DynArr::Insert(float val, std::ptrdiff_t index) {
	if (index<0 || index>size_) {
		throw out_of_range;
	}
	else {
		this->Resize(size_ + 1);
		float* temp = new float[size_];
		for (std::ptrdiff_t i = 0; i < index; i++) {
			temp[i] = data_[i];
		}
		temp[index] = val;
		for (std::ptrdiff_t i = index + 1; i < size_; i++) {
			temp[i] = data_[i - 1];
		}
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
}

void DynArr::Resize(const std::ptrdiff_t size) {
	if (size < 1) {
		throw out_of_range;
	}
	else if (capacity_ <= size) {
		float* temp = new float[size * 2];
		for (std::ptrdiff_t i = 0; i < size; i++) {
			temp[i] = 0;
		}
		for (std::ptrdiff_t i = 0; i < size_; i++) {
			temp[i] = data_[i];
		}
		size_ = size;
		capacity_ = size * 2;
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
	else {
		size_ = size;
		for (std::ptrdiff_t i = size; i < capacity_; i++) {
			data_[i] = 0;
		}
	}
}

void DynArr::remove(std::ptrdiff_t index) {
	if (index<0 || index>size_) {
		throw out_of_range;
	}
	else {
		this->resize(size_ - 1);
		float* temp = new float[size_ - 1];
		for (std::ptrdiff_t i = 0; i < index; i++) {
			temp[i] = data_[i];
		}
		for (std::ptrdiff_t i = index; i < size_ - 1; i++) {
			temp[i] = data_[i + 1];
		}
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
}

void DynArr::insert(float val, std::ptrdiff_t index) {
	if (index<0 || index>size_) {
		throw out_of_range;
	}
	else {
		this->resize(size_ + 1);
		float* temp = new float[size_ + 1];
		for (std::ptrdiff_t i = 0; i < index; i++) {
			temp[i] = data_[i];
		}
		temp[index] = val;
		for (std::ptrdiff_t i = index + 1; i < size_ + 1; i++) {
			temp[i] = data_[i - 1];
		}
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
}
*/