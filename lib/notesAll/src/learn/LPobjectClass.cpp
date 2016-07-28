#include "LPobjectClass.h"

LPobjectClass::LPobjectClass()
{
    /**
     \brief
        Segy文件格式
        地震数据一般以地震道为单位进行组织，采用SEG－Y文件格式存储。

        标准的SEG－Y文件一般包含三部分：
        @note   EBCDIC文件头(3200字节），由40个卡组成(例如：每行80个字符 * 40行），用来保存一些对地震数据体进行描述的信息。

        @note   二进制文件头(400字节）用来存储描述SEG－Y文件的一些关键信息，包括SEG－Y文件的数据格式、采样点数、采样间隔、测量单位等一些信息。
                这些信息一般存储在二进制文件头的固定位置上。

        @note   实际的地震道，每条地震道都包含240字节的道头信息和地震道数据。
                道头数据中一般保存该地震道对应的线号、道号、采样点数、大地坐标等信息，但一些关键的参数位置(如线号、道号在道头中的位置）并不固定。

                地震道数据是对地震信号的波形按一定时间间隔 delta T 进行采样，再把这一系列的离散振幅值以某种方式记录下来。

                地震数据格式可以是IBM浮点型， IEEE浮点型，整形，长整形等。

                一个三维地震工区同一次处理的地震数据格式是唯一的。地震道采样点数由该地震道道头中采样点数决定，大部分SEG－Y文件的所有地震道采样点数是
                一致的，但是也存在不同地震道采样点数不同的情况，一般称这种SEG—Y文件为变道长格式的SEG—Y文件



        测区数据结构
        typedef struct
        {
            char* name;             测区名称
            int type;               测区类型  @note 参考枚举类型 SeismicDataType
                                                有两种 typedef enum _SeismicDataMode{ Seismic3dData, Seismic2dData } SeismicDataMode;
            int numLine;            测线个数
            void  *data;            保存一个Survey3d结构或numLine个Survey2d结构
        }Survey;

        二维测线桩号数据结构
        typedef struct
        {
            float   station;        桩号
            int     cdp;            桩号对应的CDP
            double  x;              桩号所在x坐标
            double  y;              桩号所在y坐标
        }Survey2dPoint;

        二维测区数据结构
        typedef struct
        {
            char*   lineName;       二维测线名称
            int     beginCdp;       开始CDP
            int     endCdp;         结束CDP
            float   disCdp;         CDP间距
            int		numPoints;      定义桩号数
            Survey2dPoint *points;  定义的桩号数据结构数据
        } Survey2d;

        三维测区数据结构
        typedef struct
        {
            int     numInline;      主测线个数
            int     beginInline;    开始主测线号
            int     endInline;      结束主测线号
            float   disInline;      主测线间距
            int     numXline;       联络测线个数
            int     beginXline;     开始联络测线号
            int     endXline;       结束联络测线号
            float   disXline;       联络测线间距
            double  x0;             第一条主测线和第一条联络测线交点坐标
            double  y0;             第一条主测线和第一条联络测线交点坐标
            double  angle;          主测线方位角，为了方便计算，采用正东为零度，逆时针为正方向，单位为弧度
            int     direction;      主测线于联络测线位置关系。 @note 0-左手法则， 1-右手法则
        } Survey3d;

        @struct _WellInfoRec
        @brief 井信息数据结构
        typedef struct _WellInfoRec {
            char *  welluwi;        ///< 唯一的井标识符，用于数据库文件名
            char *  wellname;       ///< 井名
            char  * wellnet;        ///< 井网名称
            char  * remark;         ///< 备注

            int     well_tpye;      ///< 井类型ID
            int     isDeviated;     ///< 是否是斜井
            double  x, y;           ///< 井口坐标
            double  xeye, yeye;     ///< 井底(靶心)坐标
            float   depth;          ///< 完钻井深
            float   tvd;            ///< 完钻井深
            float   kbelev;         ///< 补心海拔

            int     formationFlag;  ///< 分层数据标志
            int     lithFlag;       ///< 岩性数据标志
            int     trajectoryFlag; ///< 轨迹数据标志
            int     logFlag;        ///< 测井曲线数据标志
            int     loginterpFlag;  ///< 测井解释数据标志
            int     payzoneFlag;    ///< payzone数据标志
            int     tdcFlag;        ///< 时深数据标志（包括输入的VSP和标定的时深关系）

            int     blockid;        ///< 区块ID
            float   waterdepth;     ///< 水深
        } WellInfoRec;
     */
}

void LPobjectClass::epDataIO()
{
    /**
     \brief 这个类是数据对象类的辅助类，用于数据的输入和输出以及更新
      @note 函数
        getTimeStamp(); 获得文件最新的更新时间。用来查看是否和m_iTimeStamp是否相等。
        load();用来加载数据。

        关键字是数据库文件的标识信息，用关键字可以组合这个正确的数据库文件名
            第一个关键字          第二个关键字
        getPrimaryName();   getSecondaryName();

     @variable 定义了一个时间戳
        m_iTimeStamp;   //保存每次加载数据的时候，文件的更新时间。
     */
}

