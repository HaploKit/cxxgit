CFLAGS=		-g -gdwarf-3 -fpermissive -Wall -O0 #-O2
CC=			g++
INCLUDES=	-I.
OBJS=		bseq.o 
PROG=		pstools
LIBS=		-lm -lz -lpthread #./libminimap2.a ./libz.a
CPPFLAGS=	-std=c++11
ifneq ($(asan),)
	CFLAGS+=-fsanitize=address
	LIBS+=-fsanitize=address
endif

.SUFFIXES:.c .o
.PHONY:all clean depend

.c.o:
		gcc -c $(CFLAGS)  $(INCLUDES) $< -o $@

all:$(PROG)

pstools: $(OBJS) main.cpp 
	g++ $(CFLAGS) $(CPPFLAGS) main.cpp  bseq.o   $(LIBS) -o $@
clean:
		rm -fr gmon.out *.o ext/*.o a.out $(PROG) *~  *.dSYM session*

# depend:
# 		(LC_ALL=C; export LC_ALL; makedepend -Y -- $(CFLAGS) $(DFLAGS) -- *.c)


bseq.o: bseq.h kseq.h
# htab.o: htab.cpp kthread.h yak-priv.h yak.h khashl.h
# kthread.o: kthread.h
# misc.o: yak-priv.h yak.h
# sys.o: sys.cpp yak-priv.h yak.h
# hic_mapping.o: htab.o hic_mapping.h kthread.h ketopt.h bseq.h yak-priv.h yak.h
# hic_completeness.o: htab.o hic_mapping.h kthread.h ketopt.h bseq.h yak-priv.h yak.h
# hic_switch_error.o: htab.o hic_mapping.h kthread.h ketopt.h bseq.h yak-priv.h yak.h
# hic_qv.o: kthread.h yak-priv.h yak.h bseq.h
# count.o: kthread.h yak-priv.h yak.h kseq.h

# main.o: main.cpp