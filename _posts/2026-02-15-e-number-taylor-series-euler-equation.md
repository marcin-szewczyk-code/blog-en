---
title: "The Number “e”: Taylor Series and Euler’s Formula"
date: 2026-02-15 07:00:00 +0100
categories: [Mathematics]
tags: [math, e, taylor-series, euler]
---

Let us play for a moment with Euler’s famous formula:

$$
e^{ix}=\cos x + i\sin x.
$$

R.P. Feynman, in his Lectures, referred to it as “the most remarkable formula in mathematics.” Many important results follow from it. For $x=\pi$, it yields the famous identity $e^{i\pi}+1=0$, linking five fundamental constants of mathematics.


> **Source** This post is an adapted chapter from my book: M. Szewczyk, *[Analytical Methods in the Calculation of Switching Processes in Power Systems](https://www.sklep.pw.edu.pl/produkty/metody-analityczne-w-obliczeniach-procesow-laczeniowych-w-systemie-elektroenergetycznym)*, OWPW 2024. At a deeper source level, it is also based on the beautiful textbook: G. Fichtenholz, *Differential and Integral Calculus*, Vol. II, PWN, Warsaw 1965. Original title: Г. М. Фихтенгольц, *Course of Differential and Integral Calculus*, Moscow–Leningrad 1958.

## The Taylor Series

Euler’s formula $e^{ix}=\cos x + i\sin x$ can be obtained by examining the Taylor expansions of the functions $e^x$, $\cos x$, and $\sin x$ about $x_0=0$:

$$
f(x)=\sum_{n=0}^{\infty}{f^{(n)}(0)\over n!}x^n\:\:.
$$

For elementary functions, successive derivatives $f^{(n)}(0)$ in Taylor series are computed according to the familiar formulas:

$$
\frac{\mathrm{d}}{\mathrm{d}x}e^x = e^x,\:\:\:
\frac{\mathrm{d}}{\mathrm{d}x}\cos{x} =-\sin{x},\:\:\:
\frac{\mathrm{d}}{\mathrm{d}x}\sin{x} = \cos{x}.
$$

Since the function $e^x$ reproduces itself under differentiation, $(e^x)' = e^x$, its Taylor expansion follows immediately:

$$
e^x=\sum_{n=0}^{\infty}{x^n\over n!}.
$$
		
In the case of $\cos x$, only the *even* terms are nonzero, while for $\sin x$, only the *odd* terms remain. This happens because the remaining derivatives are proportional to $\sin x$, which vanishes at $x=0$. Moreover, the signs alternate, starting with a positive term.

Thus, for $\cos x$:

$$
\cos x
=	{x^0\over0!}+0-{x^2\over2!}+0+{x^4\over4!}+0-{x^6\over6!}+0+{x^8\over8!}+0-\ldots
\approx
$$		

$$      
\approx 1-{x^2\over2!}+{x^4\over4!}-{x^6\over6!}+{x^8\over8!}-\ldots
+{(-1)^Nx^{2N}\over (2N)!}
=\sum_{n=0}^{N}{(-1)^nx^{2n}\over (2n)!}
$$

and similarly for $\sin x$:
		
$$
\sin x
={x^1\over1!}+0-{x^3\over3!}+0+{x^5\over5!}+0-{x^7\over7!}+0+{x^9\over9!}+0-\ldots\approx
$$

$$
\approx
x-{x^3\over3!}+{x^5\over5!}-{x^7\over7!}+{x^9\over9!}-\ldots
+{(-1)^Nx^{2N+1}\over (2N+1)!}
=\sum_{n=0}^{N}{(-1)^nx^{2n+1}\over (2n+1)!}.
$$

Therefore, for all three functions, $e^x$, $\cos x$ i $\sin x$, we have:
		
$$
e^x=\sum_{n=0}^{\infty}{x^n\over n!}\:\:,
\:\:\:
\cos x=\sum_{m=0}^{\infty}{(-1)^nx^{2n}\over (2n)!}\:\:,
\:\:\:
\sin x=\sum_{n=0}^{\infty}{(-1)^nx^{2n+1}\over (2n+1)!}\:\:.
$$

## Rearranging the Series

The next step is to appropriately rearrange and group the terms in the expansion
		
$$
e^x=\sum_{n=0}^{\infty}{x^n\over n!},
$$

so that within the series for $e^x$ we can recognize the series for $\cos x$ and $\sin x$.

There are interesting theorems concerning permutations (rearrangements) of series terms which justify that such regrouping is legitimate in this case.

## Euler’s Formula

Since the Taylor series may be rearranged, we now substitute $ix$ for $x$, where $i^2=-1$, and obtain:

$$
e^{ix}=\sum\limits_{n=0}^\infty{(ix)^n\over n!}
=\sum\limits_{n=0}^\infty{\left[
{(ix)^{2n}\over (2n)!} + {(ix)^{2n+1}\over (2n+1)!}
\right]}
=
\sum\limits_{n=0}^\infty{
{(-1)^n\over (2n)!}x^{2n}}
+
i\sum\limits_{n=0}^\infty{
{(-1)^n\over (2n+1)!}x^{2n+1}},
$$
		
where we use the identities:
$(ix)^n=i^nx^n$,  
$i^{2n}=(i^2)^n = (-1)^n$,  
$i^{2n+1}=(-1)^ni$.

Recognizing in these expressions the Taylor series of $\cos x$ and $\sin x$, we obtain the formula known as *Euler’s formula*:

$$
T_{e^{ix}}=T_{\cos x} + i~T_{\sin x}\:\:\Rightarrow\:\:
\boxed{\:e^{ix}=\cos x + i\sin x\:}\:.
$$