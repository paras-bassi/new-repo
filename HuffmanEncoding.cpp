// C++ program for Huffman Coding
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <iterator>
#include<iostream>
//#include "HuffmanDecoding.cpp"
using namespace std;

struct MinHeapNode {
	// One of the input characters
	int data;
	// Frequency of the character
	unsigned freq;

	// Left and right child
	MinHeapNode *left, *right;

	MinHeapNode(int data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};
class HuffmanEncoding
{
// For comparison of
// two heap nodes (needed in min heap)
struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};
// Prints huffman codes from
// the root of Huffman Tree.

public:
    string encodedString="";

    void printCodes(struct MinHeapNode* root, string str )
    {

        if (!root)
            return;

        if (root->data != '$')
        {
            encodedString+=str;
            //cout << root->data << ": " << str << "\n";
          //cout<<"Encoded String : " << encodedString;
        }


        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");

    }

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
    public : void HuffmanCodes(int data[], int freq[], int size)
    {
        struct MinHeapNode *left, *right, *top;

        // Create a min heap & inserts all characters of data[]
        priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

        for (int i = 0; i < size; ++i)
            minHeap.push(new MinHeapNode(data[i], freq[i]));

        // Iterate while size of heap doesn't become 1
        while (minHeap.size() != 1) {

            // Extract the two minimum
            // freq items from min heap
            left = minHeap.top();
            minHeap.pop();

            right = minHeap.top();
            minHeap.pop();

            // Create a new internal node with
            // frequency equal to the sum of the
            // two nodes frequencies. Make the
            // two extracted node as left and right children
            // of this new node. Add this node
            // to the min heap '$' is a special value
            // for internal nodes, not used
            top = new MinHeapNode('$', left->freq + right->freq);

            top->left = left;
            top->right = right;

            minHeap.push(top);
        }

        // Print Huffman codes using
        // the Huffman tree built above
        printCodes(minHeap.top(), "");
        decode_file(minHeap.top(), encodedString);
        //cout<<"Encoded String : " << MinHeapNode->encodedString;
        //HuffmanDecoding obj;

        //decodedString = decode_file(minHeap.top(), encodedString);
        //return minHeap.top();
    }

    string decode_file(struct MinHeapNode* root,string s)
    {
        //string s = objHuffmanEncoding.encodedString;
        string ans = "";
        struct MinHeapNode* curr = root;
        //cout<<"Size : "<<s;
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == '0')
            curr = curr->left;
            else
            curr = curr->right;

            // reached leaf node
            if (curr->left==NULL and curr->right==NULL)
            {
                ans += curr->data;
                curr = root;
            }
        }
       cout<<"Encoded : "+s <<"\n"<<"Decoded : "+ans<<endl;
        //return ans+'\0';
    }
};
