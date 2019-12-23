#include <iostream>
#include <string.h>
using namespace std;
int s[150][150];
int ss[150];
int main()
{
	long n,m;
	cin>>n>>m;
	int t1,t2,l;
	

    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
				s[i][j]=1000;
			
		}
	}
	
	
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2>>l;
		s[t1][t2]=l;
		s[t2][t1]=l;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		s[i][i]=0; 
	} 

	for(int k=1;k<=n;k++)
	{
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[i][k]+s[k][j]<s[i][j] && s[i][k]+s[k][j]>0)
				{
					
					s[i][j]=s[i][k]+s[k][j];


				}
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		ss[i]=-1;
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]>=ss[i])
			{
				ss[i]=s[i][j];
			}
		}

	}
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			cout<<s[i][j]<<" ";
		}
		cout<<endl;

	}

	
	int len=ss[1];
	int tt=1;
	for(int i=1;i<=n;i++) 
	{
		if(ss[i]<len)
		{
			len=ss[i];
			tt=i;
		}
	}
	
	
	
	
	
    if(len>=500)
    {
    	cout<<"0"<<endl;
	}
	cout<<tt<<" "<<len;

	return 0;
 } 
