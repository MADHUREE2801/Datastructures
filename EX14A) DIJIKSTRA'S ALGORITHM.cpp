//EX 14A)  DIJIKSTAR'S ALGORITHM
#include<iostream>

//#include<conio.h>
#include<limits>
using namespace std;

int A[20][20];
int d[20];
bool known[20];
int n;
int findmin(int d[],bool known[20])
{
 int min=INT_MAX;
 int p;
 for(int i=0;i<n;i++)
 {
  if(known[i]==false && d[i]<min)
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
  cout<<d[i]<<"  ";
}

void dijik(int source)
{
 for(int i=0;i<n;i++)
 {
  d[i]=INT_MAX;
  known[i]=false;
 }
  d[source]=0;
  for(int j=0;j<n-1;j++)    //table  n-1 times
  {
   int updated_min=findmin(d,known);
   known[updated_min]=true;
   for(int v=0;v<n;v++)
   {
    if(known[v]==false && A[updated_min][v]!=0 &&
    d[updated_min]!=INT_MAX && d[updated_min]+A[updated_min][v]<d[v])
      d[v]=d[updated_min]+A[updated_min][v];
    }
   }
  cout<<"\nPRINT SHORTEST PATHS: ";
  print();

}

int main()
{
// clrscr();
 cout<<"\nENTER THE NO OF VERTICES: ";
 cin>>n;
 cout<<"\nENTER THE ADJACENCY MATRIX: ";
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
   cin>>A[i][j];
 }
 int source;
 cout<<"\nENTER THE SOURCE VERTEX: ";
 cin>>source;
 dijik(source);
 //getch();
return 0;
}



/*
ENTER THE NO OF VERTICES: 5

ENTER THE ADJACENCY MATRIX: 
0 10 5 0 0
0 0 0 1 0
0 3 0 9 2
0 0 0 0 0
2 0 0 6 0

ENTER THE SOURCE VERTEX: 0

PRINT SHORTEST PATHS: 0  8  5  9  7

*/
