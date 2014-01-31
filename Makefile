CHECK = ../cppcheck/cppcheck -q --rule-file=rules-c.xml --template=gcc --std=posix tests

all: rules.xml
	@$(CHECK) 2> .test_result && diff .test_result test_result; rm .test_result

rules-c.xml:rules.in rules-c.in gen_rules.py
	cat rules.in rules-c.in | @python gen_rules.py > $@

rules-cpp.xml:rules.in rules-cpp.in gen_rules.py
	cat rules.in rules-cpp.in | @python gen_rules.py  > $@

test_result: rules-c.xml rules-cpp.xml
	@$(CHECK) 2> test_result
