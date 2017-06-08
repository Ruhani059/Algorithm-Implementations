#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#define SIZE 17
using namespace std;

class Hashing
{
public:
    string hashTable[SIZE];

    Hashing()
    {

        for(int i=0;i<SIZE;i++)
        {
            hashTable[i][0] = '\0';
        }
    }

    int hashFunction1(string s1)
    {
        int ascii = 0;
//        cout<<s1.at(0);
        for(int i=0;i<s1.size();i++)
        {
            ascii += s1.at(i);
    //        cout<<s1.at(i);
            ascii = ascii%SIZE;
        }
        return ascii%SIZE;
    }

    int hashFunction2(string s1)
    {
        int ascii = 1;
//        cout<<s1.at(0);
        for(int i=0;i<s1.size();i++)
        {
            ascii *= s1.at(i);
    //        cout<<s1.at(i);
            ascii = ascii%SIZE;
        }
        if(ascii%SIZE == 0)
            return 1;
        else
            return ascii%SIZE;
    }

    int hashFunction (string s1)
    {
        return 0;

    }

    void insert(string s1)
    {
        int hashValue = 0;
        hashValue = hashFunction1(s1);
        if(hashTable[hashValue][0]=='\0')
        {
            hashTable[hashValue] = s1;
            cout<<"successful\n";
        }
        else
        {
            for(int i = 0;i<SIZE;i++)
            {
                hashValue += hashFunction2(s1);
                hashValue = hashValue%SIZE;
                if(hashTable[hashValue][0]==NULL)
                {
                    hashTable[hashValue] = s1;
                    cout<<"successful\n";
                    break;
                }
            }
        }

    }

    void show()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<hashTable[i]<<endl;
        }
    }

    void search(string s1)
    {
        int check = 0;
        int hashValue = 0;
        hashValue = hashFunction1(s1);
        cout<<"check1";
        if(hashTable[hashValue]== s1)
        {
            cout<<"Yes Paisi\n";
            check = 1;
        }
        else
        {
            cout<<"check2";
            for(int i = 0;i<SIZE;i++)
            {
                cout<<"check3";
                hashValue += hashFunction2(s1);
                hashValue = hashValue%SIZE;
                if(hashTable[hashValue]==s1)
                {
                    cout<<"Yes!\n";
                    check =1;
                    cout<<"check4";
                    break;
                }
            }
        }
        if(check == 0)
            cout<<"pain nai. so sad\n";

    }

};

int main()
{
    Hashing H;
    int hash1 = H.hashFunction1("anfceswne");
    cout<<hash1<<" ";
    int hash2 = H.hashFunction2("anfceswne");
    cout<<hash2;
    H.insert("Ruhani");
    H.insert("Faiheem");
    H.insert("Ruhani");
    H.insert("Rahman");
    H.show();
//    H.search("anfceswnve");
    H.search("Ruhani");
    H.search("Faiheem");
    H.search("hello");
    H.search("Rahman");
    H.search("anfceswne");
    return 0;
}
