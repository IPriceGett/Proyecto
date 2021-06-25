#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    void* key;
    void * value;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->key = key;
    new->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)){
  TreeMap *map = (TreeMap *) malloc (sizeof(TreeMap));
  map->root = NULL;
  map->current = NULL;
  map->lower_than = lower_than;
  return map;
}

void insertTreeMap(TreeMap * tree, void* key, void * value) {
  
  TreeNode *aux = tree->root;
  TreeNode *node = createTreeNode(key, value);
  if ( searchTreeMap(tree, key) == NULL ){
    while (aux != NULL){

      if (aux->left == NULL){
        aux->left = node;
        node->parent = aux;
        tree->current = node;
        break;
      }

      if (aux->right == NULL){
        aux->right = node;
        node->parent = aux;
        tree->current = node;
        break;
      }

      if( tree->lower_than(key,aux->key) == 1 ){
        aux = aux->left;
      }
      else{
        aux = aux->right;
      }

    }
  }

}

TreeNode * minimum(TreeNode * x){
  if (x->left == NULL) return x;
  while(x->left != NULL){
    x = x->left;
  }
  return x;
}


void removeNode(TreeMap * tree, TreeNode* node) {

  if (node->left == NULL && node->right == NULL){
    if (node->parent->left == node) node->parent->left = NULL;
    else node->parent->right = NULL;
    free(node);
  }
  else{

    if (node->left == NULL && node->right != NULL){
      if (node == node->parent->left){
        node->parent->left = node->right;
        node->right->parent = node->parent;
      }
      else{
        node->parent->right = node->left;
        node->right->parent = node->parent;
      }
      free(node);
    }

    if (node->left != NULL && node->right == NULL){
      if (node == node->parent->right){
        node->parent->right = node->left;
        node->left->parent = node->parent;
      }
      else{
        node->parent->left = node->right;
        node->left->parent = node->parent;
      }
      free(node);
    }

    if (node->left != NULL && node->right != NULL){
      TreeNode *aux = node->right;
      aux = minimum(aux);
      node->key = aux->key;
      node->value = aux->value;
      removeNode(tree, aux);
    }
  }

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}

void * searchTreeMap(TreeMap * tree, void* key){

  TreeNode *aux = tree->root;
  while( aux != NULL ){
    if (is_equal(tree, key, aux->key) == 1){
      tree->current = aux;
      return aux->value;
    }

    if( tree->lower_than(key,aux->key) == 1 ){
      aux = aux->left;
    }
    else{
      aux = aux->right;
    }
    
  }
  return NULL;

}


void * upperBound(TreeMap * tree, void* key) {

  TreeNode *aux = tree->root;
  TreeNode *dato = tree->root;
  while( aux != NULL ){

    if ( is_equal(tree, key, aux->key) == 1 ){
      dato=aux;
      break;
    }

    if( tree->lower_than(key, aux->key) == 1 ){
      aux = aux->left;
    }
    else{
      aux = aux->right;
    }

    if ( (aux != NULL) && (tree->lower_than(key,aux->key) == 1) ){
      dato = aux;
    }

  }
  tree->current = dato;
  if (tree->lower_than(dato->key, key) == 1) return NULL;
  return dato->value;

}

void * firstTreeMap(TreeMap * tree) {

  TreeNode *aux = tree->root;
  if (aux == NULL) return NULL;
  while (aux->left != NULL){
    aux = aux->left;
  }
  return aux->value;

}

void * nextTreeMap(TreeMap * tree) {

  TreeNode *aux = tree->current;
  if (aux->right != NULL){
    aux = aux->right;
    aux = minimum(aux);
    tree->current = aux;
    return aux->value;
  }

  TreeNode *parent = aux->parent;
  while (parent != NULL){
    if( tree->lower_than(aux->key,parent->key) != 1 ){
      parent = parent->parent;
    }
    else break;
  }

  if (aux == NULL || parent == NULL) return NULL;
  tree->current = parent;
  return parent->value;

}
