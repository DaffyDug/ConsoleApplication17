#pragma once
#include "QueueCell.h"
class Queue
{
	QueueCell* first = nullptr;
	QueueCell* last = nullptr;
public:
	void Push(QueueCell* cell)
	{
		if (first == nullptr)
		{
			first = cell;
			last = cell;
		}
		else
		{
			last->setAddress(cell);
			last = cell;
		}
	}

	Cell* Pop()

	{
		Cell* result = first->getCell();
		first = first->getAddress();
		return result;
	}
};

