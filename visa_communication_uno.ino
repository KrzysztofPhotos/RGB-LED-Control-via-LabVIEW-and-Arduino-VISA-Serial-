// PWM pins (Arduino Uno)
const int R = 9;
const int G = 11;
const int B = 10;

// Zapamiętane PWM
int pwmR = 0;
int pwmG = 0;
int pwmB = 0;

// Stan ON/OFF
bool onR = false;
bool onG = false;
bool onB = false;

void applyLEDs() {
  analogWrite(R, onR ? pwmR : 0);
  analogWrite(G, onG ? pwmG : 0);
  analogWrite(B, onB ? pwmB : 0);
}

void setup() {
  Serial.begin(9600);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  applyLEDs();
  Serial.println("RGB READY (COMMON CATHODE)");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    // ---------- ON / OFF ----------
    if (cmd.indexOf("R1") >= 0) onR = true;
    if (cmd.indexOf("R0") >= 0) onR = false;

    if (cmd.indexOf("G1") >= 0) onG = true;
    if (cmd.indexOf("G0") >= 0) onG = false;

    if (cmd.indexOf("B1") >= 0) onB = true;
    if (cmd.indexOf("B0") >= 0) onB = false;

    // ---------- PWM ----------
    int i;

    i = cmd.indexOf("RP");
    if (i >= 0) pwmR = constrain(cmd.substring(i + 2).toInt(), 0, 255);

    i = cmd.indexOf("GP");
    if (i >= 0) pwmG = constrain(cmd.substring(i + 2).toInt(), 0, 255);

    i = cmd.indexOf("BP");
    if (i >= 0) pwmB = constrain(cmd.substring(i + 2).toInt(), 0, 255);

    applyLEDs();

    // ---------- FEEDBACK ----------
    Serial.print("STATE ");
    Serial.print(onR); Serial.print(",");
    Serial.print(onG); Serial.print(",");
    Serial.print(onB); Serial.print(" | PWM ");
    Serial.print(pwmR); Serial.print(",");
    Serial.print(pwmG); Serial.print(",");
    Serial.println(pwmB);
  }
}