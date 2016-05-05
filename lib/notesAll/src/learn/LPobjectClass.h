#ifndef LPOBJECTCLASS_H
#define LPOBJECTCLASS_H

class LPobjectClass
{
public:
    LPobjectClass();

    /**
     \brief     object类中的两个重要的基类之一(EPDataIO)
     */
    void    epDataIO();

    /**
     \brief     object类中的两个重要的基类之一(EPObject)
     */
    void    epObject();

    /**
     \brief     由EPObject派生出来的基类(EPDataSetObject)
     */
    void    epDataSetObject();

    /**
     \brief     关于地震测区集管理类
     */
    void    epSurveySetObject();

    /**
     \brief    三维测区对象，使用load()函数加载三维测区对象，使用save()函数保存三维测区对象
                管理三维测区中的地震数据，层位数据，断层数据等
                提供测线位置和坐标的相互转换等功能
    */

    void    ep3dSurveyObject();

    /**
     \brief     地震数据管理，主要完成对地震数据的打开，读写操作。

     */

    void    seismicMgr();

    /**
     \brief     关于数据保存的模式
     */
    void    ObjectSave();

};

#endif // LPOBJECTCLASS_H
