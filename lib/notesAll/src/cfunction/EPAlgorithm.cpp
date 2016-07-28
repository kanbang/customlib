#include "EPAlgorithm.h"
#include <EPBinTreeNode.h>
#include <QDebug>
#include <math.h>
#include <iostream>
using namespace std;

EPAlgorithm::EPAlgorithm()
{
    values = 2;
}

void EPAlgorithm::dataStruct()
{
    /**
      编写过局域网的聊天工具和文件传输工具，熟悉Linux系统、shell脚本和Makefile文件、QML、数据结构和算法。
栈 (Stack)

是只能在某一端插入和删除的特殊线性表。它按照先进后出的原则存储数据，
先进入的数据被压入栈底，最后的数据在栈顶，需要读数据的时候从栈顶开始弹出数据
（最后一个数据被第一个读出来）。

队列 (Queue)

一种特殊的线性表，它只允许在表的前端（front）进行删除操作，
而在表的后端（rear）进行插入操作。进行插入操作的端称为队尾，
进行删除操作的端称为队头。队列是按照“先进先出”或“后进后出”的原则组织数据的
。队列中没有元素时，称为空队列。

链表 (Linked List)

是一种物理存储单元上非连续、非顺序的存储结构，它既可以表示线性结构，
也可以用于表示非线性结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。
每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。

树 (Tree)

是包含n（n>0）个结点的有穷集合K，且在K中定义了一个关系N，N满足 以下条件：
（1）有且仅有一个结点 K0，他对于关系N来说没有前驱，称K0为树的根结点。简称为根（root）。
（2）除K0外，K中的每个结点，对于关系N来说有且仅有一个前驱。
（3）K中各结点，对关系N来说可以有m个后继（m>=0）。

图 (Graph)

图是由结点的有穷集合V和边的集合E组成。其中，为了与树形结构加以区别，
在图结构中常常将结点称为顶点，边是顶点的有序偶对，若两个顶点之间存在一条边，
就表示这两个顶点具有相邻关系。

堆 (Heap)

在计算机科学中，堆是一种特殊的树形数据结构，每个结点都有一个值。
通常我们所说的堆的数据结构，是指二叉堆。堆的特点是根结点的值最小（或最大），
且根结点的两个子树也是一个堆。

散列表 (Hash)

若结构中存在关键字和K相等的记录，则必定在f(K)的存储位置上。
由此，不需比较便可直接取得所查记录。称这个对应关系f为散列函数(Hash function)，
按这个思想建立的表为散列表。

      */
}

void EPAlgorithm::insertSort(int arr[], int length)
{
    int i,j;
    for(i=1;i<length;i++)
    {
        j=i+1;
        if(arr[j] < arr[i]){
            arr[0] = arr[j];
            while(arr[0] < arr[i])
            {
                arr[i+1] = arr[i];
                i--;
            }
            arr[i+1] = arr[0];
        }
        i = j - 1;
    }
}