void LPobjectClass::epObject()
{

    /**
     \brief
     \brief EPObject类
            EPObject是所有的数据对象的基类,每个EPObject对象都有一个对象类型、一个对象名称和一个指向父对象的指针。
            使用getObjectType()函数获得对象的类型；使用getObjectName()函数获得对象的名称；
            使用getParent() 函数获得父类对象指针；
     @note  对象类型的设置是在具体的子类中进行设置。

            每个父对象可以包含一组子对象。使用getObjectCount() 函数获得子对象个数，使用getObject()函数获得指定的子对象。
            在子对象中有一个当前对象，使用currentObject()可得到它。


            在EPObject的子类EPDataSetObject中，有一个QList<EPObject*> m_set;这个列表是用来管理对象的。
            还有 QList<EPObjectType> m_childrenType;


     @note  EPObject类中，获得对象所属的集合对象的名称
            getDefaultObjectName(EPObjectType type);



     @variable      EPObjectDefinition  m_definition;
                    EPObjectType        m_objectType;   对象类型
                    EPObject            *m_parent;      父对象指针
                    QString             m_objectName;   对象名称
                    int                 m_uid;
                    double              m_fDataMin;     数据最小值
                    double              m_fDataMax;     数据最大值

                    static EPObjectFactory* m_pObjectFactory;   工厂类
     **/
}

void LPobjectClass::epDataSetObject()
{
    /**
     \brief EPDataSetObject这个类继承了EPObject。
            EPObject以对象数的形式来组织它和它的子类。每个父对象都包含一个子对象列表，每个子对象都包含一个指向父对象的指针。
            EPObject类中定义了接口，但是并没有实现。
     @note  在EPDataSetObject中提供了所有功能。
            使用父对象的manage()函数把子对象加到父对象类表中。
            在manage()函数中会检查对象的类型，判断该类型是否可以加到自己的对象列表中。
            EPDataSetObject还提供了数据插入，删除，查找等函数。

            在这个类中，提供管理EPObject类的函数，就是m_set;
            在manage(EPObject*)这个类中会查看，管理的EPObject是不是已经添加到列表了。
      @fn   函数功能说明
            @note   首先判断这个obj的type有没有包含在m_childrenType列表中(!isManageTyep(obj->getObjectType());如果不包含，那就返回false
                    其次判断这个m_set是不是包含这个obj，如果包含，那就返回false。如果不包含，那就把这个obj添加到m_set中，然后返回true。
                    最后判断isExist(EPObjectType type, const QString& objName);

            bool    manage(EPObject* obj);

            @note   在EPDataSetObject的其他派生类中，都有重新实现isManageType(EPObjectType type)这个函数，
                    这些派生类中都是判断这个type是不是等于该对象的type。并没有把这个type添加到m_childrenType中。

            bool    isManageType(EPObjectType type);

            @note   根据测区数据结构创建测区对象

            static  EPDataSetObject*    createSurveyObjectByStruct(Survey* survey);

            @note   根据三维测区结构创建三维测区对象

            static  EP3dSurveyObject*   create3dSurveyObjectByStruct(Survey* survey);

            @note   根据二维测区结构创建二维测区对象

            static  EP2dSurveyObject*   create2dSurveyObjectByStruct(Survey* survey);

            @note   加载所有测区数据，返回测区名个数(num)，返回测区数据结构数组(Survey*)。

            Survey* EPloadSurveys(int *num);

            @note   保存所有测区数据， 需要保存的测区结构数据(svys),测区数据结构长度(num)

            int     EPSaveSurveys(Survey *svys, int num);

      @variable     QList<EPObject*>    m_set;              对象列表
                    bool                m_bAutoDelete;      是否自动删除EPobject指针指向的对象，影响clear和remove;
                    EPObject*           m_pCurrentObject;   当前对象必须是m_set中的一个。
                    QList<EPObjectType> m_childrenType;
     */
}

void LPobjectClass::epSurveySetObject()
{
    /**
     \brief 这个类是个二维地震测区集管理类，同时管理全部定义测区和已经加载进内存的测区，
            这个类中提供的方法主要是用来管理工区中定义的全部测区数据，通常使用静态方法
            加载进内存的测区由其基类EPDataSetObject提供的方法管理。

            主要功能有这些：
     @fn    函数功能说明
            @note   获得指定的测区对象，如果没有找到，并且autoCreate等于true，这自动加载。
                    首先会从m_set对象列表中获取对象名字为name的对象。如果列表中没有，则判断
                    autocreat是否为true来加载一个这样的对象。

            EPObject*   getSurvey(const QString& name, bool autoCreate = false);

            @note   从数据库中获得一个二维Survey对象
     */
}

void LPobjectClass::ep3dSurveyObject()
{
    /**
      \brief    三维测区对象记录三维测区的几何信息。三维测区通常为一矩形，有若干主测线构成，主测线中相同CDP的地震道构成联络测线。
                三维测区对象中包含的信息有：

                起始主测线好， 终止主测线号，主测线间距
                起始联络测线号，终止联络测线号，联络测线间距
                起始主测线第一个CDP点的坐标
                主测线的旋转角度
                主测线与联络测线的关系
                其中主测线和联络测线的间距都为1
      */
}

void LPobjectClass::seismicMgr()
{
    /**
      \brief

      */
}

void LPobjectClass::ObjectSave()
{
    /**
     \note

     @a 使用工厂接口类  EPObjectFactoryInterface.h::save(EPObject* obj) = 0 ;
     目前继承这个代理工厂类的接口
     EPGeologicSectionFactory 、 EPWellLogFactory 、 EPGeoConnectionFactory.

     工厂代理类：  EPobjectFactoryProxy.
         这个类用单例模式，同时有一个成员变量 @ QMap<int, EPObjectFactoryInterface*> map;
         一旦创建一个工厂代理类，就会在构造函数中把上面三个继承EPObjectFactoryInterface 的子类注册到 map 这个变量中。

      bool EPObjectFactoryProxy::save(EPObject* object)
      {
            EPObjectFactoryInterface *factory = d->map.value(object->getObjectType(), 0);
            if(factory)
            {
                bool ok = factory->save(object);
                return ok;
             }
             else
                return false;
       }
     */
}





































