#include <stdio.h>
#include <gmp.h>

/*
 Obliczenie liczby e z GMP (duża precyzja).
 Liczymy szereg: e = sum_{n=0..∞} 1/n!
 Zatrzymanie gdy kolejny wyraz term < eps.
 Zapis wyniku: plik e_number_gmp.txt

 Kompilacja: gcc e_number_gmp.c -O2 -lgmp -o e_number_gmp.exe
 */

int main(void)
{
    const long DIGITS = 1000000;   // 1000000 dla miliona cyfr
    const double LOG2_10 = 3.32192809488736234787;

    /* precyzja binarna ~ DIGITS cyfr dziesiętnych + zapas */
    mp_bitcnt_t prec = (mp_bitcnt_t)(DIGITS * LOG2_10) + 128;
    mpf_set_default_prec(prec);

    /* e = suma, term = kolejny wyraz 1/k! */
    mpf_t e, term, eps;
    mpf_init(e);
    mpf_init(term);
    mpf_init(eps);

    mpf_set_ui(e, 1);      // suma startuje od 1/0! = 1
    mpf_set_ui(term, 1);   // term = 1/0! = 1

    /* eps = 10^(-(DIGITS+2)) -> 2 cyfry zapasu */
    mpf_set_ui(eps, 1);
    for (long i = 0; i < DIGITS + 2; i++)
        mpf_div_ui(eps, eps, 10);

    unsigned long k = 1;

    // zatrzymanie gdy kolejny wyraz term < eps
    while (mpf_cmp(term, eps) > 0) {
        mpf_div_ui(term, term, k); // term = 1/k!
        mpf_add(e, e, term);       // e += term
        k++;
    }

    // zapis do pliku
    FILE *f = fopen("e_number_gmp.txt", "w");
    if (!f) {
        perror("fopen e.txt");
        mpf_clear(e);
        mpf_clear(term);
        mpf_clear(eps);
        return 1;
    }

    gmp_fprintf(f, "e = %.*Ff\n", (int)DIGITS, e);
    fclose(f);

    printf("Zapisano wynik do e_number_gmp.txt\n");
    printf("Cyfry po przecinku: %ld\n", DIGITS);
    printf("Uzyte wyrazy szeregu: %lu\n", k);

    mpf_clear(e);
    mpf_clear(term);
    mpf_clear(eps);

    return 0;
}