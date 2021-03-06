PAPI_SRCDIR = $(PWD)	
CFLAGS += $(EXTRA_CFLAGS)
SOURCES	  = $(MISCSRCS) papi.c papi_internal.c papi_hl.c extras.c multiplex.c \
    papi_fwrappers.c papi_fwrappers_.c papi_fwrappers__.c upper_PAPI_FWRAPPERS.c \
    threads.c cpus.c $(MEMSUBSTR)-memory.c $(SUBSTR).c papi_preset.c \
    papi_vector.c papi_memory.c papi_user_events.c $(COMPSRCS)
OBJECTS = $(MISCOBJS) papi.o papi_internal.o papi_hl.o extras.o multiplex.o \
    papi_fwrappers.o papi_fwrappers_.o papi_fwrappers__.o upper_PAPI_FWRAPPERS.o \
    threads.o cpus.o $(MEMSUBSTR)-memory.o $(SUBSTR).o papi_preset.o \
    papi_vector.o papi_memory.o papi_user_events.o $(COMPOBJS) $(MISCOBJS)
HEADERS   = $(MISCHDRS) papi.h papi_internal.h papiStdEventDefs.h $(SUBSTR).h \
    papi_preset.h threads.h cpus.h papi_vector.h \
    papi_memory.h config.h papi_user_events.h \
    extras.h multiplex.h papi_hl.h \
    papi_common_strings.h components_config.h \
    papi_events_table.h
LIBCFLAGS += -I. $(CFLAGS) -DSUBSTRATE=\"$(SUBSTR).h\" 
FHEADERS = fpapi.h f77papi.h f90papi.h

all: $(SHOW_CONF) $(LIBS) utils tests
.PHONY : all test fulltest tests testlib utils ctests ftests comp_tests null

include $(COMPONENT_RULES)

showconf:
		@echo "Host architecture: $(DESCR)";
		@echo "Host substrate   : $(SUBSTR).c"; 
		@echo "Installation DESTDIR: $(DESTDIR)"; 
		@echo "Installation PREFIX : $(PREFIX)"; 
		@echo "Installation EPREFIX: $(EPREFIX)"; 
		@echo "Installation INCDIR : $(INCDIR)"; 
		@echo "Installation LIBDIR : $(LIBDIR)"; 
		@echo "Installation BINDIR : $(BINDIR)"; 
		@echo "Installation MANDIR : $(MANDIR)"; 
		@echo "Installation DOCDIR : $(DOCDIR)"; 
		@echo "Installation DATADIR: $(DATADIR)"; 
		@echo

show_bgp_conf:
	@echo;
	@echo "BG/P System Path   :  $(BGP_SYSDIR)";
	@echo "BG/P Install Path  :  $(BGP_INSTALLDIR)";
	@echo "BG/P GNU/Linux Path:  $(BGP_GNU_LINUX_PATH)";
	@echo "BG/P ARCH Path     :  $(BGP_ARCH_PATH)";
	@echo "BG/P Runtime Path  :  $(BGP_RUNTIME_PATH)";
	@echo

static: $(LIBRARY)

shared: $(SHLIB)

$(LIBRARY): $(OBJECTS)
	rm -f $(LIBRARY)
	$(AR) $(ARG64) rv $(LIBRARY) $(OBJECTS)

$(SHLIB): $(HEADERS) $(SOURCES) $(SHLIBOBJS) 
	@if test "$(SHLIB)" != "libpapi.so" ; then \
	    rm -f $(SHLIB) libpapi.so; \
	fi
	$(CC_SHR) $(LIBCFLAGS) $(OPTFLAGS) $(SOURCES) $(SHLIBOBJS) -o $@ $(LDFLAGS) $(SHLIBDEPS) 
	@if test "$(POST_BUILD)" != "" ; then \
		-$(POST_BUILD) ; \
	fi
	@if test "$(SHLIB)" != "libpapi.so" ; then \
		ln -sf $(SHLIB) libpapi.so; \
	fi
							
