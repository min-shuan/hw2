typedef struct node{
	int key;
	struct node *next;
} lnode;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
	int Data;
	BinTree Left;
	BinTree Right;
};
struct dnode{
	int key;
	struct dnode *next;
};
int product_insert_data();
int product_query_num();
int array_insert();
int array_query();
int binary_search();
lnode *linked_list_insert();
int linked_list_query();
BinTree Insert();
Position Find();
struct dnode *l_insert();
struct dnode *l_find();
void hash_insert();
struct dnode *hash_find();


