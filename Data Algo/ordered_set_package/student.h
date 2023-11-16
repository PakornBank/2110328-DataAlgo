#ifndef STUDENT_INCLUDED_
#define STUDENT_INCLUDED_

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> s;
    for(const auto& i : A){
        if(s.find(i) == s.end()){
            s.insert(i);
            v.push_back(i);
        }
    }
    for(const auto& i : B){
        if(s.find(i) == s.end()){
            s.insert(i);
            v.push_back(i);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> s;
    for(const auto& i : B){
        s.insert(i);        
    }
    for(const auto& i : A){
        if(s.find(i) != s.end()){
            v.push_back(i);
        }
    }
    return v;
}

#endif