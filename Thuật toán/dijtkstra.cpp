/*  Thuat toan Dijkstra
	Input: 
	Dong dau la so dinh, dong 2 la so canh, cac dong con lai la canh
VD:
4
4
1 2 2
2 3 1
3 4 5
1 4 3
	
	Output
Duong di ngan nhat tu dinh 1 den cac dinh
 2 <- 1
 3 <- 2 <- 1
 4 <- 1


*/
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MAX 100
#define VOCUNG 10000
int n,c,s=1,u,v,w,i,j;
// n la so dinh, c la so canh
char chon;
int Danhdau[MAX], // danh dau duong di
	Khoangcach[MAX], // danh dau khoang cach
	Trongso[MAX][MAX], // Ma tran trong so
	Chuaxet[MAX]; // danh dau dinh da gan nhan
	
void Nhap()
{
	scanf("%d%d",&n,&c);
	for (i=1; i<=c; i++ ) 
	{
		scanf("%d%d%d",&u,&v,&w);
		Trongso[u][v]=w;
		Trongso[v][u]=w;
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
   			if (Trongso[i][j] == 0) Trongso[i][j] = VOCUNG;
}

void Dijkstra(int t)
{
	int minp;
	for (v = 1; v <= n; v++)
	{
		Khoangcach[v] = Trongso[s][v];
		Danhdau[v] = s;
		Chuaxet[v] = FALSE;
	}
	Danhdau[s] = 0;
	Khoangcach[s] = 0;
	Chuaxet[s] = TRUE;
	while (!Chuaxet[t]) 
	{
		minp = VOCUNG;
		for ( v = 1; v <= n; v++)
			if ((!Chuaxet[v]) && (minp > Khoangcach[v]))
			{
				u = v;
				minp = Khoangcach[v];
			}
		Chuaxet[u] = TRUE;
		if (!Chuaxet[t])
		{
			for ( v = 1; v <= n; v++)
			if ((!Chuaxet[v]) && (Khoangcach[u] + Trongso[u][v] < Khoangcach[v]))
			{
				Khoangcach[v] = Khoangcach[u] + Trongso[u][v];
				Danhdau[v] = u;
			}
		}

 	}

}
void Ketqua(int t)
{
	printf(" %d <- ",t);
	i = Danhdau[t];
	while (i != s)
	{
		printf("%d <- ",i);
  		i = Danhdau[i];
 	}
	printf("%d",s);
	
}
int main()
{
	Nhap();
	printf("Duong di ngan nhat tu dinh 1 den cac dinh\n");
	for (j=2; j<=n; j++) 
	{
		Dijkstra(j);
		Ketqua(j);
		printf("\n");
	}
	return 0;
}

