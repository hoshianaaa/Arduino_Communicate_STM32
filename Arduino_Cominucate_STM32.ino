

//送信データ形式:[header, mode, data1, data2, data3]
uint8_t txbuf_0[] = {255, 0, 0, 0, 0};//モード1用
uint8_t txbuf_1[] = {255, 1, 1, 1, 1};//モード2用
uint8_t mode = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {

  //シリアル信号を受信したらモードチェンジ
  if (Serial.available()) {
    mode = Serial.read();
  }

  if (mode == '0') {
    for (int i = 0; i < sizeof(txbuf_0); i++)Serial.write(txbuf_0[i]);//txbuf_0を垂れ流す
  }

  if (mode == '1') {
    for (int i = 0; i < sizeof(txbuf_1); i++)Serial.write(txbuf_0[i]);//txbuf_1を垂れ流す
  }

}
