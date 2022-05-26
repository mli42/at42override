#!/usr/bin/env bash

for i in {0..21}; do
  echo "Trying ${i}"
  (python -c "print (0x1337d00d - ${i})"; echo "echo '>>>>' ITS ME ${i} >&2") | /home/users/level03/level03 1>/dev/null
done
