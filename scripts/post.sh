#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"  
. ${SCRIPT_DIR}/common.sh

curl -X POST ${EndPoint}/test/setcounter \
    -H "$JSON_HDR" \
    -d '{"tagUuidKey": "abcxyz", "tagRank": 0, "tagScore": 1000, "upVoteCount": 0, "downVoteCount": 0, "sharedCount": 0, "readCount": 0, "showCount": 0, "commentCount": 0, "followCount": 0, "bookMarkCount": 0, "blockedCount": 0}' | jq

curl ${EndPoint}/test/get | jq
