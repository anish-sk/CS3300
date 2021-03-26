int bsearch(int x){
    int low;
    int high;
    int mid;
    int v[100];
    int i;
    i=0;
    while(i<100){
        v[i] = (3*i) + 5;
        i++;
    }
    low = 0;
    high = 100 - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < (v[mid]))
            high = mid - 1;
        else if (x > (v[mid]))
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1;
}
int main(){
    int x;
    int j;
    x = 65;
    j = bsearch(x);
    printf("%d\n", j);
}
