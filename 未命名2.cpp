#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int s1[15];
int s2[15];
int s[15][15];
int  n,m;
void bfs(int start)
{
	queue<int> q;
	int t;
	q.push(start);
	s1[start]=1;
	cout<<"{ ";
	t=q.front();
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		for(int i=0;i<n;i++)
		{
			if(s[q.front()][i]==1 && s1[i]==0)
			{
				q.push(i);
				s1[i]=1;
			}

		}
		q.pop();
		t=q.front();
	}
	cout<<"}"<<endl;

}
void dfs(int start)
{
	stack<int> ss;
	ss.push(start);
	s2[start]=1;
    cout<<"{ ";
    cout<<ss.top()<<" ";
    int t;
	t=ss.top();
    bool is_push ;//= false;
	while(!ss.empty())
	{
//		cout<<ss.top()<<" ";
        is_push = false;
		for(int i=0;i<n;i++)
		{
			if(s[t][i]==1 && s2[i]==0)
			{
				ss.push(i);
				s2[i]=1;
				cout<<i<<" ";
				t=ss.top();
				is_push = true;	
				break;
			}

		}
		if(!is_push)
		{
			
			ss.pop();
			if(ss.empty())
			{
				break;
			}
			t=ss.top();
		}
		
	}
	cout<<"}"<<endl;
}
int main()
{

	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int r,l;
		cin>>r>>l;
		s[r][l]=1;
		s[l][r]=1;	
	}
		for(int i=0;i<n;i++)
	{
		if(s2[i]==1)
		{
			continue;
		}
		else
		{
			dfs(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s1[i]==1)
		{
			continue;
		}
		else
		{
			bfs(i);
		}
	}
	return  0;
 } 

