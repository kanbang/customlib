#ifndef GLODONDELPHI_H
#define GLODONDELPHI_H

#include "glodonlearn_global.h"

class GLODONLEARNSHARED_EXPORT GlodonDelphi
{
public:
    GlodonDelphi();


    void delphi_annote();
    void delphi_feature();
    void delphi_variable();
    void delphi_const();
    void delphi_operator();
    void delphi_object_pascal_type();
    void delphi_custome_type();
    void delphi_cast();
    void delphi_unit();
    /**
     * @brief Delphi 的窗体
     */
    void delphi_window();
    void delphi_create_window();
    void delphi_constructor();
    void delphi_class_object();

    void delphi_project();

private:

    /**
     \brief Delphi 字符 和 字符串
     */
    void delphi_char();
    void delphi_string();

    /**
      \brief 编译器指令
      */
    void delphi_compile_grammar();
};

#endif // GLODONDELPHI_H
