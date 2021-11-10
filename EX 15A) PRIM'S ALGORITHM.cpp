//EX15a) PRIM'S ALGORITHM
#include<iostream>
#include<limits>
using namespace std;
int A[20][20],n,output[20],d[20];
bool known[20];
int find_min(int d[])
{
	int min=INT_MAX;
	int p;
	for(int i=0;i<n;i++)
	{
		if(known[i]==false && d[i]<=min)
		{
			min=d[i];
			p=i;
		}
	}
	return p;
}
void print()
{
	for(int i=0;i<n;i++)
	cout<<d[i]<<" ";
}

void prims(int A[20][20])
{
	int v;
	for(int i=0;i<n;i++)
	{
		known[i]=false;
		d[i]=INT_MAX;
	}
	d[0]=0;
	
	output[0]=-1;
	
	for(int j=0;j<n-1;j++)
	{
		int updated_min=find_min(d);
		known[updated_min]=true;
		
		for(v=0;v<n;v++)
		{
			if(known[v]==false && A[updated_min][v] && A[updated_min][v]<d[v]  )
			{
				output[v]=updated_min;
				d[v]=A[updated_min][v];
			}
		}
	}
	print();
}




int main()
{
	cout<<"\nENTER THE NO OF NODES:";
	cin>>n;
	cout<<"\nENTER THE ADJACENCY MATRIX:";
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	  cin>>A[i][j];
	  
	 prims(A);
	 return 0; 
}

/*
ENTER THE NO OF NODES:6

ENTER THE ADJACENCY MATRIX:0 7 8 0 0 0
7 0 3 6 0 0
8 3 0 4 3 0
0 6 4 0 2 5
0 0 3 2 0 2
0 0 0 5 2 0

ENTER THE SOURCE VERTEX:0
0 7 3 2 3 2
*/
