#!/bin/bash

echo please type a keyword
read val
grep -c $val myexamfile.txt
