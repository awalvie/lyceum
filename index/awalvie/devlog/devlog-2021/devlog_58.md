---
title: dev log 58
subtitle: Daily notes and go-blender
created: 2021-08-02
---
# Dev Log 58

### Work

Still automating local setup. I had to change contexts over to optimizing our
database latencies (which I also did not end up doing, I showed up a list of
slow queries and my team lead told me to take rest since he'd fixed 90% of them
already) last week which pushed this more than was needed. Now we're just
resorting to using plain old `ansible`.

### Personal

Lyceum's refactor is under way in a new repo,
[go-blender](https://github.com/awalvie/go-blender). It'll take a couple of
weekends to get this done at best, proabably more, but I'm enjoying writing
`go`.

I've been experimenting with using [Obsidian.md](https://obsidian.md/) and it's
**Daily Notes** plugin for some weeks now. Since I'm constantly reading and
learning about new things at work, I wanted to take notes in a way that the
knowledge accreted into a digital external corpus that I could refer back to.
My initial approach was to create notes and link them in a zettelkasten style
but per usual I realized that I was trying to over-engineer something that
should be simple. I couldn't put my finger on why, because the zettelkasten
appraoch made sense, but I had a nagging itch that something was wrong. So I
tried to rationally think about it, by writing. What follows isn't necessarily
well written, I just wanted to show how using writing as a medium of thinking
can be an excellent medium to reason about things.

#### Why takes daily notes?

Learning things usually involves significant effort. Grappling with the unknown
is difficult and time-consuming. Notes (in theory), allow us to maintain a
corpus of knowledge about information we have encountered, that can be referred
to instead of the source material to refresh our understanding of the subject
matter. This noble idea usually falls flat in practise if note-taking is done
passively, just for the sake of doing it. Passive note-taking gives the
illusion of ensuring that a piece of information won’t be forgotten, since
we’ve written it down. Yes, it won’t be forgotten, it will be lost instead, in
the pile of notes that get created this way. They won’t accumulate any insight.
In reality creating an external brain of sorts, consisting of information
accrued in interconnected notes takes significant time, effort and care itself.
Take [Andy
Matuschak’s](https://publish.obsidian.md/andymatuschak/Evergreen+notes)
**evergreen notes** as an exmaple.

The above is traditionally the purpose of note-taking. Instead daily notes
serve the following purposes:

- As scratchpads for temporarily supporting working memory that will be written
and discarded. They serve as a way to engage with the subject material actively
and help process it.
- Records of daily work and progress, which can be transformed into
technical/development blogs on the website.
- Streamline and simplify weekly reflections/reviews, no guess-work or
forgetting both completed and pending tasks.

Hence they are by design ephemeral. I don't need to spend time categorizing,
tagging or linking them. Note things down if I need to get a better
understanding of the subject-matter, or just to reinforce an existing concept,
then forget about them.
