---
title: "LaTeX: VS Code instead of TeXstudio – step-by-step"
description: "Step-by-step LaTeX setup in VS Code: installing TeX Live, configuring LaTeX Workshop with latexmk, enabling PDF preview and SyncTeX, and organizing the build directory with Git."
date: 2026-02-21 07:00:00 +0100
categories: [LaTeX, Tools]
tags: [latex, vscode, texstudio, overleaf, workflow, setup]
---

In [TeXstudio](https://www.texstudio.org/), I wrote, typeset, and prepared the graphics for the book *[Analytical Methods in Calculations of Switching Processes in Power Systems](https://www.sklep.pw.edu.pl/produkty/metody-analityczne-w-obliczeniach-procesow-laczeniowych-w-systemie-elektroenergetycznym)*,
published by OWPW in 2024.

For this blog, I moved my workflow from TeXstudio to VS Code [VS Code](https://code.visualstudio.com/) to work in a single environment covering Markdown, HTML, CSS, Python, C++, Git, and LaTeX. Future books will likely be prepared here as well.

LaTeX document is a text file that describes structure and typesetting using commands and environments. It is compiled into output formats such as PDF.

There are several ways to create LaTeX documents:

- **Overleaf** is a cloud-based solution -- convenient for collaborative work and submitting articles directly to publishers, but dependent on a web browser.
- **TeXstudio** is a classic, dedicated IDE designed exclusively for working with LaTeX.
- **VS Code** is a powerful general-purpose editor, extensible via extensions. With proper configuration, it can serve as a full LaTeX environment and replace TeXstudio, while integrating with GitHub at the same time.

Below is a step-by-step configuration of LaTeX in VS Code.

---

## Installing LaTeX

VS Code is "only" an editor. Compilation requires a LaTeX distribution.

I use the full TeX Live distribution, available at: [https://www.tug.org/texlive/](https://www.tug.org/texlive/)

To verify the installation in the VS Code terminal (\`Ctrl + \`\`):

``` bash
pdflatex --version
latexmk --version
```

If the commands return version numbers, LaTeX is installed correctly (in my case: TeX Live 2025).

Where:
- **pdflatex** is the engine that compiles LaTeX documents directly to PDF
- **latexmk** is an automation tool that runs the required programs (e.g., pdflatex, biber) as many times as needed to generate the document

---

## Installing the LaTeX Workshop Extension

In VS Code:

1.  `Ctrl + Shift + X` or click the Extensions icon in the sidebar\
2.  Search for: **LaTeX Workshop** (James Yu)\
3.  Install

This extension provides:

-   LaTeX-to-PDF compilation\
-   built-in PDF viewer\
-   SyncTeX (synchronization between source code and PDF)\
-   bibliography support (BibTeX / biber)\
-   built-in LaTeX environment templates (snippets)\
-   command and environment auto-completion

---

## Setting a Build Shortcut

VS Code has its own project build mechanism ("Run Build Task"), independent of LaTeX Workshop.

The default build shortcut may trigger that mechanism instead of: `LaTeX Workshop: Build LaTeX project`.

To ensure compilation uses LaTeX Workshop, assign a shortcut directly to this command.

Set a custom shortcut:

1.  `Ctrl + K`, `Ctrl + S`\

2.  Search for:\
    `LaTeX Workshop: Build LaTeX project`\

3.  Assign, for example:

        Ctrl + Alt + B  

4.  Remove the shortcut assigned to:

        Run Build Task  

From now on, `Ctrl + Alt + B` triggers compilation via LaTeX Workshop.

---

## Setting latexmk as the Default Compilation Method

We now set `latexmk` as the default compilation method used by `LaTeX Workshop: Build LaTeX project`.

Open:

    Ctrl + Shift + P
    → Preferences: Open User Settings (JSON)

Add:

``` json
{
    "latex-workshop.latex.recipe.default": "latexmk",
    "latex-workshop.latex.autoBuild.run": "onSave"
}
```

If the `.json` file already contains other settings, add only these internal lines (preserving JSON commas).

### What does this provide?

-   uses `latexmk`\
-   automatically detects bibliography and multiple compilation passes\
-   compiles on save (`Ctrl+S`)

---

## PDF Preview in VS Code

In Settings set:

    latex-workshop.view.pdf.viewer → tab

The PDF opens as a tab in VS Code.

To reopen the PDF tab after closing it:\
**Ctrl + Shift + P**, then *LaTeX Workshop: View LaTeX PDF file*.

---

## Bidirectional Synchronization (SyncTeX)

### Code → PDF

Press `Ctrl + Shift + P` and type:

    LaTeX Workshop: SyncTeX from cursor

### PDF → Code

In the PDF preview:

    Ctrl + click

The editor jumps to the corresponding location in the source file.

---

## Separate build Directory

To avoid cluttering the project directory with auxiliary compilation
files, you can define a separate output directory.

### How to configure it

In `settings.json`\
(`Ctrl + Shift + P` → `Preferences: Open User Settings (JSON)`) add:

``` json
"latex-workshop.latex.outDir": "%DIR%/build"
```

This means:

-   `%DIR%` -- the directory containing the current `.tex` file\
-   `build` -- a subdirectory where auxiliary files will be stored

After compilation, files such as `.aux`, `.log`, `.fls`, `.synctex.gz` will be placed in `build/`.

---

### build Directory and Git

The `build/` directory contains intermediate files generated by `latexmk`:

-   `.aux`\
-   `.log`\
-   `.fls`\
-   `.fdb_latexmk`\
-   `.synctex.gz`

These are compilation artifacts, not source files.

For this reason, `build/` should not be versioned in Git.

Add to `.gitignore`:


```txt
    build/
```

The repository will then contain only:

-   `.tex` files\
-   bibliography files\
-   graphics\
-   optionally the final PDF (if intended for publication)

---

### PDF in the Root Directory

If the PDF file is to be versioned in the repository, you can compile
into `build/` and then copy the generated PDF from `build/` to the
project root.

Create a file named `latexmkrc` in the project directory (next to the `.tex` file) with the following content:

``` perl
$out_dir = 'build';
$pdf_mode = 1;
$success_cmd = 'cp build/%R.pdf %R.pdf';
```

On Windows (cmd / PowerShell), replace `cp` with `copy` and use Windows path separators:

``` perl
$out_dir = 'build';
$pdf_mode = 1;
$success_cmd = 'copy build\\%R.pdf %R.pdf';
```

After each successful compilation, the PDF will be copied from `build/` to the project root.

The repository will therefore contain the sources and a copy of the
final PDF, while `build/` remains a technical directory and is not
versioned in GitHub.

---

## Final Result

After configuration:

-   `Ctrl+S` → automatic compilation, `Ctrl+Alt+B` → manual build\
-   PDF in a VS Code tab\
-   `latexmk` automatically performs required compilation passes\
-   SyncTeX works in both directions

This setup allows working within a single VS Code environment for code, documentation, and Git repositories.

---

## Summary

The configuration comes down to:

1.  TeX Live -- installation from [https://www.tug.org/texlive/](https://www.tug.org/texlive/) (MiKTeX
    is also possible)\
2.  LaTeX Workshop -- installing the extension from the VS Code
    Marketplace\
3.  Configuring `latexmk` in `settings.json`

And that's it.