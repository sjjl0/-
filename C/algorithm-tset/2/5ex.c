#include <stdio.h> 
#include <stdlib.h>
int calendar[1025][1025];  //日程表数组

void game(int k)
{
 int p,q,m,number;
 int i,j;
 number=k;
 p=m=1;
 calendar[1][1]=2;
 calendar[2][1]=1;
 while(m<number)
 {
   m++;
   p=2*p;
   q=2*p;
     //填充日程表的左下角
   for(i=p+1;i<=q;i++)
      for(j=1;j<p;j++)
        calendar[i][j]=calendar[i-p][j]+p;
     //填充日程表的右上角
   calendar[1][p]=p+1;
   for(i=2;i<=p;i++)
      calendar[i][p]=calendar[i-1][p]+1;
   for(j=p+1;j<q;j++)
    {
      for(i=1;i<p;i++)
        calendar[i][j]=calendar[i+1][j-1];
      calendar[p][j]=calendar[1][j-1];                 
    }  
       //填充日程表的右下角
    for(j=p;j<q;++j)
       for(i=1;i<=p;++i)
         calendar[calendar[i][j]][j]=i;            
 }    
}
int main()
{
  int i,j;
  int number,n;//人数、 人数是二的几次方 
	while(scanf("%d",&number)!=EOF)
	{
		n=0;
  int a=1;
  while(a!=number)
  {
   n++;
   a*=2;
  }
  game(n);
  for(i=i;i<=number;i++)
  	calendar[i][0]=i;
    //输出二维表 
  for(i=1;i<=number;i++)
        {
            for(j=0;j<number-1;j++)
            {
				printf("%d ",calendar[i][j]);
			} 
			printf("%d",calendar[i][number-1]);
            printf("\n");
        }	
	}  
}