void EPAlgorithm::bubbleSort(int arr[], int length)
{
    for(int i = 1; i< length; i++)
        for(int j = 0; j< length-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}

void EPAlgorithm::selectSort(int arr[], int length)
{
    int min_index;
    for(int i = 0; i<length-1; i++)
    {
        min_index = i;
        for(int j = i+1; j < length; j++)
            if(arr[j] < arr[min_index])
                min_index = j;
        if(min_index !=i)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void EPAlgorithm::selectSortArrary(int arr[], int length)
{
    for(int i = 1; i<length; i++)
    {
        int temp = arr[i];
        int j = i -1;
        while (j > 0 && arr[j] > temp)
        {
            int tmp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j]= tmp;
            j--;
        }
        arr[j+1] = temp;
    }
}

//void EPAlgorithm::HeapSort(Node L[])

//{

//BuildingHeap(L);//建堆（大根堆）

//For(int i=n;i>0;i--)//交换

//{

//Int temp=L[i];

//L[i]=L[0];

//L[0]=temp;

//Heapify(L,0,i);//调整堆

//}

//}


//void EPAlgorithm::BuildingHeap(Node L[])

//{ For(i=length/2 -1;i>0;i--)

//Heapify(L,i,length);

//}

void EPAlgorithm::shellSort(int arr[], int length)
{
    for(int incr = 3; incr <0; incr--){
        for(int j = 0; j<(length -1)/incr; j++)
        {
            for(int i = j + incr; i<length; i+=incr)
            {
                int temp = arr[i];
                int k = i -incr;
                while(k>= 0&& arr[k] >temp)
                {
                    arr[k+incr] = arr[k];
                    k -= incr;
                }
                arr[k+incr] = temp;
            }
        }
    }
}

void EPAlgorithm::mergeSort(int arr[], int low, int high)
{
    int mid;
    if(low >= high) return;
    else  mid = (low + high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    int *point = new int[high - low + 1];
    for(int i = low, j = mid + 1,k = low; i<mid && j<=high; k++)
    {
        if(arr[i] <= arr[j])
        {
            point[k] = arr[j];
            i++;
        } else
        {
            point[k] = arr[j];
            j++;
        }
    }
}
#include <QDebug>
int EPAlgorithm::sumf(int n)
{
    int sum=0;
    for(int i = 1; i<=n; i++){
        sum += f(i);
        qDebug()<<__PRETTY_FUNCTION__<<f(n);
    }
    return sum;
}

int EPAlgorithm::f(int n)
{
    if (n<1) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    return f(n-1)+f(n-2);
}

int EPAlgorithm::AdjustArray(int s[], int l, int r) //返回调整后基准数的位置
{
    int i = l, j = r;
    int x = s[l]; //s[l]即s[i]就是第一个坑
    while (i < j)
    {
        // 从右向左找小于x的数来填s[i]
        while(i < j && s[j] >= x)
            j--;
        if(i < j)
        {
            s[i] = s[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
            i++;
        }

        // 从左向右找大于或等于x的数来填s[j]
        while(i < j && s[i] < x)
            i++;
        if(i < j)
        {
            s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
            j--;
        }
    }
    //退出时，i等于j。将x填到这个坑中。
    s[i] = x;

    return i;
}

int EPAlgorithm::fastQuery(int arr[], int left, int right)
{
    int key = arr[left];
    int i = left;
    int j = right;
    while (i !=j ){
        if(key > arr[j]){
            int temp;
            temp = key;
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }else
            j--;

    }
    return j;
}

void EPAlgorithm::quickSort(int arr[], int begin, int end)
{
    int q;
    if(begin < end){
        q = AdjustArray(arr,begin,end);
        quickSort(arr,begin, q-1);
        quickSort(arr,q+1,end);
    }
}
void EPAlgorithm::quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
              //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                            j--;
            if(i < j)
                            s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                            i++;
            if(i < j)
                            s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}
// array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
//本函数功能是：根据数组array构建大根堆

void  EPAlgorithm::HeapAdjust(int array[], int i, int nLength)
{
    int nChild;
    int nTemp;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // 子结点的位置=2*（父结点位置）+ 1
        nChild = 2 * i + 1;
        // 得到子结点中较大的结点
        if ( nChild < nLength-1 && array[nChild + 1] > array[nChild])
            ++nChild;
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if (nTemp < array[nChild])
        {
            array[i] = array[nChild];
            array[nChild]= nTemp;
        }
        else
        // 否则退出循环
            break;
    }
//    qDebug()<<__PRETTY_FUNCTION__;
//    for(int i = 0; i<nLength; i++)
//        cout<<" "<< array[i];
//    cout<<endl;
}

// 堆排序算法
void  EPAlgorithm::HeapSort(int array[],int length)
{
    int tmp;
    // 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是第一个非叶节点，此处"/"为整除
    for (int i = floor(length/ 2)-1 ; i >= 0; --i)
        HeapAdjust(array, i, length);
    // 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (int i = length - 1; i > 0; --i)
    {
        // 把第一个元素和当前的最后一个元素交换，
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
      ///  Swap(&array[0], &array[i]);
          tmp = array[i];
          array[i] = array[0];
          array[0] = tmp;
        // 不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array, 0, i);
    }
}

int EPAlgorithm::add( int a, int b )
{
    int c;
    while( c == (a&b) ){
        a = (a^b);
        b = (c<<1);
    }
    return (a^b);
}

// 求补码
int EPAlgorithm::rev( int a )
{
    return add((~a), 1);
}

// 判断正负
int EPAlgorithm::ispos( int a )
{ // 正
    return (a&0xFFFF) && !(a&0x8000);
}
int EPAlgorithm::isneg( int a )
{ // 负
    return a&0x8000;
}
int  EPAlgorithm::iszero( int a )
{ // 0
    return !(a&0xFFFF);
}

// 比较两个正数的大小（非负也可）
int EPAlgorithm:: isbig_pos( int a, int b )
{ // a>b>0
    int c = 1;
    b = (a^b);
    if( iszero(b) ) return 0;
    while( b >>= 1 ){
        c <<= 1;
    }
    return (c&a);
}

// 比较两个数的大小
int EPAlgorithm::isbig( int a, int b )
{ // a>b
    if( isneg(a) ){
    if( isneg(b) ){
        return isbig_pos( rev(b), rev(a) );
    }
    return 0;
    }
    if( isneg(b) ) return 1;
    return isbig_pos(a, b);
}

// 减法
int  EPAlgorithm::sub( int a, int b )
{
    return add(a, rev(b));
}

// 正数乘法
int  EPAlgorithm::pos_mul( int a, int b ){
    int c = 0x8000;
    int re = a;
    while( (c>>=1) && (!(b&c)) );
    while( c >>= 1 ){
    re <<= 1;
    if( c&b )
    re = add(re, a);
    }
    return re;
}

// 乘法
int  EPAlgorithm::mul( int a, int b ){
    if( iszero(a) || iszero(b) )
        return 0;
    if( ispos(a) && ispos(b) )
        return pos_mul(a, b);
    if( isneg(a) ){
        if( isneg(b) ){
            return pos_mul( rev(a), rev(b) );
        }
        return rev( pos_mul( rev(a), b ) );
    }
    return rev( pos_mul(a, rev(b)) );
}

// 正数除法
int  EPAlgorithm::pos_div( int a, int b )
{
    int re = 0, temp = b;
    if( isbig_pos(b, a) ) return 0;
    do{
        temp <<= 1;
    }while( !isbig_pos(temp, a) );
    while( isbig_pos(temp, b) ){
        re <<= 1;
        temp >>= 1;
        if( !isbig_pos(temp, a) )
        {
            a = sub(a, temp);
            re = add(re, 1);
        }
}
return re;
}

// 除法
int  EPAlgorithm::idiv( int a, int b ){
    if( iszero(b) ) {
        cout << "error" << endl;
        exit(1);
    }
    if( iszero(a) ) return 0;
    if( ispos(a) ){
        if( ispos(b) )
            return pos_div(a, b);
        return rev( pos_div( a, rev(b)));
    }
    if( ispos(b) )
        return rev( pos_div( rev(a), b ) );
    return pos_div( rev(a), rev(b) );
}

void EPAlgorithm::swap(int &a, int &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
    qDebug()<<__PRETTY_FUNCTION__<<a << b;
}

void EPAlgorithm::binaryOne(int num)
{
    int count = 0;
    while(num){
        if(num & 1)
            count++;
        num=num>>1;
    }
}
#include <EPCFunction.h>
#include <effective.h>
#include <time.h>
#include <EPmapView.h>
#include <EPAVLTree.h>

int i = 10;
void EPAlgorithm::showResult()
{
    clock_t start, finish;
    start = clock();
    finish = clock();
    double duration = double (finish - start)/CLOCKS_PER_SEC;

    float a = 0.0f;
    qDebug()<<(int)a <<" "<<&a<<" "<<(int&)a<<endl;
    qDebug()<<"xkd"<<i;

    float x = 5.01;
    int x1 = 1;
    double x2 = 5.1;
    qDebug()<<&x1 <<endl<<&x<<endl<<&x2<<endl;
    qDebug()<<sizeof(x1)<<" "<<sizeof(x) <<" "<<sizeof(x2)<<endl;

    EPmapView w;
    w.setScaleZoom();

    BinTree::showResult();

//    showAvl();
    int arr[] = {5,2,5,1,6,2,6,7,9};
    int count = sizeof(arr)/sizeof(int);
    insertSort(arr,count);
    for(int i = 0; i<count; i++)
        qDebug()<<arr[i];
//    count = 100000;
//    int array[count];
//    for(int i = 0; i<count; i++)
//        array[i] = rand();
  /*//    bubbleSort(array,count);
    HeapSort(array,count);



  char* p =0;
    int *p1 = new int(10);
    char array[] = "hello world";
    p = array;
    qDebug()<< sizeof(p) <<sizeof(char)<<sizeof(char*)<<sizeof(p1) <<sizeof(int*)<<sizeof(int);
    memory *men = new memory();
    memory *men1 = new memory();
    qDebug()<<men->p<<men1->p;
    men1->p = men->p;
    delete men;
    qDebug()<<*men1->p <<men1->p;

    int x1 = 200;
    int x2 = 120;
    x1 = (x1&x2) + ((x1^x2)>>1);
    x2 = x1;

    Da *pD = new Da;
    pD->show();

    A a;
    const QPoint& pos = a.getPos();
    const_cast<QPoint&>(pos).setX(100);
    a.show();
    a.point = 10;
    a.x = 17;
    pD->point = 20;
    qDebug()<<A::point <<Da::point <<a.x;
    const uint data[] = {

     // content:
           6,       // revision
           0,       // classname
           0,    0, // classinfo
           3,   14, // methods
           0,    0, // properties
           0,    0, // enums/sets
           0,    0, // constructors
           0,       // flags
           2,       // signalCount

     // signals: signature, parameters, type, tag, flags
           8,    7,    7,    7, 0x05,
          21,    7,    7,    7, 0x05,

     // slots: signature, parameters, type, tag, flags
          38,    7,    7,    7, 0x0a,

           0        // eod
    };
    const char qt_meta_stringdata_Object[] = {
        "Object\0\0emitSignal()\0emitSignal2(int)\0"
        "slotSignal()\0"
    };
    const uint* pdata = data;
    qDebug()<<sizeof(qt_meta_stringdata_Object);
    D wa;
    qDebug()<<"D "<<sizeof(wa) <<sizeof(pD) <<sizeof a <<sizeof(QPoint);*/
}

const int& EPAlgorithm::getValues() const
{
    return values;
}
