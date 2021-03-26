int main() {
    int i;
    int j;
    i=0;
    j=0;
    while(i<100)
    {
      j=j+1;
      i=i+j;
    }
    j=-2000;
    printf("%d\n", i);
    printf("%d\n", j);
    return 0;
}
