#
# Berlin Brown
#
# $Id: Makefile,v 1.7 2004/05/15 19:33:32 bigbinc Exp $
#

TOPDIR          = $(shell /bin/pwd)

VERS=0.0.5

all: backup 

backup:
	cd .. && tar cf - spiritroom | gzip > spiritroom-$(VERS).tar.gz

clean:
	@echo "==## Cleaning ##=========================="
	$(TOPDIR)/scripts/rm_squid
	@echo "==## done ##=============================="

