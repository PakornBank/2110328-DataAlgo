void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if (mSize == 0) {
        return;
    }
    auto it = mHeader;
    for (long long i = 0; i < (mSize + 1) / 2; ++i) {
        it = it->next;
    }
    // connect first element of x to last element of a
    node* t1 = list1.mHeader->prev;
    node* t2 = it->next->prev;
    node* t3 = list1.mHeader->prev->next;
    node* t4 = mHeader->next;
    node* t5 = list2.mHeader->prev;
    node* t6 = mHeader->prev;
    node* t7 = list2.mHeader->prev->next;
    node* t8 = it->next;

    if (mSize > 1) {
        it->next->prev = t5;
        list2.mHeader->prev->next = t8;
        list2.mHeader->prev = t6;
        mHeader->prev->next = t7;
    }

    list1.mHeader->prev->next = t4;
    mHeader->next->prev = t1;
    it->next = t3;
    list1.mHeader->prev = t2;

    mHeader->next = mHeader;
    mHeader->prev = mHeader;

    list1.mSize += (mSize + 1) / 2;
    list2.mSize += (mSize) / 2;
    mSize = 0;
}
