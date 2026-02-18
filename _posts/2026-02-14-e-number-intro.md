---
title: "The Number “e”: Where It Comes From and Why It Matters"
date: 2026-02-14 07:00:00 +0100
categories: [Mathematics]
tags: [math, e]
---

Let’s raise the bar a bit. We’ll take a break from installations and configuration and dive into some interesting, elementary mathematics.

> **Source** This post is an adapted chapter from my book: M. Szewczyk, *[Analytical Methods in the Calculation of Switching Processes in Power Systems](https://www.sklep.pw.edu.pl/produkty/metody-analityczne-w-obliczeniach-procesow-laczeniowych-w-systemie-elektroenergetycznym)*, OWPW 2024.

## The Exponential Function $a^x$ and the Special Case $e^x$

The function $e^x$ is regarded as one of the most important functions in mathematical analysis. A natural place to introduce it is when computing the derivative of the function $a^x$, and then examining that derivative for a particular base. That special base is denoted by $a = e$. In this case we obtain the exponential function $e^x$, which is also commonly written as $e^x = \exp(x)$.

Let us introduce simple terminology: in the function $a^x$, the number $a$ is called the *base*, and $x$ is called the *exponent*.

Below I present an intuitive argument based directly on the definition of the derivative and on a simple numerical estimate. In a standard course on mathematical analysis, the number $e$ is introduced earlier - typically in the study of limits of sequences and infinite series. Still, this numerical intuition is interesting enough to follow.

We begin with the definition of the derivative of a function $f(x)$ as a limit:

$$
\frac{\mathrm{d}f(x)}{\mathrm{d}x}
=\lim_{\Delta x\to 0}{\frac{f(x+\Delta x)-f(x)}{\Delta x}}.
$$

## Derivative of the Exponential Function $a^x$

Using the definition above, we compute the derivative of $a^x$ directly:

$$		
\frac{\mathrm{d}a^x}{\mathrm{d}x}
=\lim_{\Delta x\to 0}{\frac{a^{x+\Delta x} - a^x}{\Delta x}}
=\lim_{\Delta x\to 0}{a^x\frac{a^{\Delta x} - 1}{\Delta x}}
=a^x\lim_{\Delta x\to 0}{\frac{a^{\Delta x} - 1}{\Delta x}}.
$$

We immediately notice that the limit appearing in the formula above (the rightmost term) does not depend on the variable $x$ - it depends only on the base $a$. This observation is essential, so we rewrite the expression as:

$$
\frac{\mathrm{d}a^x}{\mathrm{d}x}
=C_a a^x,\:\:\:\text{gdzie:}\:\:C_a=\lim_{\Delta x\to 0}{\frac{a^{\Delta x} - 1}{\Delta x}}.
$$
		
Thus, the derivative of the exponential function $a^x$ is equal to the same function multiplied by a constant $C_a$. This constant does not depend on $x$, but it does depend on $a$. It is precisely the limit defined above.

## A Numerical Estimate of the Constant $C_a$

A rigorous computation of the limit $C_a$ requires a deeper look into the structure of mathematical analysis - in particular, into the language of sequences and the formal definition of the number $e$. Instead, let us perform a simple *numerical* estimate. The intuition that emerges from it is interesting enough to justify this approach.

<!--

\footnote{\label{footnote:granica_axex}~Granicę \eqref{eq:pochodna_axex_2} można łatwo obliczyć, \textit{znając} pochodną funkcji $e^x$, posługując się wówczas rozwinięciem funkcji $e^x$ w~szereg Taylora\index{Taylor} \eqref{eq:zbieznosc_taylora_12} lub, jeszcze prościej, regułą \textit{de l'Hospitala\index{de l'Hospital}} \eqref{eq:delhospital_final}. Obie te metody wymagają jednak posługiwania się pochodną funkcji $e^x$, np. wg reguły de l'Hospitala\index{de l'Hospital}: $\lim_{\Delta x\to 0}{\tfrac{e^{\Delta x} - 1}{\Delta x}}=\lim_{\Delta x\to 0}{\tfrac{(e^{\Delta x} - 1)'_{\Delta x}}{(\Delta x)'_{\Delta x}}}=\lim_{\Delta x\to 0}{\tfrac{e^{\Delta x}}{1}}=1$.}.

-->


***Tab. 1.** Values of the constant $C_a$ computed for $a=2$, $a=3$, and for an intermediate value $2<a=e<3$, for selected $\Delta x$.*

| $\Delta x$ | $C_{a=2}$ | $C_{a=e\approx 2.71828\ldots}$ | $C_{a=3}$ |
|:--:|--:|--:|--:|
| $10^{-1}$ | 0.7177346 | 1.0517092 | 1.1612317 |
| $10^{-2}$ | 0.6955550 | 1.0050167 | 1.1046691 |
| $10^{-3}$ | 0.6933874 | 1.0005002 | 1.0992159 |
| $10^{-4}$ | 0.6931712 | 1.0000500 | 1.0986726 |
| $10^{-5}$ | 0.6931495 | 1.0000050 | 1.0986183 |
| $10^{-6}$ | 0.693147(4) $< 1$ | 1.000000(5) $\approx 1$ | 1.098612(8) $> 1$ |

Since the limit $C_a$ is a function of the base $a$, in Table 1 we examine its values for $a=2$ and $a=3$, as well as for an intermediate value $2<a<3$. For each base, the limit is approximated numerically using progressively smaller values of $\Delta x = 10^{-1}, 10^{-2}, \ldots, 10^{-6}$. For the smallest step $\Delta x = 10^{-6}$, the computed values differ from the exact limit (as $\Delta x \to 0$) only in the last decimal place - marked in parentheses in the table.

We observe that for $\Delta x = 10^{-6}$:
- for $a=2$, we obtain $C_{a=2} < 1$,
- for $a=3$, we obtain $C_{a=3} > 1$.

Since $C_a$ depends continuously on $a$ (see the formula above), there must exist a value of $a$ between $2$ and $3$ for which the function $C_a$ takes the value $1$.


The value of the base $a$ for which the constant $C_a$ in the derivative formula $(a^x)' = C_a a^x$ equals $1$ is *called* the number $e$.

This number is irrational (that is, it cannot be expressed as a ratio of two integers), and its approximate value is $e\approx 2.7182818284590452\dots$:

$$
C_{a=e}=\lim_{\Delta x\to 0}{\frac{e^{\Delta x} - 1}{\Delta x}}=1.
$$

## Final Result

It follows directly that for $a = e$ we have

$$
\frac{\mathrm{d}e^x}{\mathrm{d}x}=e^x.
$$

In other words, the derivative of $e^x$ is equal to the function itself.

This fact has many far-reaching consequences.