#include <map>
#include <set>
#include <string>
#include <iostream>
#include <iterator>
#include "HuffmanEncoding.cpp"
using namespace std;


struct returnHuffmanData
{
    struct MinHeapNode;
    string encodedString;
};
multimap<int, int> :: iterator itr,i;
multiset<pair<int, int>> sortedMap;

multiset<pair<int, int>> sortMap(multimap<int, int , greater <int> > dataMap){

    for ( i=dataMap.begin(); i!=dataMap.end(); i++)
        {
            sortedMap.insert(pair<int, int>((*i).first, (*i).second));
        }
    return sortedMap;
}

int main() {

multimap<int, int , greater <int> > dataMap;
dataMap.insert(pair<int, int>(5, 1));
dataMap.insert(pair<int, int>(2, 9));
dataMap.insert(pair<int, int>(1, 1));
dataMap.insert(pair<int, int>(3, 2));
dataMap.insert(pair<int, int>(4, 2));

sortedMap = sortMap(dataMap);
int i=0;
int numArray[sortedMap.size()];
int freqArray[sortedMap.size()];
//Print Sorted Data
for (itr = dataMap.begin(); itr != dataMap.end(); ++itr)
    {
        numArray[i]= itr->first;
        freqArray[i]=itr->second;
        i++;
    }
//for(int x:numArray)
//{
//  // cout<< x;
//}
//cout<<"\n" ;
//for(int x:freqArray)
//{
//  cout<< x;
//}
//cout<<"\n" ;


HuffmanEncoding objHuffmanEncoding;
objHuffmanEncoding.HuffmanCodes(numArray, freqArray, sortedMap.size());
}
