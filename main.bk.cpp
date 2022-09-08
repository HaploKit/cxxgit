#include <iostream>
#include <string>
#include <array>
#include <regex>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <cstring>
 #include<stdlib.h>
#include <thread>
#include <mutex>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/bind.hpp>
#include <time.h>
#include <cstdlib> // random number

#include <seqan/sequence.h>
#include <seqan/stream.h>
#include <seqan/seeds.h>
#include <seqan/seq_io.h>

using namespace std;
using namespace seqan;

#include "seed.h"

#define loop10(T) T T T T T T T T T T

// compile on wachbach
// g++ *.cpp -std=c++14 -o mainO2 -I../include -O2;timef ./mainO2 /prj/phasebook/centro/test/mhc/mhc_reads.GS.class

void get_kmer2type(std::unordered_map<std::string, std::array<uint16_t, 4>> &kmer2type)
{
    //   std::unordered_map<std::string, std::array<uint16_t,4>> kmer2type;
    kmer2type["ATCG"] = {2, 1, 2, 5};
    kmer2type["TTCG"] = {20, 1, 2, 5};
    //  std::unordered_map<std::string, std::array<uint16_t,4>> & kmer2type_ref = kmer2type;
    // return kmer2type_ref;
}
int maina1(int argc, char **argv)
{
    std::unordered_map<std::string, std::array<uint16_t, 4>> kmer2type;
    get_kmer2type(kmer2type);
    std::cout << "ref2:" << kmer2type["ATCG"][0] << std::endl;
    std::cout << "ref2:" << kmer2type["ATCG"].size() << std::endl;

    std::string aa = "ATCG";
    std::cout << "Oh:" << revcomp(aa) << std::endl;
    // std::cout<< "Oh:"<<jess(aa)<<std::endl;
    return 0;
}
std::mutex mt;

void addxx(int a, int b, std::vector<int> &vout)
{
    mt.lock(); // process e.g. 10 reads every time to avoid lock-unlock frequently
    vout.emplace_back(a + b);
    mt.unlock();
}
void addxx_hash(int a, int b, std::unordered_map<int, int> &vout)
{
    // mt.lock(); // process e.g. 10 reads every time to avoid lock-unlock frequently
    vout[a] = b;
    // mt.unlock();
}


int main()
{
    string file_path = __FILE__;
    // string dir_path = file_path.substr(0, file_path.rfind("\\"));
    cout<<file_path<<endl;
    // cout<<dir_path<<endl;

    std::vector<int> mapi = {1,34,98, 2};
    std::cout <<mapi.back()<<endl;
    mapi.pop_back();
    std::cout <<mapi.back()<<endl;

    exit(0);
    std::vector<int> mapi2;
    uint64_t qread_id=3;
    for (uint64_t i = qread_id+1;i<10;i++){
        cout<<"i="<<i<<std::endl;
    }
        cout<<"qread="<<qread_id<<std::endl;

    if(true){
    std::vector<int> & mapiref = mapi;
    mapi[1]=45;
    }
    std::cout <<mapi.size() <<" "<<mapi[1]<<std::endl;
    mapi.clear();
    mapi2.clear();
    exit(0);

    typedef Seed<Simple> TSeed;
    typedef SeedSet<TSeed> TSeedSet;

    TSeedSet seedSet;
    addSeed(seedSet, TSeed(0, 0, 3), Single());
    // addSeed(seedSet, TSeed(1, 1, 3), Single());
    // addSeed(seedSet, TSeed(2, 2, 3), Single());
    addSeed(seedSet, TSeed(4, 4, 3), Single());
    // addSeed(seedSet, TSeed(3, 3, 3), Single());
    // addSeed(seedSet, TSeed(4, 4, 3), Single());
    // addSeed(seedSet, TSeed(5, 5, 3), Single());
    // addSeed(seedSet, TSeed(6, 6, 3), Single());
    addSeed(seedSet, TSeed(80, 80, 3), Single());
    addSeed(seedSet, TSeed(30, 30, 3), Single());
    addSeed(seedSet, TSeed(60, 60, 3), Single());
    addSeed(seedSet, TSeed(62, 62, 3), Single());
    addSeed(seedSet, TSeed(63, 63, 3), Single());
    addSeed(seedSet, TSeed(70, 70, 3), Single());
    addSeed(seedSet, TSeed(120, 120, 3), Single());
    // addSeed(seedSet, TSeed(8, 8, 2), Single());

    String<TSeed> result;
    chainSeedsGlobally(result, seedSet, SparseChaining());
    for(int i = 0; i < length(result); i++){

    std::cout << result[i] << length(result) << std::endl;
    }
    exit(0);

    std::cout << "(" << beginPositionH(result[length(result) - 1]) << ", "
              << endPositionH(result[length(result) - 1]) << ", "
              << beginPositionV(result[length(result) - 1]) << ", "
              << endPositionV(result[length(result) - 1]) << ")" << std::endl;
    exit(0);

    int64_t qstart=3;
    int64_t qend=2;
    int64_t tstart=4;
    int64_t tend=6;
    int64_t num_nonconfict_shapmers=1;
    if ((tend - tstart < num_nonconfict_shapmers) or (qend - qstart < num_nonconfict_shapmers))
        std::cout<<"shit"<< std::endl;
    std::string ovlp_record;
    std::string a="aa";
    std::string b="bb";
    char ss='+';
    int yy=65;
    ovlp_record=a+"\t"+b+"\t"+"dd";
    ovlp_record=a+"\t"+std::to_string(ss)+"\t"+"dd";
    cout<<ovlp_record;


    std::cout << "Resulting seeds.\n";
    typedef Iterator<TSeedSet>::Type TIter;
    for (TIter it = begin(seedSet, Standard());
         it != end(seedSet, Standard()); ++it)
        std::cout << "(" << beginPositionH(*it) << ", " << endPositionH(*it)
                  << ", " << beginPositionV(*it) << ", " << endPositionV(*it)
                  << ", " << lowerDiagonal(*it) << ", " << upperDiagonal(*it)
                  << ")\n";

    return 0;
}

