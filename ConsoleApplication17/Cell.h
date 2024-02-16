#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class Cell
{
	Cell* right;
	Cell* left;
	Cell* parent;
	char info[100];
	int num;
	bool wasHere;
public:
	Cell(const char info[], int num, Cell* parent)
	{
		wasHere = false;
		this->num = num;
		strcpy_s(this->info, info);
		this->parent = parent;
	}
	int getNum()
	{
		return num;
	}
	char* getInfo()
	{
		return info;
	}

	Cell* getLeft()
	{
		return left;
	}
	Cell* getRight()
	{
		return right;
	}
	Cell* getParent()
	{
		return parent;
	}
	bool getWasHere()
	{
		return wasHere;
	}

	void setWasHere(bool wasHere)
	{
		this->wasHere = wasHere;
	}

	void setRight(Cell* right)
	{
		this->right = right;
	}

	void setLeft(Cell* left)
	{
		this->left = left;
	}
};

