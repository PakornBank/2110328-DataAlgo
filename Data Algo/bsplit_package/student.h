#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
    // your code here
    CP::map_bst<KeyT, MappedT, CompareT> result;

    node* it = mRoot;
    node* itResult;
    // ***careful a-jarn check for new node, delete node or modified node
    node* itResultPrev = NULL;
    node* itResultRoot = itResult;

    while (true) {
        if (!it) {
            break;
        }

        if (compare(it->data.first, val) != -1) {
            if (!result.mRoot) {
                if (it->left) {
                    it->left->parent = it->parent;
                }
                if (it->parent) {
                    it->parent->right = it->left;
                } else {
                    mRoot = it->left;
                }
                result.mRoot = it;
                it = it->left;
                result.mRoot->left = NULL;
                result.mRoot->parent = NULL;
                itResult = result.mRoot;
            } else {
                if (it->left) {
                    it->left->parent = it->parent;
                }
                if (it->parent) {
                    it->parent->right = it->left;
                } else {
                    mRoot = it->left;
                }
                itResult->left = it;
                it = it->left;
                itResult->left->left = NULL;
                itResult->left->parent = itResult;
                itResult = itResult->left;
            }

            if (compare(itResult->data.first, val) == 0) {
                break;
            }
        }

        else {
            it = it->right;
        }
    }

    return result;
}

#endif
