int partition()
{
    int low;
    int high;
    int pivot;
    int i;
    int j;
    int f;
    int arr[16];
    i = 0;
    f = 1;
    while(i<16){
        int g;
        arr[i] = (i+1)*(16-i);
        g = arr[i];
        printf("%d\n", g);
        i++;
    }
    low = 0;
    high = 15;
    i = low - 1; 
    j = high + 1;
    pivot = arr[8];
    while (f) {
        int t;
        // Find leftmost element greater than
        // or equal to pivot
        i++;
        while ((arr[i]) < pivot)
            i++;

        // Find rightmost element smaller than
        // or equal to pivot
        j--;
        while ((arr[j]) > pivot)
            j--;

        // If two pointers met.
        if (i >= j)
            f = 0;
        if(f){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++; 
            j--;
        }
    }
    i=0;
    while(i<16){
        int g;
        g = arr[i];
        printf("%d\n", g);
        i++;
    }
    return 0;
}
int main(){
    int a;
    a = partition();
    printf("%d\n", a);
    return 0;
}
