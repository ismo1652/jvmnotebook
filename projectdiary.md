# Project Diary and Changelog #

**10/30/2007**

Nice little idioms in python;  This has very little to do with jvm languages (unless you are using jython), but I really like these non-imperative style idioms, little python one-liners.  Here is a good one for working with delimited text data:

```
Given a string, split based on the period delimiter and convert all the values to integer type, return
that array.

>>> a = "123.123.123"
>>> b = [int(i) for i in a.split(".")]
>>> b
[123, 123, 123]
>>>

>>> a = "123        \t   123   \t   123   \t   kjklff  \t   sdfsdf  "
>>> b = [i.strip() for i in a.split("\t")]
>>> b
['123', '123', '123', 'kjklff', 'sdfsdf']
>>>
```

```
Now with python's map functionality:

c = map(lambda line: line.strip(), a.split("\t"))
```

You can read more about functional programming in python, here:

http://python.genedrift.org/2007/11/01/functional-programming-in-python-using-filter-take-one/

**10/23/2007**


Made initial code imports of the jvm language notebook source.  So far, I have a couple of jython and jruby practical examples.  I suggest monitoring the subversion source which is linked in the project tabs above.  There you should be able to check out the latest jruby, jython, scala or abcl examples.