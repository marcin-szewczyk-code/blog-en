---
title: "Jekyll Blog: Newsletter – MailerLite"
description: "Newsletter implementation using a Static Frontend + SaaS Backend architecture (Jekyll, Chirpy, MailerLite)."
date: 2026-03-04 07:00:00 +0100
categories: [Jekyll Blog]
tags: [newsletter, jekyll, chirpy, mailerlite]
---

I thought about creating a newsletter – so I did.

The newsletter informs about new blog posts – independently of external social media platforms.

---

## Concept

### Assumptions

Static frontend + external backend for email subscription and distribution:

-   The blog operates as a fully static frontend.
-   Subscription handling and email distribution are implemented through an external backend (SaaS model).
-   Email addresses are not stored in the repository or on the blog server – only within the SaaS system.

### Operating Principle

-   Notifications are sent each time a new post is published.
-   Double opt-in is enabled during subscription (email confirmation required).
-   Subscribers can unsubscribe at any time using the link in the email footer.
-   Confirmation pages are hosted within my own domain.

### SaaS Selection (Software as a Service)

I chose MailerLite because:

-   Free plan up to 500 subscribers and 12,000 emails per month.
-   No aggressive marketing elements.
-   Simple operational model.
-   Ability to export the subscriber database.

### Architecture

Static frontend + external backend:

-   **Frontend:** Jekyll + Chirpy theme (GitHub Pages)
-   **Backend:** MailerLite

---

## Implementation

### Subscription Flow

The subscription process works as follows:

1.  In `_includes/topbar.html` there is a link to the subscription page:
    [https://blog.marcinszewczyk.net/newsletter/](https://blog.marcinszewczyk.net/newsletter/)

2.  The form on that page is connected to the backend (MailerLite).

3.  The user enters their email address and submits the form.
    They receive a confirmation email with an activation link.
    At the same time, the following page is displayed: [https://blog.marcinszewczyk.net/newsletter-confirmation/](https://blog.marcinszewczyk.net/newsletter-confirmation/)

4.  The user clicks the confirmation link in the email.
    A confirmation page is displayed: [https://blog.marcinszewczyk.net/newsletter-confirmed/](https://blog.marcinszewczyk.net/newsletter-confirmed/)

The external backend handles the subscription logic, while the blog remains fully static.

### MailerLite Configuration

#### Account Settings:

-   Sender: Name and surname
-   Address: newsletter@marcinszewczyk.net

#### Sending Domains:

A sending domain was added along with authentication records (SPF/DKIM) to improve deliverability.

#### Subscriber Group:

Created group: **Blog Newsletter**.

#### Forms:

Two forms were created:
- Form: PL
- Form: EN

Settings:

-   "Custom success page" enabled,
-   double opt-in enabled,
-   auto-confirm disabled.

---

### Frontend Integration (Jekyll-Chirpy)

#### 1. Script

JavaScript provided by MailerLite, added in `_includes/head.html`:

``` html
<!-- MailerLite Universal -->
<script>
    (function(w,d,e,u,f,l,n){w[f]=w[f]||function(){(w[f].q=w[f].q||[])
    .push(arguments);},l=d.createElement(e),l.async=1,l.src=u,
    n=d.getElementsByTagName(e)[0],n.parentNode.insertBefore(l,n);})
    (window,document,'script','https://assets.mailerlite.com/js/universal.js','ml');
    ml('account', '2151227');
</script>
<!-- End MailerLite Universal -->
```

The script initializes the global `ml` object required for embedding
forms.

#### 2. Newsletter Page in Jekyll-Chirpy

In `_pages/newsletter.md`, the MailerLite form was added:

``` html
<div class="ml-embedded" data-form="cY1WRm"></div>
```

### Data Flow

1.  The user enters their email address.
2.  The form sends data directly to MailerLite.
3.  MailerLite:
    -   sends a confirmation email,
    -   stores the subscriber in the group,
    -   allows unsubscription.

Jekyll does not participate in storing or processing subscriber data – the blog remains fully static.

---

## Summary

The blog now has a newsletter that serves as a simple notification mechanism for new posts.

No marketing.

No sales automation.

Simple. Exactly as much as needed.
