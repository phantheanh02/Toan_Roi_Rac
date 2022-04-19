#include <stdio.h>

/* To mau do thi
###	Input:
Nhap so dinh va canh: 5 6
1 2
2 3
4 2
1 5
5 3
3 4
	Output
Dinh 1 to mau 1
Dinh 3 to mau 1
Dinh 2 to mau 2
Dinh 5 to mau 2
Dinh 4 to mau 3

###	Input
Nhap so dinh va canh: 5 5
1 2
2 3
3 4
4 1
1 5
	Output
Dinh 1 to mau 1
Dinh 3 to mau 1
Dinh 2 to mau 2
Dinh 4 to mau 2
Dinh 5 to mau 2
*/
int i,j,dinh,canh,mau=0,k;
int a[1000][1000], b[1000];

// lay du lieu
void input()
{
	int m,n;
	printf("Nhap so dinh va canh: ");
	scanf("%d%d",&dinh,&canh);
	for (i=1; i<=dinh; i++) 
	{
		for (j=1; j<=dinh; j++) a[i][j]=0;
		b[i]=0;
	}
	for (i=1; i<= canh; i++) 
	{
		scanf("%d%d",&m,&n);
		a[m][n]=1;
		a[n][m]=1;
	}
}

// tomau
int tomau()
{
	int kt;
    for( i=1;i<=dinh;i++)
        if(!b[i]) {
            mau++; 
            b[i]=mau;
            for( j=i+1;j<=dinh;j++) 
                if((a[i][j]==0) && (b[j]==0)){
                    kt=1;
                    for(k=i+1;k<j;k++)
                        if((a[k][j]==1) && (b[i]==b[k])){
                            kt=0;
                            break;
                        }
                    if(kt==1) b[j]=mau;
                }                   
        }
}
int main()
{
	input();
	tomau();
	for (i=1; i<=mau; i++)
		for (j=1; j<=dinh; j++)
			if (b[j]==i) printf("Dinh %d to mau %d\n",j,i);
	return 0;
}