papi_fwrappers_.c: papi_fwrappers.c $(HEADERS)
	$(CPP) -DFORTRANUNDERSCORE papi_fwrappers.c > papi_fwrappers_.c 

papi_fwrappers__.c: papi_fwrappers.c $(HEADERS)
	$(CPP) -DFORTRANDOUBLEUNDERSCORE papi_fwrappers.c > papi_fwrappers__.c

upper_PAPI_FWRAPPERS.c: papi_fwrappers.c $(HEADERS)
	$(CPP) -DFORTRANCAPS papi_fwrappers.c > upper_PAPI_FWRAPPERS.c

papi_fwrappers.o: papi_fwrappers.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_fwrappers.c -o papi_fwrappers.o

papi_fwrappers_.o: papi_fwrappers_.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_fwrappers_.c -o papi_fwrappers_.o 

papi_fwrappers__.o: papi_fwrappers__.c $(HEADERS) 
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_fwrappers__.c -o papi_fwrappers__.o

upper_PAPI_FWRAPPERS.o: upper_PAPI_FWRAPPERS.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c upper_PAPI_FWRAPPERS.c -o upper_PAPI_FWRAPPERS.o

papi.o: papi.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi.c -o papi.o 

papi_internal.o: papi_internal.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_internal.c -o papi_internal.o 

threads.o: threads.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c threads.c -o threads.o 

cpus.o: cpus.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c cpus.c -o cpus.o 

papi_hl.o: papi_hl.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_hl.c -o papi_hl.o 

$(MEMSUBSTR)-memory.o: $(MEMSUBSTR)-memory.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c $(MEMSUBSTR)-memory.c -o $(MEMSUBSTR)-memory.o

linux-timer.o: linux-timer.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c linux-timer.c -o linux-timer.o

linux-common.o: linux-common.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c linux-common.c -o linux-common.o

extras.o: extras.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c extras.c -o extras.o 

papi_memory.o: papi_memory.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_memory.c -o papi_memory.o

papi_vector.o: papi_vector.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_vector.c -o papi_vector.o

papi_preset.o: papi_preset.c $(HEADERS) $(PAPI_EVENTS_TABLE)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_preset.c -o papi_preset.o 

multiplex.o: multiplex.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c multiplex.c -o multiplex.o 

$(SUBSTR).o: $(SUBSTR).c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c $(SUBSTR).c -o $(SUBSTR).o 

x86_cpuid_info.o: x86_cpuid_info.c x86_cpuid_info.h $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c x86_cpuid_info.c -o x86_cpuid_info.o

sys_perf_event_open.o: sys_perf_event_open.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c sys_perf_event_open.c -o sys_perf_event_open.o

$(PAPI_EVENTS_TABLE):	$(PAPI_EVENTS_CSV) papi_events_table.sh
	sh papi_events_table.sh $(PAPI_EVENTS_CSV) > $@

$(ARCH_EVENTS)_map.o: $(ARCH_EVENTS)_map.c  $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c $(ARCH_EVENTS)_map.c -o $(ARCH_EVENTS)_map.o

papi_user_events.o: papi_user_events.c $(HEADERS)
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c papi_user_events.c -o papi_user_events.o

# Required for BGP
.SUFFIXES: .rts.o
.c.rts.o:
	$(CC) $(CFLAGS) -c $< -o $@

linux-bgp-preset-events.o: linux-bgp-preset-events.c  $(HEADERS)
	$(CC) $(LIBCFLAGS) -DSUBSTRATE=\"$(SUBSTR).h\" -DCOMP_VECTOR=_bgp_vectors $(OPTFLAGS) -c linux-bgp-preset-events.c -o linux-bgp-preset-events.o

bgp_tests:$(LIBRARY) null
	$(SETPATH) cd ctests/bgp; $(MAKE) CC="$(CC)" CC_R="$(CC_R)" CFLAGS="-I.. -I../.. $(CFLAGS)" TOPTFLAGS="$(TOPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY="../$(LINKLIB)" bgp_tests
 
