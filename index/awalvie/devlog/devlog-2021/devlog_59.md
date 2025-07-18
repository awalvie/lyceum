---
title: "devlog 59"
subtitle: "Welcome to Lyceum 2.0"
created: 2021-09-02
---
# Devlog 59

Oh boy am I excited to write this one!

### Lyceum 2 Electric Boogaloo

Welcome to Lyceum 2.0 powered by
[go-blender](https://github.com/awalvie/go-blender)! I'm ecstatic to have `v1`
finished. Some features are:

- [x] Markdown support! No more writing raw HTML
- [x] Classy navigation bar ~~stolen~~ heavily inspired by
[XXIIVV](https://wiki.xxiivv.com/)
- [x] Tree like file structure, eg:

```console |-- index/ |-- _index.md |-- about/ |-- _index.md |-- friends.md |--
devlog |-- _index.md |-- devlog-2020 |-- _index.md |-- devlog_57.md |--
devlog_58.md |-- devlog-2021 ... ```

Essentially it's a generic file system. The `_index.html` files represent the
parent folder while all the `.md` files have their own pages. The navigation
bar is made of (usually) 3 columns.

``` Parent | Current | Child ```

All three of these are generated dynamically by `go-blender` during the build
phase. I'd become tired of maintaining a massive single folder with all my
source files in the previous version. Since I have to manually link files, in
case I forgot, well the file's lost now. Folders allow me to track files
easily. Another advantage of this folder-based approach is the ease of turning
single pages into folders themselves, which is crucial to create a wiki. For
eg: I'm going to be restarting [drawabox](https://drawabox.com/). To add it on
the website, all I have to do is create a folder inside [art](art.html) for it
and then add my work inside. I can also further create folders for it's
multiple lessons. It's recursive! If you can't tell already I love creating
folders and organizing things, might be an OCD :p

If you can't tell from the name already, it's also written in `Golang`!, the
previous version used `C` and the code was, well, horrible (look at your own
risk: [archived](https://github.com/awalvie/lyceum/tree/master/archived)). I
will be the first to admit though that `go-blender` has some rough edges, but
it's a huge step up from it's predecessor. I maintained a
[scratchpad](https://github.com/awalvie/go-blender/blob/master/steps.md) file
if you want to know how I went about building it. Might not make a lot of
sense, but in it's defense that wasn't its purpose.

##### Pending features

- [ ] RSS support
- [ ] Backlink parsing support (Maybe)

#### Credits

No I'm not smart enough to build something like this! I had help directly and
indirectly!

- [@neauoire](https://merveilles.town/@neauoire) for creating
[XXIIVV](https://wiki.xxiivv.com/site/home.html). I consulted the
[oscean](https://github.com/XXIIVV/oscean) code multiple times for inspiration
and the website styling!
- [icyphox](https://icyphox.sh/)'s [vite](https://git.icyphox.sh/vite/) project
and for being an awesome friend in general.
- My mom, even though she didn't understand what I was doing she was always
happy to see what I'd made!

#### Closing thoughts

I love the way Lyceum looks and writing this post in markdown has been bliss.
I'm also looking forward to populating it with entries regularly.

- Adding a separate **techlog** where I can write focused technical posts for
things I have on my
[to-do-list](https://github.com/awalvie/things-to-do/issues).
- Entries about progress in my hobbies
- Rambling about random things

I love my cozy corner on the internet.
