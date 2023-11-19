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
    /// careful a-jarn check new node bruh
    node* itResultPrev = NULL;
    node* itResultRoot = itResult;

    while (true) {
        if (!it) {
            break;
        }
        if (compare(it->data.first, val) == 0) {
            if (!result.mRoot) {
                if (it->left) {
                    it->left->parent = it->parent;
                }
                if (it->parent) {
                    it->parent->right = it->left;
                } else {
                    mRoot = it->left;
                }

                it->left = NULL;
                it->parent = NULL;
                result.mRoot = it;
                break;
            }
            if (it->left) {
                it->left->parent = it->parent;
            }
            if (it->parent) {
                it->parent->right = it->left;
            } else {
                mRoot = it->left;
            }
            it->left = NULL;
            it->parent = itResult;
            itResult->left = it;
            break;
        }

        else if (compare(it->data.first, val) == 1) {
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
                continue;
            }

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
            continue;
        }

        else {
            it = it->right;
            continue;
        }
    }

    return result;
}

#endif
