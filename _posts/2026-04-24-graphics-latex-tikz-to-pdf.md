---
title: "Graphics: TikZ in LaTeX – workflow in a larger project (PDF instead of inline)"
description: "How to generate TikZ drawings as PDF files, crop them with pdfcrop, and use them in LaTeX documents instead of inline drawings."
date: 2026-04-24 07:00:00 +0100
categories: [Graphics, LaTeX-TikZ]
tags: [latex, tikz, workflow]
---

TikZ drawings are useful, but in larger LaTeX documents they can slow down compilation and cause package conflicts.

Instead of compiling TikZ drawings directly in the document, they can be compiled as separate PDF files and inserted as ready-made graphics, e.g. using the `\includegraphics` command from the `graphicx` package.

This approach is shown below.

---

## Standard approach – TikZ directly in the document

The standard approach is to place a TikZ drawing directly in the document:

```latex
\begin{circuitikz}
  % TikZ code
\end{circuitikz}
```

TikZ code can be long, so it is convenient to keep it in separate files and include it with `\input{example.tikz}`:

```latex
\begin{figure}[ht]
    \centering
    \input{example.tikz}
    \caption{Figure caption}
    \label{fig:1}
\end{figure}
```

The file `example.tikz` contains the drawing code:

```latex
\begin{circuitikz}
  % TikZ code
\end{circuitikz}
```

This works well, but has some drawbacks:

- long compilation time with many drawings,
- possible package conflicts,
- less convenient project organization (working with drawings inside the main document).

---

## Approach: TikZ → PDF

Instead of compiling TikZ drawings in the main document, a TikZ drawing can be compiled as a separate PDF file and cropped using `pdfcrop`.

### Source files

- [`tikz2pdf.tex`](/assets/posts/graphics-latex-tikz-to-pdf/tikz2pdf.tex) – file compiling the drawing to PDF  
- [`example.tikz`](/assets/posts/graphics-latex-tikz-to-pdf/figures/example.tikz) – drawing definition in TikZ  
- [`tikz2pdf-crop.cmd`](/assets/posts/graphics-latex-tikz-to-pdf/tikz2pdf-crop.cmd) – script for cropping PDF (`pdfcrop`)  
- [`tikz2pdf-usage.tex`](/assets/posts/graphics-latex-tikz-to-pdf/tikz2pdf-usage.tex) – example usage in a LaTeX document  
- [`pdf2png.cmd`](/assets/posts/graphics-latex-tikz-to-pdf/pdf2png.cmd) – script for creating PNG files (optional)  

### Output files

- [`tikz2pdf.pdf`](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf.pdf) – compilation result of `tikz2pdf.tex`  
- [`tikz2pdf-crop-1.pdf`](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf-crop-1.pdf) – cropped file, variant 1 (with grid and helper nodes)  
- [`tikz2pdf-crop-2.pdf`](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf-crop-2.pdf) – cropped file, variant 2 (with helper nodes)  
- [`tikz2pdf-crop-3.pdf`](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf-crop-3.pdf) – cropped file, variant 3 (final version)  

---

## Figures

The figures below show three variants of the same drawing generated from TikZ code.

Variant 1:

![Variant 1 – drawing with grid and helper nodes](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf-crop-1.png)
***Fig. 1.** Variant 1 – drawing with grid and helper nodes.*

Variant 2:

![Variant 2 – drawing with helper nodes](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf-crop-2.png)
***Fig. 2.** Variant 2 – drawing with helper nodes.*

Variant 3:

![Variant 3 – final drawing](/assets/posts/graphics-latex-tikz-to-pdf/output/tikz2pdf-crop-3.png)
***Fig. 3.** Variant 3 – final drawing.*

---

## Summary

Generating TikZ drawings as separate PDF files simplifies project organization, reduces compilation time, and lowers the risk of package conflicts.

In practice, this is a convenient approach when working with larger LaTeX documents.
