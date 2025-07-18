---
title: dev log 37
subtitle: got me an internship
created: 2020-12-08
---
# Dev Log 37

"Warm greetings to my connections! I am happy to share that...", yeah, none of
that award acceptance speech that everyone gives on Linkedin, hell na. I did my
task well and got accepted for an internship. It was quick because, I got
lucky, that's it.

My task is on github, it's called [anzibl](https://github.com/awalvie/anzibl).
It was a very interesting task, I had to:

- Create a small EC2 or DO instance.
- Run a small HTTP server (preferably in Golang) with a ping endpoint
- Run prometheus on the same machine to monitor ping endpoint and raise an
alert over email when either:
  - HTTP server process has crashed
  - Ping endpoint is not responding

All of it, infrastructure creation, provisioning (installing relevant
software), deployment and monitoring, needed to be automated using
[ansible](https://www.ansible.com/). It was a fantastic opportunity to get to
learn ansible, prometheus and get familiar with AWS, a little nerve wracking,
but fun nonetheless. I got to learn a crap tonne. I wrote down all the steps
that I took to get the task completed in a file called
[steps_taken.md](https://github.com/awalvie/anzibl/blob/master/STEPS_TAKEN.md).

The internship starts sometime in the first couple of weeks of January, because
I have my final uni exams throughout december, which means I have a couple of
weeks to spare. I'm planning on starting
[adventofcode](https://adventofcode.com/), since all of my merveilles feed is
full of people doing it. I'll be attempting it in go, because I enjoy writing
go and want to get better at writing it. I'll also be researching more about
how [bittorrent](https://en.wikipedia.org/wiki/BitTorrent) works because I want
to write my own client in go. That's about it.
