#define BAUD_RATE 9600

#define ROW_0_PIN 2
#define ROW_1_PIN 3
#define ROW_2_PIN 4
#define ROW_3_PIN 5
#define ROW_4_PIN 6

#define COL_0_PIN 35
#define COL_1_PIN 37
#define COL_2_PIN 39
#define COL_3_PIN 41
#define COL_4_PIN 43
#define COL_5_PIN 45
#define COL_6_PIN 47
#define COL_7_PIN 49
#define COL_8_PIN 51
#define COL_9_PIN 53

void setup() 
{
  //Setup serial communications.
  Serial.begin(BAUD_RATE);

  //Setup matrix row pins.
  pinMode(ROW_0_PIN, OUTPUT);
  pinMode(ROW_1_PIN, OUTPUT);
  pinMode(ROW_2_PIN, OUTPUT);
  pinMode(ROW_3_PIN, OUTPUT);
  pinMode(ROW_4_PIN, OUTPUT);
  digitalWrite(ROW_0_PIN, LOW);
  digitalWrite(ROW_1_PIN, LOW);
  digitalWrite(ROW_2_PIN, LOW);
  digitalWrite(ROW_3_PIN, LOW);
  digitalWrite(ROW_4_PIN, LOW);
  
  //Setup matrix column pins.
  pinMode(COL_0_PIN, OUTPUT);
  pinMode(COL_1_PIN, OUTPUT);
  pinMode(COL_2_PIN, OUTPUT);
  pinMode(COL_3_PIN, OUTPUT);
  pinMode(COL_4_PIN, OUTPUT);
  pinMode(COL_5_PIN, OUTPUT);
  pinMode(COL_6_PIN, OUTPUT);
  pinMode(COL_7_PIN, OUTPUT);
  pinMode(COL_8_PIN, OUTPUT);
  pinMode(COL_9_PIN, OUTPUT);
  digitalWrite(COL_0_PIN, HIGH);
  digitalWrite(COL_1_PIN, HIGH);
  digitalWrite(COL_2_PIN, HIGH);
  digitalWrite(COL_3_PIN, HIGH);
  digitalWrite(COL_4_PIN, HIGH);
  digitalWrite(COL_5_PIN, HIGH);
  digitalWrite(COL_6_PIN, HIGH);
  digitalWrite(COL_7_PIN, HIGH);
  digitalWrite(COL_8_PIN, HIGH);
  digitalWrite(COL_9_PIN, HIGH);
}

void loop() 
{
  decoder();
  plexer();
}

unsigned char led_state[50] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  5, 5, 5, 5, 5, 5, 5, 5, 5, 5
};

void decoder()
{
  static int led_index = 0;

  //No data.
  if(!Serial.available())
    return;
  
  char ch = Serial.read();

  //End of data, reset.
  if(ch == '\n') {
    led_index = 0;
    return;
  }

  //Invalid data.
  if(ch < 48 || ch > 57)
    return;
  
  led_state[led_index] = ch - 48;

  //Increment for next function call.
  if(++led_index >= 50)
    led_index = 0;
}

