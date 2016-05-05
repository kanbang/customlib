#ifndef EPHASHTABLE_H
#define EPHASHTABLE_H
#include<iostream>
using namespace std;

#define FALSE false
#define TRUE true

typedef bool STATUS;
typedef struct _NODE
{
    int data;
    struct _NODE* next;
}NODE;

typedef struct _HASH_TABLE
{
    NODE* value[10];
}HASH_TABLE;

HASH_TABLE* create_hash_table();
NODE* find_data_in_hash(HASH_TABLE* pHashTbl, int data);
STATUS insert_data_into_hash(HASH_TABLE* pHashTbl, int data);
STATUS delete_data_from_hash(HASH_TABLE* pHashTbl, int data);



int Hash(int key,int length)
{
    return (key*3)%length;
}
typedef struct element
{
    int key;
    int state;
}Element;

class EPHashTable
{
public:
    EPHashTable();
};


class HashTable
{
private:
    Element * m_element;
    int m_size;
    int m_nodenum;
public:
    HashTable(int a):m_size(a)
        {
        this->m_nodenum=0;
        m_element=new Element[a];
        for(int i=0;i<a;i++)
            {
            m_element[i].key=0;
            m_element[i].state=0;
            }
        }
    ~HashTable()
        {
        delete []m_element;
        }
    bool Insert(int key);
    bool Search(int item,int &pos);
    int GetSize()
        {
        return this->m_nodenum;
        }
    void Display()
        {
        if(this->m_nodenum==0)
            {
            cout<<"the table is empty!"<<endl;
            return ;
            }
        for(int i=0;i<this->m_size;i++)
            {
            if(this->m_element[i].state==1)
                {
                cout.width(4);
                cout<<this->m_element[i].key;
                cout<<"                         ";
                cout.width(3);
                cout<<i<<endl;
                }
            }
        }

};

#endif // EPHASHTABLE_H
