#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>>& ls) {
    // write your code here
    for (auto& tmp : ls) {
        end().ptr->prev->next = tmp.end().ptr->next;
        tmp.end().ptr->next->prev = end().ptr->prev;
        end().ptr->prev = tmp.end().ptr->prev;
        tmp.end().ptr->prev->next = end().ptr;
        tmp.end().ptr->next = tmp.end().ptr;
        tmp.end().ptr->prev = tmp.end().ptr;
        mSize += tmp.mSize;
        tmp.mSize = 0;
    }
}

#endif
