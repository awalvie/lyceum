---
title: dev log 1
subtitle: dev log 1
created: 2020-06-12

---

Spent six hours trying to find and fix memory leaks with my Static Site Generator. I was planning switching to the new website today, but there are critical errors that halted progress. The flow of the SSG is very simplistic right now.

- 1. Get contents of the data directory into a C string array
- 2. Read the metadata on top of the file and the rest of the content
- 3. Generate the static HTML files from that content

I’ve identified that I have a memory leak which leads to a buffer overflow causing reading multiple files to have undefined behavior when I read the contents of the source file into a C Structure meant to store the metadata and the contents.

Assessing today I realize that I might have made more progress if I took breaks while debugging. I was frustrated, drained, exhausted and more importantly left irritable after having sat on the PC for so long. I have tried the pomodoro technique in the past but never stuck to it. I want a simple minimal application that has a timer that shows up on the status bar of my screen, but I haven’t found any. I’ll look for one.

Other than that I had a long meeting with the startup that I am working with. We tried to figure out problems we were having while writing routes for our website.

---
