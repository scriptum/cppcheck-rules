all: rules.xml
	../cppcheck/cppcheck -q -j16 --rule-file=rules.xml --template=gcc --std=posix tests

rules.xml:rules.in gen_rules.py
	python gen_rules.py < $< > $@
