#include <stdio.h> 
#include <stdlib.h>
int calendar[1025][1025];  //�ճ̱�����

void game(int n)
{
 int len=2;
 int i,j,k;
 calendar[1][1]=1;calendar[2][1]=2;
 calendar[1][2]=2;calendar[2][2]=1;
  
  
  for(k=2;k<=n;k++){
		   int t=len;
		   len=2*len;
		   //������½ǣ����½Ǻ����Ͻ�һ��
		   for(i=t+1;i<=len;i++){
			   for(j=t+1;j<=len;j++){
				   calendar[i][j]=calendar[i-t][j-t];
			   }
		   }
		   //������½�
		   for(i=t+1;i<=len;i++){
			   for(j=1;j<=t;j++){
				   calendar[i][j]=calendar[i-t][j]+t;
			   }
		   }
		   //������Ͻǣ����ϽǺ����½�һ��
		   for(i=1;i<=t;i++){
			   for(j=t+1;j<=len;j++){
				   calendar[i][j]=calendar[i+t][j-t];
			   }
		   }
	   }
  
}

int main()
{
  int i,j;
  int number,n;//������ �����Ƕ��ļ��η� 
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
  
  for(i=1;i<=number;i++)
        {
            for(j=1;j<=number;j++)
            {
				printf("%d ",calendar[i][j]);
			}
            printf("\n");
        }	
	}  
}

