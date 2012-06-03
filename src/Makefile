ObjSuf        = o
SrcSuf        = cxx
ExeSuf        =
DllSuf        = so
OutPutOpt     = -o $(BinDir)/
SrcDir	      = .
ObjDir        = ./obj
BinDir	      = ../bin
IncludeDir    = ../include


ROOTCONFIG   := root-config
ROOTCFLAGS   := $(shell $(ROOTCONFIG) --cflags)
ROOTLDFLAGS  := $(shell $(ROOTCONFIG) --ldflags)
ROOTLIBS     := $(shell $(ROOTCONFIG) --libs)
ROOTGLIBS    := $(shell $(ROOTCONFIG) --glibs)
#HASTHREAD    := no # $(shell $(ROOTCONFIG) --has-thread)

# Linux with egcs, gcc 2.9x, gcc 3.x (>= RedHat 5.2)
CXX           = g++
CXXFLAGS      = -g -Wall -fPIC -Wno-deprecated # use -O for otimized code, but not use when debugging !!! #use -g for debugging 
LD            = g++
LDFLAGS       = -O
SOFLAGS       = -shared

CXXFLAGS     += $(ROOTCFLAGS)
LDFLAGS      += $(ROOTLDFLAGS)
LIBS          = $(ROOTLIBS) $(SYSLIBS)
GLIBS         = $(ROOTGLIBS) $(SYSLIBS)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf)
.$(SrcSuf).$(ObjSuf) :
	$(CXX) $(CXXFLAGS) -o $@ -I$(IncludeDir) -c $(SrcDir)/$<

PLOTFROMFILEO       = plotFromFile.$(ObjSuf)
PLOTFROMFILES       = plotFromFile.$(SrcSuf)

MERGEDATA        = mergeData$(ExeSuf)
MERGEDATAO       = mergeData.$(ObjSuf)
MERGEDATAS       = mergeData.$(SrcSuf)

DIJETCS        = dijetcs$(ExeSuf)
DIJETCSO       = dijetcs.$(ObjSuf)
DIJETCSS       = dijetcs.$(SrcSuf)

DIJETALLCS        = dijetAllCS$(ExeSuf)
DIJETALLCSO       = dijetAllCS.$(ObjSuf)
DIJETALLCSS       = dijetAllCS.$(SrcSuf)


DIJETUUCS      = dijetUUcs$(ExeSuf)
DIJETUUCSO     = dijetUUcs.$(ObjSuf)
DIJETUUCSS     = dijetUUcs.$(SrcSuf)

DIJETDDCS      = dijetDDcs$(ExeSuf)
DIJETDDCSO     = dijetDDcs.$(ObjSuf)
DIJETDDCSS     = dijetDDcs.$(SrcSuf)

DIJETSSCS      = dijetSScs$(ExeSuf)
DIJETSSCSO     = dijetSScs.$(ObjSuf)
DIJETSSCSS     = dijetSScs.$(SrcSuf)

DIJETLIGHTCS      = dijetLightCS$(ExeSuf)
DIJETLIGHTCSO     = dijetLightCS.$(ObjSuf)
DIJETLIGHTCSS     = dijetLightCS.$(SrcSuf)

DIJETBBCS      = dijetBBcs$(ExeSuf)
DIJETBBCSO     = dijetBBcs.$(ObjSuf)
DIJETBBCSS     = dijetBBcs.$(SrcSuf)

HIGGSINCCS     = higgsIncCS$(ExeSuf)
HIGGSINCCSO    = higgsIncCS.$(ObjSuf)
HIGGSINCCSS    = higgsIncCS.$(SrcSuf)

HIGGSMKMR     = higgsM_KMR$(ExeSuf)
HIGGSMKMRO    = higgsM_KMR.$(ObjSuf)
HIGGSMKMRS    = higgsM_KMR.$(SrcSuf)

PROGRAMS 	= $(DIJETCS) $(DIJETALLCS) $(DIJETUUCS) $(DIJETDDCS) $(DIJETSSCS) $(DIJETBBCS) $(DIJETLIGHTCS) $(HIGGSINCCS) $(HIGGSMKMR) $(MERGEDATA)

all:$(PROGRAMS)		

$(DIJETCS): $(DIJETCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(DIJETALLCS): $(DIJETALLCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(DIJETUUCS): $(DIJETUUCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(DIJETDDCS): $(DIJETDDCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(DIJETSSCS): $(DIJETSSCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(DIJETLIGHTCS): $(DIJETLIGHTCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"


$(DIJETBBCS): $(DIJETBBCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(HIGGSINCCS): $(HIGGSINCCSO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(HIGGSMKMR): $(HIGGSMKMRO) $(PLOTFROMFILEO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(MERGEDATA): $(MERGEDATAO)
	$(LD) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
	@echo "$@ done"

$(DIJETCSO):$(DIJETCSS)
$(DIJETBBCSO):$(DIJETBBCSS)
$(HIGGSINCCSO):$(HIGGSINCCSS)
$(HIGGSMKMRO):$(HIGGSMKMRS)
$(PLOTFROMFILEO):$(PLOTFROMFILES)
$(MERGEDATAO):$(MERGEDATAS)

clean:
	@rm -f $(SrcDir)/*.$(ObjSuf)