//#include "ListOf.h"
//
//
//template<class T> ListOf<T>::ListOf(void)
//{
//	for (int i=0; i < MAX; i++)
//		list[i] = NULL;
//	number = 0;
//}
//
//
//template<class T> ListOf<T>::~ListOf(void)
//{
//	pop();
//}
//
//template<class T> void ListOf<T>::operator+=(T* t)
//{
//	for (int i=0; i < number; i++)
//		if (list[i] == t)
//			return;
//	if (number < MAX)
//		list[number++] = t;
//}
//
//template<class T> void ListOf<T>::pop()
//{
//	for (int i=0; i < number; i++)
//		delete list[i];
//	number = 0;
//}
//
//template<class T> T ListOf<T>::operator[](int index)
//{
//	if (index < 0)
//		index = 0;
//	if (index >= number)
//		index = number - 1;
//	return *list[index];
//}