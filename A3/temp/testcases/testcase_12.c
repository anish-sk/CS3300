int main(){
    int fahr;
    int Celsius;
    int lower;
    int upper;
    int step;
    lower =0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step =20; /* step size */
    fahr = lower;
    while (fahr <= upper) {
    Celsius = 5 * ((fahr-32) / 9);
    printf ( "%d\n", fahr);
    printf ( "%d\n", Celsius);
    fahr = fahr + step;
    }
    return 0;
}
