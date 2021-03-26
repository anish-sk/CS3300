int add(int a, int b) {
    printf("%d\n", a);
    return a + b;
}

int fib(int n) {
    int c;
    int d;
    if((n == 1) || (n == 2)) {
        return 1;
    }
    c = fib(n-1);
    d = fib(n-2);
    return add(c, d);
}

int main() {
    int n;
    int sum;
    int i;
    int a[1000];
    i = 1;
    n = 10;
    while(i <= n) {
        int x;
        a[i - 1] = fib(i);
        i = i + 1;
    }
    i = 0;
    while(i < n) {
        int f;
        f = a[i];
        printf("%d\n", f);
        i = i + 1;
    }
    i = (((2 * (add(i, n))) + (3 / i)) * (((a[6]) + ((7 % (fib(3))) && n)) || (1313 - (a[8])))) - ((((i - n) % 7) + ((-n) * (16 / (a[3])))));
    printf("%d\n", i)   ;
    return 0;
}
