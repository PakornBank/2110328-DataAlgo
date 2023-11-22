#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  size_t range = last - first;
  size_t size = mSize + range ;
  size_t pos = position - begin();
  size_t posTo = (position - begin()) + range;
  ensureCapacity(size);
  
  
  for(size_t i = size ; i > posTo ; --i){
    mData[i - 1] = mData[i-range-1];
  }
  int in = 0;
  for(size_t i = pos ; i < posTo ; ++i){
    mData[i] = *first++;
  }
  mSize += range;
}

#endif

