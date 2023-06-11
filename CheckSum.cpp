#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define so sort(a , a+n)
#define migmig ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
int N , K;

int binary_search(int* arr, int low, int high, int key) 
{
    if (high >= low) 
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) return binary_search(arr, low, mid - 1, key);
        else return binary_search(arr, mid + 1, high, key);
    }
    return -1; 
}

bool conquer(int* arr , int low , int high)
{
    int mid = (low + high) / 2;
    int i = low , j = high;
    while (i < mid && mid < j)
    {
        if(arr[i] + arr[j] == K) return true;
        else if(arr[i] + arr[j] > K) j--;
        else i++;
    }
    return false;  
}

bool Divide(int* arr , int low , int high)
{
    if(low > high) {return false;}
    else
    {
        int mid = ((low + high)/2);
        int res = K - arr[mid];
        if(binary_search(arr , low , mid - 1 , res)!=-1) {return true;}
        else if(binary_search(arr , mid + 1 , high , res)!=-1) {return true;}
        else {return (Divide(arr , low , mid - 1)|| Divide(arr , mid + 1 , high));}
    }
}

int main()
{

    cin>>N>>K;
    int arr[N];
    for (int i = 0; i <N; i++) cin>>arr[i];
    sort(arr , arr + N);
    if(Divide(arr , 0 , N - 1)) cout<<"YES";
    else concur(arr , 0 , N - 1) ? cout<<"YES":cout<<"NO";        
}