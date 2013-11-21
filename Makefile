all: rules.xml
	../cppcheck/cppcheck -q --rule-file=rules.xml --template=gcc --std=posix tests

rules.xml:rules.in gen_rules.py
	python gen_rules.py < $< > $@
