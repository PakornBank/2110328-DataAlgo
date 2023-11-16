#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  for (long long i = 0; i < (b - a + 1) / 2; ++i){
    T temp = mData[(mFront + a + i) % mCap];
    mData[(mFront + mCap + a + i) % mCap] = mData[(mFront + b - i) % mCap];
    mData[(mFront + mCap + b - i) % mCap] = temp;
}
}
#endif
