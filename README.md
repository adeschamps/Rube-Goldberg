# Rube-Goldberg #

Preposterously complex code to do simple things, created for a contest between friends.

## increment ##

Why use the increment operator when you can convert an int to a string, query Wolfram Alpha for the next number, then parse the webpage?

demonstration.cxx will print numbers from 0 to 20.
As an added benefit of making system calls, if you hit Ctrl C, it'll interrupt the child process and the parent will just make another call!