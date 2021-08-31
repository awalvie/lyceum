---
title: dev log 2
subtitle: dev log 2
created: 2020-06-13
---

Spent most of the morning trying to debug the generator but did not end up finding the issue. It was only in the afternoon, when a member of a community I belong to identified the issue, that I understood what was wrong. As was pointed out to me:

`The data returned by readdir() may be overwritten by subsequent calls to readdir() for the same directory stream.

On success, readdir() returns a pointer to a dirent structure. (This structure may be statically allocated; do not attempt to free(3) it.)`

I was trying to read the data in `dname` (the name of the file) directly into a structure which was a temporary pointer to a further temporary array of strings and not the value of the string itself. This was producing aberrant behavior when parsing multiple files. Already having taken the trouble to look through my badly written code he went the extra mile and suggested a clever solution that worked instantly and I was overjoyed when it worked flawlessly! If you read this, thanks a lot again!

I then also wrote a simple python script that converted the existing markdown entries on the previous website into source files for the current generator, made some changes to the CSS and wrote the missing tags for the HTML pages.

I feel very lucky to have been able to find a community online (purely by chance) this past month that inspires me and makes me feel like I finally have like minded people that I can talk to. Their endless creativity and passion give me strength to get up when I’m feeling lost.

Lyceum is the first thing that I’ve made from scratch. I did not follow a tutorial or written instructions. I have always been apprehensive of my capabilities and being able to complete this has contributed in a small way to my dismal self-confidence. I look forward to getting this website live tomorrow and make new projects after that. Programming might be fun after all!

---
