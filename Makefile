#----------------------------------------------------------------------------
#       Make Workspace
#
# 
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# ./mwc.pl -type make
#
#----------------------------------------------------------------------------


all: assignment3

depend: assignment3-depend

clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.assignment3 $(@)

.PHONY: assignment3
assignment3:
	@$(MAKE) -f Makefile.assignment3 all

.PHONY: assignment3-depend
assignment3-depend:
	@$(MAKE) -f Makefile.assignment3 depend

project_name_list:
	@echo assignment3
