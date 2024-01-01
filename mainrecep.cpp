#include "mainrecep.h"
#include "ui_mainrecep.h"

void HomeAnimationPack(Ui::MainRecep *ui);
void SearhAnimationPack(Ui::MainRecep* ui);
void AddList(QMap<QString, Place>* list, QListWidget* widget);

MainRecep::MainRecep(QWidget *parent)
   : QMainWindow(parent), ui(new Ui::MainRecep)
{
   ui->setupUi(this);

   connect(ui->minimizeWinBtn, SIGNAL(clicked()), this, SLOT(onMinimizeClicked()));
   connect(ui->restoreWinBtn, SIGNAL(clicked()), this, SLOT(onMaximizeClicked()));
   connect(ui->closeWinRBtn, SIGNAL(clicked()), this, SLOT(onCloseClicked()));
   connect(ui->searchPlaceBtn, SIGNAL(clicked()), this, SLOT(SearchPlace()));
   connect(ui->homeStartBtn, SIGNAL(clicked()), this, SLOT(SearchPlace()));
   connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(HomePage()));
   connect(ui->additionalBtn, SIGNAL(clicked()), this, SLOT(AdditionalInfoPlace()));
   connect(ui->addPlaceBtn, SIGNAL(clicked()), this, SLOT(AddPage()));
   connect(ui->SetRoomIMGbtn, SIGNAL(clicked()), this, SLOT(SetPlaceRoomIMG()));
   connect(ui->SetDishIMGbtn, SIGNAL(clicked()), this, SLOT(SetPlaceDishIMG()));
   connect(ui->SetLogoIMGbtn, SIGNAL(clicked()), this, SLOT(SetPlaceLogoIMG()));

   // Home page

   HomeAnimationPack(ui);

   // Search Place page

   SearchList = new QMap<QString, Place>();
   QFile file("C:/cpp/projectsQt/LB_OOP_4/Files/PlaceList.txt");

   if(file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
      QTextStream in(&file);
      while (!in.atEnd())
      {
         QString name = in.readLine();
         QString location = in.readLine();
         double rating = in.readLine().toDouble();
         QString contactPhoneNumber = in.readLine();
         QString description = in.readLine();
         QString additionalInfo = in.readLine();
         QString frontImgPath = in.readLine();
         QString roomImgPath = in.readLine();
         QString DishName = in.readLine();
         QString price = in.readLine();
         QString DishDescription = in.readLine();
         QString weight = in.readLine();
         QString iconPath = in.readLine();
         Dish* UsDish = new Dish(DishName, price, DishDescription, weight, iconPath);

         (*SearchList)[name] = Place(name, location, rating, contactPhoneNumber, description, additionalInfo,
                                  frontImgPath, roomImgPath, UsDish);
      }

      file.close();
   }

   AddList(SearchList, ui->placeList);


}

MainRecep::~MainRecep()
{
   delete ui;
}

void MainRecep::onMinimizeClicked()
{
   if (auto *mainWindow = qobject_cast<QMainWindow *>(window()))
   {
      mainWindow->showMinimized();
   }
}

void MainRecep::onMaximizeClicked()
{
   if(auto *mainWindow = qobject_cast<QMainWindow *>(window()))
   {
      if(mainWindow->isMaximized())
      {
         QIcon newIcon("C:/cpp/projectsQt/LB_OOP_4/Imegs and Icon/icon/square.svg");
         ui->restoreWinBtn->setIcon(newIcon);

         mainWindow->showNormal();
      }
      else
      {
         QIcon newIcon("C:/cpp/projectsQt/LB_OOP_4/Imegs and Icon/icon/normalSize.svg");
         ui->restoreWinBtn->setIcon(newIcon);

         mainWindow->showMaximized();
      }
   }
}

void MainRecep::onCloseClicked()
{
   if(auto *mainWindow = qobject_cast<QMainWindow *>(window()))
   {
      mainWindow->close();
   }
}

