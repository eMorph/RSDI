const int jsX = A4;
const int jsY = A5;

void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("X: ");
  Serial.print(analogRead(jsX));
  Serial.print(", Y: ");
  Serial.println(analogRead(jsY));
}
