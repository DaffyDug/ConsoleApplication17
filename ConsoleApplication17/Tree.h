#pragma once
#include "Cell.h"
#include "Queue.h"
class Tree
{
	Cell* cell;
	Queue* que;
public:
	Cell* getCell()
	{
		return cell;
	}
	Tree()
	{
		cell = new Cell("Я", 1, nullptr);
		cell->setRight(new Cell("Мама", 2, cell));
		cell->setLeft(new Cell("Папа", 3, cell));
		cell->getRight()->setRight(new Cell("Бабушка, по маминой линии", 4, cell->getRight()));
		cell->getRight()->setLeft(new Cell("Дедушка, по маминой линии", 5, cell->getRight()));
		cell->getLeft()->setRight(new Cell("Бабушка, по папиной линии", 6, cell->getLeft()));
		cell->getLeft()->setLeft(new Cell("Дедушка, по папиной линии", 7, cell->getLeft()));
		cell->getRight()->getRight()->setRight(new Cell("Прабабушка 1", 8, cell->getRight()->getRight()));
		cell->getRight()->getRight()->setLeft(new Cell("Прадедушка 1", 9, cell->getRight()->getRight()));
		cell->getRight()->getLeft()->setRight(new Cell("Прабабушка 2", 8, cell->getRight()->getLeft()));
		cell->getRight()->getLeft()->setLeft(new Cell("Прадедушка 2", 9, cell->getRight()->getLeft()));
		
		cell->getLeft()->getRight()->setRight(new Cell("Прабабушка 3", 8, cell->getLeft()->getRight()));
		cell->getLeft()->getRight()->setLeft(new Cell("Прадедушка 3", 9, cell->getLeft()->getRight()));
		cell->getLeft()->getLeft()->setRight(new Cell("Прабабушка 4", 8, cell->getLeft()->getLeft()));
		cell->getLeft()->getLeft()->setLeft(new Cell("Прадедушка 4", 9, cell->getLeft()->getLeft()));
	}
	void WidthSearch(Cell* cell, int number)
	{
		if (number == cell->getNum())
		{
			std::cout << cell->getInfo() << std::endl;
		}

		if (cell->getLeft() != nullptr)
		{
			que->Push(new QueueCell(cell->getLeft(), nullptr));
		}

		if (cell->getRight() != nullptr)
		{
			que->Push(new QueueCell(cell->getRight(), nullptr));
		}

		WidthSearch(que->Pop(), number);
	}

	void DeepSearch(Cell* cell, int number)
	{
		//std::cout << cell->getNum() << " ";
		if (number == cell->getNum() && cell->getWasHere()==false)
		{
			std::cout << cell->getInfo() << std::endl;
		}
		cell->setWasHere(true);
		if (cell->getLeft() != nullptr && cell->getLeft()->getWasHere() ==false)
		{
			DeepSearch(cell->getLeft(), number);
		}
		else if(cell->getRight() != nullptr && cell->getRight()->getWasHere() == false)
		{
			DeepSearch(cell->getRight(), number);
		}
		else if (cell->getParent() != nullptr)
		{
			DeepSearch(cell->getParent(), number);
		}
	}
};

