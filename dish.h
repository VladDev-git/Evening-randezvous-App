#ifndef DISH_H
#define DISH_H

#include <QString>

class Dish
{
 public:
   Dish();
   Dish(QString new_name, QString new_price, QString new_description, QString new_weight, QString new_iconPath);
   Dish(Dish& new_dish);

   ~Dish();

   QString GetName();
   QString GetPrice();
   QString GetDescription();
   QString GetWeight();
   QString GetIconPath();

   void SetName(QString new_name);
   void SetPrice(QString new_price);
   void SetDescription(QString new_description);
   void SetWeight(QString new_weight);
   void SetIconPath(QString new_iconPath);

 private:
   QString name;
   QString price;
   QString description;
   QString weight;
   QString iconPath;
};

#endif // DISH_H
