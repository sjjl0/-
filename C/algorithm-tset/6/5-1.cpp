
#include<iostream>

#include<algorithm>

using namespace std;

 

const int maxn=20;

 

struct timetable

{

	int a;

	int b;

}time[maxn];

 

bool comp(timetable &x,timetable &y)//�࿴���� 

{

		return (x.a<y.a);

}

 

 

 

int main()

{

	int i,j,N,n,count;

	int begin,end;

	while(cin>>N)//N��ʾ�м���������� 

	{

		while(N--)

		{

			cin>>begin>>end;

			cin>>n;//n������ 

			for(i=0;i<n;i++)

			{

				cin>>time[i].a;

				cin>>time[i].b;

			}

			

			sort(time,time+n,comp);//���䰴��a��С�������� 

			

			count=0;

			int len=0,maxlen,tmp;

			int newbegin=begin;

			i=0; 

			while(len<end-begin)

			{

				maxlen=0;

				for(i;i<n;i++)//�ҵ�ǰbegin������ 

			    {

					if(time[i].a<=newbegin)

					{

						tmp=time[i].b-newbegin;

						if(tmp>maxlen)

						{

							maxlen=tmp;

							j=i;

						}	

					}

					else

						break;	

				}

				

				if(maxlen==0)//˵�����ˣ��������������� 

				{

					cout<<"no exit;";

					return 0;

				}

				

				cout<<"("<<time[j].a<<","<<time[j].b<<")"<<"  ";

				len+=maxlen;

				count++;

				newbegin=time[j].b;

				

			}

			cout<<endl<<count<<endl; 

		}

	} 

} 

