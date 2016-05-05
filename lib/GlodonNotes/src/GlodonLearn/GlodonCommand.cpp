#include "GlodonCommand.h"

GlodonCommand::GlodonCommand()
{
}

void GlodonCommand::dir()
{
    /**
    @ dir /b /s /a :-D

      */
}

void GlodonCommand::find()
{
    /**
      从D盘中查找文件名有 GBQ 字符的文件
    @ dir D: /s /b | find "GBQ"

      从当前文件中查找文件名有 GBQMainForm.h 字符的文件
    @ dir . /s /b | find "GBQMainForm.h"
      */
}
