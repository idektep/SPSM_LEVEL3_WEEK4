const char *htmlHomePage PROGMEM = R"HTMLHOMEPAGE(

<!DOCTYPE html>
<html>
  <head>
  <meta name="viewport" content="width=device-width, height=device-height, target-densitydpi=device-dpi, initial-scale=1, minimum-scale=1, maximum-scale=1, user-scalable=no">
    <style>
    td {
      width: 100px;
      height: 80px;
      font-size: 16px;
      background-color:pink;
      border-radius:40%;
      box-shadow: 5px 5px #888888;
    }
    td:active {
      transform: translate(5px,5px);
      box-shadow: none; 
    }
    .noselect {
      touch-action: manipulation; /disable docule tap to zoom */
      -webkit-touch-callout: none; /* iOS Safari */
        -webkit-user-select: none; /* Safari */
         -khtml-user-select: none; /* Konqueror HTML */
           -moz-user-select: none; /* Firefox */
            -ms-user-select: none; /* Internet Explorer/Edge */
                user-select: none; /* Non-prefixed version, currently
                                      supported by Chrome and Opera */      
    }
    </style>
  </head>

  <body class="noselect" align="center" style="color: white;text-align:center;" style="background-color:white">
    <h3 style="color: teal;text-align:center;">&#129470;Robot Arm Web Controller</h3> 
   
    <table id="mainTable" style="width:500;margin:auto;table-layout:fixed" CELLSPACING=8>
    
      <tr>
        <td ontouchstart='toggleCheckbox("TURN_RIGHT_RM")' ontouchend='toggleCheckbox("H_OFF")'>TR_RBA</span></td>
        
      </tr>
      
      <tr>
        <td ontouchstart='toggleCheckbox("TURN_LEFT_RM")' ontouchend='toggleCheckbox("H_OFF")'>TL_RBA</span></td>
         
      </tr>
      
      <tr>
      	<td ontouchstart='toggleCheckbox("GRIP")' ontouchend='toggleCheckbox("H_OFF")'>GRIP</span></td>
      	<td style="background-color:#95F5E7;box-shadow:none"><h4 style="color: DarkMagenta;text-align:center;" ontouchstart='toggleCheckbox("home")' ontouchend='toggleCheckbox("H_OFF")'>&#129470; HOME </h4></td>
    	  
      </tr>
      
      <tr>
        <td ontouchstart='toggleCheckbox("UN_GRIP")' ontouchend='toggleCheckbox("H_OFF")'>UN_GRIP</span></td>
        <td style="background-color:white;font-size:50px;box-shadow:none;height:10px;width:10px;">&#129302;</td>
        
      </tr>
    </table>
    
   <script>
    // ... (your existing JavaScript code)
      var webSocketUrl = "ws:\/\/" + window.location.hostname + "/ws";
      var websocket;
      
      function initWebSocket() 
      {
        websocket = new WebSocket(webSocketUrl);
        websocket.onopen    = function(event){};
        websocket.onclose   = function(event){setTimeout(initWebSocket, 2000);};
        websocket.onmessage = function(event){};
      }

      function onTouchStartAndEnd(value) 
      {
        websocket.send(value);
      }
  
     function toggleCheckbox(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/" + x, true);
     xhr.send();
    }
            
    window.onload = initWebSocket;
      document.getElementById("mainTable").addEventListener("touchend", function(event)       {
        event.preventDefault()
      });

    </script>
  </body>
</html>


)HTMLHOMEPAGE";
void handleRoot(AsyncWebServerRequest *request) {
  request->send_P(200, "text/html", htmlHomePage);

  // Send web page to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", htmlHomePage);
  });

  // Recevie
  server.on("/TURN_RIGHT_RM", HTTP_GET, [](AsyncWebServerRequest *request) {
    hold_flag = "TURN_RIGHT_RM";
    Serial.println(hold_flag);
    request->send(200, "text/plain", "ok");
  });
  server.on("/TURN_LEFT_RM", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "TURN_LEFT_RM";
    request->send(200, "text/plain", "ok");
  });
  server.on("/EXTEND", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "EXTEND";
    request->send(200, "text/plain", "ok");
  });
  server.on("/RESTACK", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "RESTACK";
    request->send(200, "text/plain", "ok");
  });
  server.on("/UPPER", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "UPPER";
    request->send(200, "text/plain", "ok");
  });
  server.on("/LOWER", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "LOWER";
    request->send(200, "text/plain", "ok");
  });
  server.on("/UPPER_G", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "UPPER_G";
    request->send(200, "text/plain", "ok");
  });
  server.on("/LOWER_G", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "LOWER_G";
    request->send(200, "text/plain", "ok");
  });
  server.on("/GRIP", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "GRIP";
    request->send(200, "text/plain", "ok");
  });
  server.on("/UN_GRIP", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "UN_GRIP";
    request->send(200, "text/plain", "ok");
  });
  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println(hold_flag);
    hold_flag = "home";
    request->send(200, "text/plain", "ok");
  });
  server.on("/H_OFF", HTTP_GET, [](AsyncWebServerRequest *request) {
    hold_flag = "H_OFF";
    Serial.println(hold_flag);
    request->send(200, "text/plain", "ok");
  });
}

void handleNotFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "File Not Found");
}

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      // client->text(getRelayPinsStatusJson(ALL_RELAY_PINS_INDEX));
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      
      break;
    case WS_EVT_DATA:
      AwsFrameInfo *info;
      info = (AwsFrameInfo *)arg;
      if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        std::string myData = "";
        myData.assign((char *)data, len);
        // Serial.println(myData.c_str());
      }
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
    default:
      break;
  }
}