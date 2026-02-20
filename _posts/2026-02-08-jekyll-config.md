---
title: "Jekyll Blog: Blog Configuration in Jekyll – YAML, HTML and CSS"
description: "Configuring a Jekyll blog with the Chirpy theme: editing _config.yml, YAML settings, HTML/CSS modifications, avatar and favicons, and basic structure adjustments."
date: 2026-02-08 07:00:00 +0100
categories: [Jekyll Blog]
tags: [blog, jekyll, setup]
---

The next step in building the blog is configuring Jekyll and the Chirpy theme. The basic configuration is done by editing YAML files. Further customization can be achieved by modifying the theme’s HTML files and adding your own CSS styles.

## Basic Configuration: _config.yml

The main configuration file is `_config.yml`:

```yaml
tagline: Notes and records.        # blog subtitle (displayed in the header)
description: >-                    # blog description for SEO and Atom/RSS feed
    Notes on programming, mathematics, simulations, and building a blog in Jekyll.
baseurl: ""                        # subdirectory where the blog runs
url: "https://marcin-szewczyk-code.github.io" # main site address
avatar: /assets/img/avatar.jpeg    # path to author avatar
theme: jekyll-theme-chirpy         # Jekyll theme in use
lang: pl                           # blog language
timezone: "Europe/Warsaw"          # time zone (post dates)
github:
  username: marcin-szewczyk-code   # GitHub username
social:
  name: Marcin Szewczyk            # author name
  email:                           # email (optional, can be empty)
  github: marcin-szewczyk-code     # GitHub profile
  linkedin: marcin-szewczyk        # LinkedIn profile
  links:
    # the first link is treated as primary (copyright)
    - https://marcinszewczyk.net/                  # personal website
    - https://www.linkedin.com/in/marcin-szewczyk/ # LinkedIn
    - https://github.com/marcin-szewczyk-code      # GitHub
    - https://orcid.org/0000-0003-3699-5559        # ORCID
    - https://www.ee.pw.edu.pl/~szewczyk/          # academic page
```

After modifying `_config.yml`, stop the server (`Ctrl-C`) and start Jekyll again:

```bash
Ctrl-C
bundle exec jekyll serve
```

## Customizing the Theme via HTML and CSS

### Modifying HTML Files

The most relevant theme files are `_includes/*.html`.

Jekyll overrides theme files with local files of the same name and path within your project.

If you use the gem-based version of Chirpy, the `_includes/*.html` files come from the theme and are not visible in your repository.

You can override and modify them as follows:

1. Open the theme repository (`jekyll-theme-chirpy`).
2. Copy the file you want to modify, e.g. `_includes/head.html`, `_includes/footer.html`, `_includes/topbar.html`, `_includes/sidebar.html`.
3. Place it in your project under `_includes/`.
4. Make your changes, then restart Jekyll or commit and push to Git.

### How to Copy Theme Files

The `_includes/*.html` files can be copied directly from the installed gem directory.

First, check the path to the gem:

```bash
bundle show jekyll-theme-chirpy
```

Then copy selected files (example for Windows):

```bash
copy "E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1\_includes\head.html" "_includes\head.html"
copy "E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1\_includes\footer.html" "_includes\footer.html"
copy "E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1\_includes\topbar.html" "_includes\topbar.html"
copy "E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1\_includes\sidebar.html" "_includes\sidebar.html"
```

From this point on, the local versions override the gem versions and can be freely modified.

Below I describe my own examples, starting with modifying `_includes/head.html`, which allows overriding existing styles or introducing your own CSS.

### Modifying CSS Styles

The blog’s appearance can be customized by adding your own CSS file (e.g. `assets/css/custom.css`). It must then be loaded in `_includes/head.html` after the theme CSS so that it properly overrides the default styles.

In:

```text
_includes/head.html
```

find:

```html
<!-- Theme style -->
<link rel="stylesheet" href="{{ '/assets/css/:THEME.css' | replace: ':THEME', site.theme | relative_url }}">
```

Directly below it, add:

```html
<!-- Custom overrides -->
<link rel="stylesheet" href="{{ '/assets/css/custom.css' | relative_url }}">
```

Important: the custom stylesheet must be loaded **after** the theme CSS for overrides to work.

## My HTML and CSS Changes

In subsequent posts, I describe the changes applied in this blog:

1. In `head.html` I add:
   - The line `<link rel="stylesheet" href="{{ '/assets/css/custom.css' | relative_url }}">`, which loads `/assets/css/custom.css` with my styles (described when customizing the pinned post and sidebar).
   - JavaScript (`.js`) that enables the MathJax library for rendering mathematical formulas using LaTeX syntax.
2. In `_includes/footer.html`:
   - Footer edits with links to Google Analytics and license information -- described in the post about configuring Google Analytics.
3. In `_includes/topbar.html`:
   - Adding a link to the Subscribe RSS page -- described in the RSS configuration post.
4. In `_includes/sidebar.html`:
   - Adding a light/dark switch, PL | EN switch, and RSS -- described in a separate post.
   - Adding elements around the link icons at the bottom of the sidebar -- described in another post.

## CSS Changes – assets/css/custom.css

The most important changes I introduced in the Chirpy theme via `assets/css/custom.css`:

- Appearance of the pinned post -- described in a separate post.
- Appearance of elements around the link icons at the bottom of the sidebar -- described in a separate post.

## Other Changes

Editing the sidebar menu (`_includes/sidebar.html`) -- Categories, Tags, Archive, About -- is done via files in the `_tabs` directory. For example, removing `_tabs/tags.md` removes *Tags* from the sidebar. You can also add additional menu items there.

The avatar requires uploading the image to `/assets/img` and specifying its path in `_config.yml`. Recommended dimensions are, for example, 512×512 px.

The Polish language version uses the file `pl.yml` in `_data/locales` and the entry `lang: pl` in `_config.yml`.

## Graphics

### Avatar

The avatar is defined in `_config.yml`:

```yml
avatar: /assets/img/avatar_tatry_512.jpeg
```

The image file should be square, preferably `512x512` px, optimized for size (JPEG compression ~80–85%).

To crop and resize, you can use **ImageMagick** (MSYS2 / MinGW, described in a separate post):

**JPG image:**

```bash
magick input.jpg -gravity center -crop 1:1 -resize 512x512 -quality 82 output.jpg
```

**PNG image:**

```bash
magick input.png -gravity center -crop 1:1 -resize 512x512 output.png
```

The `-gravity center` option ensures central cropping before resizing.

### Favicons

Favicons can be generated, for example, using **RealFaviconGenerator**: https://realfavicongenerator.net/

After generation, upload the files to:

```bash
/assets/img/favicons
```

Example structure:

```text
assets/
└── img/
    └── favicons/
        ├── apple-touch-icon.png
        ├── favicon.ico
        ├── favicon.svg
        ├── favicon-32x32.png
        ├── web-app-manifest-192x192.png
        └── web-app-manifest-512x512.png
```

If the generator creates `favicon-96x96.png`, rename it to `favicon-32x32.png` to match the Chirpy theme requirements.

### Home Screen Shortcut

You can create a home screen icon on a smartphone (e.g., iPhone) that opens the blog in full-screen mode like an app (condition: the site must run over **HTTPS**).

In Safari:
- open `https://blog.marcinszewczyk.pl`
- tap the *Share* icon (square with arrow up)
- choose "Add to Home Screen"

The icon used is `/assets/img/favicons/apple-touch-icon.png` (recommended size 180x180 px). If the file does not exist, iOS generates an icon automatically (page snapshot).

## Summary

It may look complicated at first. You make a few small changes, and it works. Once configured, it simply feels right.