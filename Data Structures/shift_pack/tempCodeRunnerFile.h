void shift(int k) {
    // TODO: Add your code here
    auto it = mHeader->next;
    if (k < 0) {
        k += mSize;
    }
    for (size_t i = 0; i < k % mSize; ++i) {
        it = it->next;
    }
    mHeader->prev->next = mHeader->next;
    mHeader->next->prev = mHeader->prev;
    mHeader->next = it;
    mHeader->prev = it->prev;
    it->prev->next = mHeader;
    it->prev = mHeader;
}
