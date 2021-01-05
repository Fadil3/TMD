#include "header.h"
int baris = 0;

char temp_parent[100];
int temp_level = 0;
simpul *parent;
simpul *parent_mandiri;
void makeTree(char c[], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer, c);
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char c[], simpul *root, int status)
{
    if (root != NULL)
    { /* jika simpul root tidak kosong, berarti 
        dapat ditambahkan simpul anak */
        simpul *baru;

        if (status < 2)
        {

            baru = (simpul *)malloc(sizeof(simpul));
            /* code */
        }

        strcpy(baru->kontainer, c);

        if (status == 1)
        {
            //add level
            baru->level = root->level + 1;
        }

        baru->child = NULL;
        if (root->child == NULL)
        {
            /* jika simpul root belum memiliki 
            simpul anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            { /* jika simpul root memiliki anak yang belum 
                memiliki saudara, maka simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                /* mencari simpul anak terakhir karena akan 
                dikaitkan dengan simpul baru sebagai simpul 
                anak terakhir yang baru, simpul anak terakhir 
                adalah yang memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul anak terakhir,
                penunjuk last akan berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul **root)
{ //Dilakukan kalo emang siblingnya udah diatur, atau emang gapunya sibling
    if ((*root) != NULL)
    {
        /* jika simpul root tidak kosong */
        if ((*root)->child != NULL)
        {

            if ((*root)->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */

                delAll(&(*root)->child);
                free((*root)->child);
                (*root)->child = NULL;
            }
            else
            {

                simpul *bantu;
                simpul *proses;
                bantu = (*root)->child;
                while (bantu->sibling != (*root)->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(&proses);
                }
                delAll(&bantu);
                free((*root)->child);
                (*root)->child = NULL;
            }
        }

        // printf("dibersihkan : %s ", (*root)->kontainer);
        //(*root)->kontainer = '\0';

        free(*root);
        *root = NULL;

        // printf("done \n");
        // if (*root != NULL)
        // {
        //     printf("awdjawdkjhakjsdbjksadbjkashgjkhasdf : %s \n", (*root)->kontainer);
        // }
    }
}

void delChild(char c[], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                /*jika hanya mempunyai satu anak*/
                if (strcmp(root->child->kontainer, c) == 0)
                {
                    // delAll(&root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul
				anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (strcmp(hapus->kontainer, c) == 0)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }

                /*memproses simpul anak terakhir karena
				belum terproses dalam pengulangan*/
                if ((ketemu == 0) && (strcmp(hapus->kontainer, c) == 0))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
					membantu proses atau pemeriksaan jika yang
					dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus
						anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak
							lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {

                        if ((prev == root->child) && (root->child->sibling->sibling == root->child))
                        { // diganti
                            /* jika hanya ada dua simpul
							anak dan yang dihapus adalah simpul
							anak kedua */

                            root->child->sibling = NULL;
                        }
                        else
                        {

                            /* jika yang dihapus bukan            kalo ga diujung ditengah
							simpul anak pertama dan simpul root
							memiliki simpul anak lebih dari dua
							simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    // delAll(&hapus);
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul *findSimpul(char c[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer, c) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (strcmp(bantu->kontainer, c) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(c, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    // kalo ga di ujung
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(bantu->kontainer, c) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                            if (hasil != NULL)
                            {
                                ketemu = 1;
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam
					pengulangan*/
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer, c) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printTreePreOrder(simpul *root)
{
    int i, j = 0;
    if (root != NULL)
    {
        // sort(root);
        if (baris > 0)
        {
            printf("\n");
        }

        if (root->level != 0)
        {
            printSpasi(root->level);
        }

        printf("|%s\n", root->kontainer);
        for (i = 0; i < root->m; i++)
        {
            if (root->level != 0)
            {
                printSpasi(root->level);
            }
            printf(" %s\n", root->bawaan[i]);
        }

        // printf("parent ->%s\n", root->parent);
        // printf("level ->%d\n", root->level);
        // printf("spasi ->%d\n", spasiLevel[root->level]);

        baris++;

        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu);
            }
            else
            { /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTreePreOrder(bantu);
            }
        }
    }
    else
    {
        printf("kosong");
    }
}

void migrasi(simpul *root, simpul *root2, simpul *tree)
{
    simpul *node;

    int i, j = 0;
    if (root != NULL)
    {
        addChild(root2->kontainer, root, 0);

        node = findSimpul(root2->kontainer, tree);
        //jika findSimpul tidak menemukan

        for (j = 0; j < root2->m; j++)
        {
            addBawaan(root2->bawaan[j], j, root2->m, node);
        }

        if (masuk == 0)
        {
            strcpy(node->parent, root->kontainer);
            node->level = root->level + 1;
        }
        else
        {
            strcpy(node->parent, parent->kontainer);
            node->level = parent->level + 1;
        }
        strcpy(temp_parent, node->kontainer);
        parent = findSimpul(temp_parent, tree);
        //jika findSimpul tidak menemukan
        masuk++;

        simpul *bantu = root2->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpul anak*/
                migrasi(root, bantu, tree);
            }
            else
            { /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root2->child)
                {
                    migrasi(root, bantu, tree);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                migrasi(root, bantu, tree);
            }
        }
    }
    else
    {
        printf("kosong");
    }
}

void printTreePostOrder(simpul *root)
{
    if (root != NULL)
    {
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpulanak*/
                printTreePostOrder(bantu);
            }
            else
            { /*jika memiliki banyak simpulanak*/ /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePostOrder(bantu);
                    bantu = bantu->sibling;
                } /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTreePostOrder(bantu);
            }
        }
        printf(" %s ", root->kontainer);
    }
}