void MainRecep::SearchPlace()
{
   ui->stackedWidget->setCurrentIndex(1);
   SearhAnimationPack(ui);
}

void MainRecep::HomePage()
{
   ui->stackedWidget->setCurrentIndex(0);
   HomeAnimationPack(ui);
}

void MainRecep::AddPage()
{
   ui->stackedWidget->setCurrentIndex(3);
}

void MainRecep::AdditionalInfoPlace()
{
   QListWidgetItem* curItem = ui->placeList->currentItem();
   QString name = curItem->data(Qt::UserRole).toString();

   ui->placeNameLbl->setText(name);
   ui->placeAdressLbl->setText((*SearchList)[name].GetLocation());
   ui->placeRatingLbl->setText(QString::number((*SearchList)[name].GetRating()));
   ui->placeNumberLbl->setText((*SearchList)[name].GetPhoneNumber());
   ui->placeDescriptionLbl->setText((*SearchList)[name].GetAdditionalInfo());
   QPixmap pixmapRoom((*SearchList)[name].GetRoomImgPath());
   ui->roomImgLbl->setPixmap(pixmapRoom);
   QPixmap pixmapDish((*SearchList)[name].GetFavoriteDish()->GetIconPath());
   ui->dishImgLbl->setPixmap(pixmapDish);
   ui->dishNameLbl->setText((*SearchList)[name].GetFavoriteDish()->GetName());
   ui->dishPriceLbl->setText((*SearchList)[name].GetFavoriteDish()->GetPrice());
   ui->dishDescriptionLbl->setText((*SearchList)[name].GetFavoriteDish()->GetDescription());
   ui->dishWeightLbl->setText((*SearchList)[name].GetFavoriteDish()->GetWeight());

   ui->stackedWidget->setCurrentIndex(2);
}

void MainRecep::SetPlaceRoomIMG()
{
   QString filePath = QFileDialog::getOpenFileName(this, tr("Select an image"), "", tr("Image (*.png *.jpg *.bmp *.svg *.jfif *.jpeg)"));

   if(!filePath.isEmpty())
   {
      QPixmap pixmap(filePath);
      ui->addPlaceRoomLBL->setPixmap(pixmap.scaled(ui->addPlaceRoomLBL->size(), Qt::KeepAspectRatio));
   }

}

void MainRecep::SetPlaceDishIMG()
{
   QString filePath = QFileDialog::getOpenFileName(this, tr("Select an image"), "", tr("Image (*.png *.jpg *.bmp *.svg *.jfif *.jpeg)"));

   if(!filePath.isEmpty())
   {
      QPixmap pixmap(filePath);
      ui->addPlaceDishLBL->setPixmap(pixmap.scaled(ui->addPlaceDishLBL->size(), Qt::KeepAspectRatio));
   }
}

void MainRecep::SetPlaceLogoIMG()
{
   QString filePath = QFileDialog::getOpenFileName(this, tr("Select an image"), "", tr("Image (*.png *.jpg *.bmp *.svg *.jfif *.jpeg)"));

   if(!filePath.isEmpty())
   {
      QPixmap pixmap(filePath);
      ui->addPlaceLogoLBL->setPixmap(pixmap.scaled(ui->addPlaceLogoLBL->size(), Qt::KeepAspectRatio));
   }
}

