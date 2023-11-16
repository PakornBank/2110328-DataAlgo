#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if((a >= b && b+m-1 >= a) || (b >= a && a+m-1 >= b) || m <= 0 || (a+m-1 >= end() || b+m-1 >= end())){
    return false;
  }
  for(int i = 0 ; i < m ; ++i){
    T temp = *(a+i);
    *(a+i) = *(b+i);
    *(b+i) = temp;
  }
  return true;
}

#endif
