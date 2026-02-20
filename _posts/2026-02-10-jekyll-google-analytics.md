---
title: "Jekyll Blog: Google Analytics (GA4) and Footer Modification"
description: "Connecting Google Analytics 4 (GA4) in a Jekyll blog with the Chirpy theme: \\_config.yml configuration, privacy page, and extending the blog footer."
date: 2026-02-10 07:00:00 +0100
categories: [Blog Jekyll]
tags: [blog, jekyll, google-analytics, rss, setup]
---

As a final step, it is worth connecting **Google Analytics (GA4)** to
check whether anyone other than the author reads the blog.

In Jekyll with the Chirpy theme, this is done in three steps:
1. configure **Google Analytics (GA4)**
2. connect **GA4** with **Jekyll** via `_config.yml`
3. extend the footer (`_includes/footer.html`, link to privacy policy)

## GA4 Configuration in the Google Panel

Steps in the Google panel:
- go to [https://analytics.google.com/](https://analytics.google.com/) and log in with a Google account
- create a new Property, e.g. `en.blog.marcinszewczyk.net`, time zone *Poland*, currency *PLN*
- choose platform *Web*, site URL: `https://en.blog.marcinszewczyk.net`
- name the data stream, e.g. *Blog EN*
- copy the **Measurement ID**, format: `G-XXXXXXXXXX`

The **G-XXXXXXXXXX** identifier is the only information required by the Chirpy theme.

## GA4 Configuration in Jekyll + Chirpy

### Editing _config.yml

In `_config.yml`, add:

``` yml
# Web Analytics Settings
analytics:
  google: 
    id: "G-XXXXXXXXXX" # fill in your Google Analytics ID
```

After modifying `_config.yml`, rebuild locally
(`bundle exec jekyll serve`) or push changes to the repository (GitHub
Pages will trigger an automatic build). Then perform a hard refresh in
the browser (Ctrl+F5) to clear the browser cache.

That's it. The **Chirpy** theme generates the GA4 code automatically.

### Privacy Policy Page

After enabling Google Analytics, add a page describing data processing.

Create `_pages/privacy.md`, for example:

``` markdown
---
title: Privacy Policy
layout: page
permalink: /privacy/
---

The site uses Google Analytics (GA4) for statistical purposes
(page views and general usage information).

Data collected by Google Analytics is processed according to
Google’s policy: [https://policies.google.com/privacy](https://policies.google.com/privacy)

The site does not use data for profiling or marketing purposes.
```

Add the `pages` collection in `_config.yml` (below `tabs`):

``` yml
# tabs and pages collections (Chirpy)
collections:
  tabs:
    output: true
    sort_by: order
  pages:
    output: true
    permalink: /:path/
```

### Editing _data/locales/pl.yml and _data/locales/en.yml

Update the language files so the footer can display additional information.

In `_data/locales/pl.yml`, modify `meta`:

``` yml
meta: "Generator: :PLATFORM · Motyw: :THEME · Licencja: :COPYRIGHT · Analityka: :PRIVACY"
```

In `_data/locales/en.yml`, modify `meta`:

``` yml
meta: "Generator: :PLATFORM · Theme: :THEME · License: :COPYRIGHT · Analytics: :PRIVACY"
```

### Editing _includes/footer.html

Chirpy allows footer customization by copying `footer.html` from the theme into the local project.

The local version overrides the gem version.

First, check the local path of the Chirpy theme:

``` bash
bundle info jekyll-theme-chirpy
```

The path depends on the installed version.

Copy `_includes/footer.html` from the theme to the project:

``` bash
copy ^
"E:\Ruby34-x64\lib\ruby\gems\3.4.0\gems\jekyll-theme-chirpy-7.4.1\_includes\footer.html" ^
"_includes\footer.html"
```

In `_includes/footer.html`, comment out:

``` markdown
{{ site.data.locales[include.lang].meta
  | replace: ':PLATFORM', _platform
  | replace: ':THEME', _theme
}}
```

Replace it with:

``` markdown
{{ site.data.locales[include.lang].meta
  | replace: ':PLATFORM', _platform
  | replace: ':THEME', _theme
  | replace: ':COPYRIGHT', _license
  | replace: ':PRIVACY', _privacy
}}
```

Above this block, define `_privacy` and `_license`:

``` markdown
{%- capture _privacy -%}
  <a href="{{ '/privacy/' | relative_url }}">GA4</a>
{%- endcapture -%}

{%- capture _license -%}
  <a href="{{ '/legal/' | relative_url }}">Copyright</a>
{%- endcapture -%}
```

The result is a modified footer generated according to the current
language (Fig. 1 and Fig. 2).

![Blog footer in Polish](/assets/posts/jekyll-google-analytics/footer-pl.png)
***Fig. 1.** Blog footer in Polish.*

![Blog footer in English](/assets/posts/jekyll-google-analytics/footer-en.png)
***Fig. 2.** Blog footer in English.*

## Testing Data Collection

Finally, test in the Google Analytics panel (Reports → Realtime).

## Summary

At this stage, the blog:
- collects statistics (GA4)
- provides an RSS feed (configured earlier)
- remains fully static

It works.
