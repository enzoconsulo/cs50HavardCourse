# CS50 Harvard Course — Topics mapped to repository folders

A concise guide that links major CS50 topics to the folders in this repository. For each folder I list the core CS50 concepts it relates to and a short explanation of those concepts so you get the big picture quickly.

---

## How to use this

Open the folder in the repo that matches a topic to find exercises and small projects that put the concept into practice. Each folder contains practical files and short READMEs that show how the concept is used in code.

---

## CS50 topics 

* [**exercisesC/**](https://github.com/enzoconsulo/cs50HavardCourse/tree/main/exercisesC) — *C, low-level programming, memory, pointers, and systems fundamentals*
  Core topics: C syntax and control flow (variables, loops, conditionals), functions, arrays and strings, pointers and pointer arithmetic, memory allocation (`malloc`/`free`), structs, file I/O, and debugging with tools like `valgrind`/`gdb`. These are the foundations CS50 uses to teach how programs map to hardware and how to reason about memory and performance.

* [**exercisesPython/**](https://github.com/enzoconsulo/cs50HavardCourse/tree/main/exercisesPython) — *High-level programming, scripting, and rapid prototyping*
  Core topics: Python syntax, data types (lists, dicts, sets), comprehension and iteration patterns, functions and modules, file handling, simple object orientation, and using libraries. This folder demonstrates writing higher-level programs quickly, focusing on readability and problem solving rather than low-level memory details.

* [**exercisesSql/**](https://github.com/enzoconsulo/cs50HavardCourse/tree/main/exercisesSql) — *Relational data modeling and querying*
  Core topics: SQL syntax, SELECT/INSERT/UPDATE/DELETE, joins, aggregation (`GROUP BY`, `HAVING`), filtering, ordering, and normalization basics. Exercises teach how to structure data and retrieve insights using queries against SQLite databases.

* [**exercisesHTML,CSS,JS/**](https://github.com/enzoconsulo/cs50HavardCourse/tree/main/exercisesHTML,CSS,JS) — *Front-end web basics: structure, presentation, and client behavior*
  Core topics: HTML document structure, semantic elements, CSS layout and responsiveness, basic styling, and JavaScript for interactivity (DOM manipulation, event handling). These exercises show how to build user interfaces and create interactive pages that run in the browser.

* [**exercisesFlask/**](https://github.com/enzoconsulo/cs50HavardCourse/tree/main/exercisesFlask) — *Back-end web development, HTTP, templating, and simple persistence*
  Core topics: HTTP routing (GET/POST), Flask app structure, Jinja2 templating, handling forms and sessions, secure password storage, and storing data with SQLite. These projects bridge front-end work with server logic and persistent storage, demonstrating how web applications handle requests and maintain state.

---

## Broader CS50 themes you’ll encounter across folders

* **Algorithms & Problem Solving** — algorithmic thinking (searching, sorting, complexity), breaking problems into steps, and designing correct, efficient solutions. Practiced in both C and Python exercises.
* **Data Structures** — arrays, linked lists, stacks, queues, hash tables, trees. Understanding these is key to organizing data efficiently; examples appear in C and Python work.
* **Memory & Performance** — how programs use memory, tradeoffs between speed and space, and writing code that avoids leaks and undefined behavior (mainly in C).
* **Software Engineering Practices** — testing, incremental development, code organization, and basic debugging workflows that apply to every language and project type.
* **Security & Best Practices** — safe handling of user input, password hashing, and session management (especially in web exercises).
* **APIs & Networking Basics** — using web APIs and understanding HTTP semantics (covered in web/Flask exercises and some Python examples).
* **Databases & Persistence** — choosing how to persist data, schema design and CRUD operations (SQL + Flask examples).
* **User Interfaces & UX** — building clear, accessible pages and simple client interactions (HTML/CSS/JS exercises).

---

## Quick navigation tip

* If you want to understand how a concept looks in code, pick a folder from the list above and open one exercise README inside — it will point to the specific files to run and try.

---

Developed by Enzo C. Consulo (2025).
