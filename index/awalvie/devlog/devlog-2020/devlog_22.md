---
title: dev log 22
subtitle: deployment and documentation
created: 2020-10-11
---
# Dev Log 22

Our teammate responsible for the frontend informed me yesterday that he would
need the backend deployed before he could get on with the integration because
Android emulation did not play nicely with the local servers.

I had done deployment previously, so I knew the steps I had to take.

- Sping up a new virtual machine (DigitalOcean in my case)
- Add a new user and give it `sudo` privelages
- Login to it and add ssh auth
- Get all the dependencies and setup the backend
- Install Nginx
- Configure Nginx to proxy all all requests to the server to the server running
locally

And the backend has been deployed.

Then I started with the second task of the day, documentation for the routes. I
was going to manually write it all out in a single `API.md` file, but then I
thought it would be cool if we had auto-generating documenatation. I asked
around and found out that `Sphinx` and `Swagger` are commonly used for this
purpose. I set them both up but found them a little too verbose for the simple
API that we had, and went back to writing it by hand.

Tomorrow the final touches and then submission!
