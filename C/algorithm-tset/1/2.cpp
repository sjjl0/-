#include <iostream>
#include <vector> 
using namespace std;

int judge=0;
int equl=0; 
static int final;

int main(void)
{
	void comb(int n,int k,vector<int>a);
	int n,k;
	cin>>n>>k;
	final=k; 
	vector<int> a(n);//数字们 
	int b[n];
	int i=0,j=0;
	for(i=0;i<n;i++){
		cin>> b[i];
		a.push_back(b[i]);
	} 
	
	for(i=1;i<=n;i++)
	{
		comb(n,i,a);
	}
	if(judge==1)
		printf("YE5");
	else
		printf("N0");
	
	//system("pause");
} 

void comb(int n,int k,vector<int>a)//从n个数中取k个，a为来源 
{
	int i, j;
	for(i=n;i>=k;i--)
	{
		a[k]=i;
		if(k>1)
			comb(i-1,k-1,a);
		else
		{
			for (j=a[0];j>0;j--)
				equl+=a[j];
			if(equl==final)
				judge=1;
			equl=0;
		}
	}
}
