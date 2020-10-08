#include "text.h"

ZZ::ZZ (int k, int n) //создает пустой
{
	n_ = n;
	k_ = k; // c 1
	mas_ = new int[n];
	for(int i = 0; i < n;i++)
	{
		mas_[i] = 0;
	}
	//size_ = 1;
}

void ZZ::name (int temp)
{
	mas_[k_ - 1] = temp;
}

void ZZ::message (ZZ to)
{
	if(k_ > to.k_)
	{
		return;
	}
	for(int i = 0;i < k_;i++)
	{
		to.mas_[i] = mas_[i];
	}
}

bool ZZ::operator <(const ZZ b) // a < b
{
	if(n_ != b.n_)
	{
		return false; // ошибка
	}
	if(k_ == b.k_)
	{
		if(mas_[k_ - 1] < b.mas_[k_ - 1])
		{
			return true;
		}
		return false;
	}
	int temp = Min(k_, b.k_);
	for(int i = 0;i < temp; i++)
	{
		if(mas_[i] != b.mas_[i])
			return false; //ошибка
	}
	if(mas_[temp + 1] < b.mas_[temp + 1])
		return true;
	return false;
}

void ZZ::print() const
{
	printf("(");
	for(int i = 0;i < n_;i++)
	{
		printf("%d ", mas_[i]);
	}
	printf(") ");
}
ZZ::~ZZ()
{
	n_ = 0;
	k_ = 0;
	delete[] mas_;
}
/*UserException::UserException(int code, string message) : code_(code), message_(message) {}

string UserException::message() const {
	return message_;
}

int UserException::code() const {
	return code_;
}*/