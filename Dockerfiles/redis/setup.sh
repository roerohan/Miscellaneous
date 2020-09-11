#!/usr/bin/env bash

echo "Setting up redis, using ./redis.conf ..."

docker build -t redis .
docker run --name redis -d redis


