#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int randoms(int n) {
    int random_number = rand() % n;
    return random_number;
}


int partitionsRandom(vector<int>&  nums,int low,int high)
{
    int random;
    random = randoms(high);
    swap(nums[random],nums[high]);
    //int random = rand()%(high-1);
    //swap(nums[random],nums[high]);
    int x = nums[high];
    int i = low - 1;
    for(int j=low;j<=high-1;j++)
    {
        if(nums[j]<x)
        {
            i=i+1;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[high]);
    return i+1;
}

void quickSortRandom(vector<int>& nums,int low,int high)
{
    if(low<high)
    {
        int q = partitionsRandom(nums,low,high);
        quickSortRandom(nums,low,q-1);
        quickSortRandom(nums,q+1,high);
    }
}

int partitions(vector<int>&  nums,int low,int high)
{
    int x = nums[high];
    int i = low - 1;
    for(int j=low;j<=high-1;j++)
    {
        if(nums[j]<x)
        {
            i=i+1;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[high]);
    return i+1;
}


void quickSort(vector<int>& nums,int low,int high)
{
    if(low<high)
    {
        int q = partitions(nums,low,high);
        quickSort(nums,low,q-1);
        quickSort(nums,q+1,high);
    }
}

int main()
{
    int arr[] = {2,35,456,52,23,123,4,6,4,3,21,34,67,890,778,54,32,12,45,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums(arr,arr+n);
    quickSort(nums,0,nums.size()-1);
    //quickSortRandom(nums,0,nums.size()-1);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
