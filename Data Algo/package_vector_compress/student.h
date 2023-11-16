#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    if(mCap > mSize) {
      T *mNew = new T[mSize]();
      for (size_t i = 0;i < mSize;i++) {
        mNew[i] = mData[i];
      }
      delete [] mData;
      mData = mNew;
      mCap = mSize;
    }
}

#endif
