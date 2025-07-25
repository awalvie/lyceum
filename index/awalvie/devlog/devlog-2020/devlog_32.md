---
title: dev log 32
subtitle: been sick
created: 2020-11-18
---
# Dev Log 32

I've been sick for the past couple of days, which has been relatively fun. I
enjoy getting sick every now and then. Breaks the monotonocity of lockdown.

We have our halfway hackathon this week. It's the mid-point of the MLH
Fellowship and to mark that we have our second hackathon. We formed our team
quite early and did come up with an idea that we all liked but we've been
running into problems with execution. The project involves the use of
websockets. A team member who's acquainted with [socket.io](https://socket.io/)
suggested that we use it. The idea is a web app and we wanted to keep the
backend and frontend decoupled. I really wanted to take this opportunity and
get my feet wet with writing `go`, but as it turn out, go's implemtation of
`socketio` supports a very old version of the socket.io client. The python
implemtation has a flask version, so I set it up, but again we ran into
probelms. When we tried testing some common routes like `connect` and
`disconnect`, we noticed that socketio wasn't using `/ws` for websockets but
was using long polling and making `http` requests instead. We wresteled with
the problem for a while, but decided it was probably going to be a good idea to
just use the `node` implemtation, as that's what `socketio` was written for,
but we've been running into problems again. It's looking pretty troublesome
right about now.

The other piece of news is that I've switched projects **again**, this time on
my own volition. Most of [Kiwi's](https://kiwitcms.org/) issues deal with
writing test cases. Our conversation with the maintainer suggested that those
were the only triaged issues that we should work on, until we run out of them.
While yes, the bounty on the issues is enticing and I'll be the first to admit
that was what attracted it to me at first, I've been getting pretty bored of
writing them. The perfect solution came in the form of
[BentoML](https://github.com/bentoml/bentoml). We were in a meeting with our
MLH Mentors when I asked them if any other projects had devops related issues.
I've been interested in the field for a while and this would provide the
perfect excuse to learn it. They directed me to the BentoML project which had
an open issue for [Apache Kafka
Integration](https://github.com/bentoml/BentoML/issues/1229), which I scooped
up. While I have a distaste for things Machine Learning, the project has enough
of devops to keep me interested and learn new technologies. More updates on how
the issue goes in the future.
