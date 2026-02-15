---
title: "Web (1/N): Five Ways to Generate HTML - Hello World Then and Now"
date: 2026-02-18 07:00:00 +0100
categories: [Web]
tags: [web, html, php, css, js, hello-world]
---

I recently had a chat with ChatGPT about what web development looked like 25+ years ago and what has changed since then. Back then, I used HTML, CSS, PHP, JavaScript, and also C++ programs executed on the server via CGI. I was curious what it looks like today.

People often say that in IT everything changes - a lot, quickly, and frequently. Surprisingly, quite a lot stays the same, in a way. Regardless of tools, architectures, libraries, frameworks, or hosting platforms, a website is still HTML sent to a browser.

In this post, I show a simple “Hello World” example in five different page-generation models:

1. Static HTML - the simplest model  
2. Server-Side Rendering (SSR) with PHP - the classic approach  
3. Layered SSR - an application-oriented approach  
4. Client-Side Rendering (CSR) with an API  
5. Static Site Generation (SSG)

The first two approaches - static HTML and classic SSR - are what I used 25+ years ago.

This blog runs in the last model - static SSG - and is largely automated.

Setting it up required understanding the same fundamentals I was using 25+ years ago.

And yet, the foundation remains the same.

## Model 1: Static HTML - the Simplest Model

This is how I did it 25+ years ago.

It is the simplest possible form of a website. The server executes no code - it simply serves a static HTML file. The browser downloads the ready-made HTML file and renders it.

**Flow:** Browser → Server (HTML file) → Browser.

Structure:

```bash
index.html
```

Code:

```html
<!DOCTYPE html>
<html>
<body>
<h1>Hello World</h1>
</body>
</html>
```

The HTML is stored in a file and does not change between requests. It is the simplest model - and still widely used.

## Model 2: Server-Side Rendering (SSR) - Classic Approach

This is how I did it 20+ years ago.

The browser sends a request to the server. The server executes code (e.g., PHP - or historically CGI programs, for example in C++), generates HTML, and sends the fully rendered page back to the browser.

**Flow**: Browser → Server (PHP) → HTML → Browser.

Structure:

```bash
index.php
```

Code:

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

Logic and HTML generation are combined in one place. The code runs on the server for every request.

It is simple. It works. For small projects, it is still sufficient.

## Model 3: Layered SSR - Application Approach

HTML is still rendered on the server, but responsibilities are clearly separated.

Application logic does not mix directly with the view. A layered structure appears: model, controller, view.

**Flow**: Browser → Controller → Model → View → HTML → Browser.

Structure:

```bash
index.php
views/home.php
```

Code:

Controller (logic, PHP):

```php
<?php

function render($view, $data = [])
{
    extract($data);
    require "views/$view.php";
}

render("home", ["message" => "Hello World"]);
```

View (view.php):

```php
<!DOCTYPE html>
<html>
<body>
<h1><?php echo htmlspecialchars($message); ?></h1>
</body>
</html>
```

HTML is still generated on the server, but the code is organized. This approach scales much better in larger projects.

## Model 4: Client-Side Rendering (CSR) + API

Here, the place where HTML is generated changes.

In this model, the server stops generating HTML. Instead, it provides data (backend), usually in JSON format. HTML is built on the client side - in the browser - using JavaScript (frontend).

**Flow**: Browser → API → JSON → JavaScript → HTML (DOM).

Process:
- Static HTML is loaded.
- JavaScript sends a request to an API.
- The server returns data (e.g., JSON).
- JavaScript updates the view (frontend).

Structure:

```bash
api.php
index.html
```

Backend (PHP) – simple API endpoint returning JSON:

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

## Model 5: Static Site Generation (SSG)

This blog runs in this model.

Here we introduce a third moment when HTML is generated: build & deploy.

In this model, HTML is generated during the build process, not at each user request.

During the build step, a generator (in this case Jekyll, executed via GitHub Pages) creates static HTML files, which are then published via hosting platform. The server no longer executes application logic - it simply serves ready-made files to the browser.

**Flow**: Build & deploy → HTML → Server (static) → Browser.

Process:
- Markdown (content)
- Generator (Jekyll)
- Build (static HTML files are generated)
- Hosting (GitHub Pages)
- Browser

Markdown file:

```markdown
# Hello World
```

Code (generated result, static HTML produced during build):

```html
<!DOCTYPE html>
<html>
<body>
<h1>Hello World</h1>
</body>
</html>
```

This is the model used by this blog.

## Model Comparison

| Model              | When is HTML generated?     | Does the backend generate HTML per request? |
|--------------------|-----------------------------|-----------------------------------------|
| Static HTML     | przed wdrożeniem            | nie                                     |
| SSR klasyczne      | przy każdym żądaniu         | tak                                     |
| SSR warstwowe      | przy każdym żądaniu         | tak                                     |
| CSR + API          | po stronie przeglądarki     | nie                                     |
| SSG                | podczas budowania projektu  | nie                                     |

The difference between the models lies in when and where the HTML file is generated.

## Summary

A website is HTML sent to a browser.

Different models address different needs:
- static HTML is the simplest possible approach,
- classic SSR is straightforward and still works,
- the application approach organizes larger projects,
- CSR separates data from the interface,
- SSG simplifies infrastructure and improves performance.

My blog runs in the SSG model. The automation is quie extensive, but the foundation remains the same - HTML, CSS, and JavaScript. What changes is the moment when HTML is generated.

The nuances of these languages have evolved over the past 25+ years, but their core idea remains unchanged.

Interestingly, the technology in this blog has come full circle - from static HTML to an automated static SSG model based on Jekyll and GitHub.
