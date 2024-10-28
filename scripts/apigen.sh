#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC=${SCRIPT_DIR}/../src/specs

pushd .
cd $SRC
openapi-generator-cli generate -i main-api.yaml -g cpp-pistache-server -o .
popd
