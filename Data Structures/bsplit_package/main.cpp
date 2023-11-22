#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "map_bst.h"
#include "student.h"
// #pragma once

int main() {
    // std::vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<int> v = {58, 89, 43, 94, 66, 10, 68, 91, 53, 31, 65, 52, 17, 71, 55, 98, 49, 9, 32, 14, 79, 81, 41, 60, 23, 97, 3, 26, 72, 28, 12, 56, 39, 46, 78, 84, 4, 85, 2, 1, 70, 90, 61, 62, 99, 51, 34, 16, 57, 35, 80, 13, 77, 87, 45, 76, 19, 40, 93, 92, 86, 37, 20, 5, 82, 100, 8, 47, 11, 29, 54, 73, 69, 24, 48, 50, 95, 30, 21, 6, 63, 83, 59, 7, 75, 22, 27, 64, 33, 38, 18, 67, 96, 25, 15, 88, 74, 44, 36, 42};
    // std::vector<int> v = {30, 70, 40, 20, 10, 80, 50, 60, 90, 100};
    // std::reverse(v.begin(), v.end());

    // add value from v to m
    CP::map_bst<int, int>
        m1,
        m2;
    for (auto x : v) {
        m1[x] = -x;
    }

    int val = 70;
    printf("The \"original\"  tree\n");
    m1.print();
    m2 = m1.split(val);

    // check
    bool ok = true;
    for (auto &x : v) {
        if (x < val && (m1.find(x) == m1.end() || m2.find(x) != m2.end())) {
            ok = false;
            break;
        }
        if (x >= val && (m2.find(x) == m2.end() || m1.find(x) != m1.end())) {
            ok = false;
            break;
        }
    }

    printf("Start checking...\n");
    printf("The \"less than\"  tree\n");
    m1.print();
    printf("The \"equal or more than\" tree\n");
    m2.print();
    if (ok) {
        printf("OK\n");
    } else {
        printf("WRONG\n");
    }

    return 0;
}
