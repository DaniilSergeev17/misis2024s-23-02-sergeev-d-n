#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

class QueueLstPr {
private:
	struct Node {
		double v;
		Node* next = nullptr;
		Node(const double& value, Node* n = nullptr) : v(value), next(n) {}
	};
	Node* head_idx; // min_value
public:
	QueueLstPr();
	QueueLstPr(const QueueLstPr& another);
	~QueueLstPr();

	QueueLstPr& operator=(const QueueLstPr& another);

	void Push(double value);
	bool IsEmpty() const;
	int Size() const;
	double& Top() const;
	void Pop();
};


#endif