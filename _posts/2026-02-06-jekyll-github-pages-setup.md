---
title: "Jekyll Blog: How to Build a Jekyll Blog on GitHub Pages"
description: "How to build a Jekyll blog with the Chirpy theme on GitHub Pages: repository setup, basic \\_config.yml configuration, local Jekyll server, commit & push workflow, and automatic build in GitHub Actions."
date: 2026-02-06 07:00:00 +0100
categories: [Jekyll Blog]
tags: [blog, jekyll, setup]
---

I created a blog, so the question naturally arose: what should I write
so that the blog has at least one post? The obvious idea is to describe
how to build a blog. Below, I describe how this can be done.

## GitHub Repository and Local Directory

### Preliminary Notes

The blog is built with Jekyll, using the Chirpy theme (which can be
changed later), and published on GitHub Pages.

On GitHub Pages, you can publish either a *User Page* or a *Project
Page*:

-   *User Page* is a repository named `username.github.io` associated
    with the `username` account, available at
    `https://username.github.io/`
-   *Project Page* is any number of sites, each generated from a
    separate repository, e.g. `/repository-name/`, and published at
    `https://username.github.io/repository-name/`

Below I describe the *User Page* configuration -- this is how my blog
was originally built, before introducing the bilingual version.

The *User Page* configuration described here is correct, default, and
fully sufficient for a single-language site or blog.

In my case, it later changed to a *Project Page* configuration after
introducing two language versions of the blog (PL \| EN). Both versions
were then implemented as two separate *Project Pages* with identical
architecture -- I describe that in a separate post.

### GitHub Repository

What we need at the beginning and how it looked in my case (state at the
moment of creating the blog, before introducing the bilingual version):

-   **GitHub login**: `marcin-szewczyk-code`
-   **Repository name**: `marcin-szewczyk-code.github.io`
-   **Local directory**: `marcin-szewczyk-code.github.io`
-   **GitHub repo URL**:
    `https://github.com/marcin-szewczyk-code/marcin-szewczyk-code.github.io`
-   **Technical URL (GitHub Pages)**:
    `https://marcin-szewczyk-code.github.io/`
-   **Site URL (custom domain configured in DNS at the domain
    provider)**: `https://blog.marcinszewczyk.net/`
-   **Pages type**: User Page (GitHub Actions for the GitHub repository)

With a GitHub account, we create the repository
`marcin-szewczyk-code.github.io`, then upload the `Chirpy` starter
template to it.

How to do it:

-   On GitHub, create the repository `marcin-szewczyk-code.github.io`
-   Open the Chirpy Starter template repository:
    [https://github.com/cotes2020/chirpy-starter](https://github.com/cotes2020/chirpy-starter)
-   Click `Use this template` → `Create a new repository`
-   Set `Owner: marcin-szewczyk-code`,
    `Repository name: marcin-szewczyk-code.github.io`, `Public` →
    `Create repository`

Then go to the settings of `marcin-szewczyk-code.github.io` and set:
`Settings → Pages → Build and deployment: GitHub Actions`.

We now have the `marcin-szewczyk-code.github.io` repository on GitHub
containing the `chirpy-starter` content. The repository is here:
[https://github.com/marcin-szewczyk-code/marcin-szewczyk-code.github.io](https://github.com/marcin-szewczyk-code/marcin-szewczyk-code.github.io)

The live blog is here: [https://blog.marcinszewczyk.net/](https://blog.marcinszewczyk.net/) (technically
also at [https://marcin-szewczyk-code.github.io/](https://marcin-szewczyk-code.github.io/)).

The live blog is the result of what GitHub Pages builds and publishes
based on the repository content.

### Local Directory

Clone the repository into a local directory
`marcin-szewczyk-code.github.io` and continue working locally:

``` bash
git clone https://github.com/marcin-szewczyk-code/marcin-szewczyk-code.github.io.git marcin-szewczyk-code.github.io
cd marcin-szewczyk-code.github.io
```

The remaining steps are to configure Chirpy, create the first post, and push to GitHub.

## Basic Configuration and First Post

### Basic Jekyll--Chirpy Configuration

The basic configuration is stored in `_config.yml`.

At the beginning, set the essentials; the rest can be adjusted later:

-   `url: "https://blog.marcinszewczyk.net"` -- target blog address
    (custom domain in GitHub Pages for the `marcin-szewczyk-code`
    account + DNS configuration at the domain provider).
-   `baseurl: ""` -- the blog is in the root.
-   `timezone: "Europe/Warsaw"` -- obvious.
-   `lang: "pl"` -- so that Chirpy uses Polish where translations
    exist; the rest we handle manually.

### Creating the First Post

We base everything on Markdown, so a post is simply a `.md` file. I will
describe the Jekyll "Hello world" in a separate post. It is the same
Markdown as used in GitHub documentation and in Jupyter.

## Local Server and Push to Git

### Running the Local Server (local build & preview)

Jekyll is written in Ruby, just like GitHub. Therefore, it requires Ruby
and the necessary gems (libraries).

Install dependencies:

``` bash
bundle install
```

Run Jekyll:

``` bash
bundle exec jekyll serve
```

The blog is now available locally at: [http://127.0.0.1:4000/](http://127.0.0.1:4000/)

File changes are reflected immediately -- not all of them, but the key
ones (e.g., posts). Changing `_config.yml` requires restarting Jekyll.

### Push to Git (commit & push)

Finally, `commit` and `push` to GitHub:

``` bash
git status
git add .
git commit -m "Initial Chirpy blog setup"
git push
```

In one convenient line:

``` bash
git add . && git commit -m "Update local changes" && git push
```

I follow this commit message convention:

-   New post: "Add post: file-name-without-date-prefix"
-   Minor changes: "Update local changes"

### Additional Workflow Automation

Clear cache and restart Jekyll (Windows / PowerShell command):

``` bash
Ctrl-C
rmdir /s /q .jekyll-cache & rmdir /s /q _site & bundle exec jekyll serve
```

## Summary

Workflow: repo + local → config + post → local server + commit & push (GitHub) →
build & deploy (GitHub Pages), where committing and pushing to the repository triggers automatic build
& deploy in GitHub Pages.

I build → it works → it's good.
