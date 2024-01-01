#include "place.h"

Place::Place()
    : name(""), location(""), rating(0.0), description(""), additionalInfo(""), frontImgPath(""), roomImgPath(""),
      contactPhoneNumber(""), favoriteDish(new Dish())
{

}

Place::Place(QString new_name, QString new_location, double new_rating, QString new_number, QString new_description,
             QString new_additionalInfo, QString new_frontImgPath, QString new_roomImgPath, Dish *new_dish)
    : name(new_name), location(new_location), rating(new_rating), description(new_description),
      additionalInfo(new_additionalInfo), frontImgPath(new_frontImgPath), roomImgPath(new_roomImgPath),
      contactPhoneNumber(new_number), favoriteDish(new_dish)
{

}

Place::~Place()
{
   //delete favoriteDish;
}

QString Place::GetName()
{
   return name;
}

QString Place::GetLocation()
{
   return location;
}

double Place::GetRating()
{
   return rating;
}

QString Place::GetDescription()
{
   return description;
}

QString Place::GetAdditionalInfo()
{
   return additionalInfo;
}

QString Place::GetFrontImgPath()
{
   return frontImgPath;
}

QString Place::GetRoomImgPath()
{
   return roomImgPath;
}

QString Place::GetPhoneNumber()
{
   return contactPhoneNumber;
}

Dish* Place::GetFavoriteDish()
{
   return favoriteDish;
}

void Place::SetName(QString new_name)
{
   name = new_name;
}

void Place::SetLocation(QString new_location)
{
   location = new_location;
}

void Place::SetRating(double new_rating)
{
   rating = new_rating;
}

void Place::SetDescription(QString new_description)
{
   description = new_description;
}

void Place::SetAdditionalInfo(QString new_additionalInfo)
{
   additionalInfo = new_additionalInfo;
}

void Place::SetFrontImgPath(QString new_frontImgPath)
{
   frontImgPath = new_frontImgPath;
}

void Place::SetRoomImgPath(QString new_roomImgPath)
{
   roomImgPath = new_roomImgPath;
}

void Place::SetPhoneNumber(QString new_number)
{
   contactPhoneNumber = new_number;
}

void Place::SetFavoriteDish(Dish *new_dish)
{
   favoriteDish->SetName(new_dish->GetName());
   favoriteDish->SetPrice(new_dish->GetPrice());
   favoriteDish->SetDescription(new_dish->GetDescription());
   favoriteDish->SetWeight(new_dish->GetWeight());
   favoriteDish->SetIconPath(new_dish->GetIconPath());
}










