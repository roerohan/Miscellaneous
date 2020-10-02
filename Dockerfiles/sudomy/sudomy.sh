#!/bin/bash

# USAGE: ./sudomy.sh -d hackerone.com
# This will use the docker container

PWD="$HOME/Software/sudomy"

NEW_PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/lib/sudomy:/usr/lib/sudomy/lib/bin"

docker rm sudomy 2>/dev/null

docker run \
	-v "$PWD/output:/usr/lib/sudomy/output" \
	-v "$PWD/sudomy.api:/usr/lib/sudomy/sudomy.api" \
	-e "PATH=$NEW_PATH" \
	-it --name sudomy \
	screetsec/sudomy:v1.1.8 "$@"

