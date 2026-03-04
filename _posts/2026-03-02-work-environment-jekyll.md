---
title: "Environment: Jekyll – Toolchain Configuration (VS Code, Git, SSH, Ruby)"
description: "Configuration of a local development environment for a Jekyll blog: Git, SSH, Ruby (DevKit) and local build workflow."
date: 2026-03-02 07:00:00 +0100
categories: [Environment]
tags: [jekyll, git, github, ssh, ruby]
---

This post documents the configuration of a development environment for a **Jekyll**-based blog hosted on GitHub Pages.

---

## 1. Visual Studio Code

Visual Studio Code (VS Code, VSC) is used as the primary editor.

It serves both as a source editor (Markdown, YAML, HTML, CSS) and as an integrated terminal.

Installation: [https://code.visualstudio.com/](https://code.visualstudio.com/)

---

## 2. Git

Git is a distributed version control system (SCM – Source Code Management).  
It enables change tracking, branching, and synchronization of repositories with GitHub.

Installation: [https://git-scm.com/](https://git-scm.com/)

During installation the following options were selected:

- ✔ **Use Visual Studio Code as Git's default editor**
- ✔ **Override the default branch name: main**
- ✔ **Git from the command line and also from 3rd-party software**
- ✔ **Use bundled OpenSSH**

Global identity configuration:

```bash
git config --global user.name "Your Name"
git config --global user.email "your_github_email@gmail.com"
```

Verification:

```bash
git config --global --list
```

Repository access is performed via SSH (alternatively HTTPS with a personal access token may be used).

---

## 3. SSH Configuration for GitHub

### Key Generation

A cryptographic key pair is generated to authenticate GitHub connections without using a password:

```bash
ssh-keygen -t ed25519 -C "your_github_email@gmail.com"
```

Displaying the public key:

```bash
type %USERPROFILE%\.ssh\id_ed25519.pub
```

where `%USERPROFILE%` denotes the current user's home directory, containing the `.ssh` folder with SSH keys.

### Adding the Key to GitHub

1. GitHub → Settings  
2. SSH and GPG keys  
3. New SSH key  
4. Title (e.g., `Lenovo-X250-2026`)  
5. Paste the key  
6. Add SSH key  

Connection test:

```bash
ssh -T git@github.com
```

Expected result:

```text
Hi your-username! You've successfully authenticated, but GitHub does not provide shell access.
```

---

## 4. Ruby (required by Jekyll)

Jekyll is a static site generator written in Ruby.  
Therefore, running the blog locally requires an installed Ruby interpreter and package manager.

By the way, Ruby was created with the idea of “programmer happiness” (Y. Matsumoto)[^1].

[^1]: Y. Matsumoto, *The Philosophy of Ruby*, Artima Developer, 2003.  
      https://www.artima.com/articles/the-philosophy-of-ruby

      “For me the purpose of life is partly to have joy. Programmers often feel joy when they can concentrate on the creative side of programming. So Ruby is designed to make programmers happy.”

Installation: [https://rubyinstaller.org/](https://rubyinstaller.org/)

Selected version: **Ruby+Devkit 3.3.x**

After installation:

```bash
ridk install
```

The `ridk install` command installs MSYS2 and the required toolchain (gcc, make), necessary to compile gems with native extensions.

Verification:

```bash
ruby -v
```

![Ruby installer for Windows](/assets/posts/work-environment-jekyll/ruby-installer.png)
***Rys. 1.** Ruby installer for Windows.*

---

## 5. Installing Project Dependencies

The installation is performed separately for each repository:

```bash
cd "C:/Git/repositories/blog-pl"
gem install bundler
bundle install

cd "../blog-en"
gem install bundler
bundle install
```

This installs:

- Bundler  
- all gems listed in the `Gemfile` 
- including Jekyll and the active theme (e.g., Chirpy)

In Ruby, packages (libraries) are distributed as gems.

---

## 6. Local Execution

For `blog-pl`:

```bash
bundle exec jekyll s
```

The default Jekyll port is 4000.

Preview: [http://127.0.0.1:4000/](http://127.0.0.1:4000/)

For `blog-en` (alternative port):

```bash
bundle exec jekyll s -P 4001
```

Preview: [http://127.0.0.1:4001/](http://127.0.0.1:4001/).

This launches local Jekyll development servers.

---

## Summary

Configuration result:

- VS Code installed  
- Git installed and connected to GitHub via SSH  
- Repositories synchronized  
- Ruby + DevKit compiling dependencies  
- Jekyll running locally on ports 4000 and 4001

Build → works → done. It's cool.