#include "Sqlite.h"

Sqlite::Sqlite()
{
    /**
    sqlite3常用命令
    当前目录下建立或打开test.db数据库文件，并进入sqlite命令终端，以sqlite>前缀标识：
    #sqlite3 test.db

    查看数据库文件信息命令(注意命令前带字符'.')：
    sqlite>.database

    查看所有表的创建语句：
    sqlite>.schema

    查看指定表的创建语句：
    sqlite>.schema table_name

    以sql语句的形式列出表内容：
    sqlite>.dump table_name

    设置显示信息的分隔符：
    sqlite>.separator symble
    Example：设置显示信息以‘：’分隔
    sqlite>.separator :

    设置显示模式：
    sqlite>.mode mode_name
    Example:默认为list，设置为column，其他模式可通过.help查看mode相关内容
    sqlite>.mode column

    输出帮助信息：
    sqlite>.help

    设置每一列的显示宽度：
    sqlite>.width width_value
    Example:设置宽度为2
    sqlite>.width 2

    列出当前显示格式的配置：
    sqlite>.show

    退出sqlite终端命令：
    sqlite>.quit
    或
    sqlite>.exit


      */
}

void Sqlite::sqlite_pragram()
{
    /**
    pragma:
    1.pragma auto_vacuum ＝ 0|1 设置自动缩放文件

    2.PRAGMA cache_size = Number-of-pages;
    查询或修改SQLITE，一次存储在内存中的数据库文件页数。
    改变只是对当前会话有效，关闭数据库时。无效

    3.PRAGMA case_sensitive_like ＝0｜1
    是否忽略大小写

    4.PRAGMA count_changes = 0 | 1
    开启时，返回影响行数的整数

    5.PRAGMA default_cache_size ＝Number-of-pages;
    永久性地改变缓存大小。

    6.PRAGMA empty_result_callbacks = 0 | 1;
    是否调用回叫函数
    ATTACH命令创建的数据库使用与主数据库相同的编码格式

    7.PRAGMA full_column_names = 0 | 1;
    若short-column-names和full-column-names标记同时被设置，则使用full-column-names方式

    8.pragma fullfsync =0|1
    决定是否在支持的系统上使用F_FULLSYNC同步模式

    9.pragma page_size = bytes
    只有在未创建数据库时才能设置page-size。页面大小必须是2的整数倍且大于等于512小于等于8192。

    10.pragma read_uncommitted =0|1
    查询，设置或清除READ UNCOMMITTED isolation(读取未授权的分隔符).

    11.PRAGMA short_column_names = 0 | 1;
    查询或更改the short-column-names标记

    12.
    PRAGMA synchronous;
    PRAGMA synchronous = FULL; (2)
    PRAGMA synchronous = NORMAL; (1)
    PRAGMA synchronous = OFF; (0)
    查询或更改"synchronous"标记的设定

    13.
    PRAGMA temp_store;
    PRAGMA temp_store = DEFAULT; (0)
    PRAGMA temp_store = FILE; (1)
    PRAGMA temp_store = MEMORY; (2)
    查询或更改"temp_store"参数的设置

    14.
    PRAGMA temp_store_directory = 'directory-name';
    查询或更改"temp_store_directory"设置——存储临时表和索引的文件所在的目录。
    仅在当前连接有效，在建立新连接时重置为缺省值

    15.PRAGMA database_list;
    对每个打开的数据库，使用该数据库的信息调用一次回叫函数

    16.PRAGMA foreign_key_list(table-name);

    17.PRAGMA index_info(index-name);

    18.PRAGMA index_list(table-name);

    19.PRAGMA table_info(table-name);


    20.PRAGMA [database.]schema_version;
    PRAGMA [database.]schema_version = integer ;
    PRAGMA [database.]user_version;
    PRAGMA [database.]user_version = integer ;

    查看版本信息

    21 PRAGMA integrity_check;
    该命令对整个数据库进行完整性检查

    22
    PRAGMA parser_trace = ON; (1)
    PRAGMA parser_trace = OFF; (0)
    打开或关闭SQLite库中的SQL语法分析追踪，用于debug.只有当SQLite不使用NDEBUG宏进行编译时该pragma才可用。

    22
    PRAGMA vdbe_trace = ON; (1)
    PRAGMA vdbe_trace = OFF; (0)
    打开或关闭SQLite库中的虚拟数据库引擎追踪

    23
    PRAGMA vdbe_listing = ON; (1)
    PRAGMA vdbe_listing = OFF; (0)
    打开或关闭虚拟机程序列表，当开启列表功能，整个程序的内容在执行前被打印出来，
    就像在每条语句之前自动执行EXPLAIN. 语句在打印列表之后正常执行



    24

    PRAGMA table_info(表名称)

      */
}

