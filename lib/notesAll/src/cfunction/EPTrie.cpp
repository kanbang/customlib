#include "EPTrie.h"

void insert(Trie *root,const char *s) //将单词s插入到字典树中
{
    if(root==NULL||*s=='\0')
        return;
    Trie *p=root;
    while(*s)
    {
        if(p->next[*s-'a']==NULL)//如果不存在存储该字符的节点，则建立结点
        {
            Trie *temp=new Trie;
            for(int i=0; i<MAX; i++)
            {
                temp->next[i]=NULL;
            }
            temp->isStr=false;
            p->next[*s-'a']=temp;
            p=p->next[*s-'a'];
        }
        else
        {
            p=p->next[*s-'a'];
        }
        s++;//让指针s指向下一个字符
    }
    p->isStr=true;//单词结束的地方标记此处可以构成一个串
}

int search(Trie *root,const char *s)//查找某个单词s是否已经存在
{
    Trie *p=root;
    while(p&&*s)
    {
        p=p->next[*s-'a'];
        s++;
    }
    return (p&&p->isStr);  //在单词结束处的标记为true时，单词才存在
}

void del(Trie *root)//释放整个字典树占的堆区空间
{
    for(int i=0; i<MAX; i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    delete root;
}

void showMain()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    char s[100];
    Trie * root = new Trie;
    for(int i=0; i<MAX; i++)
    {
        root->next[i]=NULL;
    }
    root->isStr=false;
    int n,m; //n为建立Trie树输入的单词数，m为要查找的单词数
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++) //先建立字典树
    {
        scanf("%s",s);
        insert(root,s);
    }
    while(~scanf("%d",&m))
    {
        if(!m)
            break;
        for(int i=0; i<m; i++) //查找
        {
            scanf("%s",s);
            if(search(root,s))
                printf("YES\n");
            else
                printf("NO\n");
        }
        printf("\n");
    }
    del(root); //释放空间很重要
    return ;
}
