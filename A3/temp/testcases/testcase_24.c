int main() {
    int i;
    int j;
    int s;
    i = 1;
    s = 0;
    if(1 || (i/0))
        s = 2;
    printf("%d\n", s);
    return 0;
}
