// Participante                            |  TIA
// FABIO DOMINGUES PEREIRA SABINO          - 32154429
// JOAO VITOR BOS CASTELLI                 - 32130430
// MAYARA MENEGHETTI HONDA                 - 32152280
// PAULO HENRIQUE BRAGA CECHINEL           - 32151128
// RICARDO GABRIEL MARQUES DOS SANTOS RUIZ - 32134908

#include "Food.h"
// Constructor
Food::Food(std::string foodAndServing, int calories, int caloriesFromFat, double totalFatG, int totalFatDv,
           int sodiumG, int sodiumDv,int potassiumG, int potassiumDv, int totalCarboHydrateG, int totalCarboHydrateDv,
           int dietaryFiberG, int dieteryFiberDv, int sugarsG, int proteinG, int vitaminADv, int vitaminCDv,
           int calciumDv, int eeironeeDv, double saturatedFatDv, int saturatedFatMgE, int choleSterolDv,
           int choleSterolMgE, std::string foodType) : _foodAndServing(foodAndServing), _calories(calories),
                                                              _caloriesFromFat(caloriesFromFat), _totalFatG(totalFatG),
                                                              _totalFatDv(totalFatDv), _sodiumG(sodiumG),
                                                              _sodiumDv(sodiumDv), _potassiumG(potassiumG),
                                                              _potassiumDv(potassiumDv), _totalCarboHydrateG(totalCarboHydrateG),
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
// Aqui imprimimos a tabela nutricional ao chamar o cout em um objeto da classe
std::ostream &operator<<(std::ostream &os, const Food &food)
{   
    std::string card = "|" + food._foodAndServing + "|";
    os << std::setfill('_') << std::setw(food._foodAndServing.size() + 2) << "" << std::endl;
    os << std::left << std::setfill('_') << std::setw(20) << card  << std::setw(67) << "" << std::endl;
    os << std::setfill(' ');
    os.flush();
    os << std::left << std::setw(30) << "|Calories" << "|" << std::setw(55) << food._calories << "|" << std::endl
       << std::left << std::setw(30) << "|CaloriesFromFat" << "|" << std::setw(55) << food._caloriesFromFat << "|" << std::endl
       << std::left << std::setw(30) << "|TotalFatG (g)" << "|" << std::setw(55) << food._totalFatG << "|"  << std::endl
       << std::left << std::setw(30) << "|TotalFatDv (%)" << "|" << std::setw(55) << food._totalFatDv << "|"  << std::endl
       << std::left << std::setw(30) << "|SodiumG (g)" << "|" << std::setw(55) << food._sodiumG << "|"  << std::endl
       << std::left << std::setw(30) << "|SodiumDv (%)" << "|" << std::setw(55) << food._sodiumDv << "|"  << std::endl
       << std::left << std::setw(30) << "|PotassiumG (g)" << "|" << std::setw(55) << food._potassiumG << "|"  << std::endl
       << std::left << std::setw(30) << "|PotassiumDv (%)" << "|" << std::setw(55) << food._potassiumDv << "|"  << std::endl
       << std::left << std::setw(30) << "|TotalCarboHydrateG (g)" << "|" << std::setw(55) << food._totalCarboHydrateG  << "|"  << std::endl
       << std::left << std::setw(30) << "|TotalCarboHydrateDv (%)" << "|" << std::setw(55) << food._totalCarboHydrateDv <<  "|"  << std::endl
       << std::left << std::setw(30) << "|DietaryFiberG (g)" << "|" << std::setw(55) << food._dietaryFiberG << "|"  << std::endl
       << std::left << std::setw(30) << "|DieteryFiberDv (%)" << "|" << std::setw(55) << food._dieteryFiberDv << "|"  << std::endl
       << std::left << std::setw(30) << "|SugarsG (g)" << "|" << std::setw(55) << food._sugarsG << "|"  << std::endl
       << std::left << std::setw(30) << "|ProteinG (g)" << "|" << std::setw(55) << food._proteinG << "|"  << std::endl
       << std::left << std::setw(30) << "|VitaminADv (%)" << "|" << std::setw(55) << food._vitaminADv << "|"  << std::endl
       << std::left << std::setw(30) << "|VitaminCDv (%)" << "|" << std::setw(55) << food._vitaminCDv << "|"  << std::endl
       << std::left << std::setw(30) << "|CalciumDv (%)" << "|" << std::setw(55) << food._calciumDv << "|"  << std::endl
       << std::left << std::setw(30) << "|EeironeeDv (%)" << "|" << std::setw(55) << food._eeironeeDv << "|"  << std::endl
       << std::left << std::setw(30) << "|SaturatedFatDv (%)" << "|" << std::setw(55) << food._saturatedFatDv << "|"  << std::endl
       << std::left << std::setw(30) << "|SaturatedFatMgE (mg)" << "|" << std::setw(55) << food._saturatedFatMgE << "|"  << std::endl
       << std::left << std::setw(30) << "|CholeSterolDv (%)" << "|" << std::setw(55) << food._choleSterolDv << "|"  << std::endl
       << std::left << std::setw(30) << "|CholeSterolMgE (mg)" << "|" << std::setw(55) << food._choleSterolMgE << "|"  << std::endl
       << std::left << std::setw(30) << "|FoodType" << "|" << std::setw(55) << food._foodType << "|" << std::endl;
    os << "|_____________________________________________________________________________________|" << std::endl;
    
    return os;
}
