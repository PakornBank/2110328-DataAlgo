#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
#include <unordered_set>
#include <algorithm>

//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  std::unordered_set<T> dataSet;
  CP::vector<T> newVec;
  
  for(const auto& i : *this){
    if(dataSet.find(i) == dataSet.end()){
      newVec.push_back(i);
      dataSet.insert(i);
    }
  }
  *this = newVec;
}
#endif
