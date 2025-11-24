#include<stdio.h>
 int a[10][10],n;
 void adj(int k);
 void main()
{
int i,j,root;
printf("enter no of nodes:"); 
scanf("%d",&n);
printf("\nenter adjacent matrix\n");
 for(i=1;i<=n;i++) {
 for(j=1;j<=n;j++)
{
printf("enter connecting of %d->%d::",i,j);
 scanf("%d",&a[i][j]);
}
}
printf("\nenter root node:");
 scanf("%d",&root); adj(root);
}
void adj(int k)
{
int i,j;
printf("adjacent node of root node::\n"); 
printf("%d->",k);
for(j=1;j<=n;j++)
{
if(a[k][j]==1||a[j][k]==1)
 printf("%d->",j);
}
//printf("\n");
 for(i=1;i<=n;i++)
{
if((a[k][j]==0)&&(a[i][k]==0)&&(i!=k))
 printf("%d->",i);
}
}
