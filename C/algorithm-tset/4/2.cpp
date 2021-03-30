#include <iostream>
#include <string.h>
using namespace std;

int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int minnum(char *stra,char *strb)
{
	int lena=strlen(stra);
	int lenb=strlen(strb);
	int i,j,temp;
	
	int d[lena+1][lenb+1];
	d[0][0]=0;
	for(i=1;i<=lena;i++)
		d[i][0]=i;
	for(i=0;i<=lenb;i++)
		d[0][i]=i;
	for(i=1;i<=lena;i++)
		for(j=1;j<=lenb;j++)
			{
				if(strb[j-1]==stra[i-1])
					d[i][j]=d[i-1][j-1];
				else
				{
					temp=min(d[i][j-1],d[i-1][j]);
					d[i][j]=min(temp,d[i-1][j-1])+1;
				}
			}
	return d[lena][lenb];
	
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,j,t;
	for(t=0;t<T;t++)
	{
		char stra[1010],strb[1010];
		cin>>stra>>strb;
		int solve;
		solve=minnum(stra,strb);
		printf("%d\n",solve);
	}
	system("pause");
}
