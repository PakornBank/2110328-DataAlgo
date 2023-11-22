// Your code here

int imbalance(node* n, KeyT& ans, int& maxImbalance) {
    if (!n) {
        return -1;
    }
    int hl = imbalance(n->left, ans, maxImbalance);
    int hr = imbalance(n->right, ans, maxImbalance);
    int imb = hl - hr;
    if (imb < 0) {
        imb = -imb;
    }
    int h;
    if (hr > hl) {
        h = 1 + hr;
    } else {
        h = 1 + hl;
    }

    if (imb > maxImbalance) {
        maxImbalance = imb;
        ans = n->data.first;
    }
    if (imb == maxImbalance) {
        if (mLess(n->data.first, ans)) {
            ans = n->data.first;
        }
    }
    return h;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    KeyT ans = mRoot->data.first;
    node* n = mRoot;
    int maxImbalance = 0;
    imbalance(n, ans, maxImbalance);
    return ans;
}