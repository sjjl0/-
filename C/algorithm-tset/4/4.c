#include <stdio.h>
#include <malloc.h>

int slove(int *a,int n)
{ 
	int d,i,j,ind;//dΪ����
        int temp;
        for(d=n/2;d>0;d=d/2)  //�����ѭ��������ȷ�������Ķ���
        {
                for(i=0;i<d;i++)    //���ѭ��������ȷ��Ҫִ�ж��ٴ�ֱ�Ӳ�������
                {
                        for(j=i;j<n;j=j+d)   //�ڲ�ѭ�������������򣬲���ֱ�Ӳ�������
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
