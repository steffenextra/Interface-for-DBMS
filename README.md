	<br>
<b>	---Vorwort---	</b>

 Selektierung von C++ und der Standard-Bibliothek von MySQL.<br>
 SQL-Statements können über Methoden und Parameter abgearbeitet werden.<br>
 Bedienbar entweder über die Konsole und den einfachen Methoden-Aufruf oder über das Interface.<br>
<br>

<b>	---Einrichtung---	</b>

 Der Socket für XAMPP auf Linux sowie MAMP auf MacOS wurden bereits implementiert falls diese Bibliothek local genutzt werden soll.<br>
 Für die Anwendung ist es außerdem Vorraussetzung den MYSQL-Header zu implementieren. <br>
 Durch weitere Präprozessor-Direktiven in der sqllib.hpp sind die Standardpfade des MYSQL-Headers für Linux-/ sowie MacOS-Systeme bereits implementiert. <br>
<br>
 Sollte die Anwendung nicht Lokal genutzt werden, muss der Ort an dem der spezifische SQL-Socket <br>
 clientseitig liegt identifiziert werden um mit dem SQL-Server zu kommunizieren.<br>
 Für den Verbindungsaufbau wird die connectionless-Methode connectionless() (siehe Übergabe-Parameter) der connection-Klasse <br>
 benutzt und baut nach der Build-Routine bei der Ausführung des Programm's eine Verbindung auf.
<br>


<br>
<br>
<br>

@author Steffen Extra
@author Martin Meyer






