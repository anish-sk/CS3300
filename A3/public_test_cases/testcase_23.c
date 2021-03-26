int main() {
    int i;
    int j;
    int a[4000];
    int b[4000];
    int c[5000];
    int s;
    s = 0;
    i = 0;
    j = 0;
    while(i < 1000) {
        int j;
        j = 0;
        a[i] = i + 1;
        while(j < 200) {
            b[j] = ((a[i]) - 1) * 3;
            c[i + j] = (c[i + j]) + ((b[i]) + (a[j]));
            j = j + 1;
        }
        i = i + 1;
    }
    while(i < 1200) {
        s = (s) + (c[i]);
        i = i + 1;
    }
    printf("%d\n", s);
}
