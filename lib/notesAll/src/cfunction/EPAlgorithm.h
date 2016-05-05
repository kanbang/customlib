#ifndef EPALGORITHM_H
#define EPALGORITHM_H

class EPAlgorithm
{
public:
    EPAlgorithm();

    void dataStruct();
    void insertSort(int arr[], int length);
    void bubbleSort(int arr[],int length);
    void selectSort(int arr[],int length);
    void selectSortArrary(int arr[], int length);
    
    void shellSort(int arr[], int length);
    void mergeSort(int arr[], int low, int high);
    int  sumf(int n);
    int  f(int n);

    //快速排序
    int AdjustArray(int s[], int l, int r); //返回调整后基准数的位置
    int fastQuery(int arr[], int begin, int end);
    void quickSort(int arr[], int begin, int end);
    void quick_sort(int arr[], int begin, int end);
    void HeapAdjust(int array[], int i, int nLength);
    void HeapSort(int array[], int length);
    int add(int a, int b);
    int rev(int a);
    int ispos(int a);
    int isneg(int a);
    int iszero(int a);
    int isbig_pos(int a, int b);
    int isbig(int a, int b);
    int sub(int a, int b);
    int pos_mul(int a,int b);
    int mul(int a, int b);
    int pos_div(int a, int b);
    int idiv(int a, int b);
    void swap(int &a, int &b);

    void binaryOne(int num);
    void showResult();

    const int &getValues()const;

private:
    int values;

};

#endif // EPALGORITHM_H
