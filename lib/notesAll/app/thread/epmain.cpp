#include <ETAllHeader.h>
#include <threadSignalSlot.h>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    threadWindowApp w;

    w.show();
    return app.exec();
}
