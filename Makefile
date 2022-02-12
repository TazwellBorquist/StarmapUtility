# StarmapUtility Makefile
# By Tazwell Borqiust
# Feburary 7 2022

# Defines
define NEWLINE

endef

# The Project's name and the end compiled program
PROJECTNAME=StarmapUtility

# Build directory
BLDDIR=build

# Directory to put object files in
OBJDIR=objs

# Source directory
SRCDIR=source

# C++ compiler
CC=g++

# Linker flags specifies the libraries to link against
LINKERFLAGS=

# Include Directories
INCLUDE_GLAD=-I/Users/tazwell/Desktop/c_workspace/glad/build/include
INCLUDES:=$(INCLUDE_GLAD)

# Library Directories
LINK_GLAD=-L/Users/tazwell/Desktop/c_workspace/glad/build
LINKEDLIBS:=$(LINK_GLAD)

# OBJS defines all of the unlinked object files

OBJS:=$(filter %.c %.cpp, $(shell find -L source))

# g++ with all of the options to not link, and everything it needs to link the objs
NOLINKCC:=$(CC) $(INCLUDES)
FULLCC:=$(CC) $(LINKERFLAGS) $(INCLUDES) $(LINKEDLIBS)

# Build Targets
.PHONY: default
default: $(addprefix $(BLDDIR)/, $(PROJECTNAME))

# partialcomp compiles all of the .cpp files in the 'source/' directory into the 'objs/' directory
define GENERATE_UNLINKED_TARGET
$(addprefix $$(OBJDIR)/, $(notdir $(1))).o: $(1)
	@ECHO Building: $(1)
	@$(if $(findstring .c, $(1)), gcc, $$(NOLINKCC)) -c $$^ -o $$@
endef

# calls partialcomp for each file to be compiled, creates .o files to be linked
$(foreach OBJ, $(OBJS), $(eval $(call GENERATE_UNLINKED_TARGET, $(OBJ))))

# links all of the object files in the 'objs/' folder
$(addprefix $(BLDDIR)/, $(PROJECTNAME)): $(addsuffix .o,$(addprefix $(OBJDIR)/, $(notdir $(OBJS))))
	@rm -f $(addprefix $(BLDDIR)/, $(PROJECTNAME))
	@ECHO Linking Everything: $(notdir $@)
	@$(FULLCC) $^ -o $@
	@ECHO Finished building project sucessfully

.PHONY: clean
clean:
	@ECHO removing $(PROJECTNAME) executable...
	@rm -f $(addprefix $(BLDDIR)/, $(PROJECTNAME))

.PHONY: nuke
nuke:
	@ECHO Removing all objects and executables...
	@rm -f $(addprefix $(BLDDIR)/, $(PROJECTNAME)) $(OBJDIR)/*

.PHONY: printfiles
printfiles:
	@ECHO List of files that are compiled:
	@$(foreach OBJ, $(OBJS),ECHO $(OBJ);)

.PHONY: gitaddsource
gitaddsource:
	git add source
