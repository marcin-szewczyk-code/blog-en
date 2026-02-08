---
title: "Blog Jekyll (3/4): Konfiguracja bloga w Jekyllu: pliki YAML, HTML i CSS"
date: 2026-02-08 07:00:00 +0100
categories: [Blog]
tags: [blog, jekyll, setup]
---

Ostatni krok budowy bloga to konfiguracja ustawień.

## Podstawowa konfiguracja

Podstawowa konfiguracja znajduje się w pliku ```_config.yml```:

```markdown
tagline: Notatki i zapiski.       # podtytuł bloga (wyświetlany w nagłówku)
description: >-                   # opis bloga dla SEO i kanału Atom/RSS
    Notatki o programowaniu, matematyce i budowie bloga w Jekyllu.
baseurl: "/blog"                  # podkatalog, w którym działa blog
url: "https://marcin-szewczyk-code.github.io" # główny adres strony
avatar: /assets/img/avatar.jpeg   # ścieżka do avatara autora
theme: jekyll-theme-chirpy        # używany motyw Jekylla
lang: pl                          # język bloga
timezone: "Europe/Warsaw"         # strefa czasowa (daty wpisów)
github:
  username: marcin-szewczyk-code  # nazwa użytkownika GitHub
social:
  name: Marcin Szewczyk           # imię i nazwisko autora
  email:                          # email (opcjonalny, może być pusty)
  github: marcin-szewczyk-code    # profil GitHub
  linkedin: marcin-szewczyk       # profil LinkedIn
  links:
    # pierwszy link traktowany jest jako główny (copyright)
    - https://marcinszewczyk.net/                  # strona osobista
    - https://www.linkedin.com/in/marcin-szewczyk/ # LinkedIn
    - https://github.com/marcin-szewczyk-code      # GitHub
    - https://orcid.org/0000-0003-3699-5559        # ORCID
    - https://www.ee.pw.edu.pl/~szewczyk/          # strona akademicka
```

Zmiana pliku ```_config.yml``` wymaga zatrzymania (```Ctrl-C```) i restartu serwera Jekylla:
 
```bash
Ctrl-C
bundle exec jekyll serve
```

## Potrzebne drobiazgi

Edycja menu po lewej stronie (Kategorie, Tagi, Archiwum, O mnie) robiona jest poprzez pliki w katalogu ```_tabs```. Na przykład usunięcie pliku ```_tabs/tags.md``` powoduje usunięcie *Tags* z lewego menu.

Awatar to wgranie zdjęcia do katalogu ```/assets/img```, a następnie zlinkowanie go w ```_config.yml```. Zdjęcie o wymiarach na przykład 512x512.

Polska wersja jęykowa to plik ```pl.yml``` w katalogu ```_data/locales``` i wpis w ```_config.yml```.

Ciekawy jest sposób dodania pliku ```_includes/head.html``` i umieszczenia w nim skryptu ```.js```. Opisałem to przy okazji pokazywania konfiguracji wzorów matematycznych LaTeX w MathJax.