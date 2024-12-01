#!/bin/bash

endpoint=http://localhost:8000

curl -H "Authorization: Bearer eyJhbGciOiJIUzUxMiJ9.eyJ1c2VyVXVpZCI6ImJiMjhiNjVhLWIyODgtNGQzNy05ZWQ2LTUxNTBhMmVhYzhmOSIsInN1YiI6IjE4MDAtbGludXgiLCJpc3MiOiJzZWFsIiwiaWF0IjoxNzMyNjY0Mzg0LCJleHAiOjE3MzMyNjkxODR9.zlhvCaccQb7uP3u0iL9yfL5RAx0MdmvTVhMf4HQh7RXiN3508Axibh2OI_Ize13xMacsBvrVCe5J3qUdfyvFpQ" -H "Content-Type: application/json" -X POST -d @statops.json ${endpoint}/auth/counter
