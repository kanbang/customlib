#include "EPHashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HASH_TABLE* create_hash_table()
{
    HASH_TABLE* pHashTbl = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
    memset(pHashTbl, 0, sizeof(HASH_TABLE));
    return pHashTbl;
}

NODE* find_data_in_hash(HASH_TABLE* pHashTbl, int data)
{
    NODE* pNode;
    if(NULL ==  pHashTbl)
        return NULL;

    if(NULL == (pNode = pHashTbl->value[data % 10]))
        return NULL;

    while(pNode){
        if(data == pNode->data)
            return pNode;
        pNode = pNode->next;
    }
    return NULL;
}

STATUS insert_data_into_hash(HASH_TABLE* pHashTbl, int data)
{
    NODE* pNode;
    if(NULL == pHashTbl)
        return FALSE;

    if(NULL == pHashTbl->value[data % 10]){
        pNode = (NODE*)malloc(sizeof(NODE));
        memset(pNode, 0, sizeof(NODE));
        pNode->data = data;
        pHashTbl->value[data % 10] = pNode;
        return TRUE;
    }

    if(NULL != find_data_in_hash(pHashTbl, data))
        return FALSE;

    pNode = pHashTbl->value[data % 10];
    while(NULL != pNode->next)
        pNode = pNode->next;

    pNode->next = (NODE*)malloc(sizeof(NODE));
    memset(pNode->next, 0, sizeof(NODE));
    pNode->next->data = data;
    return TRUE;
}

STATUS delete_data_from_hash(HASH_TABLE* pHashTbl, int data)
{
    NODE* pHead;
    NODE* pNode;
    if(NULL == pHashTbl || NULL == pHashTbl->value[data % 10])
        return FALSE;

    if(NULL == (pNode = find_data_in_hash(pHashTbl, data)))
        return FALSE;

    if(pNode == pHashTbl->value[data % 10]){
        pHashTbl->value[data % 10] = pNode->next;
        goto final;
    }

    pHead = pHashTbl->value[data % 10];
    while(pNode != pHead ->next)
        pHead = pHead->next;
    pHead->next = pNode->next;

final:
    free(pNode);
    return TRUE;
}

bool HashTable::Insert(int key)
{
    if(this->m_nodenum==this->m_size)
    {
        cout<<"the table is full!"<<endl;
        return 0;
    }
    int hashValue=Hash(key,this->m_size);
    for(int i=0;i<this->m_size;i++)
    {
        if(m_element[hashValue].state==0)
        {
            this->m_element[hashValue].key=key;
            this->m_nodenum++;
            this->m_element[hashValue].state=1;
            cout<<"Insert Value Success!The value is:"<<key<<";the addr is:"<<hashValue<<endl;
            return 1;
        }
        else if(m_element[hashValue].state==1)
        {
            hashValue=(hashValue+i)%(this->m_size);
        }
    }
    cout<<"Insert filled !"<<endl;
    return 0;
}
bool HashTable::Search(int item, int &pos)
{
    if(this->m_nodenum==this->m_size)
    {
    cout<<"the table is full!"<<endl;
    pos=-1;
    return 0;
    }
    int keyvalue=Hash(item,this->m_size);
    for(int i=0;i<this->m_size;i++)
    {
    if(this->m_element[keyvalue].state==1&&this->m_element[keyvalue].key==item)
        {
        cout<<"find the element "<<item<<" and the position is "<<i<<endl;
        pos=keyvalue;
        return 1;
        }
    else
        keyvalue=(keyvalue+i)%(this->m_size);
    }
    cout<<"can't find the value!"<<endl;
    pos=-1;
    return 0;
}
int main()
{
    int array[]={22, 41, 53, 46, 30,13, 01,67};
    HashTable hTable(11);
    for(int i =0;i < 8;i++)
    hTable.Insert(array[i]);
    hTable.Display();
    int pos;
    hTable.Search(41,pos);
    cout<<"the pos is "<<pos<<endl;
    return 0;
}

EPHashTable::EPHashTable()
{
}
