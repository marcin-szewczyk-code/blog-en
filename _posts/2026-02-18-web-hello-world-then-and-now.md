---
title: "Web (1/N): Pięć modeli generowania HTML – Hello World dawniej i dziś"
post_id: web-hello-world-then-and-now
date: 2026-02-18 07:00:00 +0100
categories: [Web]
tags: [web, html, php, css, js, hello-world]
---

Uciąłem pogawędkę z Chatem o tym, jak wyglądało programowanie stron webowych 20+ lat temu i co się od tego czasu zmieniło. Wtedy używałem HTML, CSS, PHP i JavaScript i jestem ciekawy, jak to wygląda dziś.

Mówi się, że w IT zmienia się dużo, szybko i często. Zaskakująco dużo jednak zostaje. Niezależnie od narzędzi, strona internetowa wciąż jest HTML-em wysłanym do przeglądarki.

W tym wpisie pokazuję przykład „Hello World” w pięciu modelach generowania strony:

- statyczny HTML — najprostszy model
- renderowanie po stronie serwera: Server-Side Rendering (SSR) — podejście klasyczne
- SSR z separacją warstw — podejście aplikacyjne
- renderowanie w przeglądarce z wykorzystaniem API: Client-Side Rendering (CSR) + API
- generowanie strony w czasie budowania projektu: Static Site Generation (SSG)

Pierwsze z tych podejść — klasyczne SSR — stosowałem 20+ lat temu.

Ten blog działa w ostatnim modelu — statycznym SSG — i jest w dużym stopniu zautomatyzowany.

Do konfiguracji tego bloga potrzebne okazało się rozumienie tych samych podstaw, z których korzystałem 20+ lat temu.

Fundament jest więc wciąż ten sam.

## Statyczny HTML — najprostszy model

To najprostsza możliwa forma strony internetowej. Serwer nie wykonuje żadnego kodu. Przeglądarka pobiera gotowy plik HTML i wyświetla go.

Schemat: Browser → Serwer (plik HTML) → Browser.

Struktura:

```bash
index.html
```

Kod:

```html
<!DOCTYPE html>
<html>
<body>
<h1>Hello World</h1>
</body>
</html>
```

HTML jest zapisany w pliku i nie zmienia się przy kolejnych żądaniach. To najprostszy, ale wciąż używany model.

## Server-Side Rendering (SSR) – podejście klasyczne

Tak to robiłem 20+ lat temu.

Przeglądarka wysyła żądanie do serwera. Serwer uruchamia kod (np. PHP), generuje HTML i odsyła gotową stronę do przeglądarki.

Schemat: Browser → Serwer (PHP) → HTML → Browser.

Struktura:

```bash
index.php
```

Kod:

```php
<?php
$message = "Hello World";
?>
<!DOCTYPE html>
<html>
<body>
<h1><?php echo $message; ?></h1>
</body>
</html>
```
Logika i generowanie HTML są tu w jednym miejscu. Kod wykonuje się na serwerze przy każdym żądaniu.

To proste i działa. W małych projektach wciąż jest wystarczające.

## SSR z separacją warstw – podejście aplikacyjne

HTML nadal renderowany jest po stronie serwera, ale z wyraźnym podziałem odpowiedzialności.

Logika aplikacji nie miesza się bezpośrednio z widokiem. Pojawia się podział na warstwy: model, kontroler, widok.

Schemat: Browser → Controller → Model → View → HTML → Browser.

Struktura:

```bash
index.php
views/home.php
```

Kod:

Controller (logika, PHP):

```php
<?php

function render($view, $data = [])
{
    extract($data);
    require "views/$view.php";
}

render("home", ["message" => "Hello World"]);
```

Widok (view.php):

```php
<!DOCTYPE html>
<html>
<body>
<h1><?php echo htmlspecialchars($message); ?></h1>
</body>
</html>
```

HTML nadal powstaje na serwerze, ale kod jest uporządkowany. To podejście dobrze skaluje się w większych projektach.

## Client-Side Rendering (CSR) + API

Tu zmienia się miejsce generowania HTML. W tym modelu serwer przestaje generować HTML. Zamiast tego serwer dostarcza dane (backend), zwykle w formacie JSON. HTML budowany jest po stronie klienta, czyli w przeglądarce przez JavaScript (frontend).

Schemat: Browser → API → JSON → JavaScript → HTML (DOM).

Proces:
- Ładuje się statyczny HTML.
- JavaScript wysyła żądanie do API.
- Serwer (backend) zwraca dane (np. JSON).
- JavaScript aktualizuje widok (frontend).

Struktura:

```bash
api.php
index.html
```

Kod:

Backend (PHP) – prosty endpoint API zwracający dane w formacie JSON:

```bash
api.php
```

```php
<?php
header("Content-Type: application/json");
echo json_encode(["message" => "Hello World"]);
```

Frontend (JavaScript):

```bash
index.html
```

```html
<!DOCTYPE html>
<html>
<body>

<h1 id="app">Loading...</h1>

<script>
fetch("api.php")
  .then(response => response.json())
  .then(data => {
    document.getElementById("app").innerText = data.message;
  });
</script>

</body>
</html>
```

## Static Site Generation (SSG)

Ten blog działa w tym modelu.

Tu dochodzi trzeci moment generowania HTML – build & deploy.

W tym modelu HTML generowany jest w czasie budowania projektu, a nie przy każdym żądaniu użytkownika.

Podczas budowania projektu generator (w tym blogu GitHub Pages) tworzy z niego statyczny plik HTML. Serwer nie wykonuje już żadnej logiki – jedynie wysyła gotowy plik na żądanie przeglądarki, która go wyświetla.

Schemat: Build & deploy → HTML → Serwer (statyczny) → Browser.

Proces:
- Uruchamiany jest proces build.
- Powstaje plik HTML.
- Serwer jedynie go serwuje.

Plik Markdown:

```markdown
# Hello World
```

Kod (efekt końcowy wygenerowany statycznie na etapie budowania projektu):

```html
<!DOCTYPE html>
<html>
<body>
<h1>Hello World</h1>
</body>
</html>
```

To model, w którym działa ten blog.

## Porównanie modeli

| Model              | Kiedy powstaje HTML?        | Czy backend generuje HTML przy żądaniu |
|--------------------|-----------------------------|-----------------------------------------|
| Statyczny HTML     | przed wdrożeniem            | nie                                     |
| SSR klasyczne      | przy każdym żądaniu         | tak                                     |
| SSR warstwowe      | przy każdym żądaniu         | tak                                     |
| CSR + API          | po stronie przeglądarki     | nie                                     |
| SSG                | podczas budowania projektu  | nie                                     |

Różnica między modelami polega na tym, kiedy i gdzie jest generowany plik HTML.

## Podsumowanie

Strona internetowa jest HTML-em wysłanym do przeglądarki.

Różne modele odpowiadają na różne potrzeby:
- statyczny HTML jest najprostszy z możliwych
- klasyczne SSR jest proste i wciąż działa,
- podejście aplikacyjne porządkuje większe projekty,
- CSR oddziela dane od interfejsu,
- SSG upraszcza infrastrukturę i przyspiesza działanie.

Ten blog działa w modelu SSG. Automatyzacja jest duża, ale fundament pozostaje ten sam – HTML, CSS i JavaScript nadal mają znaczenie. Różni się sposób generowania HTML. Zmieniły się niuanse tych języków w stosunku do 20+ lat temu, ale ich idea pozostała ta sama.

Ciekawe jest też to, że w tym blogu technologia zatoczyła koło — od statycznego HTML do zautomatyzowanego modelu SSG opartego na Jekyllu i GitHubie.
