//ex14B)  FLOYD WARSHALL ALGORITHM

#include<iostream>
using namespace std;
int A[20][20];
int output[20][20];
int n;
void print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<output[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void floyd()
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(output[i][k]+output[k][j]<output[i][j])
				    output[i][j]=output[i][k]+output[k][j];
			}
		}
	}
	print();
}



int main()
{
	cout<<"\nENTER THE NO OF VERTICES: ";
	cin>>n;
	cout<<"\nENTER THE ADJACENCY MATRIX: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];
			output[i][j]=A[i][j];
		}
	}
	
	floyd();
	return 0;
	
}


/*

ENTER THE NO OF VERTICES: 4

ENTER THE ADJACENCY MATRIX:
0 9 -4 999
6 0 999 2
999 5 0 999
999 999 1 0
0 1 -4 3
6 0 2 2
11 5 0 7
12 6 1 0   */
