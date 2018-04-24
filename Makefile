# Perry Lee
# pxl172630@utdallas.edu
# CS3377.002

CXX = g++
CXXFLAGS = -Wall
CPPFLAGS = -I/scratch/perkins/include

LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

PROJECTNAME = CS3377.Program6
EXECFILE = Program6

SRCS = program6.cc
OBJS = $(SRCS:cc=o)


all: $(EXECFILE)

clean:
	rm -f $(OBJS) *.d *~ \#* $(EXECFILE)

$(EXECFILE):	$(OBJS) 
	$(CXX) -o $(EXECFILE) $(LDFLAGS)  $(OBJS) $(LDLIBS)

backup:	clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!

# include the dependency files
-include $(SRCS:.cc=.d)
