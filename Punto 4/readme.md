Los campos mínimos para realizar la implementación serían:

•	Corroborar que incluímos (y tenemos instalada) la librería necesaria ArduinoJson.h

•	La incluirémos en nuetro código: #include <ArduinoJsin.h>

•	Posteriormente crearemos un documento Json estático y le indicaremos la memoria disponible: StaticJsonDocument<200>doc;

•	Transmitiremos los datos leídos por el sensor al documento Json:

		doc ["temperatura"] = temperatura; 
		doc ["humedad"] = humedad; 
		
•	Serializamos y mostramos los datos:
		serializeJson(doc, Serial); 
		Serial.println(); 

