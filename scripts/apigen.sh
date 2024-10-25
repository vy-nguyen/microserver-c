#!/bin/bash

SRC=src/specs
openapi-generator-cli generate -i $SRC/rest.yaml -g cpp-pistache-server -o $SRC
