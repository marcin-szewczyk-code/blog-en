---
title: "Jekyll Blog: CSS Modification in the Chirpy Theme – Footer in Sidebar"
description: "How to add a custom footer to the sidebar in the Chirpy theme."
date: 2026-02-24 07:00:00 +0100
categories: [Jekyll Blog]
tags: [jekyll, chirpy, css, html, config]
---

I liked the element at the bottom of the sidebar in the [Flexible Jekyll](https://github.com/artemsheludko/flexible-jekyll) theme, so I implemented it. This required modifying `_includes/sidebar.html` and adding a few classes and CSS rules to assets/css/custom.css.

It required a modification of `_includes/sidebar.html` and adding a few custom classes and CSS rules to `assets/css/custom.css`.

![Sidebar footer](/assets/posts/jekyll-chirpy-sidebar-contact/sidebar-contact-en.png)
***Fig. 1.** Sidebar footer.*

The sidebar footer consists of three elements:

1.  A **CONTACT** title with decorative lines on both sides
2.  Existing social icons (without modifying the theme logic)
3.  A copyright notice below the icons

## Modifying _includes/sidebar.html

The title is inserted before the icons block, and the copyright is added inside `.sidebar-bottom` (below the icons loop).

``` html
  <!-- MPS: CONTACT title -->
  <div class="mps-sidebar-contact-title w-100">
    <span class="line"></span>
    <span class="text">CONTACT</span>
    <span class="line"></span>
  </div>

  <!-- MPS: Chirpy icons (unchanged, CONTACT copyright added) -->
  <!-- replace: 
      <div class="sidebar-bottom d-flex flex-wrap align-items-center w-100">
      with:
      <div class="sidebar-bottom mps-contact-bottom d-flex flex-wrap align-items-center w-100">
  -->
 <div class="sidebar-bottom mps-contact-bottom d-flex flex-wrap align-items-center w-100">

  {% for entry in site.data.contact %}
    <!-- original theme loop without changes -->
  {% endfor %}

    <!-- MPS: CONTACT copyright -->
    <div class="mps-sidebar-contact-copyright">
      © 2026 Marcin Szewczyk
    </div> 

</div>
```

## Adding CSS to `assets/css/custom.css`

The following is appended at the end of the file:

``` css
/* ==========================================================================
   MPS: Sidebar – CONTACT (title + icons + copyright)
   ========================================================================== */

/* Title */
#sidebar .mps-sidebar-contact-title {
  display: flex;
  align-items: center;
  justify-content: center;
  gap: 0.6rem;
  margin-bottom: 0.5rem;
  font-weight: 600;
  letter-spacing: 0.08em;
  text-transform: uppercase;
  font-size: 0.9rem;
  color: var(--sidebar-muted-color);
}

/* Title decorative lines */
#sidebar .mps-sidebar-contact-title .line {
  flex: 1;
  height: 2px;
  background: currentColor;
  opacity: 0.45;
  max-width: 60px;
}

/* Center this specific sidebar-bottom block */
#sidebar .mps-contact-bottom {
  justify-content: center !important;
  padding-left: 0 !important;
  padding-right: 0 !important;
}

/* Copyright in this block */
#sidebar .mps-contact-bottom .mps-sidebar-contact-copyright {
  flex: 0 0 100% !important;
  width: 100% !important;
  text-align: center !important;
  margin-top: 0.2rem;
  font-size: 0.9rem;
  opacity: 0.75;
  color: var(--sidebar-muted-color);
}
```

A simple naming convention is applied: all custom classes in `custom.css` start with `mps-`. This minimizes the risk of conflicts with future theme updates.

## Summary

Simple → works → looks good.
