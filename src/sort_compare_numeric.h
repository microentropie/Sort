/*
Author:  Stefano Di Paolo
License:  MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2016-12-18

compare method for the Sorting function.
Sources repository: https://github.com/microentropie/Sort
*/

// sorting method, valid for all the numeric types: char int long float double
template<typename T>
int compareNumeric(T *p1, T *p2)
{
  return *p1 - *p2;
}
