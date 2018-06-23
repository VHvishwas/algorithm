#include<iostream>
#define Max 100007
using namespace std;

void merging(int *a,int l,int m,int r)
{
int n1=m-l+1;
int n2=r-m;

int res[n1+n2+1];
int i=l,j=m+1;
int k=0;
while(i<=m&&j<=r)
{

if(a[i]>a[j])
{
  res[k++]=a[j];
  j++;
}
else
{
  res[k++]=a[i];
i++;
}

}
while(i<=m)
{
  res[k++]=a[i++];
}
while(j<=r)
{
  res[k++]=a[j++];
}


for(int u=l,f=0;u<=r;u++)
{
  a[u]=res[f++];
}


}

void merge_sort(int *a,int l,int r)
{
  if(l<r)
    {
       int m=(l+r)>>1;
       merge_sort(a,l,m);
       merge_sort(a,m+1,r);
       merging(a,l,m,r);
    }
}



int main()
{
cout<<"enter the no of elements";
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
       cin>>a[i];

merge_sort(a,0,n-1);


for(int i=0;i<n;i++)
cout<<a[i]<<" ";

       return 0;
}
