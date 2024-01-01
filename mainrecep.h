#ifndef MAINRECEP_H
#define MAINRECEP_H

#include <QMainWindow>
#include <QIcon>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QFile>
#include <QMap>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>

#include "place.h"
#include "dish.h"

QT_BEGIN_NAMESPACE
    namespace Ui { class MainRecep; }
QT_END_NAMESPACE

    class MainRecep : public QMainWindow
{
   Q_OBJECT

   public:
   MainRecep(QWidget *parent = nullptr);
   ~MainRecep();

 private:
   QMap<QString, Place>* SearchList;

 private slots:
   void onMinimizeClicked();
   void onMaximizeClicked();
   void onCloseClicked();
   void SearchPlace();
   void HomePage();
   void AdditionalInfoPlace();
   void AddPage();
   void SetPlaceRoomIMG();
   void SetPlaceDishIMG();
   void SetPlaceLogoIMG();
   void addPlace();

 private:
   Ui::MainRecep *ui;
};
#endif // MAINRECEP_H
