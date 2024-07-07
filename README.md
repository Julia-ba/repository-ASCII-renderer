# repository-ASCII-renderer
## Zadanie ASCII renderer

### Wprowadzenie: czego dotyczy projekt 

ASCII renderer to program, który tworzy obrazki w formie plików ASCII. Użytkownik wybiera wymiar canvasu, na którym będą rysowane figury. Do wyboru są 3 figury: koło, protokąt lub kwadrat. Użytkownik wybiera też symbol oznaczający piksel należący do danej figury oraz piksel nienależący do żadnej figury (tło).

### Zawartość

Ten projekt zawiera nastepujące pliki:
 - canvas.h - plik nagłówkowy, w którym implementujemy klasę abstrakcyjną Canvas, z której dziedziczy klasa ASCIICanvas
 - asciicanvas.h - plik nagłówkowy, w którym definiujemy klasę ASCIICanvas, która implementuje metody ustaw_pixel i zapisz
 - figure.h - plik nagłówkowy, zawiera klasę abstrakcyjną Figure, z której dziedziczą konkretne figury, zawiera czysto wirtualną metodę draw
 - circle.h - plik nagłówkowy, definiuje klasę Circle i definiuje metody do rysowania okręgu
 - rectangle.h - plik nagłówkowy, definiuje klasę Rectangle i definiuje metody do rysowania prostokąta
 - square.h - plik nagłówkowy, definiuje klasę Square i definiuje metody do rysowania kwadratu
 - main.cpp - odpowiada za odczyt pliku konfiguracyjnego, inicjalizację obiektu ASCIICanvas, tworzenie i rysowanie figur geometrycznych na płótnie.
 - konfiguracyjny.txt - przykładowy plik konfiguracyjny

### Jak pobrać
Aby pobrać projekt, sklonuj repozytorium za pomocą poniższej komendy:

**git clone https://github.com/Julia-ba/repository-ASCII-renderer.git**

### Kompilacja i użycie
 - Aby skompilować projekt użyj następującej komendy:
   
**g++ -o ascii_renderer main.cpp -std=c++14**

- Uruchomienie programu:
  
**./ascii_renderer (wpisz nazwę swojego pliku konfiguracyjnego)**

 - Uruchomienie programu z przykładowym plikiem konfiguracyjnym - konfiguracyjny.txt:
   
**./ascii_renderer konfiguracyjny.txt**

 - Tworzenie pliku konfiguracyjnego:
   1. pierwsza linijka to szerokość canvasu 
   2. druga to wysokość canvasu
   3. w trzeciej linijce podaj nazwę pliku wyjściowego, do którego zostanie zapisany obrazek
   4. w czwartej podaj symbol dla pikseli nienależących do żadnej figury, użyj cudzysłowów (") dla znaków specjalnych i spacji
   - teraz w następnych linijkach dodajemy figury, aby dodać figurę:
     1. najpierw wpisz jeden z 3 typów figur: Circle (koło), Square (kwadrat), Rectangle (prostokąt)
     2. w następnej linijce podajemy dane współrzędne i wymiary figury
     - dla koła parametry po kolei to: współrzędna środka x, współrzędna środka y, promień
     - dla kwadratu parametry pokolei to: współrzędna lewego górnego rogu x, współrzędna lewego górnego rogu y, długość boku
     - dla prostokąta parametry po kolei to: współrzędna lewego górnego rogu x, współrzędna lewego górnego rogu y, długość pierwszej pary boków(szerokość), długość drugiej pary boków (wysokość)
     3. w linijce pod parametrami figury wpisz symbol oznaczający piksel należący do figury, użyj cudzysłowów (") dla znaków specjalnych i spacji
