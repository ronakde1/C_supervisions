#include <stdlib.h>
#include <stdio.h>
typedef struct tree {int val; struct tree* left; struct tree* right; struct tree* parent;} tree;

void swap(tree* a, tree* b){
    int temp = a-> val;
    a -> val = b-> val;
    b -> val = temp;
}

void heapify_up(tree* node) {
    while (node->parent && node->val < node->parent->val) {
        swap(node, node->parent);
        node = node->parent;
    }
}
tree* find_insertion_point(tree* root) {
    if (!root) return NULL;
    tree** queue = (tree **) malloc(sizeof(tree*) * 1024); 
    int front = 0, back = 0;
    queue[back++] = root;
    while (front < back) {
        tree* curr = queue[front++];
        if (!curr->left || !curr->right) {
            tree* res = curr;
            free(queue);
            return res;
        }
        queue[back++] = curr->left;
        queue[back++] = curr->right;
    }
    free(queue);
    return NULL;
}

void print_heap(tree* root) {
    if (!root) return;
    printf("%d ", root->val);

    print_heap(root->left);
    print_heap(root->right);
}

tree* heap_insert(tree* root, int value) {
    tree* new_node = (tree *) malloc(sizeof(tree));
    new_node->val = value;
    new_node->left = new_node->right = NULL;
    new_node->parent = NULL;
    if (!root) {
        return new_node;
    }
    tree* parent = find_insertion_point(root);
    new_node->parent = parent;

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;
    heapify_up(new_node);
    return root;
}


int main() {
    tree* heap = NULL;
    heap = heap_insert(heap, 10);
    heap = heap_insert(heap, 5);
    heap = heap_insert(heap, 15);
    heap = heap_insert(heap, 2);
    heap = heap_insert(heap, 7);
    print_heap(heap);
    return 0;
}