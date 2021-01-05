#include "header.h"

int main()
{
    //deklarasi
    tree T, T2, T3[100];
    int i, m, n, o = 0;
    int mandiri = 0;
    int pindahNaungan = 0;
    int j = 1;

    //input banyaknya data
    scanf(" %d", &n);

    //tampungan
    char parent[100];
    char child[100];
    char akar[100];
    char bawaan[100];

    //pemrosesan string
    char str[100];
    char s[2] = "#"; // # sebagai pembatas string
    char *token;

    //simpul yang nantinya dipakai untuk cari parent / target
    simpul *node;
    simpul *node2;
    simpul *node3;

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

            //atur level
            T.root->level = 0;
        }
        else
        {
            //kalau parent nya root
            if (strcmp(parent, akar) == 0)
            {
                //tambahkan child sebagai anaknya root
                addChild(child, T.root, 1);

                //atur level
                T.root->child->level = 1;
            }
            else
            {
                //cari simpul
                node = findSimpul(parent, T.root);
                addChild(child, node, 1);
            }
        }

        int k = 0;
        //buat input  bawaaan
        if (m != 0)
        {
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

                    //masukkan bawaan
                    addBawaan(bawaan, k, m, node);
                }
            }
        }

        /*================= isi parent ==============*/
        if (strcmp(parent, "null") == 0)
        {
            addParent("null", T.root);
        }
        else
        {
            //kalau parent nya bukan null child dimasukkan
            node = findSimpul(child, T.root);
            addParent(parent, node);
        }
        /*================= end of isi parent ==============*/
    }
    // copy tree ke tree2
    copyTree(T.root, &T2.root, 1);

    //request pindah
    char pindah[100];
    char target[100];
    char temp[100];

    // banyaknya proses
    scanf(" %d", &o);

    int k = 0;
    for (k = 0; k < o; k++)
    {
        masuk = 0;

        // input pindah dan targetnya
        scanf(" %s", pindah);
        scanf(" %s", target);

        //kalau target nya membuat pohon mandiri
        if (strcmp(target, "mandiri") == 0)
        {
            // cari simpul yang mau dipindah
            node = findSimpul(pindah, T2.root);

            /*=====================cari parent yang dipindah ===============*/
            node2 = findSimpul(node->parent, T2.root);

            //membuat pohon baru
            makeTree(node->kontainer, &T3[mandiri]);

            //copy simpul yang mau dipindah ke pohon baru

            //set parent ke null
            strcpy(node->parent, "null");

            //set level ke 0
            node->level = 0;

            // delete simpul di pohon lama
            delChild(pindah, node2);

            //node ke pohon baru
            copyTree(node, &T3[mandiri].root, 0);

            //atur level
            aturLevel(T3[mandiri].root, T3[mandiri].root);

            mandiri++;
        }
        // kalau target nya pindah
        else
        {
            masuk = 0;
            /*============== Cari Naungan ===============*/
            node = findSimpul(target, T2.root);

            /*============== Cari yang pindah ===============*/
            node2 = findSimpul(pindah, T2.root);

            /*============== Cari Parent yang pindah ===============*/
            node3 = findSimpul(node2->parent, T2.root);

            //delete simpul di pohon lama
            delChild(pindah, node3);

            //pindahin semua isinya
            migrasi(node, node2, T2.root);

            //atur level
            aturLevel(T2.root, T2.root);

            pindahNaungan++;
        }
    }

    printf("pohon awal:\n\n");

    //inisialisasi spasi
    resetSpasi(n);

    aturSpasi(T.root);

    printTreePreOrder(T.root);

    //inisialisasi spasi
    resetSpasi(n);

    if (pindahNaungan > 0)
    {
        printf("\npohon pindah naungan:\n\n");
        aturSpasi(T2.root);
        printTreePreOrder(T2.root);
        resetSpasi(n);
    }

    if (mandiri > 0)
    {
        for (i = 0; i < mandiri; i++)
        {
            if (i == 0)
            {
                printf("\npohon mandiri:\n");
            }
            aturSpasi(T3[i].root);
            printf("\n");
            printTreePreOrder(T3[i].root);
            resetSpasi(n);
        }
    }

    return 0;
}
