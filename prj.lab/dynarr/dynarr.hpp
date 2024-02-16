#pragma once
#ifndef DYNARR_DYNARR_HPP
#define DYNARR_DYNARR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

class DynArr {
public:
	DynArr() = default;
	DynArr(const DynArr& ) = default;
	DynArr(const std::ptrdiff_t size);
	~DynArr() ;
	
	DynArr& operator=(const DynArr& x);

	std::ptrdiff_t Size() const;
	void Resize(const std::ptrdiff_t size);
	float& operator[](const std::ptrdiff_t idx);
	const float& operator[](const std::ptrdiff_t idx) const;

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t capacity_ = 0; 
	float* data_ = nullptr;          
};

#endif
