---
title: dev log 20
subtitle: settin up flask
created: 2020-10-07
---

When I started working on the backend of the startup I'm a part of right now, everything was already setup. I'd setup flask once, a year or so ago, just following along with a tutorial, but setting up a sensible project structure that was comfortable turned out to be surprisingly difficult.

The way the backend is structured is pretty straightforward:

1. Poetry - Dependency Management
2. Flask - Backend Framework
3. PostgreSQL - Relational Database
4. SQLAlchemy - Object Relational Mapper
5. Marshmallow - Object Serialization and De-serialization

It's pretty standard, nothing new. The project structure is:

```
$ tree backend

├── app.py
├── backend
│   ├── __init__.py
│   ├── main.py
│   ├── models.py
│   ├── schemas.py
│   └── utils.py
├── config.py
├── docs
├── poetry.lock
├── pyproject.toml
├── README.md
└── route_testing

```

This time I went about setting everything up in a step-by-step manner, instead of the usual gungo-ho style of setting things up by looking at duckduckgo and wondering why it doesn't work.

- Ensure flask works
- Setup PostgreSQL on my machine
- Connect PostgreSQL with Flask
- Write a user model and ensure the table is getting created
- Write the schema for the model
- Set up flask-login
- Write the routes for login and signup
- Test routes
- Write a sane README for the backend
- Write the documentation for the APIs

It might seem like a lot of things to do, but all of them are small atomic tasks that I could work on one after the other. Breaking problems down into small digestable chunks helps me keep my anxiety low and also make the project surprisingly easy to make.
Then, I played Breath of the Wild for 3 hours, I needed that Master Sword :|
