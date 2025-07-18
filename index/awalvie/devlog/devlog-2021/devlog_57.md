---
title: dev log 57
subtitle: minor hiccups
created: 2021-07-25
---
# Dev Log 57

### Work

Been working on architecting and setting up an [inner dev
loop](https://thenewstack.io/kubernetes-infrastructure-know-the-inner-dev-loop/)
as a primary task for the quarter. We were originally planning on using
[Vagrant](https://www.vagrantup.com/) to setup a local development environment
with the VirtualBox provider for `x86_64` and Docker provider for `arm64` (to
support Apple Silicon). Easy enough, right, RIGHT!

**Vagrant Hell**

Images on [docker hub](https://hub.docker.com/) don't support Vagrant out of
the box. Vagrant will pull the image, yes, but:

1.  [The container will die
    immediately](https://github.com/hashicorp/vagrant/issues/8769)
2. `vagrant ssh` won't work unless you build/use an image from a Dockerfile
   that sets up a vagrant user and estabilishes ssh keys for it.

The image pulled using the previous step will still be an `arm64` image if
you're on Apple Silicon. If it's an `x86_64` image you're after, that will
require setting up `buildx` and `qemu` to build [multi-arch
images](https://docs.docker.com/desktop/multi-arch/).

Docker's docs outline the [problems
associated](https://docs.docker.com/docker-for-mac/apple-silicon/#known-issues)
with using `qemu` to emulate `x86_64`.

Moreover this isn't a scalable approach to automating local development setups
since we'd have to maintain Vagrantfiles for each repository.

We've been actively looking for better solutions, but don't have a clear way
forward yet.

### Personal

I setup two machines using [Oracle's Cloud Free
Tier](https://www.oracle.com/in/cloud/free/), and self-hosted
[yarr](https://github.com/nkanaev/yarr). Clean, minimal, lightweight RSS
aggregator written in Go. Plan on hosting some more services using the
[awesome-selfhosted](https://github.com/awesome-selfhosted/awesome-selfhosted)
repo for reference.

I have some long term projects in mind, but I'd like to rewrite Lyceum in Go
before I start them. I'll have an easier time documenting my progress that way.
So that's the next project I plan on picking up.

Outside of tech, I've been running regularly for the past couple weeks. Body
hurt like hell the first 2-3 days, but it's gotten progressively easier over
time and I've started enjoying the activity as an opportunity of escaping
screens for the real world every day. Been trying to eat better as well, no
strict diet, just using common sense to choose healthy over unhealthy.
