
// connect to wifi – returns true if successful or false if not

bool ConnectWifi(void)
{
  bool state = true;
  int i = 0;

  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");
  
  // Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }
  if (state) {
    digitalWrite(13,HIGH);
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    
    Serial.println(IPAddress(WiFi.localIP()));
  } else {
    digitalWrite(13,LOW);
    Serial.println("");
    Serial.println("Connection failed.");
  }
  
  return state;
}
