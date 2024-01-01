#include "dish.h"

Dish::Dish()
    : name(""), price(""), description(""), weight(""), iconPath("")
{

}

Dish::Dish(QString new_name, QString new_price, QString new_description, QString new_weight, QString new_iconPath)
    : name(new_name), price(new_price), description(new_description), weight(new_weight), iconPath(new_iconPath)
{

}

Dish::Dish(Dish &new_dish)
{
   name = new_dish.GetName();
   price = new_dish.GetPrice();
   description = new_dish.GetDescription();
   weight = new_dish.GetWeight();
   iconPath = new_dish.GetIconPath();
}

Dish::~Dish()
{

}

QString Dish::GetName()
{
   return name;
}

QString Dish::GetPrice()
{
   return price;
}

QString Dish::GetDescription()
{
   return description;
}

QString Dish::GetWeight()
{
   return weight;
}

QString Dish::GetIconPath()
{
   return iconPath;
}

void Dish::SetName(QString new_name)
{
   name = new_name;
}

void Dish::SetPrice(QString new_price)
{
   price = new_price;
}

void Dish::SetDescription(QString new_description)
{
   description = new_description;
}

void Dish::SetWeight(QString new_weight)
{
   weight = new_weight;
}

void Dish::SetIconPath(QString new_iconPath)
{
   iconPath = new_iconPath;
}











