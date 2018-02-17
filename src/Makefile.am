bin_PROGRAMS = ac

ac_SOURCES = main.cpp

noinst_HEADERS = main.h

INCLUDES = -I../

SUBDIRS = templates base command parser

ac_LDADD = parser/libparser.a command/libcommand.a base/libbase.a @MAC_LIBS@ @AC_LD_FLAGS@
