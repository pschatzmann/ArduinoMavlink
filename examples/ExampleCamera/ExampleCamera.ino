
/**
 *  This is a demo for using an ESP32S3-CAM board to capture video frames, encode them using H.264, and stream them over UDP using the RDP protocol.
 *  The example uses the H264Encoder for video encoding, UDPPrint for UDP communication, 
 */
#include "H264Encoder.h"
#include "UDPPrint.h"
#include "RDPPacketizer.h"

// The encoder needs more stack
SET_LOOP_TASK_STACK_SIZE(60 * 1024);  


H264Encoder encoder;
UDPPrint udp;
RDPPacketizer rdp(udp);
// Destination for UDP streaming (set to your receiver)
const char* DEST_IP = "192.168.1.44";
const uint16_t DEST_PORT = 5600;
const char* WIFI_SSID = "ssid";
const char* WIFI_PASS = "pwd";

void setup() {
  Serial.begin(115200);
  delay(500);
  // configure streamer (populate global cfg)
  auto cfg = encoder.defaultConfig();
  cfg.width = 320;
  cfg.height = 240;
  cfg.fps = 5;
  cfg.gop = 5; // Keyframe every 100 frames
  if (!encoder.begin(cfg)) {
    Serial.println("Streamer failed to start");
    while (true) delay(1000);
  }

  udp.initWiFi(WIFI_SSID, WIFI_PASS);
  if (!udp.begin(DEST_IP, DEST_PORT)){
    Serial.println("UDP failed to start");
    while (true) delay(1000);
  }
  
  Serial.println("Streamer started");
}

void loop() {
  encoder.captureH264(rdp);