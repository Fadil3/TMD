#include "header.h"

int main()
{
    tree T;
    int n, m = 0;
    char parent[100];
    char child[100];
    // parent#child#jumlah_bawaan
    int i = 0;
    simpul *node;
    do
    {
        scanf(" %s %s %d", parent, child, m);
        if (strcmp(parent, "null") == 0)
        {
            makeTree(child, &T);
        }
        else
        {
            node = findSimpul(parent, T.root);
            if (node != NULL)
            {
                addChild(child, node);
            }
        }

        i++;
    } while (i < n);

    // int i = 0;
    // do
    // {

    //     if (strcmp(temp, "akar") == 0)
    //     {
    //         makeTree(simpul, &T);
    //     }
    //     else
    //     {
    //         searchParent(T.root, simpul, parent, temp);
    //     }

    //     i++;
    // } while (i < n);

    // makeTree('A', &T);
    // addChild('B', T.root);
    // addChild('C', T.root);
    // addChild('D', T.root);
    // simpul *node = findSimpul('B', T.root);
    // if (node != NULL)
    // {
    //     addChild('E', node);
    //     addChild('F', node);
    // }

    // node = findSimpul('C', T.root);
    // if (node != NULL)
    // {
    //     addChild('G', node);
    // }

    // node = findSimpul('D', T.root);
    // if (node != NULL)
    // {
    //     addChild('H', node);
    //     addChild('I', node);
    //     addChild('J', node);
    // }

    // node = findSimpul('J', T.root);
    // if (node != NULL)
    // {
    //     addChild('K', node);
    //     addChild('L', node);
    //     addChild('M', node);
    // }
    // printf("=================\n");
    // printf("preOrder\n");
    // printTreePreOrder(T.root);
    // printf("\n=================\n");
    // printf("postOrder\n");
    // printTreePostOrder(T.root);
    // printf("\n=================\n");

    // tree T2;
    // copyTree(T.root, &T2.root);

    // printTreePreOrder(T2.root);

    // if (isEqual(T.root, T2.root) == 1)
    // {
    //     printf("pohon sama\n");
    // }
    // else
    // {
    //     printf("pohon tidak sama\n");
    // }

    // node = findSimpul('J', T.root);
    // if (node != NULL)
    // {
    //     delChild('K', node);
    //     delChild('L', node);
    //     delChild('M', node);
    // }
    delAll(T.root);

    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    return 0;
}
