#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int iData = 0;
  int iPos = 0;
  int iNew = 0;
  for (;iData < mSize;iData++) {
    if(iPos < pos.size() && iData == pos[iPos]){
      iPos++;
    }
    else{
      mData[iNew++] = mData[iData];
    }
  }
  mSize = mSize - pos.size();
    
}

#endif
