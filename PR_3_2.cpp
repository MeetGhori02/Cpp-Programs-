#include<iostream>
#include<vector>
using namespace std;

int recursivesum(int arr[],int n)
{
    if(n==0)
    {
        return 0;
    }
    else

    {
        return arr[n-1]+recursivesum(arr,n-1);
    }
}

int interactivesum(int Arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=Arr[i];
    }
    return sum;
}


 int main()
 {
     int SIZE;

     cout<<"Enter size you want :  ";
     cin>>SIZE;

    int Arr[SIZE];
//        vector<int> Arr(SIZE);

        cout<<"Enter" << SIZE <<  " elements :  ";
        for(int i=0;i<SIZE;i++)
        {
            cin>>Arr[i];
        }

        int recsum = recursivesum(Arr,SIZE);
        int intsum = interactivesum(Arr,SIZE);

        cout<<"Recursive sum is : "<< recsum <<endl;
        cout<<"Interactive sum is : "<< intsum <<endl;

        return 0;

 }


