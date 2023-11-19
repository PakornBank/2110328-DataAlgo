#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
    // your code here
    CP::map_bst<KeyT, MappedT, CompareT> result;

    node* it = mRoot;
    node* itResult = NULL;
    // ***careful a-jarn check for new node, delete node or modified node
    while (it) {
        if (compare(it->data.first, val) != -1) {
            if (it->left) {
                it->left->parent = it->parent;
            }
            if (it->parent) {
                it->parent->right = it->left;
            } else {
                mRoot = it->left;
            }
            auto v = it->data.first;

            result.child_link(itResult, v) = it;
            it = it->left;
            result.child_link(itResult, v)->left = NULL;
            result.child_link(itResult, v)->parent = itResult;
            itResult = result.child_link(itResult, v);

            if (compare(itResult->data.first, val) == 0) {
                break;
            }
        } else {
            it = it->right;
        }
    }
    return result;
}
#endif
