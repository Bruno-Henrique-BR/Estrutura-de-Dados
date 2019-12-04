#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* right;
	struct Node* left;
	struct Node* parent;
} Node;

typedef struct Node *tree;

void ordem(tree arvore) {
	if (arvore != NULL) {
		ordem(arvore->left);
		printf("\nA CHAVE : %d", arvore->key);
		ordem(arvore->right);
	}
}

void insert(int k, tree* x, Node *daddy) {
	if (*x == NULL) {
		Node* novo = (Node*) malloc(sizeof(Node));
		novo->key = k;
		novo->left = NULL;
		novo->right = NULL;
		novo->parent = daddy;
		*x = novo;
	} else if (k == (*x)->key) {
		printf(
				"\nERRO: CHAVE '%d' JÁ¡ UTILIZADA ANTERIORMENTE, POR FAVOR INSERIR OUTRO VALOR!",
				(*x)->key);
	} else if (k < (*x)->key) {
		insert(k, &(*x)->left, *x);
	} else if (k > (*x)->key) {
		insert(k, &(*x)->right, *x);
	}
}

int main(void) {
	setlocale(LC_ALL, "Portuguese");

	tree *topo = (tree*) malloc(sizeof(tree));
	if (*topo != NULL) {
		*topo = NULL;
	}
	int key, opc = 1, bla = 0;
	do {
		printf(
				"\n1 - INSERIR \n2 - ORDEM\n3 - SAIR DO PROGRAMA\nOPÇÃO: ");
		scanf("%d", &opc);
		if (opc == 1) {
			key = -1;
			while (key < 0) {
				printf("\nCHAVE DO NÓ: ");
				scanf("%d", &key);
			}
			if (bla == 0) {
				insert(key, topo, 0);
				bla++;
			} else {
				insert(key, topo, 0);
			}
		}
		if (opc == 2) {
			printf("\n\nRAIZES EM ORDEM:\n\n");
			ordem(*topo);
		}
	} while (opc != 3);
}