void MainRecep::addPlace()
{
   if(ui->addPlaceName->text().isEmpty())
   {

   }
   else if(ui->addPlaceAddres->text().isEmpty())
   {

   }
   else if(ui->addPlaceRating->text().isEmpty())
   {

   }
   else if(ui->addPlaceContactNumber->text().isEmpty())
   {

   }
   else if(ui->addPlaceDiscription->text().isEmpty())
   {

   }
   else if(ui->addPlaceDishName->text().isEmpty())
   {

   }
   else if(ui->addPlaceDishPrice->text().isEmpty())
   {

   }
   else if(ui->addPlaceIngradient->text().isEmpty())
   {

   }
   else if(ui->addPlaceWeight->text().isEmpty())
   {

   }
   else
   {
      Dish* addNewDish = new Dish(ui->addPlaceDishName->text(), ui->addPlaceDishPrice->text(), ui->addPlaceIngradient->text(),
         ui->addPlaceWeight->text(), QString::number(ui->addPlaceDishLBL->pixmap().cacheKey()));

      (*SearchList)[ui->addPlaceName->text()] = Place(ui->addPlaceName->text(), ui->addPlaceAddres->text(),
         ui->addPlaceRating->text().toDouble(), ui->addPlaceContactNumber->text(), ui->addPlaceDiscription->text(), "",
         QString::number(ui->addPlaceLogoLBL->pixmap().cacheKey()), QString::number(ui->addPlaceRoomLBL->pixmap().cacheKey()), addNewDish);
   }
}

void HomeAnimationPack(Ui::MainRecep* ui)
{
   // v1
   //   QPropertyAnimation* animation = new QPropertyAnimation(ui->homeStartLbl, "geometry");
   //   animation->setDuration(2000);
   //   animation->setStartValue(QRect(0,10,200,30));
   //   animation->setEndValue(QRect(0,52,577,128));
   //   animation->start();

   // v2
   QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(ui->homeStartLbl);
   ui->homeStartLbl->setGraphicsEffect(opacityEffect);
   QPropertyAnimation* animation = new QPropertyAnimation(opacityEffect, "opacity");
   animation->setDuration(2200);
   animation->setStartValue(0.0);
   animation->setEndValue(1.0);
   animation->start();


   QPropertyAnimation* welcomeAnimation = new QPropertyAnimation(ui->welcomeLbl, "geometry");
   welcomeAnimation->setDuration(1300);
   welcomeAnimation->setStartValue(QRect(400, 0, 80, 40));
   welcomeAnimation->setEndValue(QRect(439, 0, 138, 52));
   welcomeAnimation->start();


   QGraphicsOpacityEffect* opEffectPhoto1 = new QGraphicsOpacityEffect(ui->HomePhoto1);
   ui->HomePhoto1->setGraphicsEffect(opEffectPhoto1);
   QPropertyAnimation* animPhoto1 = new QPropertyAnimation(opEffectPhoto1, "opacity");
   animPhoto1->setDuration(2200);
   animPhoto1->setStartValue(0.0);
   animPhoto1->setEndValue(1.0);
   animPhoto1->start();


   QGraphicsOpacityEffect* opEffectInf1 = new QGraphicsOpacityEffect(ui->homeInfoLbl);
   ui->homeInfoLbl->setGraphicsEffect(opEffectInf1);
   QPropertyAnimation* animInfo1 = new QPropertyAnimation(opEffectInf1, "opacity");
   animInfo1->setDuration(2200);
   animInfo1->setStartValue(0.0);
   animInfo1->setEndValue(1.0);
   animInfo1->start();


   //   QGraphicsOpacityEffect* opEffectPhoto2 = new QGraphicsOpacityEffect(ui->homeFrontPhotoLbl);
   //   ui->homeFrontPhotoLbl->setGraphicsEffect(opEffectPhoto2);
   //   QPropertyAnimation* animPhoto2 = new QPropertyAnimation(opEffectPhoto2, "opacity");
   //   animPhoto2->setDuration(2200);
   //   animPhoto2->setStartValue(0.0);
   //   animPhoto2->setEndValue(1.0);
   //   animPhoto2->start();


   QGraphicsOpacityEffect* opEffectBtn1 = new QGraphicsOpacityEffect(ui->homeStartBtn);
   ui->homeStartBtn->setGraphicsEffect(opEffectBtn1);
   QPropertyAnimation* animBtn1 = new QPropertyAnimation(opEffectBtn1, "opacity");
   animBtn1->setDuration(2200);
   animBtn1->setStartValue(0.0);
   animBtn1->setEndValue(1.0);
   animBtn1->start();
}

