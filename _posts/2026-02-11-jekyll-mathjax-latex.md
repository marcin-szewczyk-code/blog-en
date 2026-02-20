---
title: "Jekyll Blog: MathJax for LaTeX Mathematical Formulas"
description: "How to enable MathJax in a Jekyll blog (Chirpy theme): adding the script to \\_includes/head.html and using LaTeX formulas inline and display in Markdown files."
date: 2026-02-11 07:00:00 +0100
categories: [Jekyll Blog]
tags: [blog, jekyll, latex, setup]
---

Jekyll has several advantages. One of them is the ability to include LaTeX formulas in Markdown files.

**MathJax** is probably the most popular solution, so I use it.

## MathJax Configuration

### Adding the MathJax Library

MathJax is a JavaScript library. It is enough to place its code inside the `<head></head>` block in the appropriate file:

``` html
<head>

<!-- other head elements -->

  <!-- MathJax v3 -->
  <script>
    window.MathJax = {
      tex: {
        inlineMath: [['$', '$'], ['\(', '\)']],
        displayMath: [['$$', '$$'], ['\[', '\]']],
        processEscapes: true
      },
      options: {
        skipHtmlTags: ['script', 'noscript', 'style', 'textarea', 'pre', 'code']
      }
    };
  </script>
  <script defer src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js"></script>
</head>
```

The remaining step is to find the correct file where this code should be inserted.

### Where to Insert the Code

I checked the `theme` field in `_config.yml`:

``` markdown
theme: jekyll-theme-chirpy
```

This means I am using the `jekyll-theme-chirpy` theme, which does not
have a local `_layouts` directory because layouts are provided by the
theme gem (library).

Chirpy allows overriding layout fragments through the `_includes` directory.

In the project directory, I create the file `_includes/head.html`:

``` bash
mkdir -p _includes
touch _includes/head.html
```

I copy the original `head.html` from Chirpy into my project. First, I
check where the gem is installed:

``` bash
bundle info jekyll-theme-chirpy
```

I get a path, for example:

``` bash
E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1
```

I substitute this path and copy the file:

``` bash
copy "E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1\_includes\head.html" "_includes\head.html"
```

Finally, I add the MathJax code to `_includes/head.html`, inside the
`<head></head>` section, for example just before `</head>`.

Now I can use LaTeX formulas.

## Using LaTeX in Markdown Files

### Inline Math

Formula in text: $e^{i x} = \cos{x} + i\sin{x}$.

Code:

``` markdown
$e^{i x} = \cos{x} + i\sin{x}$
```

### Display Math

Formula:

$$
\int_0^\infty e^{-x^2}\,dx = \frac{\sqrt{\pi}}{2}
$$

Code:

``` markdown
$$
\int_0^\infty e^{-x^2}\,dx = \frac{\sqrt{\pi}}{2}
$$
```

Formula:

$$
\left\{\begin{align}
a^2 + b^2 &= c^2 \\
e^{i\pi} + 1 &= 0
\end{align}\right.
$$

Code:

``` markdown
$$
\left\{\begin{align}
a^2 + b^2 &= c^2 \\
e^{i\pi} + 1 &= 0
\end{align}\right.
$$
```

## Summary

I add it → it works → done.
