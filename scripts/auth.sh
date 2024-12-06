#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)" 
. ${SCRIPT_DIR}/common.sh

curl -H "$JWT" -H "$JSON_HDR" -X POST -d @$JSON_DIR/statops.json ${EndPoint}/auth/setcounter

curl -H "$JWT" -H "$JSON_HDR" -X POST -d @$JSON_DIR/item-id-array.json ${EndPoint}/auth/counter

