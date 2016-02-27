#!/bin/bash

sms=$1
decoded=$sms.utf8

delim=$(grep -an ^$ "$sms" | cut -d: -f1)
let content=$delim+1
encoding=$(grep -a "^Alphabet: " "$sms" | sed s/.*:\ //)
[ -z "$encoding" ] && encoding=UCS2

{
	head -$delim "$sms"
	tail -n+$content "$sms" | recode -f $encoding..UTF8
} > "$decoded"
