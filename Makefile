CHECK = ../cppcheck/cppcheck -q --rule-file=rules.xml --template=gcc --std=posix tests

all: rules.xml
	@$(CHECK) 2> .test_result && diff .test_result test_result; rm .test_result

rules.xml:rules.in gen_rules.py
	@python gen_rules.py < $< > $@

test_result: rules.xml
	@$(CHECK) 2> test_result