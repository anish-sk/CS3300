int findgcd(int x, int y)
{
    int a;
    if(x > y){
        a = findgcd(x - y, y);
        return a;
    }
    else if(y > x){
        a = findgcd(x, y - x);
        return a;
    }
    else return x;
}
int main(){
    int a;
    int b;
    int c;
    a = 870051;
    b = 732897;
    c = findgcd(a, b);
    printf("%d\n", c);
    a = 387;
    b = 478;
    c = findgcd(a, b);
    printf("%d\n", c);
    a = 81;
    b = 241;
    c = findgcd(a, b);
    printf("%d\n", c);
    a = 525;
    b = 513;
    c = findgcd(a, b);
    printf("%d\n", c);
    a = 750;
    b = 150;
    c = findgcd(a, b);
    printf("%d\n", c);

    return 0;
}