void SearhAnimationPack(Ui::MainRecep* ui)
{
   QPropertyAnimation* titleImgAnimation = new QPropertyAnimation(ui->titleSearhImgLbl, "geometry");
   titleImgAnimation->setDuration(1300);
   titleImgAnimation->setStartValue(QRect(0, 0, 30, 30));
   titleImgAnimation->setEndValue(QRect(0, 0, 50, 50));
   titleImgAnimation->start();


   QPropertyAnimation* titleAnimation = new QPropertyAnimation(ui->titleSearhLbl, "geometry");
   titleAnimation->setDuration(1300);
   titleAnimation->setStartValue(QRect(5, 0, 300, 30));
   titleAnimation->setEndValue(QRect(11, 0, 965, 50));
   titleAnimation->start();


   QGraphicsOpacityEffect* opEffectBtn1 = new QGraphicsOpacityEffect(ui->searchFrontImg);
   ui->searchFrontImg->setGraphicsEffect(opEffectBtn1);
   QPropertyAnimation* animImg1 = new QPropertyAnimation(opEffectBtn1, "opacity");
   animImg1->setDuration(2200);
   animImg1->setStartValue(0.0);
   animImg1->setEndValue(1.0);
   animImg1->start();


   QGraphicsOpacityEffect* opEffectBtn2 = new QGraphicsOpacityEffect(ui->searchDescpLbl);
   ui->searchDescpLbl->setGraphicsEffect(opEffectBtn2);
   QPropertyAnimation* animLbl1 = new QPropertyAnimation(opEffectBtn2, "opacity");
   animLbl1->setDuration(2200);
   animLbl1->setStartValue(0.0);
   animLbl1->setEndValue(1.0);
   animLbl1->start();


   QGraphicsOpacityEffect* opEffectBtn3 = new QGraphicsOpacityEffect(ui->searhBtnLbl1);
   ui->searhBtnLbl1->setGraphicsEffect(opEffectBtn3);
   QPropertyAnimation* animLbl2 = new QPropertyAnimation(opEffectBtn3, "opacity");
   animLbl2->setDuration(2200);
   animLbl2->setStartValue(0.0);
   animLbl2->setEndValue(1.0);
   animLbl2->start();


   QGraphicsOpacityEffect* opEffectBtn4 = new QGraphicsOpacityEffect(ui->searchBtnLbl2);
   ui->searchBtnLbl2->setGraphicsEffect(opEffectBtn4);
   QPropertyAnimation* animLbl3 = new QPropertyAnimation(opEffectBtn4, "opacity");
   animLbl3->setDuration(2200);
   animLbl3->setStartValue(0.0);
   animLbl3->setEndValue(1.0);
   animLbl3->start();


   QGraphicsOpacityEffect* opEffectBtn5 = new QGraphicsOpacityEffect(ui->roomImgLbl);
   ui->roomImgLbl->setGraphicsEffect(opEffectBtn5);
   QPropertyAnimation* animImg2 = new QPropertyAnimation(opEffectBtn5, "opacity");
   animImg2->setDuration(2500);
   animImg2->setStartValue(0.0);
   animImg2->setEndValue(1.0);
   animImg2->start();


   QGraphicsOpacityEffect* opEffectBtn6 = new QGraphicsOpacityEffect(ui->dishImgLbl);
   ui->dishImgLbl->setGraphicsEffect(opEffectBtn6);
   QPropertyAnimation* animImg3 = new QPropertyAnimation(opEffectBtn6, "opacity");
   animImg3->setDuration(2500);
   animImg3->setStartValue(0.0);
   animImg3->setEndValue(1.0);
   animImg3->start();
}

void AddList(QMap<QString, Place>* list, QListWidget* widget)
{
   for(QMap<QString, Place>::iterator it = list->begin(); it != list->end(); ++it)
   {
      QString name = it.value().GetName();
      QString path = it.value().GetFrontImgPath();
      QListWidgetItem* item = new QListWidgetItem(QIcon(path), name.simplified());
      item->setData(Qt::UserRole, name);
      widget->addItem(item);
   }
}









