#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys

step = 0
tokenlist = None
print '<?xml version="1.0"?>'
for line in sys.stdin:
	line = line.strip("\n\r")
	if line.strip() == "" or line.strip()[:2] == "//":
		next
	ll = line.split() or [line]
	l = ll[0].strip()
	if l in ["style", "warning", "performance", "portability", "information", "error"]:
		severity = l
		step = 0
		tokenlist = None
		if len(ll) > 1:
			tokenlist = ll[1]
	else:
		step += 1
		if step == 2:
			summary = line
			print "<rule>"
			if tokenlist:
				print "\t<tokenlist>%s</tokenlist>" % tokenlist
			print "\t<pattern>%s</pattern>" % pattern
			print "\t<message>"
			print "\t\t<severity>%s</severity>" % severity
			if summary == "none":
				print "\t\t<summary/>"
			else:
				print "\t\t<summary>%s</summary>" % summary
			print "\t</message>"
			print "</rule>"
		else:
			pattern = line
