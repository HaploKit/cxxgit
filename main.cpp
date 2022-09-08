#include <iostream>
#include <string>
#include <array>
#include <regex>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <cstring>
#include <thread>
#include <mutex>
#include <time.h>
#include <filesystem>
#include <cstdlib> // random number

#include <stdlib.h>
#include <zlib.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/////////
#include "bseq.h"
#include "kseq.h"

using namespace std;

// KSEQ_INIT(gzFile, gzread)
#define CHUNK_SIZE 200000000
// compile on wachbach
// g++ *.cpp -std=c++14 -o mainO2 -I../include -O2;timef ./mainO2 /prj/phasebook/centro/test/mhc/mhc_reads.GS.class

#define __KS_TYPE(type_t) \
	typedef struct __kstream_t { \
		int begin, end; \
		int is_eof:2, bufsize:30; \
		type_t f; \
		unsigned char *buf; \
	} kstream_t;

#define ks_eof(ks) ((ks)->is_eof && (ks)->begin >= (ks)->end)
#define ks_rewind(ks) ((ks)->is_eof = (ks)->begin = (ks)->end = 0)

#define __BOOKS \
typedef struct __Books \
{ \
   char  title[50];\
   int   book_id; \
   int begin,end;\
   int is_eof:3;\
} Book;

// KSEQ_INIT(gzFile, gzread)


int main()
{
    const char *read_file="reads.hifi.fq.gz";
    int arr[3]={4,3,6};
    cout << "Reading: " << read_file <<endl;
    cout << "Reading: " << *(arr+1) <<endl;
	bseq_file_t* hic_fn1 = bseq_open(read_file);

    __BOOKS;
    Book  book;
    book.book_id=44;
    int a=2;int b=3;
    cout<<"a="<<a<<";b="<<b<<endl;
    exit(0);

   

    std::vector<int> mapi = {1, 34, 98, 2};
    std::cout << mapi.back() << endl;
    mapi.pop_back();
    std::cout << mapi.back() << endl;
    std::cout << "src path:" << std::__fs::filesystem::current_path() << std::endl;

    exit(0);

    return 0;
}
