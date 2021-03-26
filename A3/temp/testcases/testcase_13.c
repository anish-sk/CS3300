/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i; 
    int p;
    p = 1;
    i = 1;
    while ( i <= n){
        p = p * base;
        i++;
    }
    return p;
}
int main(){
    int i;
    i=0;
    while (i < 10){
        int j;
        int k;
        j = power(2,i);
        k = power(-3,i);
        printf("%d\n", i);
        printf("%d\n", j);
        printf("%d\n", k);
        i++;
    }
    return 0;
}
