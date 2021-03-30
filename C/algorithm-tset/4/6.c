#include <stdio.h>
char str[10010];
int count[30];


int main()
{
	gets(str);
	int i,j;
	for(i=0;i<30;i++)
		count[i]=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='a')
			count[1]++;
		else if(str[i]=='b')
			count[2]++;
		else if(str[i]=='c')
			count[3]++;
		else if(str[i]=='d')
			count[4]++;
		else if(str[i]=='e')
			count[5]++;
		else if(str[i]=='f')
			count[6]++;
		else if(str[i]=='g')
			count[7]++;
		else if(str[i]=='h')
			count[8]++;
		else if(str[i]=='i')
			count[9]++;
		else if(str[i]=='j')
			count[10]++;
		else if(str[i]=='k')
			count[11]++;
		else if(str[i]=='l')
			count[12]++;
		else if(str[i]=='m')
			count[13]++;
		else if(str[i]=='n')
			count[14]++;
		else if(str[i]=='o')
			count[15]++;
		else if(str[i]=='p')
			count[16]++;
		else if(str[i]=='q')
			count[17]++;
		else if(str[i]=='r')
			count[18]++;
		else if(str[i]=='s')
			count[19]++;
		else if(str[i]=='t')
			count[20]++;
		else if(str[i]=='u')
			count[21]++;
		else if(str[i]=='v')
			count[22]++;
		else if(str[i]=='w')
			count[23]++;
		else if(str[i]=='x')
			count[24]++;
		else if(str[i]=='y')
			count[25]++;
		else if(str[i]=='z')
			count[26]++;
	}
	int temp;
	for(i=1;i<30;i++)
		for(j=1;j<30-1-i;j++)
			if(count[j]<count[j+1])
			{
				temp=count[j];
				count[j]=count[j+1];
				count[j+1]=temp;
			}
	int solve=0;
	for(i=1;i<27;i++)
		solve+=count[i]*(27-i);
	printf("%d",solve);
	system("pause");
}
