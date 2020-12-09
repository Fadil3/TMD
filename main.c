#include "header.h"

int main()
{
    tree T;
    int n, m = 0;

    //input banyaknya data
    scanf(" %d", &n);

    //tampungan
    char parent[100];
    char child[100];
    char akar[100];
    char bawaan[100];
    // parent#child#jumlah_bawaan

    int i,
        k = 0;
    int j = 1;

    char str[100];
    char s[2] = "#";
    char *token;
    simpul *node;

    // makeTree("burana", &T);
    // addChild("srisiam", T.root);
    // simpul *node = findSimpul("srisiam", T.root);
    // if (node != NULL)
    // {
    //     addChild("sogodoll", node);
    // }

    // addChild("anosnum", T.root);
    // node = findSimpul("anosnum", T.root);
    // if (node != NULL)
    // {
    //     addChild("susanae", node);
    // }

    // node = findSimpul("sogodoll", T.root->child);
    // if (node != NULL)
    // {
    //     addChild("hariefa", node);
    // }
    for (i = 0; i < n; i++)
    {
        scanf(" %s", str);
        j = 1;
        /* get the first token */
        token = strtok(str, s);
        strcpy(parent, token);

        /* walk through other tokens */
        while (token != NULL)
        {
            token = strtok(NULL, s);
            // printf("masuk\n");
            if (j == 1)
            {
                strcpy(child, token);
            }
            else if (j == 2)
            {
                int x = atoi(token);
                m = x;
            }
            j++;
        }

        if (strcmp(parent, "null") == 0)
        {
            makeTree(child, &T);
            strcpy(akar, child);
        }
        else
        {
            if (strcmp(parent, akar) == 0)
            {
                addChild(child, T.root);
            }
            else
            {
                int masuk = 0;
                node = findSimpul(parent, T.root);
                if (node != NULL)
                {
                    masuk = 1;
                    addChild(child, node);
                }

                if (masuk == 0)
                {
                    node = findSimpul(parent, T.root->child);
                    addChild(child, node);
                }
            }
        }

        // makeTree("burana", &T);

        // addChild("Caa", T.root);
        // addChild("Daa", T.root);

        //buat input  bawaaan
        for (k = 0; k < m; k++)
        {
            scanf(" %s", bawaan);
            if (strcmp(parent, "null") == 0)
            {
                Addbawaan(bawaan, k, T.root);
            }
            else
            {
                Addbawaan(bawaan, k, node);
            }
        }
        //printf("parent :%s child: %s bawaan: %d\n", parent, child, m);
    }
    // printf("tes bawaan :%s \n", T.root->bawaan[2]);
    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root, m);
    return 0;
}
