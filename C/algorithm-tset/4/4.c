#include <stdio.h>
#include <malloc.h>

int slove(int *a,int n)
{ 
	int d,i,j,ind;//d为增量
        int temp;
        for(d=n/2;d>0;d=d/2)  //最外层循环，用来确定增量的多少
        {
                for(i=0;i<d;i++)    //外层循环，用来确定要执行多少次直接插入排序
                {
                        for(j=i;j<n;j=j+d)   //内层循环，分组后的排序，采用直接插入排序
                        {
                                temp=a[j];
                                ind=j-d;
                                while(temp<a[ind] && ind>=0)
                                {
                                       a[ind+d]=a[ind]; 
                                       ind=ind-d; 
                                }
                                a[ind+d]=temp;
                
                        }
                }
        }
	
										  
	int b[n];
	b[0]=0;
	for(i=1;i<n;i++)
         b[i]=b[i-1]+a[i-1];
    int sub=0;
    for(i=0;i<n;i++)
        sub=sub+b[i];
	return sub;	
							  
}

int main()
{
	int T;
	scanf("%d",&T);
	int t;
	for(t=0;t<T;t++)
	{
		int n,i;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int time=slove(a,n);
		printf("%d\n",time);
	}
	system("pause");
}
