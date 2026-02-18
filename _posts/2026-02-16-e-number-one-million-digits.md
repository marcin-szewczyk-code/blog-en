---
title: "The Number “e”: Accurate to One Million Decimal Places"
date: 2026-02-16 07:00:00 +0100
categories: [Mathematics]
tags: [math, e, taylor-series, c, gmp]
---

## The Taylor Series of $e^x$

The number $e$ has many interesting properties and applications. In addition, the Taylor series expansion of $e^x$ at $x=1$ is strictly positive (non-alternating) and converges very rapidly. This is due to the factorial in the denominator:

$$
e^x=\sum_{n=0}^{\infty}\frac{x^n}{n!}
\:\:\Rightarrow\:\:
e=\sum_{n=0}^{\infty}\frac{1}{n!}.
$$

Because of this, it is straightforward to write a program in C that computes this series with good precision - and, using the GMP library, with essentially arbitrary precision.

GMP (GNU Multiple Precision Arithmetic Library) is a library for computations with numbers of arbitrarily high precision, far beyond what standard floating-point types provide, limited only by available memory.

## Computing $e$ from the Taylor Series

Here I provide two codes:
- plain C, without GMP, computing $e$ to ten decimal places: [e_number.c](/assets/posts/e-number-one-million-digits/e_number.c)
- a similar code using GMP, computing $e$ to one million decimal places: [e_number_gmp.c](/assets/posts/e-number-one-million-digits/e_number_gmp.c)

The output of `e_number.c` is: $e=2.7182818284\ldots$.

The program `e_number_gmp.c` produces the value of $e$ with one million digits after the decimal point, written to the file [e_number_gmp.txt](/assets/posts/e-number-one-million-digits/e_number_gmp.txt). The first 1000 digits (out of one million) look as follows:

```txt
e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353545
713821785251664274274663919320030599218174135966290435729003342952605956307381323286
279434907632338298807531952510190115738341879307021540891499348841675092447614606680
822648001684774118537423454424371075390777449920695517027618386062613313845830007520
449338265602976067371132007093287091274437470472306969772093101416928368190255151086
574637721112523897844250569536967707854499699679468644549059879316368892300987931277
361782154249992295763514822082698951936680331825288693984964651058209392398294887933
203625094431173012381970684161403970198376793206832823764648042953118023287825098194
558153017567173613320698112509961818815930416903515988885193458072738667385894228792
284998920868058257492796104841984443634632449684875602336248270419786232090021609902
353043699418491463140934317381436405462531520961836908887070167683964243781405927145
6354906130310720851038375051011574770417189861068739696552126715468895703503540212..
```

There are more similar computations, for example in the project
[y-cruncher na numberworld.org](https://www.numberworld.org/y-cruncher/),
which also record-breaking results for $e$, $\pi$, and other constants.


Some time ago I also typeset in LaTeX an interesting book on this topic and wrote a foreword to it:
[Number e to Approximately 1 Million Places](/assets/posts/e-number-one-million-digits/number_e_to_approximately_1_million_places.pdf).

## C Code (without GMP)

Below is the simple C code without GMP (self-explanatory), from the file [e_number.c](/assets/posts/e-number-one-million-digits/e_number.c):

```c
#include <stdio.h>
/*
 Computation of e without GMP (limited precision).
 We compute the series: e = sum_{n=0..∞} 1/n!
 Stop when the term becomes smaller than eps.
 The result is printed to 10 decimal places.

 Compilation: gcc e_number.c -O2 -o e_number.exe */

int main(void)
{
    const int DIGITS = 10;
    const long double eps = 1e-12L;  // safety margin relative to 1e-10

    long double e = 1.0L;      // sum
    long double term = 1.0L;   // 1/0!
    unsigned long k = 1;

    // stop when the next term is too small to affect the result
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

I compile the C codes in MinGW:

```bash
gcc e_number.c -O2 -o e_number.exe
gcc e_number_gmp.c -O2 -lgmp -o e_number_gmp.exe
```

You do it. It works. Nice.

This concludes the three-part series on the number $e$: from intuition, through Euler’s formula and Taylor series, to computations accurate to one million decimal places.
