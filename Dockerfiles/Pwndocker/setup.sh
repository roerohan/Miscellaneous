# https://github.com/skysider/pwndocker

docker run -d \
	--rm \
	-h ${ctf_name} \
	--name ${ctf_name} \
	-v $(pwd)/${ctf_name}:/ctf/work \
	-p 23946:23946 \
	--cap-add=SYS_PTRACE \
	skysider/pwndocker

docker exec -it ${ctf_name} /bin/bash

