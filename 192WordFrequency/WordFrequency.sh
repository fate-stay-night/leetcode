#########################################################################
# File Name: WordFrequency.sh
# Author: zhang zheng
# E-mail: kezy-5566@163.com
# Created Time: Fri 07 Oct 2016 07:22:28 PM CST
# Word Frequency:
#	Write a bash script to calculate the freqency of each word in a 
#	text file words.txt.
#	For simplicity sake, you may assume:
#	* words.txt contains only lowercase characters and space ' ' characters.
#	* Each word must consist of lowercase characters only.
#	* Words are separated by one or more whitespace characters.
#	For example, assume that words.txt has the the following content:
#		the day is sunny the the
#		the sunny is is
#	Your script should output the following, sorted by descending 
#	frequency:
#		the 4
#		is 3
#		sunny 2
#		day 1
#	Note:
#	Don't worry about handing ties, it is guaranteed that each word's
#	frequency count is unique.
#########################################################################
#!/bin/bash
# Read from the file words.txt and output the word frequency list to stdout.
#sed "s/  */ /g" words.txt|tr " " "\n"|sort |uniq -c|sort -rn|awk '{print $2 " " $1}'
cat words.txt|tr "\n" " "|sed "s/  */ /g"|tr " " "\n"|sort|uniq -c| sort -rn|awk '{print $2 " " $1}'

