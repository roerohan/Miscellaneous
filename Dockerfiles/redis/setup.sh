#!/usr/bin/env bash

echo "Setting up redis, using ./redis.conf ..."

docker build -t redis .
docker run --name redis -p 6379:6379 -d redis