int mainqq()
{
    std::array<int64_t, 2> arr_read_pos;
    int64_t i = 322;
    arr_read_pos[0] = 22;
    arr_read_pos[1] = i * (-1);
    std::vector<int> mapi = {1, 2};
    std::vector<std::vector<int>> mapi2;
    mapi2.emplace_back(mapi);
    cout << mapi[0] << std::endl;
    cout << mapi2[0][0] << std::endl;

    // exit(1);
    std::vector<std::vector<std::pair<std::string, int64_t>>> qread_hapmers;
    std::vector<std::pair<std::string, int64_t>> qread_hapmers2;
    std::pair<std::string, int64_t> pp("ATGG", 10);
    // std::pair<std::string, int64_t> pp("TGCA",100);
    std::cout << pp.first << ' ' << pp.second << std::endl;
    // qread_hapmers2.emplace_back(pp);
    // std::vector<std::vector<int>> M;
    // qread_hapmers[0].emplace_back(pp);
    qread_hapmers2.emplace_back(std::make_pair("ATGG", 10));
    qread_hapmers2.emplace_back(std::make_pair("QQATGG", 100));
    for (auto &jt : qread_hapmers2)
    {
        std::cout << jt.first << "" << jt.second << std::endl;
    }
    qread_hapmers.emplace_back(qread_hapmers2);

    std::cout << qread_hapmers[0][0].first << std::endl;
    std::cout << qread_hapmers[0][0].second << std::endl;
    std::cout << qread_hapmers[0][1].first << std::endl;
    std::cout << qread_hapmers[0][1].second << std::endl;

    String<Dna> myDnaGenome = "TATACGCGRRR";
    String<Dna> gg = infix(myDnaGenome, 0, 8);
    std::string as = "TATACGCG";
    if (gg == as)
    {
        std::cout << "shit" << std::endl;
    }
    // exit(1);
    bool bo = false;
    bool bo2 = false;
    int sumbo = bo + bo + bo2;
    int ss = 45;
    ss *= -1;
    char bout = (bo ^ bo2) ? '-' : '+'; //^XOR运算符。规则：相同为0，相异为1
    std::cout << "boo:" << ss << std::endl;
    // std::cout << "boo:" <<sumbo << std::endl;
    // exit(1);

    std::array<int, 28> arrxx;
    std::vector<int> vout;
    std::unordered_map<int, int> hout;
    int t = 4;
    // loop10(vout.emplace_back(t);)
    // for (auto &it : vout)
    // {
    //     // std::cout << it << std::endl;
    // }

    // exit(1);
    std::thread tr[t];
    for (int x = 0; x < 10000; x++)
    {
        // int y =x;
        // std::cout << "random: "<< rand()%100<<std::endl;
        int y = rand() % 20;
        for (int i = 0; i < t; i++)
        {
            tr[i] = std::thread(boost::bind(addxx, x, y, boost::ref(vout)));
            // tr[i] = std::thread(std::bind(addxx_hash, y, x, std::ref(hout)));
        }
        for (int i = 0; i < t; i++)
        {
            tr[i].join(); // wait for the end of processing threads
        }
    }
    for (auto &it : hout)
    {
        std::cout << it.first << "\t" << it.second << std::endl;
    }
    // exit(1);

    typedef Seed<Simple> TSeed;
    typedef SeedSet<TSeed> TSeedSet;

    TSeedSet seedSet;
    addSeed(seedSet, TSeed(0, 0, 2), Single());
    addSeed(seedSet, TSeed(3, 5, 2), Single());
    addSeed(seedSet, TSeed(4, 2, 3), Single());
    addSeed(seedSet, TSeed(9, 9, 2), Single());

    String<TSeed> result;
    chainSeedsGlobally(result, seedSet, SparseChaining());
    std::cout << result[0] << length(result) << std::endl;
    std::cout << result[1] << length(result) << std::endl;
    std::cout << result[2] << length(result) << std::endl;
    // std::cout << result[3] << length(result)<<std::endl;
    exit(1);

    std::cout << "Resulting seeds.\n";
    typedef Iterator<TSeedSet>::Type TIter;
    for (TIter it = begin(seedSet, Standard());
         it != end(seedSet, Standard()); ++it)
        std::cout << "(" << beginPositionH(*it) << ", " << endPositionH(*it)
                  << ", " << beginPositionV(*it) << ", " << endPositionV(*it)
                  << ", " << lowerDiagonal(*it) << ", " << upperDiagonal(*it)
                  << ")\n";

    return 0;
}

