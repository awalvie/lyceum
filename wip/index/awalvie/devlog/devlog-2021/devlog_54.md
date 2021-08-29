---
title: dev log 54
subtitle: last weeks at internship
created: 2021-05-31
---

I will be leaving SendX on June 15th and joining deepsource on June 21st. The next two weeks, I will be wrapping up any and all work that's currenlty on my plate and handing off my function to the rest of the team by making process documents.

Infrastructure at both companies is starkly different.

At SendX, the infrastructure consists of AWS EC2 instances of various sizes. Manual intervention is needed to create, migrate or terminate any instances and the database often has to be configured accordingly to reflect any changes made. We don't have a staging environment and code is directly deployed to production using Ansible. It's less SRE/DevOps work but more SysAdmin work. Except for setting up monitoring and logging, a major chunk recurring work is manual in nature. Provisioning new IPs, migrating older machines to newer machines, emptying disk when it was filling up too fast (yes, I'm aware log rotation is a thing), etc etc. The reason for this is two-fold. First to reduce infrastructure cost and second to get the most out of the hardware we're using. To facilitate both, there is a higher focus on optimizing code and making it as efficient as possible than to bring up new infrastructure.

I have yet to see deepsource's infra, but I know that it utilizes Containers and Kubernetes. It is a primary reason for my interest in the role. I wanted to understand how containers are used to orchestrate infrastructure at scale, how CI/CD pipelines are setup and maintained and debugging niche production issues that are bound to pop up as a result of the inherent complexity of interaction between various microservices. I will talk more about the infra once I am familiar with it and have obtained permission to talk about it.

It's not the most articulate dev log I've written and I'll be the first to agree, but I'm trying to stay more consistent, so I can accept some sacrifice in quality.
