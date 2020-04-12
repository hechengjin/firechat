#include "boxes/main_widget.h"
#include <QApplication>
#include <QTranslator>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

    QTranslator translator_zh;
    translator_zh.load(QString(":/qm/language_zh"));
    app.installTranslator(&translator_zh);


    QSharedMemory shared_memory;
    shared_memory.setKey(QString("main_window"));

    if(shared_memory.attach())
    {
        return 0;
    }

    if(shared_memory.create(1))
    {
        MainWidget main_widget;
        main_widget.setTranslator(&translator_zh);
        main_widget.translateLanguage();
        main_widget.showWidget();

        return app.exec();
    }
}