int mainbbc()
{

    String<int> myNumbers = 13245;
    std::string mystring = "ATCG";
    // The horizontal and vertical sequence (subject and query sequences).
    CharString seqH = "The quick BROWN fox jumped again!";
    CharString seqV = "thick BROWNIES for me!";
    // Create and print the seed sequence.
    // Seed<Simple> seed(11, 7, 14, 10); //beginH, beginV,endH, endV
    Seed<Simple> seed(11, 7, 14); // beginH, beginV, length
    std::cout << beginPositionH(seed) << " " << endPositionH(seed) << std::endl;
    std::cout << beginPositionV(seed) << " " << endPositionV(seed) << std::endl;
    std::cout << lowerDiagonal(seed) << " " << std::endl;
    std::cout << "original\n"
              << "seedH: " << infix(seqH, beginPositionH(seed), endPositionH(seed)) << "\n"
              << "seedV: " << infix(seqV, beginPositionV(seed), endPositionV(seed)) << "\n";

    // Perform match extension.
    extendSeed(seed, seqH, seqV, EXTEND_BOTH, MatchExtend());
    // Print the resulting seed.
    std::cout << "result\n"
              << "seedH: " << infix(seqH, beginPositionH(seed), endPositionH(seed)) << "\n"
              << "seedV: " << infix(seqV, beginPositionV(seed), endPositionV(seed)) << "\n";

    return 0;
}

// int mainxxx(){
//     /*   double x;
//     int64_t aa=20;
//     int64_t bb=30;
//     x=double(aa)/bb;
//     aa=1;*/
//     // std::unordered_map<std::string, std::vector<u_int8_t>> kmer2type;
//     std::unordered_map<std::string, std::array<uint16_t,4>> kmer2type;
//     std::array<uint16_t, 4> arr ={1,2,3,4};
//     // std::vector<u_int16_t> arr_vec={0,0,0,0};
//     std::string s="ATCGTTG";
//     std::string s2="CAACGAT";
//     std::string s3="Bccc";
//     // assert(s.length()==s3.length());
//     char cc=s3.substr(0,1).c_str()[0] ;
//     std::cout<<s3.substr(0,1)  <<std::endl;
//     std::cout<<cc  <<std::endl;

//     if (strcasecmp(s.c_str(),s3.c_str())>0)
//     {
//     std::cout<<"shit" <<std::endl;

//     }
//     else{
//     std::cout<<"shit2" <<std::endl;

//     }

//     // p = arr;
//     kmer2type["ATCG"]=arr;
//     kmer2type["ATCC"]=arr;
//     int p=54;
//     if (p>4) std::cout<< "aaaaa" <<std::endl;

//     for (auto & p : kmer2type){
//         std::cout<<p.first <<std::endl;
//         std::cout<<p.second[1] <<std::endl;
//         std::cout<< 'a' <<std::endl;
//     }
//     exit(1);
//     char a='A';
//     std::unordered_map<char, uint16_t> type2idx {{'H',0},{'D',1},{'D',2},{'E',3}};

//     // std::array<u_int8_t, 4> arr2=kmer2type["ATCG"];
//     // // std::cout<<*p<<std::endl;

//     // arr[1]+=1;
//     // // kmer2type.emplace(s,arr_vec);
//     // // kmer2type.emplace(s,arr);
//     // // kmer2type["ATCG"]=p;
//     // // std::cout<<*(p+1)<<std::endl;
//     kmer2type["ATCC"][0]+=10;
//     std::cout<<"OUT:"<<kmer2type["ATCC"][0]<<std::endl;
//     uint64_t b =s.length();
//     uint i =45;

//     std::cout<< b-arr[0] <<std::endl;
//     std::cout<< s2.substr(2,1) <<std::endl;

//     return 0;
// }
