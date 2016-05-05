#ifndef LINK_H
#define LINK_H
#include <QDebug>

template <class T>
class Node
{
public:
    Node(T t)
    {
        m_type = t;
        m_next = NULL;
    }

    T m_type;
    Node* m_next;
};

template <class T>
class Link
{
public:
    //类模板中的构造函数写在头文件里
    Link():head(NULL), m_count(0){}
    void append(T t)
    {
        if(head == NULL)
        {
            Node<T> *node = new Node<T>(t);
            head = node;
            m_count++;
        }
        else
        {
            Node<T> *node = new Node<T>(t);
            Node<T> *tmp = head;
            while(tmp->m_next)
            {
                tmp = tmp->m_next;
            }
            tmp->m_next = node;
            m_count++;
        }
    }
    int count()
    {
        return m_count;
    }

    T at(int index)
    {
        if(m_count > index)
        {
            Node<T>* tmp = head;
            for(int i = 0; i<index; i++)
            {
                tmp = tmp->m_next;
            }
            return tmp->m_type;
        }

        return NULL;
    }

    Node<T>* nodeAt(int index)
    {
        if(m_count > index)
        {
            Node<T>* tmp = head;
            for(int i = 0; i<index; i++)
            {
                tmp = tmp->m_next;
            }
            return tmp;
        }

        return NULL;
    }

    void Delete(int index)
    {
        if(m_count > index)
        {
            Node<T>* tmp = head;
            if(index == 0)
            {
               tmp = head->m_next;
               delete head;
               head = tmp;
            }
            else if(index == m_count - 1)
            {
                Node<T>* current = nodeAt(index);
                Node<T>* before = nodeAt(index-1);
                delete current;
                before->m_next = NULL;
            }
            else
            {
                Node<T>* current = nodeAt(index);
                Node<T>* before = nodeAt(index-1);
                Node<T>* after = nodeAt(index + 1);
                delete current;
                before->m_next = after;
            }
            m_count--;
        }
    }

private:
    Node<T>* head;
    int m_count;
};


#endif // LINK_H
