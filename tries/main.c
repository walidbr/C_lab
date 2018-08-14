#include <stdio.h>
#include <stdlib.h>

#define QUEUE_DATA_TYPE TNode*
// #define QUEUE_DATA_TYPE int
#define TREE_ELEMENTS   15 // 8+4+2+1

typedef struct _tnode
{
      int data;
      struct _tnode* left;
      struct _tnode* right;
} TNode;


typedef struct _qnode
{
      QUEUE_DATA_TYPE data;
      struct _qnode * next;
      struct _qnode * previous;
} QNode;

typedef struct 
{
      int size;
      QNode * in;
      QNode * out;
} Queue;

TNode T;
int A[TREE_ELEMENTS];
Queue Q;

void init_tree(TNode * root)
{
   root->data = 0;
   root->left = NULL;
   root->right = NULL;
}

void queue_init(Queue * q)
{
      q->size = 0;
      q->in = NULL;
      q->out = NULL;
}

void enqueue(Queue * q, QUEUE_DATA_TYPE data)
{
      QNode * N = (QNode *)malloc(sizeof(QNode));
      if(q->size == 0)
      {
            q->out = N;
      }
      else
      {
            q->in->previous = N;
      }
      q->in = N;
      N->data = data;
      N->previous = NULL;
      N->next = q->in;
      q->size++;
      printf("enqueue %d\n", data);

}

QUEUE_DATA_TYPE dequeue(Queue * q)
{
      QUEUE_DATA_TYPE data;
      if(q->size == 0)
      {
            printf("Queue Empty\n");
            return NULL;
      }
      QNode * N ;
      if(q->size == 1)
      {
            // Last element
            N = q->out;
            q->out = NULL;
            q->in = NULL;
      }
      else
      {
            N = q->out;
            q->out = N->previous;
      }
      q->size--;
      data = N->data;
      free(N);
      printf("dequeue %d\n", data);
      return N;
}

static inline int Pow(int x, int power)
{
      int count = power;
      int ans = 1;
      while(count --)
      {
            ans *= x;
      }
      //printf("%d pow %d = %d\n", x , power, ans);
      return ans;
}

static void get_tree_depth(int size)
{
      int sum = 0, count = 0;
      int height = 0;
      if(size == 0)
            return 0;
      else
      {
            while( sum < size)
            {
                  sum += Pow(2,count);
                  count ++;
                  height++;
            }
            //printf("Size %d Height %d \n", size, height);
            return height+1;
      }
}

static void fill_array(int *a)
{
      int i;
      for(i=0;i<TREE_ELEMENTS;i++)
            a[i] = i+1;
}
static int count = 0;
void fill_tree(TNode * tree, int height)
{
      tree->data = count++;
      if(height > 1)
      {
            TNode * L = (TNode *)malloc(sizeof(TNode));
            TNode * R = (TNode *)malloc(sizeof(TNode));
            L->left = NULL;
            L->right = NULL;
            R->left = NULL;
            R->right = NULL;
            tree->left = L;
            tree->right = R;
            fill_tree(tree->left, height-1);
            fill_tree(tree->right, height-1);
      }
      else
      {
            tree->left = NULL;
            tree->right = NULL;
      }
}

void print_tree(TNode * tree)
{
      printf("_%d", tree->data);
      if(tree->left != NULL)
            print_tree(tree->left);
      if(tree->right != NULL)
            print_tree(tree->right);
}

void print_tree_transversal(TNode * tree, int level)
{
      // printf("_%d", tree->data);
      QUEUE_DATA_TYPE  N;
      if(Q.size == Pow(2,level-1));
      {
            N = dequeue(&Q);
            printf("*%d", N->data);
      }
            
      if(tree->left != NULL)
            enqueue(&Q, tree->left);
      if(tree->right != NULL)
            enqueue(&Q, tree->left);
}

int main() {

      init_tree(&T);
      fill_tree(&T, 4);
      print_tree(&T);
      fill_array(A);

      queue_init(&Q);
      /* enqueue the first element */
      enqueue(&Q, &T);
      print_tree_transversal(&T, 1);


      return 0;
}