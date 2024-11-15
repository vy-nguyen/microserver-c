#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC=${SCRIPT_DIR}/../src/specs

pushd .
cd $SRC
pwd
openapi-generator-cli generate -i ./main-api.yaml -g cpp-pistache-server -o .
find api -type f -name '*.h' -exec sed -i 's/private:/protected:/g' {} +

popd
