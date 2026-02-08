---
title: "Blog Jekyll (2/4): Jak robić wpisy na blogu: Markdown „Hello World” w Jekyllu"
date: 2026-02-07 07:00:00 +0100
categories: [Blog]
tags: [blog, jekyll, hello-world]
---

W ```Jekyllu``` jest parę fajnych rzeczy, a pierwsza to, że blog jest statyczny i budowany z wpisów robionych w języku ```Markdown```. Pokażę tutaj przykład wpisu ```hello-world```, czyli kilka elementów, których najbardziej używam.

Treść bloga budowana jest przez Jekylla jako strona statyczna wystawiana przez GitHuba. To, co edytuję, to zwykłe pliki tekstowe w ```markdownie```, z prostą składnią. Poniżej pokazuję podstawowe elementy, których używam: nagłówki, listy, kody i linki. Tyle wystarczy, żeby napisać i opublikować wpis. Do tego dochodzą metadane z tytułem, datą, kategorią i tagami.

Jekyll dba o to, żeby wpisy pojawiały się dopiero wtedy, gdy nadejdzie ich data. Dzięki temu można łatwo planować publikację wpisów z zaplanowanym rytmem.

Wpisy zapisuję w lokalnym folderze ```_posts```, w plikach o super wygodnym formacie nazwy, czyli data ```yyyy-mm-dd```, potem nazwa i rozszerzenie ```.md```. Na przykład: ```2026-02-06-wpis-hello-world.md```.

Gdy dokładam w lokalnym folderze ```_posts``` kolejne pliki ```.md```, to są one widoczne od razu lokalnie na ```127.0.0.1:4000```, a na blogu po zrobieniu ```commit``` i ```push```.

Czyli robię plik ```.md```, zapisuję go lokalnie w ```_posts```, robię ```commit``` i ```push``` -- i wpis jest gotowy, a widoczny staje się zgodnie z datą.

## Hello-world wpisu bloga w markdownie

### Metadane (front matter / head)

Na początku jest front matter (nagłówek), który zawiera metadane rozpoznawane przez ```Jekylla```.

```yaml
---                                      # Początek front matter
title: "Hello-world markdown for Jekyll" # Wyświetlany jako nagłówek strony
date: 2026-02-06 08:00:00 +0100  # Data i godzina publikacji wpisu; Jekyll używa jej do sortowania i publikacji
categories: [Blog]               # Kategoria wpisu (lub lista kategorii)
tags: [blog, jekyll]             # Lista tagów do oznaczania tematów wpisu i późniejszego filtrowania
---                              # koniec front matter
```

### Treść wpisu (content / body)

#### Tekst wpisu (akapity)

Tekst wpisu to zwykły tekst, np. "Zrobiłem bloga, więc powstała kwestia, co napisać, żeby blog miał jakiś wpis" .

#### Nagłówki

Są używane do spisu treści, kotwic i SEO (*Search Engine Optimization*):

```markdown
# Nagłówek poziomu 1
## Nnagłówek poziomu 2
### Nagłówek poziomu 3
```

#### Listy

Lista punktowana:
- element listy
- **tekst** - pogrubienie
- `tekst` -- kod inline

```markdown
- element listy
- **tekst** - pogrubienie
- `tekst` -- kod inline
```

Lista numerowana:
1. element listy
2. **tekst** - pogrubienie
3. `tekst` -- kod inline


```markdown
1. element listy
2. **tekst** - pogrubienie
3. `tekst` -- kod inline
```

#### Formatowanie tekstu

**Pogrubienie**, *pochylenie (kursywa)*, ***pogrubienie i pochylenie***:

````markdown
**Pogrubienie**, *pochylenie (kursywa)*, ***pogrubienie i pochylenie***
````

#### Linki

Tak robi się [taki link](https://github.com/marcin-szewczyk-code/blog):

```markdown
[taki link](https://github.com/marcin-szewczyk-code/blog)
```

#### Bloki kodu

Kod ```bash```:

````markdown
```bash
git clone https://github.com/...
```
````

Wynik:

```bash
git clone https://github.com/...
```

Kod ```markdown```:

````markdown
```markdown
title: "Hello-world markdown for Jekyll"
...
```
````

Wynik:

```markdown
title: "Hello-world markdown for Jekyll"
...
```

Kod ```python```:

````markdown
```python
print("Hello, world!")
...
```
````

Wynik:

```python
print("Hello, world!")
...
```
