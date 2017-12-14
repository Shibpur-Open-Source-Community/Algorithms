#include <stdio.h>

bool DP(int set[], int n, int sum)
{
    bool subset[n+1][sum+1];
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;
    for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] ||
                                 subset[i - 1][j-set[i-1]];
       }
     }
     return subset[n][sum];
}

int main()
{
  int n;
  int sum;
  printf("Enter no of elements of array and desired sum\n");
  scanf("%d%d",&n,&sum);
  int i,a[n];
  printf("Enter the array\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  if (DP(a, n+1, sum) == true)
     printf("Found a subset with given sum\n");
  else
     printf("No subset with given sum\n");
  return 0;
}
