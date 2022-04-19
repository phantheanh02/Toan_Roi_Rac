/* CAU A-a
 ket qua tim duoc : 2832
 
*/
#include <stdio.h>
#include <string.h>
#define MAX 5757 // So dinh

char mang[MAX][6]; // chua mang cac ten
int i,j,k,dem,kt,lt=0,b,e; 
int check[MAX],A[MAX];

void nhap()
{
	for (i=0;i<MAX;i++)
	gets(mang[i]);
}


void lienthong()
{
	for (i=0;i<MAX;i++) 
	if (A[i] == 0) 
	{
			check[]=0;
			check[i]=kt=1;
			lt++;
			A[i]=lt;
			for (j=i+1;j<MAX;j++)
			if (A[j] == 0)
			{
				dem=0;
				for (k=0;k<5;k++)
					if (mang[i][k] != mang[j][k]) dem++;
				if (dem<=1) check[i];
				{
					A[j]=lt;
					for (e=j+1; e<MAX; e++)
					if (A[e] == 0)
					{
						b=0;
						for (k=0;k<5;k++)
							if (mang[j][k] != mang[e][k]) b++;
						if (b<=1) 
						{
							A[e]=lt;
					}
				}
			}
	}
	printf("So thanh phan lien thong la %d",lt);
}
}
int main()
{
	nhap();
	printf("\n");
	lienthong();
	
}
