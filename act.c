#include<stdio.h>
#include<stdlib.h>
int sor(int str[],int end[],int n)
{
    int i,j;
	for( i=1;i<n;i++)
	{
		int temp=end[i],temp1=str[i];
		for( j=i-1;j>=0;j--)
		{
			if(end[j]>temp)
			{
				end[j+1]=end[j];
				str[j+1]=str[j];
			}
			else
			break;
		}
		end[j+1]=temp;
		str[j+1]=temp1;
	}
}
int solve(int str[],int end[],int prev,int curr,int n)
{
	printf("%dp%dl",curr,prev);
	if(curr>n-1)
	return 0;
	if(end[prev]<=str[curr]){
	prev=curr;printf("%d",prev);return solve(str,end,prev,curr+1,n);}
	return solve(str,end,prev,curr+1,n);
}
int main()
{
	int n;
	scanf("%d",&n);
	int str[n],end[n],i;
	for( i=0;i<n;i++)
	scanf("%d",&str[i]);
	for( i=0;i<n;i++)
	scanf("%d",&end[i]);
	sor(str,end,n);
	printf("0 ");
	solve(str,end,0,1,n);
}
