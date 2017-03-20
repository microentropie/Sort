#ifndef _SORT_BUBBLE_
#define _SORT_BUBBLE_
/*
Author:  Stefano Di Paolo
License:  MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2016-12-18

Sort an array of objects.
In form of a C++ template libray, particularly suited for micros
thanks to the low memory usage.

Bubble Sort, from Wikipedia presudo-code
https://en.wikipedia.org/wiki/Bubble_sort

Supply a comparation function and it will sort any kind of objects.
The compare function inputs 2 pointers (to 2 instances of the object)
and returns:
* 0  if the objects (e1 and e2) are equals
* <0 if e1 < e2
* >0 id e1 > e2

Sources repository: https://github.com/microentropie/Sort
How to install:
  https://www.arduino.cc/en/guide/libraries
*/



#include "sort_compare_numeric.h"

// classic Bubble Sort
// sort an array of pointers
// to be preferred !
template<typename T>
void bubbleSort(T *Ary[], int qtElem, int(*compareFn)(T *e1, T *e2))
{
  int i, j;
  T *pTemp;

  for (i = 0; i < qtElem; i++)
  {
    for (j = i + 1; j < qtElem; j++)
    {
      if (compareFn(Ary[i], Ary[j]) > 0)
      {
        // swap pointers
        pTemp = Ary[i];
        Ary[i] = Ary[j];
        Ary[j] = pTemp;
      }
    }
  }
}

// classic Bubble Sort (low memory usage)
// sort an array of T objects
// entire T objects are swapped instead of their pointers
// this means a lot of memory copy operations, acceptable
// only if T is small (i.e. sizeof(T) <= sizeof(*T)).
// NOTE: the size of a pointer is 4 byte for 32 bit systems.
template<typename T>
void bubbleSort(T Ary[], int qtElem, int(*compareFn)(T *e1, T *e2))
{
  int i, j;
  T temp;

  for (i = 0; i < qtElem; i++)
  {
    for (j = i + 1; j < qtElem; j++)
    {
      if (compareFn(&Ary[i], &Ary[j]) > 0)
      {
        // swap T instance
        temp = Ary[i];
        Ary[i] = Ary[j];
        Ary[j] = temp;
      }
    }
  }
}


// simplified method for numeric arrays or
// arrays of objects where a subtraction operator is defined
template<typename T>
void bubbleSort(T Ary[], int qtElem)
{
  bubbleSort(Ary, qtElem, compareNumeric<T>);
}

#endif //_SORT_BUBBLE_
