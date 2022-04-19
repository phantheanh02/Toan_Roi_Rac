#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int pi[MAX];
int rank[MAX];

void Makeset (int x) {
    pi[x] = x;
    rank[x] = 0;
}

int Find(int x) {
    while (x != pi[x]) { x=pi[x];}
    return x;
}
void Union (int x, int y)
{
    int rx = Find(x);
    int ry = Find(y);
    if (rx == ry) return;
    if (rank[rx]>rank[ry]) pi[ry] = rx;
    else {
        pi[rx] = ry;
        if (rank[rx]==rank[ry]) rank[ry] = rank[rx] + 1;
    }
}

void printGraphviz (int n)
{
    printf ("digraph ds { \n");
    for (int x = 0; x < n; x++)
        printf ("%d->%d;\n",x, pi[x]);
    printf ("}\n");
}

struct Canh {
    int u, v, w; // dinh u, v voi trong so w

};

#define MAXEDG 100
int n, m;  // So dinh, so danh
struct Canh dsCanh[MAXEDG];

// Dung cho qsort
int cmpfunc (const void *a, const void * b) {
    struct Canh *a_ = (struct Canh*) a;
    struct Canh *b_ = (struct Canh*) b;
    return a_->w - b_->w;
}

void Kruskal ()
{
    // sort 
    qsort(dsCanh, m, sizeof(struct Canh), cmpfunc);
    
    for (int u = 0; u < n; u++)
        Makeset(u);

    for (int i=0; i < m; i++)
    {
        int u = dsCanh[i].u; 
        int v = dsCanh[i].v;
        if (Find(u) != Find(v))
        {
            printf ("%d-%d\n", u, v);
            Union(u,v);       
        }
    }
}

int main(int argc, char const *argv[])
{
    
    scanf("%d%d", &n,&m);

    for (int i=0; i < m; i++) {
            scanf("%d%d%d", &dsCanh[i].u, &dsCanh[i].v, &dsCanh[i].w);
        }
    Kruskal();
    //printGraphviz(10);
    return 0;
}