void ConnectSibling(simpul *root, simpul *smpl)
{
    //jika child sebelumnya belum punya sibling, kaitkan dengan yang baru
    if (root->child->sibling == NULL)
    {
        smpl->sibling = root->child;
        root->child->sibling = smpl;
    }
    //jika sudah ada
    else
    {
        //cari sampai elemen terakhir sibling
        simpul *last = root->child;
        while (last->sibling != root->child)
        {
            last = last->sibling;
        }
        //kaiktan elemen terakhir sibling dengan yang baru
        smpl->sibling = root->child;
        last->sibling = smpl;
    }
}

void copyTree(simpul *root1, simpul **root2, int status)
{

    if (root1 != NULL)
    {
        int i = 0;
        (*root2) = (simpul *)malloc(sizeof(simpul));

        strcpy((*root2)->kontainer, root1->kontainer);
        (*root2)->m = root1->m;
        for (i = 0; i < root1->m; i++)
        {
            strcpy((*root2)->bawaan[i], root1->bawaan[i]);
        }
        strcpy((*root2)->parent, root1->parent);

        (*root2)->level = 0;

        (*root2)->sibling = NULL;
        (*root2)->child = NULL;
        simpul *bantu1 = root1->child;
        simpul *bantu2 = (*root2)->child;
        if (bantu1 != NULL)
        {
            //jika tidak punya sibling
            if (bantu1->sibling == NULL)
            {
                //copy simpulnya dan semua child dari simpul tersebut
                copyTree(bantu1, &bantu2, status);
                //jadikan simpul tersebut sebagai child
                (*root2)->child = bantu2;
            }
            //jika punya sibling, cek semua sibling pohon pertama
            else
            {
                while (bantu1->sibling != root1->child)
                {
                    //copy semua simpul child dari sibling tersebut
                    copyTree(bantu1, &bantu2, status);
                    //jika child pohon kedua masih null, jadikan simpul baru sebagai child
                    if ((*root2)->child == NULL)
                    {
                        (*root2)->child = bantu2;
                    }
                    //jika sudah ada child, jadikan sebagai sibling
                    else
                        ConnectSibling((*root2), bantu2);
                    //cek sibling berikutnya
                    bantu1 = bantu1->sibling;
                    bantu2 = bantu2->sibling;
                }
                //copy sibling terakhir dan jadikan sebagai sibling di pohon kedua
                copyTree(bantu1, &bantu2, status);
                ConnectSibling((*root2), bantu2);
            }
        }
    }
}

void aturLevel(simpul *root, simpul *tree)
{
    int i, j = 0;
    simpul *node;
    if (root != NULL)
    {
        // level saat ini adalah level parent + 1
        if (strcmp(root->parent, "null") != 0)
        {
            node = findSimpul(root->parent, tree);
            root->level = node->level + 1;
        }
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpul anak*/
                aturLevel(bantu, tree);
            }
            else
            { /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    aturLevel(bantu, tree);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                aturLevel(bantu, tree);
            }
        }
    }
    else
    {
        printf("kosong");
    }
}

void addBawaan(char bawaan[], int k, int m, simpul *root)
{
    if (root != NULL)
    {
        strcpy(root->bawaan[k], bawaan);
    }
    root->m = m;
}

void addParent(char parent[], simpul *root)
{
    if (root != NULL)
    {
        strcpy(root->parent, parent);
    }
}

void printBawaan(int m, simpul *root)
{
    int i = 0;
    for (i = 0; i < m; i++)
    {
        printf(" %s ", root->bawaan[i]);
    }
}

void sort(simpul *root)
{

    int i, j, key;

    int length[100];

    //sort dengan insertion sort
    if (root->m > 0)
    {
        /* code */
        for (i = 0; i < root->m; i++)
        {
            length[i] = strlen(root->bawaan[i]);
        }

        for (i = 1; i < root->m; i++)
        {
            key = length[i];
            j = i - 1;

            while (j >= 0 && key > length[j])
            {
                length[j + 1] = length[j];
                j = j - 1;
            }
            length[j + 1] = key;
        }

        //kalau ternyata simpul nya lebih panjang
        int a = strlen(root->kontainer);
        if (a > length[0])
        {
            length[0] = a;
        }
    }
    else
    {
        //kalau simpulnya ngga punya child
        int a = strlen(root->kontainer);
        length[0] = a;
    }

    // isi spasilevel
    if (spasiLevel[root->level] == 0)
    {
        spasiLevel[root->level] += length[0] + 1;
    }
    else if (length[0] + 1 > spasiLevel[root->level])
    {
        spasiLevel[root->level] = length[0] + 1;
    }
}

void printSpasi(int level)
{
    int i, j = 0;
    int spasi = (spasiLevel[level - 1]);
    int n = 0;

    //tambah dengan spasi sebelumnya
    for (j = level - 2; j >= 0; j--)
    {
        n += spasiLevel[j];
    }

    spasi += n;
    for (i = 0; i < spasi; i++)
    {
        printf(" ");
    }
}

void aturSpasi(simpul *root)
{
    int i, j = 0;
    if (root != NULL)
    {
        //sorting
        sort(root);

        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            { /*jika memiliki satu simpul anak*/
                aturSpasi(bantu);
            }
            else
            { /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    aturSpasi(bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                aturSpasi(bantu);
            }
        }
    }
    else
    {
        printf("kosong");
    }
}

void resetSpasi(int n)
{
    //reset semua angka
    int i = 0;
    for (i = 0; i < n; i++)
    {
        totalSpasi[i] = 0;
        spasiLevel[i] = 0;
        temp_level = 0;
        baris = 0;
    }
}