#ifndef LPGEOANALYST_H
#define LPGEOANALYST_H

class LPgeoanalyst
{
public:

    /**
      @brief    测井解释模块软件的感想

    */
    LPgeoanalyst();

    /**
     \brief     坐标转换，伸缩。
     */
    void    scaleAndTransform();
    /**
     \brief     添加地震剖面的思路过程
     */
    void    addSeismicSectionThought();
    /**
     \brief     小层连接的思路
     */
    void    linker();
};

#endif // LPGEOANALYST_H
