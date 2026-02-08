---
title: "Blog Jekyll (4/4): Konfiguracja domeny dla GitHub Pages: DNS i przekierowania"
date: 2026-02-09 07:00:00 +0100
categories: [Blog]
tags: [blog, jekyll, setup]
---

Ostatni krok budowy bloga to konfiguracja domeny. Robi się to w panelu providera domeny, gdzie trzeba się w tym celu zalogować.

Założenia:
- domena główna: marcinszewczyk.net
- blog ma działać pod adresem: https://blog.marcinszewczyk.net
- domena główna ma przekierowywać (301) na blog
- blog technicznie jest wystawiany przez GitHub pod adresem marcin-szewczyk-code.github.io

W panelu dostawcy domeny przechodzimy do ustawień DNS (np. DNS Zone).

Dodajemy rekord typu CNAME:
- Type: CNAME
- Subdomain: blog
- Target: marcin-szewczyk-code.github.io. (Uwaga: końcowa kropka jest poprawna i zalecana)

Ten rekord wskazuje subdomenę blog.marcinszewczyk.net na GitHub Pages.

Rekordy dla domeny głównej (ważne)

Dla domeny głównej marcinszewczyk.net:

nie ustawiamy żadnych rekordów A

nie ustawiamy CNAME

Domena główna nie powinna wskazywać bezpośrednio na GitHub Pages, ponieważ:

GitHub Pages nie obsługuje apex domain jako redirect

przekierowanie będzie realizowane przez OVH (HTTP 301)

Rekordy typu MX / SPF (poczta) pozostawiamy bez zmian.

Konfiguracja przekierowania (OVH → Redirection)

Po skonfigurowaniu DNS przechodzimy do:

Domains → marcinszewczyk.net → Redirection

Dodajemy nowe przekierowanie.

Parametry przekierowania:

- Source: marcinszewczyk.net (bez subdomeny)
- Also redirect www.marcinszewczyk.net: ✔ zaznaczone
- Redirection type: Visible redirection
- HTTP code: Permanent (301)
- Target URL: https://blog.marcinszewczyk.net/
- Jeśli dostępna jest opcja „zachowaj ścieżkę” (keep path), należy ją włączyć.

Sprawdzenie konfiguracji

Po zapisaniu zmian:
- Otwieramy w przeglądarce: https://blog.marcinszewczyk.net
- → blog powinien się załadować
- Otwieramy: https://marcinszewczyk.net
→ adres powinien automatycznie zmienić się na: https://blog.marcinszewczyk.net


Czas propagacji:
- DNS: zwykle kilka minut (do kilkunastu)
- przekierowanie HTTP: zazwyczaj natychmiast

Najczęstsze problemy

404 z GitHub Pages na domenie głównej
→ oznacza, że rekordy A nadal wskazują na GitHub
→ należy je usunąć z DNS zone

Przekierowanie nie działa
→ rekord A dla domeny głównej blokuje redirect
→ redirect w OVH działa tylko, gdy apex nie ma A-recordów

DNS Check in Progress w GitHub Pages
→ normalne w trakcie propagacji DNS
→ zwykle znika samo

Podsumowanie

GitHub Pages:

serwuje treść bloga

OVH:

obsługuje DNS

realizuje przekierowanie 301

domena główna:

nie hostuje treści

tylko przekierowuje

Robimy to raz → działa stabilnie → nie wracamy do tematu.

Jeśli chcesz, w kolejnym kroku mogę:

dodać schemat logiczny (kto za co odpowiada),

albo przygotować krótką checklistę „DNS + redirect” jako podsumowanie rozdziału.

==============================
uwzględnij OVH -> redirections:
 
==============================

Dobrze — to, co pokazujesz na screenie, jest dokładnie poprawną i docelową konfiguracją w OVH 👍
Poniżej masz zaktualizowaną sekcję „Redirections”, uwzględniającą dokładnie ten stan, w tym rozdzielenie marcinszewczyk.net i www.marcinszewczyk.net.

