#!/bin/bash

server=silo.cs.indiana.edu
git add -A :/ &> /dev/null
git commit -m "automated commit for testing"  &> /dev/null
git push origin master &> /dev/null

ssh hasahmed@$server << ENDHERE
    cd stringset
    git stash &> /dev/null
    git pull origin master &> /dev/null
    make grind &> grind.log
    make clean &> /dev/null
    cat grind.log
    exit
ENDHERE
