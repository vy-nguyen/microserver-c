#!/bin/bash

srcdir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
nreqt=${1:-100000}
curr=${2:-100}

ab -n $nreqt -c $curr -k http://localhost:8000/test/get
