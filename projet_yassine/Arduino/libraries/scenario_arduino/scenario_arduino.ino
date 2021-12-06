
#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD


const int RS=2; 
const int E=3; 

const int D4=4; 
const int D5=5; 
const int D6=6; 
const int D7=7; 


LiquidCrystal lcd(RS, E, D4, D5, D6, D7);// initialisation LCD en mode 4 bits

//**************** FONCTION SETUP = Code d'initialisation *****

void setup()   { // debut de la fonction setup()


lcd.begin(20,4); 

delay(10); 

lcd.print("LCD OK") ; 
delay(2000); 

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran

} 
void loop(){ // debut de la fonction loop()

lcd.print("Arduino...") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.setCursor(9, 1) ;  
lcd.print("...pour te") ;
delay(2000); // pause de 2 secondes

lcd.setCursor(4, 2) ;
lcd.print("...servir") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.setCursor(12, 3) ; 
lcd.print("...amigo") ; 
delay(2000); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran
