int sumOfDigit(int num)
{
    int s;
    int a;
    s = 0;
    s = s + (num%10);
    a = num/10;
    if(a > 0)
    {
        return s + (sumOfDigit(a));
    }
    return s;
}
int main(){
    int a;
    int b;
    int c;
    a = 870051;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 732897;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 387;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 478;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 81;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 241;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 525;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 513;
    printf("%d\n", c);
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 750;
    c = sumOfDigit(a);
    printf("%d\n", c);
    a = 150;
    c = sumOfDigit(a);
    printf("%d\n", c);
    return 0;
}
