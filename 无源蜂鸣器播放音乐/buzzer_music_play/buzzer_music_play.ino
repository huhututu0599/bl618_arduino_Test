#define buzzerPin 31 // 将蜂鸣器连接到Arduino的8号引脚

// 定义音符频率
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_G5  784

// 定义音符时长
#define NOTE_Q  500 // 四分音符
#define NOTE_H  1000 // 半音符
#define NOTE_W  2000 // 全音符

void playNote(int noteFrequency, int noteDuration) {
  int period = 1000000 / noteFrequency; // 计算音符频率的周期
  int halfPeriod = period / 2; // 半个周期的时间

  long numCycles = noteDuration * 1000L / period; // 计算循环次数，以便播放指定持续时间的音符

  for (long i = 0; i < numCycles; i++) {
    digitalWrite(buzzerPin, HIGH); // 输出高电平
    delayMicroseconds(halfPeriod); // 延迟半个周期时间
    digitalWrite(buzzerPin, LOW); // 输出低电平
    delayMicroseconds(halfPeriod); // 延迟半个周期时间
  }

  delay(20); // 延迟一小段时间，留出缓冲
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // 播放"军中绿花"部分旋律
  playNote(NOTE_G4, NOTE_H);
  playNote(NOTE_A4, NOTE_Q);
  playNote(NOTE_B4, NOTE_Q);
  playNote(NOTE_D5, NOTE_H);
  playNote(NOTE_B4, NOTE_Q);
  playNote(NOTE_A4, NOTE_Q);
  playNote(NOTE_G4, NOTE_H);
  playNote(NOTE_E4, NOTE_H);
  playNote(NOTE_D4, NOTE_Q);
  playNote(NOTE_B4, NOTE_Q);

  delay(3000); // 等待一段时间后重复播放
}
