<br>
<b>	---Vorwort---	</b>

 Selektierung von C++ und der Standard-Bibliothek von MySQL.<br>
 SQL-Statements können über Methoden und Parameter abgearbeitet werden.<br>
 Bedienbar entweder über die Konsole und den einfachen Methoden-Aufruf oder über das Interface.<br>

 Der Code für das Interface wurde nicht dokumentiert <br>


<br>

<b>	---Einrichtung---	</b>

 Der Socket für XAMPP auf Unix-Systemen sowie MAMP auf MacOS wurden bereits implementiert falls diese Bibliothek local genutzt werden soll.<br>

 Sollte die Anwendung nicht Lokal genutzt werden, muss der Ort an dem der spezifische SQL-Socket <br>
 clientseitig liegt identifiziert werden um mit dem SQL-Server zu kommunizieren.<br>
 Für den Verbindungsaufbau wird die connectionless-Methode connectionless() (siehe Übergabe-Parameter) der connection-Klasse <br>
 benutzt, diese baut nach der Build-Routine bei der Ausführung des Programm's eine Verbindung auf.<br>

 Durch vorgefertigte Präprozessor-Direktiven wird für MacOS-/ sowie Linuxbetriebssysteme der zu benötigende MySQL-Header beim kompilieren direkt rausgesucht. <br>
 <br>
 In der Regel sollte der MySQL-Header im Standardpfad des dementsprechenden Betriebssystems liegen. <br>
 Sollte dies nicht der Fall sein, muss die Variable in der connectionless() Methode gelöscht und durch eine eigene Variable (String des Pfads + mysql.h) ersetzt werden.<br>


 Für das Ausführen des Programms ohne Benutzeroberfläche wird das erstellte Shellscript mit den dementsprechenden Umgebungsvariablen benutzt.<br>
 Sollte, wie vorher beschrieben der Pfad für den MySQL-Header nicht im Standardpfad liegen, muss ebenfalls das Shellscript angepasst werden. <br>
 Die Bedingung im Shellscript sieht vor, dass je nach Pfad für die mysql.h andere Compiler-Optionen vorgenommen werden. <br>
 Hier muss lediglich der Pfad mit inbegriffender Header-Datei eingebunden werden um das Shellscript lauffähig zu bekommen. <br>
 Für die Ausführung des User-Interfaces steht ein eigens entwickeltes Shellscript zur verfügung. <br>

 !Kein Support für Microsoft-Betriebssysteme! 

<br>

<b> ---Nice to know--- </b>

Da in diesem Projekt ausschließlich mit der MySQL-Standardbibliothek gearbeitet wurde, passiert die Fehlerausgabe über die check_error() Methode.<br>
Diese fängt jegliche Fehlerausgaben des MySQL-Servers ab und zeigt diese an. <br>
<br>
Sollte dieses Programm über die Konsole genutzt werden, müssen jegliche Übergabeparameter (ausgeschlossen Integer) in einen String gepackt werden. (" ")<br>
Durch die Benutzung des Interfaces kann diese Anweisung jedoch ignoriert werden. <br>
<br>

@author Steffen Extra
@author Martin Meyer






