#include <stdio.h>

int main()
{
	int i,j,n,dem=1; 
	// mang a la mang canh, mang b la bac cua cac dinh
	int a[100000][2], b[100000]; 
	scanf("%d",&n);
	for (i=0;i<=n;i++) b[i]=0;
	// thuan toan tinh bac cua cac dinh
	for (i=1;i<=n;i++)	
		{
			scanf("%d%d",&a[i][1],&a[i][2]);
			b[a[i][1]]++;
			b[a[i][2]]++; 
		}; 
	printf("Ma Prufer code cua cay: \n");
	// thuat toan tim prufer code

	while (dem < n)
	{	
		for (i=1;i<=n;i++)
		{
			// tu mang b tim cac dinh co ba la 1
			if (b[i]==1)
			{
				// gan dinh co bac la 1 = 0
				dem++; b[i]=0;
				// chay mang a de tim dinh lien ket voi dinh bac 1
				for (j=1;j<=n;j++)
				{
					if (a[j][1]!=a[j][2])
					{
						if (a[j][1]==i)
						{
							printf("%d ",a[j][2]);
							b[a[j][2]]--; 
							a[j][1]=0; a[j][2]=0;break;
						}
						if (a[j][2]==i)
						{
							printf("%d ",a[j][1]); 
							b[a[j][1]]--;
							a[j][1]=0; a[j][2]=0;break;
							
						}
					}
				}
			}
			
		}
		
	} 
	return 0;
}
