#ifndef FOOD_HEADER
#define FOOD_HEADER

#include <string>
#include <iostream>
class Food
{
public:
    // Constructors
    Food(std::string foodAndServing, int calories, int caloriesFromFat, double totalFatG, int totalFatDv,
         int sodiumG, int sodiumDv, int potassiumG, int potassiumDv, int totalCarboHydrateG, int totalCarboHydrateDv, int dietaryFiberG,
         int dieteryFiberDv, int sugarsG, int proteinG, int vitaminADv, int vitaminCDv, int calciumDv, int eeironeeDv,
         double saturatedFatDv, int saturatedFatMgE, int choleSterolDv, int choleSterolMgE,
         std::string foodType);
    Food() {};

    // Getters
    std::string getFoodAndServing() const { return _foodAndServing; }
    int getCalories() const { return _calories; }
    int getCaloriesFromFat() const { return _caloriesFromFat; }
    double getTotalFatG() const { return _totalFatG; }
    int getTotalFatDv() const { return _totalFatDv; }
    int getSodiumG() const { return _sodiumG; }
    int getSodiumDv() const { return _sodiumDv;}
    int getPotassiumG() const { return _potassiumG; }
    int getPotassiumDv() const { return _potassiumDv; }
    int getTotalCarboHydrateG() const { return _totalCarboHydrateG; }
    int getTotalCarboHydrateDv() const { return _totalCarboHydrateDv; }
    int getDietaryFiberG() const { return _dietaryFiberG; }
    int getDieteryFiberDv() const { return _dieteryFiberDv; }
    int getSugarsG() const { return _sugarsG; }
    int getProteinG() const { return _proteinG; }
    int getVitaminADv() const { return _vitaminADv; }
    int getVitaminCDv() const { return _vitaminCDv; }
    int getCalciumDv() const { return _calciumDv; }
    int getEeironeeDv() const { return _eeironeeDv; }
    double getSaturatedFatDv() const { return _saturatedFatDv; }
    int getSaturatedFatMgE() const { return _saturatedFatMgE; }
    int getCholeSterolDv() const { return _choleSterolDv; }
    int getCholeSterolMgE() const { return _choleSterolMgE; }
    std::string getFoodType() const { return _foodType; }
    // Setters: não há necessidade, uma vez que definimos como privado, não queremos que qualquer trecho altere um atributo a toa:
    // Uma vez que os dados são consistentes e lidos pelo csv, poder altera-los seria um tiro no pé.


    // Friend (para poder disponibilizar os atributos privados para o operador bitwise)
    friend std::ostream &operator<<(std::ostream &os, const Food &food);
private:
    std::string _foodAndServing;
    int _calories;
    int _caloriesFromFat;
    double _totalFatG;
    int _totalFatDv;
    int _sodiumG;
    int _sodiumDv;
    int _potassiumG;
    int _potassiumDv;
    int _totalCarboHydrateG;
    int _totalCarboHydrateDv;
    int _dietaryFiberG;
    int _dieteryFiberDv;
    int _sugarsG;
    int _proteinG;
    int _vitaminADv;
    int _vitaminCDv;
    int _calciumDv;
    int _eeironeeDv;
    double _saturatedFatDv;
    int _saturatedFatMgE;
    int _choleSterolDv;
    int _choleSterolMgE;
    std::string _foodType;
};
#endif