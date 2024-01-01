#include "mainrecep.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   MainRecep window;
   window.resize(1280, 700);
   window.setWindowFlags(Qt::FramelessWindowHint);
   window.show();
   return app.exec();
}
