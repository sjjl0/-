#include <stdio.h>

int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int minnum(char *stra,char *strb)
{
	int lena,lenb;
	int i,j;
	int temp=0;
	for(i=0;stra[i]!='\0';i++)
		temp++;
	lena=temp;
	temp=0;
	for(i=0;strb[i]!='\0';i++)
		temp++;
	lenb=temp;
	temp=0;
	int d[lenb+1][lena+1];
	d[0][0]=0;
	for(i=1;i<=lena;i++)
		d[0][i]=i;
	for(i=1;i<=lenb;i++)
		d[i][0]=i;
	for(i=1;i<=lenb;i++)
		for(j=1;j<=lena;j++)
			d[i][j]=min(min(d[i-1][j]+1,d[i][j-1]+1),(stra[j-1]==strb[i-1]?d[i-1][j-1]:d[i-1][j-1]+1));
	return d[lenb][lena];
	
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,j,t;
	fflush(stdin);
	for(t=0;t<T;t++)
	{
		char stra[1010];
		char strb[1010];
		gets(stra);
		fflush(stdin);
		gets(strb);
		int solve=minnum(strb,stra);
		printf("%d\n",solve);
		fflush(stdin);
	}
	system("pause");
}
