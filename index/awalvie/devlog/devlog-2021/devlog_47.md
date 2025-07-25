---
title: dev log 47
subtitle: relatively boring work
created: 2021-03-17
---
# Dev Log 47

It's been a while, almost a month now since the previous entry. I wasn't doing
very interesting things at my internship or during free time. While the former
is still the case, due to unfortunate events at the company, the latter has
seen development.

**Intern**

While I setup logging services for our infra fairly quickly, the problem was
our backend wasn't logging data in the right format. There were a lot of random
`print` statements scattered throughout the codebase. They did not have
associated context available which made them basically useless even if logged.
Since it's a small tech team for a fairly large codebase, I was tasked with
identifying high-priority portions of code and add logs wherever needed. It was
a whole lot of looking at code, figuring out what was happening, where it
worked and where it broke and logging those places with the appropriate context
(object values, caller, errors etc). Boring, yes, but needed to be done.
Ofcourse once we deploymed my changes, I broke production. We'd been informed
the week before that the tech team's focus would be shifting to designing
internal tools and solutions for another team. This was because the worflow of
the team in question was manual in nature and suceptible to human error. There
were'nt any historical records to see the changes that were being made and this
had been impactive the business negatively because customers were churning.
While the idea of making internal tools was exciting I was disappointed when I
was assigned a rather boring, but needed to be done task, migrate customers
from one service to the other by making the necessary db changes. That's what
I'm currently doing, I have a meeting in an hour to wrap up parts of it, but
I'm not sure how long this is going to go on for. Hopefully not too long. Both
me and our founder, (who's teaching me how to do it) end up being quite
frustrated with a senselessly complicated task that could have been avoided if
we had wrote some scripts a wihle ago.

**Other**

Reflecting personally, I'm making a point to sleep at least 7-8 hours everyday,
have started learning the guitar again, hosted the zettelkasten website, and as
soon as the chaos at work subsides will pick up sketching, and reading as well.
I have been somewhat successful at my efforts in blocking YouTube from my life
and tech in general when it's not needed. It's surprisingly difficult but I'm
working on it.

I don't want to miss sight of what I want to do with my life, at least my 20's.
Explore the world and live a modest life. A friend of mine messaged recently
that he had been contemplating the same. I mentioned the same to our founder
and he suggested that I should start building products that could say get me to
1k-2k monthly recurring revenue over say a year or two and I could effectively
fire myself from the job. That's what I'm trying to do with any free time I
get. There's a couple of ideas alredy in the pipeline that are being worked on,
I'll talk more once they're in a state to present. But yeah, long post haha.
