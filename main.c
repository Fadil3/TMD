#include "header.h"

int main()
{
    //deklarasi
    tree T;
    int i, k, m, n, o = 0;
    int j = 1;

    //input banyaknya data
    scanf(" %d", &n);

    //tampungan
    char parent[100];
    char child[100];
    char akar[100];
    char bawaan[100];
    // parent#child#jumlah_bawaan

    //pemrosesan string
    char str[100];
    char s[2] = "#"; // # sebagai pembatas string
    char *token;
    simpul *node;

    for (i = 0; i < n; i++)
    {
        //request input
        scanf(" %s", str);
        j = 1;

        //ambil token pertama
        token = strtok(str, s);

        //asumsi nya token pertama adalah parent
        strcpy(parent, token);

        // maju ke token selanjutnya
        while (token != NULL)
        {
            token = strtok(NULL, s);
            if (j == 1)
            {
                //copy ke child
                strcpy(child, token);
            }
            else if (j == 2)
            {
                //convert string ke token
                int x = atoi(token);
                m = x;
            }
            j++;
        }

        //kalau parentnya null berarti dia root nya
        if (strcmp(parent, "null") == 0)
        {
            //buat pohon
            makeTree(child, &T);
            //copy ke root
            strcpy(akar, child);
        }
        else
        {
            //kalau parent nya root
            if (strcmp(parent, akar) == 0)
            {
                //tambahkan child sebagai anaknya root
                addChild(child, T.root);
            }
            else
            {
                //cari simpul
                node = findSimpul(parent, T.root);
                if (node != NULL)
                {
                    addChild(child, node);
                }

                //kalau ngga ketemu, cari di childnya
                if (!node)
                {
                    node = findSimpul(parent, T.root->child);
                    addChild(child, node);
                }
            }
        }

        //buat input  bawaaan
        for (k = 0; k < m; k++)
        {
            //scan bawaan
            scanf(" %s", bawaan);

            //kalau parent nya null
            if (strcmp(parent, "null") == 0)
            {
                //masukkan bawaan ke root
                addBawaan(bawaan, k, m, T.root);
            }
            else
            {
                //kalau parent nya bukan null child dimasukkan
                node = findSimpul(child, T.root);

                //jika findSimpul tidak menemukan
                if (!node)
                {
                    //telusuri di child nya
                    node = findSimpul(child, T.root->child);
                }
                //masukkan bawaan
                addBawaan(bawaan, k, m, node);
            }
        }

        // //request pindah
        // scanf("%d", &o);
        // for (k = 0; k < o; k++)
        // {
        //     /* code */
        // }

        //printf("parent :%s child: %s bawaan: %d\n", parent, child, m);
    }

    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("=================\n");

    // for (i = 0; i < n; i++)
    // {

    //     printf("total Spasi %d\n", totalSpasi[i]);
    // }

    return 0;
}
