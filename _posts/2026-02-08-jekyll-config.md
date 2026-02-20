---
title: "Jekyll Blog: Blog Configuration in Jekyll – YAML, HTML and CSS"
description: "Configuring a Jekyll blog with the Chirpy theme: editing \\_config.yml, YAML settings, avatar and favicons, HTML/CSS modifications, and basic structure adjustments."
date: 2026-02-08 07:00:00 +0100
categories: [Blog Jekyll]
tags: [blog, jekyll, setup]
---

The next step in building the blog is configuring Jekyll settings. In Jekyll, most configuration is done by editing YAML files, and in some cases also HTML and CSS.

## Basic Jekyll Configuration (\_config.yml)

The main configuration file is `_config.yml`:

``` yaml
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
  email:                           # email (optional)
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

Changing `_config.yml` requires stopping (`Ctrl-C`) and restarting the Jekyll server:

``` bash
Ctrl-C
bundle exec jekyll serve
```

## Graphics

### Avatar

The avatar is defined in `_config.yml`:

``` yml
avatar: /assets/img/avatar_tatry_512.jpeg
```

The image should be square, preferably `512x512` px, optimized for size (JPEG compression \~80--85%).

To crop and resize, you can use **ImageMagick** (MSYS2 / MinGW, described in a separate post):

**JPG image:**

``` bash
magick input.jpg -gravity center -crop 1:1 -resize 512x512 -quality 82 output.jpg
```

**PNG image:**

``` bash
magick input.png -gravity center -crop 1:1 -resize 512x512 output.png
```

The `-gravity center` option ensures central cropping before resizing.

### Favicons

Favicons can be generated, for example, at: [https://realfavicongenerator.net/](https://realfavicongenerator.net/)

After generation, upload the files to:

``` bash
/assets/img/favicons
```

Example structure:

``` text
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

## Additional Configuration Elements

### Theme and Structure Adjustments

Editing the left-side menu (Categories, Tags, Archive, About) is done via files in the `_tabs` directory.
For example, removing `_tabs/tags.md` removes *Tags* from the menu. Additional menu items can also be added.

The avatar requires uploading the image to `/assets/img` and specifying its path in `_config.yml`. For example, an image sized 512x512.

The Polish language version uses the file `pl.yml` in `_data/locales` and the entry `lang: pl` in `_config.yml`.

You can also add the file `_includes/head.html` and place JavaScript code (`.js`) there. I described this when configuring LaTeX formulas using the MathJax library. Similarly, in another post I described the `_includes/footer.html` file.

### Home Screen Shortcut (Smartphone)

You can create a home screen icon on a smartphone (e.g., iPhone) that opens the blog in full-screen mode like an app.

Condition: the site must run over **HTTPS**.

In Safari:
- open `https://en.blog.marcinszewczyk.pl`
- tap the *Share* icon (square with arrow up)
- choose "Add to Home Screen"

The icon used is `/assets/img/favicons/apple-touch-icon.png` (recommended size 180x180 px). If the file does not exist, iOS generates an icon automatically (page snapshot).
