#!/bin/bash

server=silo.cs.indiana.edu
git add -A :/
git commit -m "automated commit for testing" # 2> /dev/null
git push origin master #2> /dev/null

ssh hasahmed@$server << ENDHERE
    cd stringset
    git pull origin master #2> /dev/null
    make grind 2> grind.log
    make clean
    cat grind.log
    exit
ENDHERE
