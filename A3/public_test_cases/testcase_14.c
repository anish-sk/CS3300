int bitcount(int x)
{
    int b;
    b = 0;
    while (x != 0){ 
        if (x % 2)
            b++;
        x = x/2;
    }
    return b;
}
int main(){
    int i;
    int j;
    i = 472989277;
    j = bitcount(i);
    printf("%d\n", j);
    i = 630771612;
    j = bitcount(i);
    printf("%d\n", j);
    i = 538395361;
    j = bitcount(i);
    printf("%d\n", j);
    i = 472989277;
    j = bitcount(i);
    printf("%d\n", j);
    i = 704943118;
    j = bitcount(i);
    printf("%d\n", j);
    i = 537939794;
    j = bitcount(i);
    printf("%d\n", j);
    i = 430263627;
    j = bitcount(i);
    printf("%d\n", j);
    i = 820265837;
    j = bitcount(i);
    printf("%d\n", j);
    i = 362791971;
    j = bitcount(i);
    printf("%d\n", j);
    i = 992650071;
    j = bitcount(i);
    printf("%d\n", j);
    i = 3687202;
    j = bitcount(i);
    printf("%d\n", j);
    return 0;
}
