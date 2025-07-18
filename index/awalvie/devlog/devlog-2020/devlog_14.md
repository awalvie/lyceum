---
title: dev log 14
subtitle: Porting Noodle to ANSI C
created: 2020-08-19
---
# Dev Log 14

Since I am free for a couple of weeks I've been looking around for open-source
projects to contribute to. I sent a toot out on merveilles asking for
suggestions for interesting and active projects on GitHub, written in C that I
could help out with, but didn't find any that I could meaningfully contribute
to in a couple of weeks. I saw that there were a lot of [active
projects](https://github.com/topics/go) in golang and I had been interested in
learning the language for a while, so I'd decided on going through their
wonderful tour of the language and then find some go projects that I could
contribute to after my internship. I know it's stupid but for some reason it
made sense to my caffinated brain at midnight. That's when I got a ping from
[neauoire](https://merveilles.town/@neauoire). He's planning on re-writing
[noodle](https://hundredrabbits.github.io/Noodle/) in ANSI C and gave me the
opportunity to help out, WHICH IS AWESOME! We'll be porting the code from
Javascript and will be using the SDL library to make it. So that's what I've
been getting acquainted with since yesterday.

I've spent 4 hours dealing with a stupid bug, so it's only natural that I'll
explain what it was. There are 3 basics involved with working with any game
library usually.

- 1. Initialize Resources
- 2. Game Loop
- 3. Free Resources

The first 2 went smoothly. It's the thrid step that was being the issue.

```
/* Function to free all resources */
bool close()
{
	/* Free the surface attached to the window */
	SDL_FreeSurface(surface);
	surface = NULL;

	/* Destroy the window */
	SDL_DestroyWindow(window);
	window = NULL;

	/* Gracefully quit out of SDL */
	SDL_Quit();
}

```

This lead to the following error

```
free(): double free detected in tcache 2
[1]    13472 abort (core dumped)  ./demo
```

The reason I call this a weird bug is because if I throw all the code into
`main()` and run the exact same code. It runs fine. As soon as I modularize the
code, keeping the logic of the program same, but separating the code into
functions, I get this error.

It took in a while to realize what the problem was, and it's a stupid problem,
it's the **name** of the function that's the issue. Calling the function to
free the resources `close()` conflicted with the system call for close.
Changing the function name to `quit()` solved the issue. Yeah, definitely a
weird one! Now onto writing the actual port for the project. You can find the
code on GitHub
[here](https://github.com/awalvie/cookbook/tree/master/c/noodle).