Możesz bezpośrednio podmienić wcześniejszą sekcję o przekierowaniach na tę wersję.

Konfiguracja przekierowań (OVH → Redirection)

Po skonfigurowaniu DNS (rekord CNAME dla blog) przechodzimy w panelu OVH do:

Domains → marcinszewczyk.net → Redirection


Konfigurujemy dwa przekierowania typu HTTP 301 (visible).

Przekierowanie domeny głównej

Source:

marcinszewczyk.net


Type:

Permanent visible redirection (301)


Target:

https://blog.marcinszewczyk.net/


To przekierowanie powoduje, że wejście na domenę główną automatycznie zmienia adres w pasku przeglądarki na adres bloga.

Przekierowanie subdomeny www

Source:

www.marcinszewczyk.net


Type:

Permanent visible redirection (301)


Target:

https://blog.marcinszewczyk.net/


Dzięki temu:

www.marcinszewczyk.net

marcinszewczyk.net

zawsze prowadzą do jednego, kanonicznego adresu bloga.

Stan końcowy (OVH)

Po poprawnej konfiguracji w OVH widzimy:

DNS zone:

blog.marcinszewczyk.net → CNAME → marcin-szewczyk-code.github.io

Redirections:

marcinszewczyk.net → 301 → https://blog.marcinszewczyk.net/

www.marcinszewczyk.net → 301 → https://blog.marcinszewczyk.net/

Domena główna nie hostuje treści — służy wyłącznie jako punkt wejścia i przekierowanie.

Sprawdzenie

Po zapisaniu zmian:

wejście na

https://blog.marcinszewczyk.net


→ blog ładuje się bezpośrednio

wejście na

https://marcinszewczyk.net
https://www.marcinszewczyk.net


→ następuje przekierowanie 301 do bloga

Uwaga praktyczna

W tej konfiguracji:

GitHub Pages nie musi znać domeny głównej

GitHub Pages obsługuje tylko blog.marcinszewczyk.net

cała logika SEO (canonical URL, 301) jest jednoznaczna

To jest najczystszy i najstabilniejszy wariant dla GitHub Pages + custom domain.

Jeśli chcesz, w kolejnym kroku mogę:

dopisać krótką sekcję „Dlaczego tak, a nie inaczej”,

albo przygotować diagram DNS / redirect / GitHub Pages jako wizualne podsumowanie.

===================
Uwzględnij to co w DNS Zone:
 
===================

Świetnie — ten screen idealnie domyka całość.
Poniżej masz zaktualizowaną sekcję „DNS zone (OVH)”, dokładnie zgodną z tym, co faktycznie masz ustawione (CNAME + A-recordy OVH pod redirect).

Możesz bezpośrednio podmienić wcześniejszy opis DNS na ten.

Konfiguracja DNS (OVH → DNS zone)

W panelu OVH przechodzimy do:

Domains → marcinszewczyk.net → DNS zone

Rekord dla bloga (wymagany)

Dodajemy rekord typu CNAME:

Subdomain:

blog


Type:

CNAME


TTL:

300


Target:

marcin-szewczyk-code.github.io.


Ten rekord wskazuje subdomenę blog.marcinszewczyk.net bezpośrednio na GitHub Pages.

Rekordy dla domeny głównej i www (wymagane do przekierowań OVH)

Aby przekierowania HTTP (301) w OVH działały poprawnie, domena główna musi wskazywać na infrastrukturę OVH.

Dlatego pozostawiamy (lub dodajemy) rekordy typu A:

Subdomain:

(puste)   → marcinszewczyk.net


Type:

A


Target:

213.186.33.5


Subdomain:

www


Type:

A


Target:

213.186.33.5


Adres IP 213.186.33.5 to standardowy adres OVH używany do obsługi przekierowań HTTP.

Stan końcowy (DNS zone)

Po poprawnej konfiguracji w strefie DNS widzimy:

blog.marcinszewczyk.net
→ CNAME → marcin-szewczyk-code.github.io.

marcinszewczyk.net
→ A → 213.186.33.5

