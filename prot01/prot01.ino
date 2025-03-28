//Маркеры памяти
//void - пустота - космос - ничего - не использует память
//int  - интеджер - целое - память для чисел 12345
//char - символы - буквы
//long - для всего
//------setup - Название
//------() - круглые скобки (SHIFT+9, SHIFT+0) настройки
//------{} - фигурные скобки (SHIFT+Х, SHIFT+Ъ) Начало и конец
//Сложных приказов
//-слэш - разрез /слэш в гору \слэш с горы

const int PIN_BUTTON1 = 2;  //кнопка 1
const int PIN_BUTTON2 = 3;  //кнопка 2
//----------------------------------------
#include "TM1637Display.h"

TM1637Display display(3, 2);  // CLC, DIO

const uint8_t tire = { SEG_G // - };
const uint8_t C = { SEG_A | SEG_F | SEG_E | SEG_D // C };
const uint8_t DONE = { SEG_B | SEG_C | SEG_D | SEG_E | SEG_G, // d SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O SEG_C | SEG_E | SEG_G, // n SEG_A | SEG_D | SEG_E | SEG_F | SEG_G // E };
//--------------------------------------------------

//Музыка - mus() 
void mus() {

}
//послушать и выбрать позже

//Игра - play()
void play() {
  return score;
}


//проверить кнопку1
void knop_one() {
  // Получаем состояние кнопки
    int buttonState1 = digitalRead(PIN_BUTTON1);
    Serial.println(buttonState1);
    // Если кнопка не нажата, то ничего не делаем
    if (!buttonState1) {
        delay(50);
        return;
    }
}
//проверить кнопку2
void knop_too() {
  // Получаем состояние кнопки
    int buttonState2 = digitalRead(PIN_BUTTON2);
    Serial.println(buttonState2);
    // Если кнопка не нажата, то ничего не делаем
    if (!buttonState2) {
        delay(50);
        return;
    }
}
//засветить пиксель на матрице
void pik_in_mat(nom,color) {
  
}
//очистить матрицу
void clear_mat() {
  
}

// вывести чичсло на индикатор счекта  индикатор 4 сегмента tm1637
void indikator(score) {
    display.showNumberDec(1, true, 1, 0);  // 1___
  delay(500);
  display.showNumberDec(2, true, 1, 1);  // 12__
  delay(500);
  display.showNumberDec(3, true, 1, 2);  // 123_
  delay(500);
  display.showNumberDec(4, true, 1, 3);  // 1234
  delay(500);
  display.clear();
  display.showNumberDec(00, true, 2, 1);  // _00_
  delay(500);
  display.setSegments(C, 1, 3);  // _00C
  delay(500);
  display.clear();  display.showNumberDec(1, true, 1, 0);  // 1___
  delay(500);
  display.showNumberDec(2, true, 1, 1);  // 12__
  delay(500);
  display.showNumberDec(3, true, 1, 2);  // 123_
  delay(500);
  display.showNumberDec(4, true, 1, 3);  // 1234
  delay(500);
  display.clear();
  display.showNumberDec(00, true, 2, 1);  // _00_
  delay(500);
  display.setSegments(C, 1, 3);  // _00C
  delay(500);
  display.clear();
}
void setup() {       
  int s=0;
  //
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);

  //--------------------------------

  display.setBrightness(4);  // яркость от 0 до 7, true/false
  display.clear();
  display.setSegments(tire, 1, 0);  // -___
  delay(200);
  display.setSegments(tire, 1, 1);  // _-__
  delay(200);
  display.setSegments(tire, 1, 2);  // __-_
  delay(200);
  display.setSegments(tire, 1, 3);  // ___-
  delay(200);
  display.clear();
  display.setSegments(DONE, 4, 0);  // dOnE
  delay(500);
  display.clear();
  //---------------------------------------------------
}

// matrix[64]={
//   1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,
//   9 ,10,11,12,13,14,15,16,
//   17,18,19,20,21,22,23,24,
//   25,26,27,28,29,30,31,32,
//   33,34,35,36,37,38,39,40,
//   41,42,43,44,45,46,47,48,
//   49,50,51,52,53,54,55,56,
//   57,58,59,60,61,62,63,64
// }

void loop() {
  // Переход Триггеры


  // ----------------
  // Состояния:
  // Ждать
  if (s==1) {
    while (!knop_too() or !knop_one()){

    }
  }
  // Подготовка
  if (s==2) {

  }
  // Игра
  if (s==3) {
    score=play();
    s=4;
  }
  // Конец
  if (s==4) {
    indikator(score)
    clear_mat()
  }
  // Разряжен
  if (s==5) {

  }
}