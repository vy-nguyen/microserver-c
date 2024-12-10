#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC=${SCRIPT_DIR}/../src/specs

specfile=./main-api.yaml
pydest=$SRC/../../tests/unit/py/openapi

pushd .
cd $SRC
pwd

mkdir =p $pydest

echo "Generating C++ server code..."
openapi-generator-cli generate -i $specfile -g cpp-pistache-server -o .
find api -type f -name '*.h' -exec sed -i 's/private:/protected:/g' {} +

echo "Generating Python client code..."
openapi-generator-cli generate -i $specfile -g python -o $pydest

popd
