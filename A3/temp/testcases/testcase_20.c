int isPrime(int n, int i)
{
    if(i == 1)
        return 1;   // return statement terminates the recursive funtion
    else
    {
        if((n%i) == 0)
            return 0;
        else
            return isPrime(n, i-1);    // recursive call not using return statement
    }
}
int main(){
    int a;
    int c;
    a = 87000;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 73288;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 387;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 478;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 81;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 241;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 525;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 513;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 750;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    a = 150;
    c = isPrime(a, a/2);
    printf("%d\n", c);
    return 0;
}
