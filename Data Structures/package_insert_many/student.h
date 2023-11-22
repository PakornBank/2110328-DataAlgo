#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include <map>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  std::map<int,T> m;
  for(const auto& i : data){
    m[i.first] = i.second;
  }
  auto it = m.begin();
  long long index = 0;
  CP::vector<T> vec;

  for(int i = 0 ; i < mSize ; ++i){
    if(it != m.end() && i == it->first){
      vec.push_back(it->second);
      ++it;
    }
    vec.push_back(mData[i]);
  }
  if(it != m.end()){
    vec.push_back(it->second);
  }

  *this = vec;

}

#endif
