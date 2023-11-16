#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>
#include <vector>

#include "priority_queue.h"

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
    // write your code here
    // can include anything
    if (k == 1) {
        return mData[0];
    }
    if (k == 2) {
        if (mLess(mData[1], mData[2])) {
            return mData[2];
        } else
            return mData[1];
    }

    T maxT;
    if (mLess(mData[1], mData[2])) {
        maxT = mData[1];
    } else
        maxT = mData[2];
    for (int i = 3; i <= 6; ++i) {
        if (mLess(maxT, mData[i])) {
            maxT = mData[i];
        }
    }
    return maxT;
}

#endif
