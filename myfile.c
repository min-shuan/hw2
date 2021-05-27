#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int product_insert_data(char *com){
	int N;
	if (strcmp(com, "1e4") == 0){
		N = 10000;
	}
	else if (strcmp(com, "1e5") == 0){
		N = 100000;
	}
	else if (strcmp(com, "1e6") == 0){
		N = 1000000;
	}
	return N;
}

int product_query_num(char *com){
	int M;
	if (strcmp(com, "1e3") == 0){
		M = 1000;
	}
	else if (strcmp(com, "1e4") == 0){
		M = 10000;
	}
	else if (strcmp(com, "1e5") == 0){
		M = 100000;
	}
	return M;
}

void array_insert(int *arr, int *data, int N){
	for (int i = 0; i < N; i++)
	{
		arr[i] = data[i];
	}
}

void array_query(int *arr, int idx, int data){
	for (int i = 0; i < idx; i++){
		if (arr[i] == data){
			break;
		}
	}
}

void binary_search(int *arr, int idx, int i){
	int low = 0, high = idx - 1;
	int mid = (low + high) / 2;
	while (low < high){
		mid = (low + high) / 2;
		if (arr[mid] == i){
			break;
		}
		else if (arr[mid] < i){
			low = mid + 1;
		}
		else if (arr[mid] > i){
			high = mid - 1;
		}
	}
}
typedef struct node{
	int key;
	struct node *next;
} lnode;

lnode *linked_list_insert(lnode *list, int data){
	lnode *ptr;
	ptr = malloc(sizeof(lnode));
	ptr->key = data;
	ptr->next = list;
	return ptr;
}

void linked_list_query(lnode *list, int data){
	while (list){
		if (list->key == data)
			break;
		else
			list = list->next;
	}
}
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	int Data;
	BinTree Left;
	BinTree Right;
};

Position Find(BinTree BST, int X){
	if (!BST)
		return NULL;
	if (X > BST->Data)
		return Find(BST->Right, X);
	else if (X < BST->Data)
		return Find(BST->Left, X);
	else
		return BST;
}
BinTree Insert(BinTree BST, int X){
	if (!BST){
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else{
		if (X < BST->Data)
			BST->Left = Insert(BST->Left, X);
		else
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}
struct dnode{
	int key;
	struct dnode *next;
};

struct dnode *l_insert(struct dnode *L, int key){
	struct dnode *p;
	p = (struct dnode *)malloc(sizeof(struct dnode));
	p->key = key;
	p->next = L;
	return p;
}

struct dnode *l_find(struct dnode *L, int key){
	struct dnode *p;
	if (L == NULL)
		return NULL;
	p = L;
	while (p){
		if (p->key == key){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void hash_insert(struct dnode **hTab, int maxHash, int key){
	unsigned int hv;
	struct dnode *dptr;
	hv = key % maxHash;
	dptr = hTab[hv];
	hTab[hv] = l_insert(dptr, key);
}

struct dnode *hash_find(struct dnode **hTab, int maxHash, int key){
	unsigned int hv = 0;
	struct dnode *dptr;
	hv = key % maxHash;
	dptr = hTab[hv];
	return l_find(dptr, key);
}

