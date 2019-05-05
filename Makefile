# Filename        Razvan Preotu
# Date            May 1 2019
# Author          Razvan Preotu
# Email           rnp170130@utdallas.edu
# Course          CS 3377.502 Spring 2019
# Version         1.0
# Copyright 2019, All Rights Reserved
# 
# Description
#
# Makefile for project6

CXX = g++
CXXFLAGS = -Wall -I /scratch/perkins/include
LDFLAGS = -L /scratch/perkins/lib
LDLIBS = -l cdk -lcurses
EXEC = project6
SRCS = project6.cc matrix.cc readFile.cc
OBJS = $(SRCS:cc=o)
PROJECTNAME= Project6

.PHONY: all clean

all: $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC) *.P *~ \#*

$(EXEC):$(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LDFLAGS) $(LDLIBS)

backup: clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename 'pwd'))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
