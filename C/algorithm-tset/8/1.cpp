
#include<iostream>

#include<cstring>

using namespace std;

int x[30];

bool mark[30];

int n;

bool prime(int num)

{

	int primeNum[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};//20+19=39

	for(int i=0;i<14;i++){

		if(primeNum[i]==num) return true;

	}

	return false;

}

void output()

{

	for(int i=1;i<=n;i++)

	{

		 if(i==1) cout<<x[i];

		 else printf(" %d",x[i]);

	}

	printf("\n");

}

void dfs(int t)

{

	if(t>n){

		if(prime(x[n]+x[1])==true) output();

		return;

 	}

 	else

 	{

 		for(int i=2;i<=n;i++)

 		{

 			if(mark[i]==true) continue;

 			x[t]=i;

 			mark[i]=true;

 			if(prime(x[t]+x[t-1])) dfs(t+1);

 			mark[i]=false;

		 }

	 }

}

int main(void)

{

	cin>>n; 

	memset(x,0,sizeof(x)); 

	for(int i=1;i<=n;i++){

		mark[i]=false;

	}

	x[1]=1;mark[1]=true;

	dfs(2);

	system("pause");

 } 

