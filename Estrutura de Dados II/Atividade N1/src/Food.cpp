#include "Food.h"
// Constructor
Food::Food(std::string foodAndServing, int calories, int caloriesFromFat, double totalFatG, int totalFatDv,
           int sodiumG, int sodiumDv, int potassiumDv, int totalCarboHydrateG, int totalCarboHydrateDv,
           int dietaryFiberG, int dieteryFiberDv, int sugarsG, int proteinG, int vitaminADv, int vitaminCDv,
           int calciumDv, int eeironeeDv, double saturatedFatDv, int saturatedFatMgE, int choleSterolDv,
           int choleSterolMgE, std::string foodType) : _foodAndServing(foodAndServing), _calories(calories),
                                                              _caloriesFromFat(caloriesFromFat), _totalFatG(totalFatG),
                                                              _totalFatDv(totalFatDv), _sodiumG(sodiumG),
                                                              _sodiumDv(sodiumDv), _potassiumDv(potassiumDv),
                                                              _totalCarboHydrateG(totalCarboHydrateG),
                                                              _totalCarboHydrateDv(totalCarboHydrateDv),
                                                              _dietaryFiberG(dietaryFiberG),
                                                              _dieteryFiberDv(dieteryFiberDv), _sugarsG(sugarsG),
                                                              _proteinG(proteinG), _vitaminADv(vitaminADv),
                                                              _vitaminCDv(vitaminCDv), _calciumDv(calciumDv),
                                                              _eeironeeDv(eeironeeDv), _saturatedFatDv(saturatedFatDv),
                                                              _saturatedFatMgE(saturatedFatMgE),
                                                              _choleSterolDv(choleSterolDv),
                                                              _choleSterolMgE(choleSterolMgE), _foodType(foodType)
{}

// Ostream operator
std::ostream &operator<<(std::ostream &os, const Food &food)
{
    os << "FoodAndServing: " << food._foodAndServing << std::endl
       << "Calories: " << food._calories << std::endl
       << "CaloriesFromFat: " << food._caloriesFromFat << std::endl
       << "TotalFatG: " << food._totalFatG << std::endl
       << "TotalFatDv: " << food._totalFatDv << std::endl
       << "SodiumG: " << food._sodiumG << std::endl
       << "SodiumDv: " << food._sodiumDv  << std::endl
       << "PotassiumDv: " << food._potassiumDv << std::endl
       << "TotalCarboHydrateG: " << food._totalCarboHydrateG << std::endl
       << "TotalCarboHydrateDv: " << food._totalCarboHydrateDv << std::endl
       << "DietaryFiberG: " << food._dietaryFiberG << std::endl
       << "DieteryFiberDv: " << food._dieteryFiberDv << std::endl
       << "SugarsG: " << food._sugarsG << std::endl
       << "ProteinG: " << food._proteinG << std::endl
       << "VitaminADv: " << food._vitaminADv << std::endl
       << "VitaminCDv: " << food._vitaminCDv << std::endl
       << "CalciumDv: " << food._calciumDv << std::endl
       << "EeironeeDv: " << food._eeironeeDv << std::endl
       << "SaturatedFatDv: " << food._saturatedFatDv << std::endl
       << "SaturatedFatMgE: " << food._saturatedFatMgE << std::endl
       << "CholeSterolDv: " << food._choleSterolDv << std::endl
       << "CholeSterolMgE: " << food._choleSterolMgE << std::endl
       << "FoodType: " << food._foodType << std::endl;
    return os;
}

