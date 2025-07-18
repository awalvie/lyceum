---
title: dev log 27
subtitle: django be big
created: 2020-10-25
---
# Dev Log 27

I got myself an issue assigned on Friday, but did not start working on it until
today, but fret not, I've spent a lot of time with Kiwi's codebase today and I
think I have a preliminary understanding of how to write most of the other
testcases. I'll try to remember as much of what I did as I can.

The issue I took up is of writing automated testcases for one of kiwi's
submodules ([issue](https://github.com/kiwitcms/Kiwi/issues/1626), for
reference). The issue wants us to take the `testexecutionstatus`submodule and
write tests for it. Luckily for me the file only has a single function. So this
is what I'm supposed to do:

1. Create a test file for `testexecutionstatus.py`.
2. Choose one funtion.
3. Make a test class for it.
4. Initialize all the pre-requiste objects.
5. Check all the possible use cases of the function.

Which sounded pretty easy at a first glance, as it usually does, but ain't,
especially if you have no idea what's happening in the code. I used the code
written for a similar issue (different module) as reference, and there were
plenty of other tests for different modules in the `tests`subdirectory.

While I had understood what to do, I didn't know how to do it. Digging around a
little more, I started seeing a common pattern when it came to initializing all
the pre-requisite objects. All the objects being initialized were using
_factories_. I found the `factories.py`file, and sure enough this is where the
objects being as prerequisites were being defined. I tried looking for a class
for `TestExecutionStatus`, but there wasn't one. Hmm, couldn't figure out what
to do. Then I remembered that the project maintainers had told me to look at
the individual tables and also how all of them related to each other. I started
looking for something along the lines of `TestExecutionStatus` and found it
quickly as you can see below.

![](./static/images/testexecutionstatus.png)

The image tells me that `TestExecutionStatus` is a foreign key in the
`TestExecution` model, which there exists a factory for, Bingo!.

Now to writing the actual tests, which I'll write about in the next post.

Other than that I spent a lot of time yesterday trying to figure out how to run
the test file faster. Whenever I want to run my test file I do

```
./manage.py test --pattern="test_testexecutionstatus.py"
```

This does three things:

1. Create a new test database
2. Run all the migrations on it
3. Run the test

This works, but each test run takes about **62 seconds**, which is a little too
long. I run whatever I write pretty often and this impedes progress and
concentration severely, so I was looking for ways make it faster. First I used
the `--keepdb` flag, this reuses the test databaase, but no significant
difference in the total time. Then I tried the `-v 3`flag, to have a verbose
looking output and it was clear that there were too many migrations, so it was
the second step that was causing the delays. If I could make the migrations on
the test database presist for each test run, I could significantly reduce the
test time. Sadly, I haven't been able to find a solution to it yet. I've tried
switching databases from SQlite to Postgres, turning off the
`[Migrate](https://docs.djangoproject.com/en/3.1/ref/settings/#std:setting-TEST_MIGRATE)`
flag, but have either run into problems, or it hasn't helped, I'll update if
and when I find a fix.

In dotfile news, I have started using `ripgrep`(using
[vim-ripgrep](https://github.com/jremmen/vim-ripgrep)) to search for text in
files. It has been very useful and I'd highly recommend it for people trying to
parse and understand massive codebases, it's very quick and accurate. If you're
interested in why ripgrep is so fast, you can read the [blog
post](https://blog.burntsushi.net/transducers/) by the author himself (haven't
read it myself :| it's just too big and complicated). I've also switched out
[Delimitmate](https://github.com/raimondi/delimitmate) in favour of
[Auto-Pairs](https://github.com/jiangmiao/auto-pairs) after reading
[this](https://aftnn.org/post/75730734352/vim-auto-closers-compared)
comparision, and using [vim-closetag](https://github.com/alvan/vim-closetag)
for having auto html tag completion.

That about sums it up! Yeah, long day :)
