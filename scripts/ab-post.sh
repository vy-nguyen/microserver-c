#!/bin/bash

srcdir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
nreqt=${1:-100000}
curr=${2:-100}

ab -n $nreqt -c $curr -k -T 'application/json' -p $srcdir/tagattr.json http://localhost:8000/test/setcounter
