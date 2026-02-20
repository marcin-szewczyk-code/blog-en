---
title: "Jekyll Blog: Modifying CSS in Chirpy theme – pinned posts example"
description: "How to add a custom custom.css file in the Chirpy theme and highlight pinned posts without modifying theme files."
date: 2026-02-23 07:00:00 +0100
categories: [Jekyll Blog]
tags: [jekyll, chirpy, css, config]
---

The appearance of the blog can be modified by adding a custom CSS file
(e.g. `assets/css/custom.css`) and loading it in `_includes/head.html`
after the theme CSS in order to override its styles.

The key step is determining which selector needs to be modified.

In the case of pinned posts, the Chirpy theme does not always assign a
`.pinned` class to them. In my configuration, a pinned post is marked
with a Font Awesome thumbtack icon:

``` html
<i class="fas fa-thumbtack fa-fw"></i>
```

**How to find the correct selector.** The simplest approach is to use
the browser developer tools: right-click the thumbtack icon next to a
pinned post and select "Inspect". Then, in the *Elements* panel, check
the icon class (e.g. `.fa-thumbtack`) and the parent element
(e.g. `a.post-preview`).

Next, create and link your own CSS file.

---

## Step 1: modify _includes/head.html

In the file:

``` text
_includes/head.html
```

locate the section:

``` html
<!-- Theme style -->
<link rel="stylesheet" href="{{ '/assets/css/:THEME.css' | replace: ':THEME', site.theme | relative_url }}">
```

Directly below it, add:

``` html
<!-- Custom overrides -->
<link rel="stylesheet" href="{{ '/assets/css/custom.css' | relative_url }}">
```

Important: the file must be loaded **after** the theme CSS so that the
overrides take effect.

---

## What if you do not have _includes/head.html?

If you are using the gem-based version of Chirpy, the `_includes` files
come from the theme and are not visible in your repository.

Jekyll overrides theme files with local files of the same path in your
project.

In that case:

1.  Open the theme repository (GitHub: `chirpy-starter` or
    `jekyll-theme-chirpy`).
2.  Copy the `_includes/head.html` file from the theme.
3.  Paste it into your project under:

``` html
_includes/head.html
```

Jekyll will automatically override the theme version with your local
copy.

## Step 2: file assets/css/custom.css

Create your own CSS file:

``` text
assets/css/custom.css
```

Content:

``` css
/* =========================================
   Custom CSS overrides for Chirpy
   ========================================= */

/* Pinned post — detect the card containing the thumbtack icon */
a.post-preview:has(i.fa-thumbtack) {
  border-left: 3px solid #2563eb;
  padding-left: 1rem;
}

/* Dark mode */
[data-mode="dark"] a.post-preview:has(i.fa-thumbtack) {
  border-left-color: #9ca3af;
}
```

The `:has()` selector allows styling the post card based on the fact
that it **contains** the `.fa-thumbtack` icon.

---

## Cache note

Browsers often cache previous versions of CSS files. After deployment,
perform a hard refresh (Ctrl + Shift + R).

In rare cases, you may need to additionally disable cache in DevTools (it is
automatically re-enabled after closing DevTools):

-   DevTools (F12) → Network → Disable cache\
-   Ctrl + Shift + R

---

## Summary

The cleanest architecture for modifying styles in Chirpy:

1.  Add your own file `assets/css/custom.css`
2.  Load it in `_includes/head.html` **after** the theme CSS

These are pure overrides -- without modifying the theme structure.

This solution is minimal, stable, and resistant to future theme updates.
