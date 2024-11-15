#!/bin/bash

curl -X POST http://localhost:8000/public/setcounter \
    -H "Content-Type: application/json" \
    -d '{"tagUuidKey": "abcxyz", "tagRank": 0, "tagScore": 1000, "upVoteCount": 0, "downVoteCount": 0, "sharedCount": 0, "readCount": 0, "showCount": 0, "commentCount": 0, "followCount": 0, "bookMarkCount": 0, "blockedCount": 0}'