void plexer()
{
  static int led_index = 0;
  static int row_pin = 2;
  static int col_pin = 35;   

  //Get row and column pins to set.
  switch(led_index) {
    case 0:
      row_pin = ROW_0_PIN;
      col_pin = COL_0_PIN;
      break;
    case 1:
      row_pin = ROW_0_PIN;
      col_pin = COL_1_PIN;
      break;
    case 2:
      row_pin = ROW_0_PIN;
      col_pin = COL_2_PIN;
      break;
    case 3:
      row_pin = ROW_0_PIN;
      col_pin = COL_3_PIN;
      break;
    case 4:
      row_pin = ROW_0_PIN;
      col_pin = COL_4_PIN;
      break;
    case 5:
      row_pin = ROW_0_PIN;
      col_pin = COL_5_PIN;
      break;
    case 6:
      row_pin = ROW_0_PIN;
      col_pin = COL_6_PIN;
      break;
    case 7:
      row_pin = ROW_0_PIN;
      col_pin = COL_7_PIN;
      break;
    case 8:
      row_pin = ROW_0_PIN;
      col_pin = COL_8_PIN;
      break;
    case 9:
      row_pin = ROW_0_PIN;
      col_pin = COL_9_PIN;
      break;
    case 10:
      row_pin = ROW_1_PIN;
      col_pin = COL_0_PIN;
      break;
    case 11:
      row_pin = ROW_1_PIN;
      col_pin = COL_1_PIN;
      break;
    case 12:
      row_pin = ROW_1_PIN;
      col_pin = COL_2_PIN;
      break;
    case 13:
      row_pin = ROW_1_PIN;
      col_pin = COL_3_PIN;
      break;
    case 14:
      row_pin = ROW_1_PIN;
      col_pin = COL_4_PIN;
      break;
    case 15:
      row_pin = ROW_1_PIN;
      col_pin = COL_5_PIN;
      break;
    case 16:
      row_pin = ROW_1_PIN;
      col_pin = COL_6_PIN;
      break;
    case 17:
      row_pin = ROW_1_PIN;
      col_pin = COL_7_PIN;
      break;
    case 18:
      row_pin = ROW_1_PIN;
      col_pin = COL_8_PIN;
      break;
    case 19:
      row_pin = ROW_1_PIN;
      col_pin = COL_9_PIN;
      break;
    case 20:
      row_pin = ROW_2_PIN;
      col_pin = COL_0_PIN;
      break;
    case 21:
      row_pin = ROW_2_PIN;
      col_pin = COL_1_PIN;
      break;
    case 22:
      row_pin = ROW_2_PIN;
      col_pin = COL_2_PIN;
      break;
    case 23:
      row_pin = ROW_2_PIN;
      col_pin = COL_3_PIN;
      break;
    case 24:
      row_pin = ROW_2_PIN;
      col_pin = COL_4_PIN;
      break;
    case 25:
      row_pin = ROW_2_PIN;
      col_pin = COL_5_PIN;
      break;
    case 26:
      row_pin = ROW_2_PIN;
      col_pin = COL_6_PIN;
      break;
    case 27:
      row_pin = ROW_2_PIN;
      col_pin = COL_7_PIN;
      break;
    case 28:
      row_pin = ROW_2_PIN;
      col_pin = COL_8_PIN;
      break;
    case 29:
      row_pin = ROW_2_PIN;
      col_pin = COL_9_PIN;
      break;
    case 30:
      row_pin = ROW_3_PIN;
      col_pin = COL_0_PIN;
      break;
    case 31:
      row_pin = ROW_3_PIN;
      col_pin = COL_1_PIN;
      break;
    case 32:
      row_pin = ROW_3_PIN;
      col_pin = COL_2_PIN;
      break;
    case 33:
      row_pin = ROW_3_PIN;
      col_pin = COL_3_PIN;
      break;
    case 34:
      row_pin = ROW_3_PIN;
      col_pin = COL_4_PIN;
      break;
    case 35:
      row_pin = ROW_3_PIN;
      col_pin = COL_5_PIN;
      break;
    case 36:
      row_pin = ROW_3_PIN;
      col_pin = COL_6_PIN;
      break;
    case 37:
      row_pin = ROW_3_PIN;
      col_pin = COL_7_PIN;
      break;
    case 38:
      row_pin = ROW_3_PIN;
      col_pin = COL_8_PIN;
      break;
    case 39:
      row_pin = ROW_3_PIN;
      col_pin = COL_9_PIN;
      break;
    case 40:
      row_pin = ROW_4_PIN;
      col_pin = COL_0_PIN;
      break;
    case 41:
      row_pin = ROW_4_PIN;
      col_pin = COL_1_PIN;
      break;
    case 42:
      row_pin = ROW_4_PIN;
      col_pin = COL_2_PIN;
      break;
    case 43:
      row_pin = ROW_4_PIN;
      col_pin = COL_3_PIN;
      break;
    case 44:
      row_pin = ROW_4_PIN;
      col_pin = COL_4_PIN;
      break;
    case 45:
      row_pin = ROW_4_PIN;
      col_pin = COL_5_PIN;
      break;
    case 46:
      row_pin = ROW_4_PIN;
      col_pin = COL_6_PIN;
      break;
    case 47:
      row_pin = ROW_4_PIN;
      col_pin = COL_7_PIN;
      break;
    case 48:
      row_pin = ROW_4_PIN;
      col_pin = COL_8_PIN;
      break;
    case 49:
      row_pin = ROW_4_PIN;
      col_pin = COL_9_PIN;
      break;
  }

  //Set LED brightness.
  if(led_state[led_index]) {
      digitalWrite(row_pin, HIGH);
      digitalWrite(col_pin, LOW);    
  }
  switch(led_state[led_index]) {
    case 0:
      delayMicroseconds(0);    
      break;
    case 1:
      delayMicroseconds(2);
      break;
    case 2:
      delayMicroseconds(8);
      break;
    case 3:
      delayMicroseconds(32);
      break;
    case 4:
      delayMicroseconds(128);
      break;
    case 5:
      delayMicroseconds(380);
      break;
  }
  digitalWrite(row_pin, LOW);
  digitalWrite(col_pin, HIGH);

  //Increment for next function call.
  if(++led_index >= 50)
    led_index = 0;
}
