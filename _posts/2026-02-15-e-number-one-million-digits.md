---
title: "Liczba „e” (3/3): Z dokładnością do miliona miejsc po przecinku"
post_id: e-number-one-million-digits
date: 2026-02-15 07:00:00 +0100
categories: [Mathematics]
tags: [math, e, taylor-series, c, gmp]
---

## Szereg Taylora funkcji $e^x$

Liczba $e$ ma wiele ważnych własności i zastosowań, a dodatkowo ciekawe jest też to, że szereg Taylora będący rozwinięciem funkcji $e^x$ dla $x=1$ jest dodatni (nie naprzemienny) i bardzo szybko zbieżny, ponieważ ma silnię kolejnych indeksów w mianowniku:

$$
e^x=\sum_{n=0}^{\infty}\frac{x^n}{n!}
\:\:\Rightarrow\:\:
e=\sum_{n=0}^{\infty}\frac{1}{n!}.
$$

Skoro tak, to łatwo jest napisać kod np. w C, który liczy ten szereg z dobrą precyzją, a z użyciem biblioteki GMP z dowolną precyzją.

GMP (GNU Multiple Precision Arithmetic Library) to biblioteka do obliczeń na liczbach o dowolnie dużej precyzji, znacznie większej niż oferowana przez standardowe typy zmiennoprzecinkowe, ograniczonej jedynie dostępną pamięcią.

## Obliczanie liczby $e$ z szeregu Taylora

Tutaj zamieściłem dwa kody:
- bez GMP, zwykłe C, oblicza $e$ do dziesięciu miejsc po przecinku: [e_number.c](/assets/posts/{{ page.post_id }}/e_number.c)
- analogiczny kod z GMP, oblicza $e$ do miliona miejsc po przecinku: [e_number_gmp.c](/assets/posts/{{ page.post_id }}/e_number_gmp.c)

Wynikiem kodu `e_number.c` jest liczba $e=2.7182818285$. Wynikiem kodu `e_number_gmp.c` jest liczba $e$ z milionem miejsc po przecinku zapisana w pliku [e_number_gmp.txt](/assets/posts/{{ page.post_id }}/e_number_gmp.txt).

Jest więcej takich obliczeń, np. w projekcie
[y-cruncher na numberworld.org](https://www.numberworld.org/y-cruncher/),
wraz z dużymi rekordami obliczeń dla $e$, $\pi$ i innych stałych.

## Kod w C (bez GMP)

Prosty kod w C bez GMP, który sam się tłumaczy, z pliku [e_number.c](/assets/posts/{{ page.post_id }}/e_number.c):

```c
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
```

Kody C kompiluję w MinGW:

```bash
gcc e_number.c -O2 -o e_number.exe
gcc e_number_gmp.c -O2 -lgmp -o e_number_gmp.exe
```

Robię → działa → jest fajnie.

To zamyka serię trzech wpisów o liczbie $e$: od intuicji, przez wzór Eulera i szereg Taylora, do obliczeń z precyzją miliona cyfr po przecinku.

