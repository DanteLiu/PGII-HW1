#include "HugeUInteger.h"
#include <iostream>
#include <math.h>

using namespace std;

HugeUInteger::HugeUInteger()
{
	isbigger = true;
}
HugeUInteger::HugeUInteger(HugeUInteger &in)
{

}
void HugeUInteger::random(unsigned int size)
{
	_size = size;
	for (int i = 1; i <= size;i++)
		integers.push_back(rand() % 9 + 1);
}
void HugeUInteger::add(HugeUInteger &add)
{
	int carry = 0, size_d;
	if (_size > add._size)
	{
		size_d = _size - add._size;
		for (int i = 0; i < size_d; i++)
			add.integers.push_back(0);
	}
		
	else if (_size < add._size)
	{
		size_d = add._size - _size;
		for (int i = 0; i < size_d; i++)
			integers.push_back(0);
		_size = _size + size_d;
	}
		
	
	for (int i = 0; i < _size; i++)
	{
		integers[i] = integers[i] + add.integers[i] + carry;
		if (integers[i] < 10)
			carry = 0;
		else
		{
			integers[i] -= 10;
			carry = 1;
		}
	}
	if (carry == 1)
		integers.push_back(1);
}
void HugeUInteger::subtract(HugeUInteger &sub)
{
	
	if (_size < sub._size)
		isbigger = false;
	else
	{
		int borrow = 0;
		if (_size > sub._size)
		{
			int size_d = _size - sub._size;
			for (int i = 0; i < size_d; i++)
				sub.integers.push_back(0);
		}

		for (int i = 0; i < _size; i++)
		{
			integers[i] = integers[i] - sub.integers[i] - borrow;
			if (integers[i] >= 0)
				borrow = 0;
			else
			{
				integers[i] += 10;
				borrow = 1;
			}
		}
		if (borrow != 0)
			isbigger = false;
	}

}
void HugeUInteger::print()
{
	if (!isbigger)
		cout << "(negative)0" << endl;
	else
	{
		for (int i = integers.size() - 1; i >= 0; i--)
		{
			if (i == integers.size() - 1 && integers[i] == 0)
				continue;
			cout << integers[i];
		}
	}
	
}