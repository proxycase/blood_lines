void (*myFunctions[])(void)=
  {&myFunction1, &myFunction2, &myFunction3,&myFunction4, &myFunction5,&myFunction6};
  
void setup()
{
  // This code will only run once, after each powerup or reset of board
  Serial.begin(9600);
}

void loop() {
  byte randNumber=random(6);
  //so now myFunctions[randNumber] will give me my randomly chosen function name, but how do I call that function?
  myFunctions[randNumber]();
}

void myFunction1(){
  Serial.println("Function 1");
  
}
void myFunction2(){
  Serial.println("Function 2");
    
}
void myFunction3(){
   Serial.println("Function 3");
   
}
void myFunction4(){
   Serial.println("Function 4");
   
}
void myFunction5(){
   Serial.println("Function 5");
   
}
void myFunction6(){
   Serial.println("Function 6");
   
}
