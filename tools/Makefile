include ../.makefile-header

CCFLAGSLOCAL = -I../lib/include
LFLAGSLOCAL = -L../lib -lsoap -lexm -lgridg -lpthread -lm  

####### Files

HEADERS =       share.h
SOURCES =	share.c bdrylayer.c normalshock.c shearlayer.c obliqueshock.c inlet.c inletgeom.c injector.c compressionfan.c cathode.c ringleb.c tauvt.c calc.c tecgrid2D.c tecgrid3D.c mpitest.c average.c equilairplasma.c soap.c thermionic.c
OBJECTS =	share.o bdrylayer.o normalshock.o shearlayer.o obliqueshock.o inlet.o inletgeom.o injector.o compressionfan.o cathode.o ringleb.o tauvt.o calc.o tecgrid2D.o tecgrid3D.o mpitest.o average.o equilairplasma.o soap.o thermionic.o
TARGETS  =	bdrylayer normalshock shearlayer obliqueshock inlet inletgeom injector compressionfan cathode ringleb tauvt openmptest calc tecgrid2D tecgrid3D mpitest average equilairplasma soap thermionic

####### Build rules

all: bdrylayer normalshock shearlayer obliqueshock inlet injector inletgeom compressionfan cathode ringleb tauvt openmptest calc tecgrid2D tecgrid3D mpitest average equilairplasma soap thermionic

tecgrid2D: tecgrid2D.o 
	$(L) tecgrid2D.o -o tecgrid2D $(LFLAGS) $(LFLAGSLOCAL)

tecgrid3D: tecgrid3D.o 
	$(L) tecgrid3D.o -o tecgrid3D $(LFLAGS) $(LFLAGSLOCAL)

calc: calc.o
	$(L) calc.o -o calc $(LFLAGS) $(LFLAGSLOCAL)

bdrylayer: share.o bdrylayer.o
	$(L) share.o bdrylayer.o -o bdrylayer $(LFLAGS) $(LFLAGSLOCAL)

normalshock: share.o normalshock.o
	$(L) share.o normalshock.o -o normalshock $(LFLAGS) $(LFLAGSLOCAL)

shearlayer: share.o shearlayer.o
	$(L) share.o shearlayer.o -o shearlayer $(LFLAGS) $(LFLAGSLOCAL)

obliqueshock: share.o obliqueshock.o
	$(L) share.o obliqueshock.o -o obliqueshock $(LFLAGS) $(LFLAGSLOCAL)

inlet: share.o inlet.o
	$(L) share.o inlet.o -o inlet $(LFLAGS) $(LFLAGSLOCAL)

inletgeom: share.o inletgeom.o
	$(L) share.o inletgeom.o -o inletgeom $(LFLAGS) $(LFLAGSLOCAL)

injector: share.o injector.o
	$(L) share.o injector.o -o injector $(LFLAGS) $(LFLAGSLOCAL)

compressionfan: share.o compressionfan.o
	$(L) share.o compressionfan.o -o compressionfan $(LFLAGS) $(LFLAGSLOCAL)

ringleb: ringleb.o
	$(L) ringleb.o -o ringleb $(LFLAGS) $(LFLAGSLOCAL)

tauvt: tauvt.o
	$(L) tauvt.o -o tauvt $(LFLAGS) $(LFLAGSLOCAL)

cathode: cathode.o 
	$(L) cathode.o -o cathode $(LFLAGS) $(LFLAGSLOCAL)

mpitest: mpitest.o 
	$(L) mpitest.o -o mpitest $(LFLAGS) $(LFLAGSLOCAL)

openmptest: 
	$(CC) -c -fopenmp $(CFLAGS) openmptest.c
	$(L) -fopenmp openmptest.o -o openmptest $(LFLAGS) $(LFLAGSLOCAL) 

average: average.o
	$(L) average.o -o average $(LFLAGS) $(LFLAGSLOCAL)

equilairplasma: equilairplasma.o
	$(L) equilairplasma.o -o equilairplasma $(LFLAGS) $(LFLAGSLOCAL)

soap: soap.o
	$(L) soap.o -o soap $(LFLAGS) $(LFLAGSLOCAL)
	 
thermionic: thermionic.o
	$(L) thermionic.o -o thermionic $(LFLAGS) $(LFLAGSLOCAL)

cleanall: clean
	(rm -f centveldist.plt eqchemfinal.plt nozzlecont.plt rocketsum.out subnozzlecont.plt ringleb.init ringleb.grid ringleb.dat)

# DO NOT DELETE THIS LINE -- make depend depends on it.
