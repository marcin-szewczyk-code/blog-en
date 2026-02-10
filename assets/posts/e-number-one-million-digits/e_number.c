#include <stdio.h>
/*
 Obliczenie liczby e bez GMP (mała precyzja).
 Liczymy szereg: e = sum_{n=0..∞} 1/n!
 Zatrzymanie po osiągnięciu zadanego progu eps,
 a wynik wypisywany do 10 miejsc po przecinku.

 Kompilacja: gcc e_number.c -O2 -o e_number.exe
 */

int main(void)
{
    const int DIGITS = 10;
    const long double eps = 1e-12L;  // zapas w stosunku do 1e-10

    long double e = 1.0L;      // suma
    long double term = 1.0L;   // 1/0!
    unsigned long k = 1;

    // zatrzymanie, gdy kolejny wyraz jest na tyle mały, że nie wpływa na wynik
    while (term > eps) {
        term /= (long double)k;   // term = 1/k!
        e += term;
        k++;
    }

    printf("e = %.*Lf\n", DIGITS, e);
    printf("Uzyte wyrazy szeregu: %lu\n", k);

    return 0;
}