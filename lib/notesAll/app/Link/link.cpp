#include "link.h"
//template <class T>
//Link<T>::Link():head(NULL),m_count(0)
//{
//}

//template <class T>
//void Link<T>::append(T t)
//{
//    if(head == NULL)
//    {
//        Node<T> *node = new Node<T>(t);
//        head = node;
//        m_count++;
//    }
//    else
//    {
//        Node<T> *node = new Node<T>(t);
//        Node<T> *tmp = head;
//        while(tmp->m_next)
//        {
//            tmp = tmp->m_next;
//        }
//        tmp->m_next = node;
//        m_count++;
//    }
//}

//template <class T>
//int Link<T>::count()
//{
//    return m_count;
//}

//template <class T>
//T Link<T>::at(int index)
//{
//    if(m_count > index)
//    {
//        Node<T>* tmp = head;
//        for(int i = 0; i<index; i++)
//        {
//            tmp = tmp->m_next;
//        }
//        return tmp->m_type;
//    }

//    return NULL;
//}
