#include <queuelst/queuelst.hpp>
#include <stdexcept>
#include <iostream>

QueueLst::~QueueLst() {
	Node* current = head_idx;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

QueueLst::QueueLst() :
	head_idx(nullptr), tail_idx(nullptr)
{
}

QueueLst& QueueLst::operator=(const QueueLst& another) {
	if (&another == this) {
		return *this;
	}
	if (this != &another) {
		Node* current = head_idx;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}
	if (another.head_idx == nullptr) {
		head_idx = nullptr;
		tail_idx = nullptr;
	}
	else {
		Node* another_current = another.head_idx;
		head_idx = new Node(another_current->v);
		Node* tail_idx = head_idx;
		Node* last = head_idx;
		another_current = another_current->next;

		while (another_current != nullptr) {
			last->next = new Node(another_current->v);
			last = last->next;
			another_current = another_current->next;
		}
		tail_idx = last;
		tail_idx->next = nullptr;
	}
	return *this;
}

QueueLst::QueueLst(const QueueLst& another)
{
	if (another.head_idx == nullptr) {
		head_idx = nullptr;
		tail_idx = nullptr;
	}
	else {
		Node* another_current = another.head_idx;
		head_idx = new Node(another_current->v);
		Node* last = head_idx;
		another_current = another_current->next;

		while (another_current != nullptr) {
			last->next = new Node(another_current->v);
			last = last->next;
			another_current = another_current->next;
		}
		tail_idx = last;
		tail_idx->next = nullptr;
	}
}

void QueueLst::Push(Complex value) {
	Node* new_tail = new Node(value);
	if (head_idx == nullptr) {
		head_idx = new_tail;
		tail_idx = new_tail;
	}
	else {
		tail_idx->next = new_tail;
		tail_idx = new_tail;
		tail_idx->next = nullptr;
	}
}

bool QueueLst::IsEmpty() const {
	return head_idx == nullptr;
}

int QueueLst::Size() const {
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

Complex& QueueLst::Top() const {
	if (IsEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return head_idx->v;
}

void QueueLst::Pop() {
	if (!IsEmpty()) {
		Node* current = head_idx->next;
		delete head_idx;
		head_idx = current;
	}
	else {
		tail_idx = nullptr;
	}
}