#pragma once

#define MAX 10

template <class T> class ListOf
{
	T* list[MAX];
	int number;
public:
	ListOf(void);
	~ListOf(void);

	void operator+=(T* t);
	void pop();
	T operator[](int index);
};

#include "ListOf.hpp"

