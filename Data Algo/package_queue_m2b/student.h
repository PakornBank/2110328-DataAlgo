#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  for (int i = pos; i < mSize - 1; ++i){
    std::swap(mData[(mFront + i)%mCap], mData[(mFront + i + 1)%mCap]);
  }
}

#endif
