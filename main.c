#include "header.h"

int main()
{
    //deklarasi
    tree T, T2, T3, T4;
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
    simpul *node2;

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
                printf("m = %d ", m);
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
                // addParent("null", T.root);
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

                // addParent(parent, node);
                // printf("node parent %s\n", node->parent);
            }
        }

        //kalau parent nya null
        if (strcmp(parent, "null") == 0)
        {

            addParent("null", T.root);
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

            addParent(parent, node);
            // printf("node parent %s\n", node->parent);
        }

        copyTree(T.root, &T2.root);

        //request pindah
        char pindah[100];
        char target[100];
        char temp[100];
        int posisi = 0;
        scanf("%d", &o);
        for (k = 0; k < o; k++)
        {
            posisi = 0;
            scanf("%s", pindah);
            scanf("%s", target);

            //kalau target nya membuat pohon mandiri
            if (strcmp(target, "mandiri") == 0)
            {
                // cari simpul yang mau dipindah
                node = findSimpul(pindah, T2.root);

                //jika findSimpul tidak menemukan
                if (!node)
                {
                    //telusuri di child nya
                    node = findSimpul(pindah, T2.root->child);
                    posisi = 1;
                }
                printf("node parent 1 %s\n", node->parent);

                /*=====================percobaaan===============*/
                // cari simpul yang mau dipindah
                node2 = findSimpul(node->parent, T2.root);
                //jika findSimpul tidak menemukan
                if (!node2)
                {
                    //telusuri di child nya
                    node2 = findSimpul(node->parent, T2.root->child);
                    posisi = 1;
                }
                // strcpy(temp, node2->parent);
                printf("node2 child %s  posisi %d\n", node2->child, posisi);
                /*=============================================*/

                //membuat pohon baru
                makeTree(pindah, &T3);

                //copy simpul yang mau dipindah ke pohon baru
                copyTree(node, &T3.root);

                // hapus simpul di pohon lama
                if (posisi == 1)
                {
                    // // printf("ada posisi 1\n");
                    // delChild(temp, node);
                    delAll(&node2);
                }
                else
                {
                    delChild(pindah, node2);
                }
            }
            // kalau target nya pindah
            else
            {
                printf("tes\n");
                // cari naungan
                node = findSimpul(target, T2.root);

                //jika findSimpul tidak menemukan
                if (!node)
                {
                    //telusuri di child nya
                    node = findSimpul(target, T2.root->child);
                }

                // cari posisi simpul yang ingin pindah
                node2 = findSimpul(pindah, T2.root);

                //jika findSimpul tidak menemukan
                if (!node2)
                {
                    printf("ada\n");
                    //telusuri di child nya
                    node2 = findSimpul(pindah, T2.root->child);
                }

                makeTree(pindah, &T4);
                copyTree(node2, &T4.root);

                // hapus simpul di pohon lama
                delChild(pindah, T2.root);

                // copyTree(T4.root, &node);
            }
        }
        // printf("parent :%s child: %s bawaan: %d\n", parent, child, m);
    }

    // // copyTree(T.root, &T2.root);
    // printf("=================\n");
    // printf("pohon awal:\n");
    // printTreePreOrder(T.root);
    // printf("=================\n");

    printf("pohon2 \n");
    printTreePreOrder(T2.root);
    printf("=================\n");

    printf("pohon3 \n");
    printTreePreOrder(T3.root);
    printf("=================\n");

    // printf("pohon4 \n");
    // printTreePreOrder(T4.root);
    // printf("=================\n");

    // for (i = 0; i < n; i++)
    // {

    //     printf("total Spasi %d\n", totalSpasi[i]);
    // }

    return 0;
}
