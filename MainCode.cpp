#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book { 
    long long isbn; 
    char title[100];
    char author[100];
    int height; 
    struct Book *left, *right;
} Book;


int getHeight(Book *node) { 
     if (node == NULL) return 0; 
     return node -> height; 
}

int max(int a , int b) {
    return (a>b) ? a:b;
}

int getBalanceFactor(Book *node) {
    if (node == NULL) return 0;   
    return getHeight(node->left) – getHeight(node->right); 
}

Book* createNode(long long isbn, char title[], char author[]) {
     book *node = (Book*)malloc(sizeof(Book));
     node->isbn = isbn; 
     strcpy(node->title, title);
     strcpy(node->author, author);
     node->left = NULL;
     node->right = NULL; 
     node->height = 1; 
     return node;
} 
Book*right Rotate (Book*y){
	Book *x=y->left;
	Book *T2=x->right;
	x->right=y;
	y->left=T2;
	y->height=1+max*(getHeight(y->left),getHeight(y->right));
	x->height=1+max(getHeight(x->left),getHeight(x->right));
return x;
}

Book* leftRotate(Book *x) {
   	 Book *y = x->right;
   	 Book *T2 = y->left;
    	y->left = x;
   	 x->right = T2;
   	 x->height = 1 + max(getHeight(x->left), getHeight(x->right));
  	  y->height = 1 + max(getHeight(y->left), getHeight(y->right));
   	 return y;
}

Book* insert(Book *node, long long isbn, char title[], char author[]) {
   	 if (node == NULL) return createNode(isbn, title, author);

    	if (isbn < node->isbn)
     	   node->left = insert(node->left, isbn, title, author);
  	  else if (isbn > node->isbn)
       	 node->right = insert(node->right, isbn, title, author);
  	  else
       	 return node;

   	 node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  	  int balance = getBalanceFactor(node);

   	 if (balance > 1 && isbn < node->left->isbn)
       	 return rightRotate(node);

 	   if (balance < -1 && isbn > node->right->isbn)
        	return leftRotate(node);

   	 if (balance > 1 && isbn > node->left->isbn) {
     	   node->left = leftRotate(node->left);
      	  return rightRotate(node);
  	  }

  	  if (balance < -1 && isbn < node->right->isbn) {
      	  node->right = rightRotate(node->right);
       	 return leftRotate(node);
 	   }

  	  return node;
}

Book* search(Book *root, long long isbn) {
  	  if (root == NULL || root->isbn == isbn)
     	   return root;
   	 if (isbn < root->isbn)
     	   return search(root->left, isbn);
 	   return search(root->right, isbn);
}

void inorder(Book *root) {
  	  if (root != NULL) {
     	   inorder(root->left);
    	    printf("ISBN: %lld | Title: %s | Author: %s\n", root->isbn, root->title, root->author);
      	  inorder(root->right);
 	   }
}

int main() {
    Book *root = NULL;
    int choice;
    long long isbn;
    char title[100], author[100];

    while (1) {
        printf("\n===== Library Menu =====\n");
        printf("1. Insert Book\n2. Search Book\n3. Display All\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter ISBN: "); scanf("%lld", &isbn); getchar();
            printf("Enter Title: "); fgets(title, 100, stdin); title[strcspn(title, "\n")] = 0;
            printf("Enter Author: "); fgets(author, 100, stdin); author[strcspn(author, "\n")] = 0;
            root = insert(root, isbn, title, author);
        } else if (choice == 2) {
            printf("Enter ISBN: "); scanf("%lld", &isbn);
            Book *found = search(root, isbn);
            if (found) printf("Found: %s\n", found->title);
            else printf("Not Found.\n");
        } else if (choice == 3) {
            inorder(root);
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}

	
