#include<stdio.h>
#define MAX 100

int graph[MAX][MAX];
int sodinh;

int visited[MAX];
int pre[MAX], post[MAX];
int Clock = 1;
void previsit(int v)
{
    pre[v] = Clock;
    Clock++;
}
void postvisit(int v)
{
    post[v]=Clock;
    Clock++;
}
void explore(int v)
{
	int u;
    visited[v]=1; // 1: true, 0:false
    previsit(v);

    for( u=0; u < sodinh; u++)
        if (graph[v][u] == 1)
            if (visited[u]==0) explore(u);
    postvisit(v);
}

void dfs ()
{
	int v;
    for (v=0; v<sodinh; v++)
        visited[v]=0;
    for (v=0; v<sodinh; v++)
        if (visited[v]==0) explore(v);
}
int main(int argc, char const *argv[])
{
    int socanh,i,j,e,u;
    for ( i=0; i < MAX; i++)
        for( j=0; j< MAX; j++)
            graph[i][j] = 0;

    scanf("%d", &sodinh);
    scanf("%d", &socanh);
    for(e=0; e < socanh; e++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u][v]=graph[v][u]=1;
        }
    dfs();
    for( u=0; u < sodinh; u++)
        printf("\n%d:%d-%d", u,pre[u],post[u]);
    printf("\n");
    return 0;
}
