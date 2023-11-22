
void shift(int k) {
    // TODO: Add your code here
    auto it = mHeader->next;
    int num = mSize;
    k = (k % num);
    if (k < 0) {
        k += mSize;
    }
    // don't mod negative number with unsigned number, convert them to int first
    for (size_t i = 0; i < k; ++i) {
        it = it->next;
    }
    mHeader->prev->next = mHeader->next;
    mHeader->next->prev = mHeader->prev;
    mHeader->next = it;
    mHeader->prev = it->prev;
    it->prev->next = mHeader;
    it->prev = mHeader;
}
