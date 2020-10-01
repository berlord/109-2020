#include <iostream>
#include "intset.h"

intset::intset(int minval, int maxval)
{
	size_ = 0;
	maxval_ = maxval;
	minval_ = minval;
	std::cout << minval_ << ", " << maxval_ << "\n";
}

intset::~intset()
{
	if (size_ != 0)
		delete[] ar_;
	size_ = 0;
	minval_ = 0;
	maxval_ = 0;
}

intset::intset(intset& IS)
{
	if (IS.size_ <= 0)
		return;
	minval_ = IS.minval_;
	maxval_ = IS.maxval_;
	ar_ = new int[IS.size_];
	size_ = IS.size_;
	for (int i = 0; i < IS.size_; i++)
		ar_[i] = IS.ar_[i];
	
	std::cout << size_ << " " << minval_ << " " << maxval_ << "\n";
	for (int i = 0; i < size_; i++)
	std::cout << ar_[i] << "\n";
}

void intset::put(int item)
{
	if ((item > maxval_) || (item < minval_))
		return;
	int *ar;
	ar = new int[size_ + 1];
	for (int i = 0; i < size_; i++)
		ar[i] = ar_[i];
	ar[size_] = item;
	if (size_ > 0)
		delete[] ar_;
	size_++;
	ar_ = ar;
}

void intset::del(int item)
{
	if (size_ == 0)
		return;
	for (int i = 0, j = 0; i <= size_ ; i++)
	{
		if (i >= size_)
		{
			size_ = j;
			if (size_ == 0)
			{
				delete[] ar_;
			}
		}
		if (ar_[i] != item)
		{
			ar_[j] = ar_[i];
			j++;
		}
	}
}

bool intset::is_emtpy()
{
	if (size_ == 0)
		return 1;
	return 0;
}

int main(void)
{
	intset IS(-2, 2);
	std::cout << IS.is_empty() << "\n";
	IS.put(1);
	IS.put(1);
	IS.put(2);
	IS.put(2);
	IS.del(1);
	intset IS1(IS);
	std::cout << IS.is_empty() << "\n";
	return 0;
}
