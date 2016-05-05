#ifndef GLODONTESTGRAMMAR_H
#define GLODONTESTGRAMMAR_H

#include <QPair>
#include "glodontestlib_global.h"
#include <QStringList>

#define DEFINE_CONSTSTR(name, value) const QString name = QStringLiteral(value);
#define DEFINE_CONST(name) extern const QString name;

DEFINE_CONSTSTR(xkd0,"xkjdlsjaf;dsj")
DEFINE_CONSTSTR(xkd1,"xkjdlsjaf;dsj")
DEFINE_CONSTSTR(xkd2,"xkjdlsjaf;dsj")
DEFINE_CONSTSTR(xkd3,"xkjdlsjaf;dsj")
DEFINE_CONSTSTR(xkd4,"xkjdlsjaf;dsj")
//DEFINE_CONST(string)

typedef QStringList GStrings;
typedef QList<int> GInts;

const GInts c_n2222RGb = GInts()<<1<<3<<2;
//const 必须在定义时同时被初始化
const GStrings c_n2009RGs = (GStrings()<<xkd0<<xkd1<<xkd2<<xkd3<<xkd4);


class WIDGETSHARED_EXPORT GlodonTestGrammar
{
public:
    GlodonTestGrammar();

    static void testPair();

    /**
      \brief 哈希表删除key以后，如果value是个指针，那么这个指针的内存还存在，需要自己删除
      */
    void testHashRemove();

    /**
      \brief
      */
    void testVariant();

    /**
     * @brief QStackWidget
     */
    void testStackWidget();

    /**
     * @brief testTabBar
     */
    void testTabBar();

    /**
     * @brief testLayout
     */
    void testLayout();

    /**
     * @brief 补全功能
     */
    static void testCompletor();

    /**
     * @brief testPushButton_Menu_ListWidget
     */
    static void testPushButton_Menu_ListWidget();
    /**
     * @brief testDir
     */
    static void testDir();

    /**
     * @brief testStaticFunction
     */
    static void testStaticFunction();

    /**
     * @brief testNew
     */
    static void testNew();

    /**
     * @brief testTry_Catch
     */
    static void testTry_Catch();
    /**
     * @brief testTreeWidget
     */
    static void testTreeWidget();

    /**
     * @brief 测试 tableView 窗口的列标题
     */
    static void testTableView();

    /**
     * @brief 测试换行
     */
    static void testEnter();

    /**
     * @brief testProcess
     */
    static void testProcess();

    /**
     * @brief testTextStream
     */
    static void testTextStream();
};

extern "C" __declspec(dllexport) int add(int a, int b);

#endif // GLODONTESTGRAMMAR_H
