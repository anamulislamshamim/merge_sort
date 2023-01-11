#include<bits/stdc++.h>

using namespace std;

vector<int>mergeSort(vector<int>arr)
{
    // check if the array length is 1 or 0 then this array is already sorted
    if(arr.size() <= 1)
        return arr;
    int mid = arr.size() / 2;
    // create an array with the value of less than arr[mid];
    vector<int>left;
    for(int i=0;i<mid;i++)
        left.push_back(arr[i]);
    // create an array with the value greater than or equal to arr[mid];
    vector<int>right;
    for(int i=mid;i<arr.size();i++)
        right.push_back(arr[i]);
    // now we need to sort the left and right array:
    vector<int>sorted_left=mergeSort(left);
    vector<int>sorted_right=mergeSort(right);
    // now the we need to merge the sorted left and right array:
    vector<int>sorted_arr;
    int il=0,ir=0;
    while(il < sorted_left.size() && ir < sorted_right.size()){
        if(sorted_left[il] < sorted_right[ir]){
            sorted_arr.push_back(sorted_left[il]);
            il++;
        }else
        {
            sorted_arr.push_back(sorted_right[ir]);
            ir++;
        }
    };
    // we should check if any elements left. Since the array is already sorted
    // we just push_back the rest elements into the sorted_arr
    while(il<sorted_left.size()){
        sorted_arr.push_back(sorted_left[il]);
        il++;
    };
    while(ir<sorted_right.size()){
        sorted_arr.push_back(sorted_right[ir]);
        ir++;
    };
    // so here sorted_arr is the sorted array of arr;
    return sorted_arr;
}
int main()
{
    vector<int>arr={5,1,4,3,7,2};
    vector<int>ans=mergeSort(arr);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}
