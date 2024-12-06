#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
. ${SCRIPT_DIR}/common.sh

nreqt=${1:-100000}
curr=${2:-100}
content="application/json"

ab -n $nreqt -c $curr -k -p $JSON_DIR/tagattr.json -T "$content" ${EndPoint}/test/setcounter

ab -n $nreqt -c $curr -k -T "$content" -p $JSON_DIR/statops.json -H "${JWT}" ${EndPoint}/auth/setcounter
