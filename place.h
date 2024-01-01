#ifndef PLACE_H
#define PLACE_H

#include"dish.h"

#include <QString>
#include <QStringList>

class Place
{
 public:
   Place();
   Place(   QString new_name, QString new_location, double new_rating, QString new_number, QString new_description,
         QString new_additionalInfo, QString new_frontImgPath, QString new_roomImgPath, Dish* new_dish);

   ~Place();

   QString GetName();
   QString GetLocation();
   double GetRating();
   QString GetDescription();
   QString GetAdditionalInfo();
   QString GetFrontImgPath();
   QString GetRoomImgPath();
   QString GetPhoneNumber();
   Dish* GetFavoriteDish();

   void SetName(QString new_name);
   void SetLocation(QString new_location);
   void SetRating(double new_rating);
   void SetDescription(QString new_description);
   void SetAdditionalInfo(QString new_additionalInfo);
   void SetFrontImgPath(QString new_frontImgPath);
   void SetRoomImgPath(QString new_roomImgPath);
   void SetPhoneNumber(QString new_number);
   void SetFavoriteDish(Dish* new_dish);

 private:
   QString name;
   QString location;
   double rating;
   QString contactPhoneNumber;
   QString description;
   QString additionalInfo;
   QString frontImgPath;
   QString roomImgPath;
   Dish* favoriteDish;
};

#endif // PLACE_H
