#include <stacklst/stacklst.hpp>
#include <stdexcept>
#include <iostream>

StackLst::~StackLst() {
	Node* current = head_idx;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

StackLst::StackLst() :
	head_idx(nullptr)
{
}

StackLst& StackLst::operator=(const StackLst& another) {
	if (&another == this) {
		return *this;
	}
	if (another.head_idx == nullptr) {
		head_idx = nullptr;
	}
	else {
		head_idx = new Node(another.head_idx->v);

		Node* current = head_idx;
		Node* another_current = another.head_idx->next;

		while (another_current != nullptr) {
			current = new Node(another_current->v);
			current = current->next;
			another_current = another_current->next;
		}
	}
	return *this;
}

StackLst::StackLst(const StackLst& another)
{
	if (another.head_idx == nullptr) {
		head_idx = nullptr;
	}
	else { 
		head_idx = new Node(another.head_idx->v);

		Node* current = head_idx;
		Node* anotherCurrent = another.head_idx->next;

		while (anotherCurrent != nullptr) {
			current->next = new Node(anotherCurrent->v);
			current = current->next;
			anotherCurrent = anotherCurrent->next;
		}
	}
}

void StackLst::push(Complex value) {
	Node* new_head = new Node(value);
	new_head->next = head_idx;
	head_idx = new_head;
}

bool StackLst::is_empty() const {
	return head_idx == nullptr;
}

int StackLst::get_size() const {
	if (head_idx == nullptr) {
		return 0;
	}
	else {
		int len = 1;
		Node* current = head_idx->next;
		while (current != nullptr) {
			len += 1;
			current = current->next;
		}
		return len;
	}
}

Complex& StackLst::top() const {
	if (is_empty()) {
		throw std::out_of_range("Stack is empty");
	}
	return head_idx->v;
}

void StackLst::pop() {
	if (!is_empty()) {
		Node* current = head_idx->next;
		delete head_idx;
		head_idx = current;
	}
}