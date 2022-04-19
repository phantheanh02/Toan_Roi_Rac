/* CAU A-b
Nhap du lieu sgb-words truoc
Nhap u va v sau
ket qua tim duoc :
 
*/
#include <stdio.h>
#include <string.h>
#define MAX 5757 // So dinh

char mang[MAX][6], u[6], v[6]; // chua mang cac ten
int i,j,k,e,A[MAX],dem,kt; // mang A check cac ten da duoc kiem tra

void nhap()
{
	for (i=0;i<MAX;i++)
	gets(mang[i]);
}

void lienthong()
{
	for (i=0;i<MAX;i++) 
	{
		dem=0;
		for (e=0;e<5;e++)
		if (mang[i][e] == u[e]) dem++;
		if (dem == 5) break;
	}
	kt=i;
	for (j=kt+1;j<MAX;j++)
			{
				dem=0;
				for (k=0;k<5;k++)
					if (mang[kt][k] != mang[j][k]) dem++;
				if (dem<=1) 
				{
					printf("-> %s ",mang[j]);
					kt=j;
				}
				for (e=0;e<5;e++)
				if (mang[j][e] !=v[e]) break;
			}

}

int main()
{
	nhap();
	printf("Nhap dinh u: ");
	scanf("%s",u);
	printf("Nhap dinh v: ");
	scanf("%s",v);
	printf("\n%s ",u);
	lienthong();
	
}
