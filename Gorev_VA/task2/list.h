#include <iostream>

template <class T>

class list
{
private:
	class node
	{
	public:
		T val_;
		node *next_;
	};
	node *base_; // "Empty" first element
	node *last_;
public:
	class iterator
	{
	private:
		node *current_;
	public:
		void go_next()
		{
			current_ = current_->next_;
		}
		T get_current_item()
		{
			return current_->val_;
		}
		bool is_last()
		{
			return (current_->next_ == 0);
		}
		friend list;
	};
	iterator begin()
	{
		iterator I;
		I.current_ = base_;
	}

	list() // create empty list
	{
		last_ = base_ = 0;
	}
	list(const list <T> &L)
	{
		node *N;
		last_ = base_ = 0;
		if (L.base_ != 0)
		{
			N = L.base_;
			add_item(L.base_->val_);
			N = N->next_;
			while (N != 0)
			{
				add_item(N->val_);
				N = N->next_;
			}
		}
	}
	T get_first_item() const
	{
		return base_->val_;
	}
	T get_last_item() const
	{
		return last_->val_;
	}
	bool is_empty() const
	{
		return (base_ == 0);
	}

	int add_item(const T item) // add item to the end of the list
	// return 1 if item - first created element
	// return 0 if item - not first created element
	{
		if (base_ == 0)
		{
			last_ = base_ = new node;
			base_->val_ = item;
			base_->next_ = 0;
			return 1;
		}

		node *new_element = new node;
		new_element->val_ = item;
		new_element->next_ = 0;
		last_->next_ = new_element;
		last_ = new_element;
		return 0;
	}
	int del_item() // delete item from the beginning of the list
	// return 0 if list is empty
	// return 1 if list is not empty
	{
		node *new_base;
		if (base_ == 0)
			return 0;
		new_base = base_->next_;
		if (last_ == base_)
			last_ = 0;
		delete base_;
		base_ = new_base;
		return 1;
	}

	int deletelist() // return number of deleted elements
	{
		node *N;
		if (base_ == 0)
			return 0;
		N = base_->next_;
		delete base_;
		base_ = N;
		return 1 + deletelist();
	}

	bool operator==(const list <T> &L) const
	{
		node *N1, *N2;
		N1 = base_;
		N2 = L.base_;
		while ((N1 != 0) && (N2 != 0))
		{
			if (N1->val_ != N2->val_)
				return 0;
			N1 = N1->next_;
			N2 = N2->next_;
		}
		if (N1 != N2)
			return 0;
		return 1;
	}
	list <T> &operator=(const list <T> &L)
	{
		if (base_ != L.base_)
		{
			list <T> new_list(L);
			deletelist();
			base_ = new_list.base_;
			last_ = new_list.last_;
		}
	}
};