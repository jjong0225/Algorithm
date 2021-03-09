int input_k[1000];
int b_search(int low, int high, int target)
{
    int mid = 0;
    while(low < high)
    {
        mid = (low + high)/2;
        if(target < input_k[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}