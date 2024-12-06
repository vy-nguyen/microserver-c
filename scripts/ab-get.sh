#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. ${SCRIPT_DIR}/common.sh

nreqt=${1:-100000}
curr=${2:-100}

ab -n $nreqt -c $curr -k ${EndPoint}/test/get
