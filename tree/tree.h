#define max(x,y) ((x) >(y)?(x):(y))

struct BSTree
{
    int data;
    struct BSTree* left;
    struct BSTree* right;
};

typedef struct BSTree* Tree;

extern Tree newNode(int);
extern Tree insert(Tree, int);
extern Tree insert_iterative(Tree, int);
extern int lookup(Tree, int);
extern int lookup_iterative(Tree, int);
extern int size(Tree);
extern int height(Tree);
extern void deleteTree(Tree);
extern int hasPathSum(Tree, int);
extern int maxValue(Tree);
extern int maxValue_iterative(Tree);
extern int minValue(Tree);
extern int minValue_iterative(Tree);
extern void inorder(Tree);
extern void preorder(Tree);
extern void postorder(Tree);
extern void printPaths(Tree);
extern void mirror(Tree);
extern Tree createMirror(Tree);
extern int isMirror(Tree, Tree);
extern int isSymmetric(Tree);
extern Tree copy(Tree);
extern int LCA(Tree, int, int);
extern int isIdentical(Tree,Tree);
extern struct BSTree* deleteNode(Tree, int);
extern int isBST(Tree);
extern void doubleTree(Tree);
extern int isBalanced(Tree);
extern void longestSeqPath(Tree);
extern void printLeafNodes(Tree);
extern Tree deleteAllLeafNodes(Tree);
int countLeafNodes(Tree);
int countNonLeafNodes(Tree);
int findDeepestNode(Tree);
void printAllDeepestNodes(Tree);
int  inorderSuccessor(Tree, int);
int inorderPredecessor(Tree, int);