#Required for freebsd
#freebsd-memory.o: freebsd-memory.c $(HEADERS)
#	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map.o: freebsd/map.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-unknown.o: freebsd/map-unknown.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-p6.o: freebsd/map-p6.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-p6-m.o: freebsd/map-p6-m.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-p6-3.o: freebsd/map-p6-3.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-p6-2.o: freebsd/map-p6-2.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-p6-c.o: freebsd/map-p6-c.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-k7.o: freebsd/map-k7.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-k8.o: freebsd/map-k8.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-p4.o: freebsd/map-p4.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-atom.o: freebsd/map-atom.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-core.o: freebsd/map-core.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-core2.o: freebsd/map-core2.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-core2-extreme.o: freebsd/map-core2-extreme.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-i7.o: freebsd/map-i7.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@

freebsd/map-westmere.o: freebsd/map-westmere.c $(HEADERS)
	$(CC) $(LIBCFLAGS) -c $< -o $@                                          

# So we already build this for $SUBSTRATE
#freebsd.o: freebsd.c $(HEADERS)
#	$(CC) $(LIBCFLAGS) -c $< -o $@

test: ctests
	$(SETPATH) ctests/zero

fulltest: tests
	sh run_tests.sh

tests: $(TESTS) 

testlib:
	$(SETPATH) cd testlib;  $(MAKE) CC="$(CC)" CC_R="$(CC_R)" CFLAGS="-I.. $(CFLAGS)" OPTFLAGS="$(OPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY="$(LINKLIB)"

utils: $(LIBS)
	$(SETPATH) cd utils; $(MAKE) CC="$(CC)" CC_R="$(CC_R)" CFLAGS="-I.. $(CFLAGS)" OPTFLAGS="$(OPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY="$(LINKLIB)" $(UTIL_TARGETS)

ctests: $(LIBS) testlib
	$(SETPATH) cd ctests; $(MAKE) CC="$(CC)" CC_R="$(CC_R)" CFLAGS="-I.. $(CFLAGS) $(DEBUGFLAGS)" TOPTFLAGS="$(TOPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LDL="$(LDL)" LIBRARY="$(LINKLIB)" $(CTEST_TARGETS)

ftests: $(LIBS) testlib
	$(SETPATH) cd ftests; $(MAKE) CC="$(CC)" CC_R="$(CC_R)" F77="$(F77)" CFLAGS="-I.. $(CFLAGS)" TOPTFLAGS="$(TOPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" FFLAGS="-I.. $(FFLAGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY="$(LINKLIB)" $(FTEST_TARGETS)

# compile tests added to components
comp_tests:	$(LIBS) testlib
ifneq (${COMPONENTS},)
		@for comp in ${COMPONENTS} ; do \
			$$comp_tests: $(LIBS) testlib null ; \
			$(SETPATH) cd components/$$comp/tests ; $(MAKE) CC="$(CC)" CC_R="$(CC_R)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS) $(STATIC)" ; \
			$(SETPATH) cd ../../.. ; done 
endif

clean: native_clean comp_tests_clean
	-rm -rf $(LIBRARY) $(SHLIB) libpapi.so $(OBJECTS) core rii_files genpapifdef *~ so_locations papi_fwrappers_.c papi_fwrappers__.c upper_PAPI_FWRAPPERS.c 
	-cd ctests; $(MAKE) clean
	-cd ctests/bgp; $(MAKE) clean
	-cd ftests; $(MAKE) clean
	-cd testlib; $(MAKE) clean
	-cd utils;  $(MAKE) clean
	-cd ../doc; $(MAKE) clean

# Component tests cleaning
comp_tests_clean:
ifneq (${COMPONENTS},)
	@for comp in ${COMPONENTS} ; do \
		cd components/$$comp/tests ; \
		$(MAKE) clean ; \
		cd ../../.. ; \
	done 
endif

