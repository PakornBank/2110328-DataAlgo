#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T& value) {
    // write your code here
    push(value);
    for (size_t i = 0; i < pos; ++i) {
        std::swap(mData[mSize - i - 1], mData[mSize - i - 2]);
    }
}

#endif
