include .env

cc = cc
source_directory = source
header_directory = include
build_directory = build/srfront
object_directory = $(build_directory)/object
compiler_flags = -std=c11 -Wall -Wpedantic -g -O1
includes = -I$(header_directory) -I$(LLVM)/include
linker_flags = -L$(LLVM)/lib -lclang -Wl,-rpath,$(LLVM)/lib

sources = $(wildcard $(source_directory)/*.c)
objects = $(patsubst $(source_directory)/%.c,$(object_directory)/%.o,$(sources))

define speaker
	@echo [make:$$PPID] $(1)
	@$(1)
endef

srfront: $(objects)
	$(call speaker,\
	$(cc) $(objects) -o $@ $(linker_flags))

$(objects): $(object_directory)/%.o: $(source_directory)/%.c $(wildcard $(header_directory)/*.h)
	mkdir -p $(object_directory)
	$(call speaker,\
	$(cc) $(compiler_flags) -c $< -o $@ $(includes))

.PHONY: clean remove
clean:
	@rm -rf build
remove: clean
	@rm -f srfront