clobber distclean: clean native_clobber
	-rm -f $(LIBRARY) $(SHLIB) $(EXTRALIBS) Makefile config.h libpapi.so components_config.h papi_events_table.h
	-cd utils;  $(MAKE) clean
	-rm -f config.log config.status f77papi.h f90papi.h fpapi.h

null:

dist: 
	$(MAKE) install-all PREFIX=`pwd`/papi-$(SUBSTR)
	tar cfv ./papi-$(SUBSTR).tar ./papi-$(SUBSTR)
	gzip ./papi-$(SUBSTR).tar
	rm -rf ./papi-$(SUBSTR)

install-all: install install-tests

install: install-lib install-man install-utils

install-lib: native_install
	@echo "Headers (INCDIR) being installed in: \"$(DESTDIR)$(INCDIR)\""; 
	-mkdir -p $(DESTDIR)$(INCDIR)
	-chmod go+rx $(DESTDIR)$(INCDIR)
	cp $(FHEADERS) papi.h papiStdEventDefs.h $(DESTDIR)$(INCDIR)
	cd $(DESTDIR)$(INCDIR); chmod go+r $(FHEADERS) papi.h papiStdEventDefs.h
	@echo "Libraries (LIBDIR) being installed in: \"$(DESTDIR)$(LIBDIR)\""; 
	-mkdir -p $(DESTDIR)$(LIBDIR)
	-chmod go+rx $(DESTDIR)$(LIBDIR)
	@if test -r $(LIBRARY) ; then \
	   cp $(LIBRARY) $(DESTDIR)$(LIBDIR); \
	   chmod go+r $(DESTDIR)$(LIBDIR)/$(LIBRARY); \
	fi
	@if test -r $(SHLIB) ; then \
		cp -p $(SHLIB) $(DESTDIR)$(LIBDIR)/libpapi.so.$(PAPIVER).$(PAPIREV).$(PAPIAGE).$(PAPIINC); \
		chmod go+r $(DESTDIR)$(LIBDIR)/libpapi.so.$(PAPIVER).$(PAPIREV).$(PAPIAGE).$(PAPIINC) ; \
		cd $(DESTDIR)$(LIBDIR); ln -sf libpapi.so.$(PAPIVER).$(PAPIREV).$(PAPIAGE).$(PAPIINC) libpapi.so.$(PAPIVER); \
		cd $(DESTDIR)$(LIBDIR); ln -sf libpapi.so.$(PAPIVER).$(PAPIREV).$(PAPIAGE).$(PAPIINC) libpapi.so; \
	fi

install-man:  
		cd ../man && $(MAKE) DOCDIR=$(DESTDIR)$(DOCDIR) MANDIR=$(DESTDIR)$(MANDIR) install; \

install-utils: 
	$(SETPATH) cd utils; $(MAKE) BINDIR="$(DESTDIR)$(BINDIR)" CC="$(CC)" CC_R="$(CC_R)" CFLAGS="-I.. $(CFLAGS)" TOPTFLAGS="$(TOPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY=$(LINKLIB) install
	
install-tests:
	$(SETPATH) cd ctests; $(MAKE) DATADIR="$(DESTDIR)$(DATADIR)" CC="$(CC)" CC_R="$(CC_R)" CFLAGS="-I.. $(CFLAGS)" TOPTFLAGS="$(TOPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY=$(LINKLIB) install
	$(SETPATH) cd ftests; $(MAKE) DATADIR="$(DESTDIR)$(DATADIR)" CC="$(CC)" CC_R="$(CC_R)" F77="$(F77)" CFLAGS="-I.. $(CFLAGS)" TOPTFLAGS="$(TOPTFLAGS)" SMPCFLGS="$(SMPCFLGS)" OMPCFLGS="$(OMPCFLGS)" FFLAGS="-I.. $(FFLAGS)" NOOPT="$(NOOPT)" LDFLAGS="$(LDFLAGS) $(STATIC)" LIBRARY=$(LINKLIB) install

#
# Dummy targets for configurations that do not also include a Rules file with targets
#
native_clean:

native_install:

native_clobber:
