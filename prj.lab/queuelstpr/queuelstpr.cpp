#include <queuelstpr/queuelstpr.hpp>
#include <stdexcept>
#include <iostream>
#include <limits>

QueueLstPr::~QueueLstPr() {
	Node* current = head_idx;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

QueueLstPr::QueueLstPr() :
	head_idx(nullptr)
{
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& another) {
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

QueueLstPr::QueueLstPr(const QueueLstPr& another) {
	head_idx = nullptr;
	Node* last = nullptr; 
	
	for (Node* current_another = another.head_idx; current_another != nullptr; current_another = current_another->next) {
		Node* new_node = new Node(current_another->v);

		if (last != nullptr) {
			last->next = new_node;
		}
		else {
			head_idx = new_node;
		}

		last = new_node;
	}
}


void QueueLstPr::Push(double val) {
	Node* new_node = new Node(val);
	if (head_idx == nullptr) {
		head_idx = new_node;
	}
	else {
		if (val < head_idx->v) {
			new_node->next = head_idx;
			head_idx = new_node;
		}
		else {
			Node* current = head_idx;
			while (current->next != nullptr && current->next->v < val) {
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}
}

bool QueueLstPr::IsEmpty() const {
	return head_idx == nullptr;
}

int QueueLstPr::Size() const {
	if (IsEmpty()) {
		return 0;
	}
	Node* current = head_idx;
	int k = 0;
	while (current != nullptr) {
		k += 1;
		current = current->next;
	}
	return k;
}

double& QueueLstPr::Top() const {
	if (IsEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return head_idx->v;
}

void QueueLstPr::Pop() {
	if (!IsEmpty()) {
		Node* current = head_idx->next;
		delete head_idx;
		head_idx = current;
	}
}