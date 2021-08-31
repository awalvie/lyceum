---
title: dev log 15
subtitle: My painting masterpiece
created: 2020-09-22
---

I bring news of progress. I've been working on rendering a canvas that I can use the mouse to paint with as my first milestone of porting Noodle from JS to C alongwith Devine. I'm not going to lie, it's been challenging. Graphics libraries are hard especially when you don't have tutorials. Your only choice is to open up various function documentations and keep doing that until you find what you're looking for. It's definitely satisfying when you get things working though. To walk you through the things that I did I made sure to write down a plan of action while writing the code, to break down big objectives atomically, into small actionable goals. This is what was I wrote down -

- First render a white canvas //DONE
- Poll mouse events //DONE
- Switch to a renderer instead of using surfaces //DONE
- Use mouse events to draw to canvas //DONE
- Re-Work code to remove global variables into a portable structure

Working this way the task of porting an entire program does not have to be dealt with altogether, I just have to do the next thing on the list and slowly but surely the port will happen. Here's a glimpse of what the canvas looks like right now, **behold**:

![](./static/images/dev_log_15_noodle.png)
