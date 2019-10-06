#include<stdio.h>
#include<vector>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n,vector<int> & includedElements)
{
	int i, w;
	int K[n+1][W+1];
	bool included[n+1][W+1];
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			included[i][w] = 0;
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
			{
				if(K[i-1][w] < val[i-1] + K[i-1][w-wt[i-1]])
				{
					included[i][w]=true;
					K[i][w] = val[i-1] + K[i-1][w-wt[i-1]] ;
				}
				else
				{
					included[i][w]=false;
					K[i][w] = K[i-1][w] ;
				}
			}
			else
			    K[i][w] = K[i-1][w];
		}
	}
	i=n;
	w=W;
	while(i>0 && w>0)
	{
		if(included[i][w]==1)
		{
			i--;
			w-=wt[i];
			includedElements.push_back(i);
		}
		else
		{
			i--;
		}
	}

	return K[n][W];
}

int main()
{
    int i, n, val[20], wt[20], W, noOfElements, j;
    vector<int> includedElements;
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter value and weight of items:\n");
    for(i = 0;i < n; ++i){
    	scanf("%d%d", &val[i], &wt[i]);
    }

    printf("Enter size of knapsack: ");
    scanf("%d", &W);

    printf("Total Value of Knapsack = %d \n", knapSack(W, wt, val, n, includedElements));
    noOfElements = includedElements.size();
    if(noOfElements)
    { 
   		printf("The elements in Knapsack are : \n");
       	for(j=0;j<noOfElements;j++)
       	{
       		printf("%d : w=%d    val=%d\n",j+1,wt[includedElements[j]],val[includedElements[j]]);
       	}
    }
    return 0;
}
