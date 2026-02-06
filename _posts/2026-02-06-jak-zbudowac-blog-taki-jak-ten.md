---
title: "Jak zbudować blog taki jak ten"
date: 2026-02-06 07:00:00 +0100
categories: [Blog]
tags: [blog, jekyll, setup]
---

Zrobiłem bloga, więc powstała kwestia, co napisać, żeby blog miał jakiś wpis.
Naturalny pomysł to opisać, jak zrobić bloga. Poniżej opisuję, jak to można zrobić.

## Jak to uruchomić

### Repo na GitHubie

Blog zbudowany jest na Jekyll, z motywem Chirpy (można potem zmienić), opublikowany na GitHub Pages.

Czego potrzebujemy na początek i jak to wygląda u mnie:
- **GitHub login**: ```marcin-szewczyk-code``` (konto na GitHubie)
- **Repo name**: ```blog``` (repo na GitHubie)
- **Local directory**: ```blog``` (folder na lokalnym komputerze)
- **GitHub repo URL**: [https://github.com/marcin-szewczyk-code/blog](https://github.com/marcin-szewczyk-code/blog)
- **Site URL**: [https://marcin-szewczyk-code.github.io/blog](https://marcin-szewczyk-code.github.io/blog)
- **Pages type**: project page (GitHub Actions dla repo na GitHubie)

Mając konto na GitHubie tworzymy tam repo ```blog```, potem wgrywamy do niego szablon startowy ```Chirpy```.

Jak to zrobić:
- na GitHubie tworzymy repo ```blog```
- otwieramy repo szablonu Chirpy Starter: [https://github.com/cotes2020/chirpy-starter](https://github.com/cotes2020/chirpy-starter)
- klikamy ```Use this template``` → ```Create a new repository```
- ustawiamy ```Owner: marcin-szewczyk-code```, ```Repository name: blog```, ```Public``` → Create repository```

Wchodzimy następnie w ustawienia repo ```blog``` i ustawiamy: ```Settings repo → Pages → Build and deployment: GitHub Actions```.

Mamy teraz repo ```blog``` na GitHubie, a w nim zawartość ```chirpy-starter```. Repo jest tutaj: [https://github.com/marcin-szewczyk-code/blog](https://github.com/marcin-szewczyk-code/blog), a gotowy blog jest tutaj: [https://marcin-szewczyk-code.github.io/blog](https://marcin-szewczyk-code.github.io/blog). Gotowy blog to wynik tego, co GitHub Pages buduje i publikuje na podstawie zawartości repo.

### Folder lokalny

Ściągamy (klonujemy) repo do lokalnego folderu ```blog``` i pracujemy dalej lokalnie w tym folderze:

```bash
git clone https://github.com/marcin-szewczyk-code/blog.git blog
cd blog
```

Pozostaje konfiguracja szablonu Chirpy, stworzenie pierwszego wpisu i wypchnięcie na Gita.

### Konfiguracja

Podstawowa konfiguracja zapisana jest w pliku ```_config.yml```.

Na początek ustawiamy podstawowe rzeczy, potem możemy zrobić resztę:
- ```url: "https://marcin-szewczyk-code.github.io"``` -- domena GitHub Pages dla konta ```marcin-szewczyk-code``` na GitHubie.
- ```baseurl: "/blog"``` -- szczegół, ale ważny.
- ```timezone: "Europe/Warsaw"``` -- wiadomo.
- ```lang: "pl"``` -- żeby Chirpy brał język interfejsu tam, gdzie ma tłumaczenia, resztę zrobimy ręcznie.

### Tworzenie pierwszego wpisu

Bazujemy na markdownie, więc wpis jest plikiem ```.md```. Hello world Jekylla zrobię w osobnym wpisie. Co ciekawe, jest to ten sam markdown co w dokumentacji na GitHubie i w Jupyterze.

### Uruchomienie serwera lokalnego

Jekyll jest napisany w Ruby, tak jak cały GitHub. Potrzebuje więc Ruby i gemów.

Instaluję zależności:

```bash
bundle install
```
Uruchamiam Jekylla:

```bash
bundle exec jekyll serve --baseurl ""
```
Blog działa teraz lokalnie pod adresem: [https://127.0.0.1:4000/blog](https://127.0.0.1:4000/blog).

Zmiany w plikach są widoczne na bieżąco (nie wszystkich, ale kluczowych).

Opcja ```--baseurl ""``` pozwala nie wpisywać ```/blog``` w URL.

### Wypchnięcie na Gita

Pozostaje ```commit``` i wypchnięcie ```push``` na GitHuba:

```bash
git status
git add .
git commit -m "Initial Chirpy blog setup"
git push
```

W jednej, wygodnej linii:

```bash
git add . && git commit -m "Update local changes" && git push
```

### Dodatkowe automatyzacje workflow

Czyszczenie cache i restart Jekylla:

```bash
Ctrl-C
rmdir /s /q .jekyll-cache & rmdir /s /q _site & bundle exec jekyll serve --baseurl ""
```

## Podsumowanie

Robię → działa → jest fajnie.


<!--
>```python
#print("Hello world")
#```
-->

<!--
EN:

I made a blog, so the question came up what to write so the blog has a post.
A natural idea is to describe how to make a blog.

This blog was created when I went to lunch with an IT guy and an automation engineer joined us. It was a nice conversation. I learned that there is something called Jekyll and that it is great. I set it up, added the Chairy theme and some automation in Python.

I bought a domain, created a repo on GitHub and published everything.
And that’s how it was created. The blog is built from markdown, pushed to git from VS Code. It is static and that is great. I make a commit and push and it works great. I will be able to change the theme if I like another one, because all the content is written in markdown. I wonder if I will post here in my free time. Below I describe how to run it.
-->