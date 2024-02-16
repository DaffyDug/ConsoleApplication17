#pragma once
#include "Cell.h"
class QueueCell
{
	Cell* cell;
	QueueCell* address;
public :
	QueueCell(Cell* cell, QueueCell* address)
	{
		this->cell = cell;
		this->address = address;
	}

	QueueCell* getAddress()
	{
		return address;
	}
	void setAddress(QueueCell* address)
	{
		this->address = address;
	}

	void setCell(Cell* cell)
	{
		this->cell = cell;
	}
	Cell* getCell()
	{
		return cell;
	}
};