www.marcinszewczyk.net
→ A → 213.186.33.5

Rekordy MX / SPF (poczta) pozostają bez zmian.

Dlaczego tak?

GitHub Pages:

serwuje treść bloga

obsługuje tylko blog.marcinszewczyk.net

OVH:

obsługuje DNS

realizuje przekierowania 301 dla domeny głównej i www

wymaga A-recordów wskazujących na własną infrastrukturę

To jest zalecany i stabilny model dla:

GitHub Pages + custom domain + redirect apex → subdomena

Jeśli chcesz, w następnym kroku mogę:

dodać pełną checklistę końcową (GitHub + DNS + Redirect),

albo skrócić całość do wersji „TL;DR – jak ustawić w 10 minut”.

==================
uwzględnij ustawienia repo na gicie: 
 
 
=====================


Świetnie — to jest ostatni brakujący element układanki.
Poniżej masz sekcję opisującą konfigurację repozytorium na GitHubie, dokładnie zgodną z tym screenem i spójną stylem z resztą instrukcji.

Możesz ją wkleić jako osobny podrozdział po DNS / Redirections albo jako domknięcie całej konfiguracji.

Konfiguracja GitHub Pages (repozytorium)

Po stronie GitHuba konieczne jest jeszcze skonfigurowanie repozytorium, aby GitHub Pages wiedział, pod jaką domeną serwować stronę oraz żeby poprawnie wystawić certyfikat HTTPS.

Wchodzimy do repozytorium:

marcin-szewczyk-code.github.io


następnie:

Settings → Pages

Build and deployment

W sekcji Build and deployment ustawiamy:

Source:

GitHub Actions


Blog jest budowany automatycznie przez workflow dostarczony przez szablon Chirpy.

Custom domain

W sekcji Custom domain ustawiamy:

blog.marcinszewczyk.net


Po zapisaniu GitHub:

sprawdza rekordy DNS (CNAME),

automatycznie tworzy plik CNAME w repozytorium,

rozpoczyna provisioning certyfikatu TLS.

Stan poprawny:

✔ DNS check successful

HTTPS

Po zakończeniu weryfikacji DNS i wygenerowaniu certyfikatu włączamy:

✔ Enforce HTTPS

Od tego momentu:

strona jest dostępna wyłącznie przez HTTPS,

certyfikat jest odnawiany automatycznie przez GitHub.

Stan końcowy (GitHub Pages)

Po poprawnej konfiguracji w zakładce Pages widzimy:

komunikat:

Your site is live at https://blog.marcinszewczyk.net/


ostatni deployment wykonany przez GitHub Actions,

ustawiony custom domain,

włączone HTTPS.

GitHub Pages:

serwuje treść bloga,

obsługuje certyfikat TLS,

nie obsługuje przekierowań (robi to OVH).

Relacja GitHub ↔ DNS ↔ Redirect (podsumowanie techniczne)

GitHub Pages:

repo: marcin-szewczyk-code.github.io

domena: blog.marcinszewczyk.net

HTTPS: certyfikat Let’s Encrypt (automatyczny)

OVH (DNS + Redirect):

CNAME blog → GitHub Pages

A-recordy apex + www → infrastruktura OVH

redirect 301:

marcinszewczyk.net → blog.marcinszewczyk.net

www.marcinszewczyk.net → blog.marcinszewczyk.net

Każdy element robi jedną, jasno określoną rzecz — i dzięki temu konfiguracja jest stabilna i przewidywalna.

Finalne sprawdzenie

https://blog.marcinszewczyk.net
→ blog ładuje się bezpośrednio

https://marcinszewczyk.net
→ przekierowanie 301 do bloga

https://www.marcinszewczyk.net
→ przekierowanie 301 do bloga

Jeśli to działa — konfiguracja jest skończona.

Jeżeli chcesz, mogę jeszcze:

zrobić jedną zbiorczą checklistę „gotowe / OK”,

albo skrócić całość do wersji referencyjnej (README / runbook).


