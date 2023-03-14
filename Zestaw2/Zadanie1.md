# Podaj definicję pojęć: polimorfizm dynamiczny i statyczny, klasa abstrakcyjna, funkcja wirtualna.

- **Polimorfizm dynamiczny**
  - typ poliformizmu opierający się na klasach i hierarchi dziedziczenia.
  - Wymaga tego aby w kodzie została użyta dana klasa lub klasa dziedzicząca z niej
    - Czyli gdy mamy klasę `Zwierze` i metode `podaj_gatunek(Zwierze zwierze)` to zostanie zaakceptowana tylko ta klasa lub klasa dziedzicząca po niej
  - Sprawdzanie odbywa się w czasie **kompilacji**
    - Już wtedy kompilator zgłosi błędy
  ### Przykład
  ```c++
  void draw_shapes(Shape *table[],size_t n) {
      for(size_t i=0;i<n;++i)
          table[i]->draw();
  }
  ```
  
- **Polimorfizm statyczny**
  - Opiera się na szablonach
  - Korzysta z tzw. **duck typing**'u
    - Czyli skupia się na możliwości które ten obiekt oferuje a nie czy jest to obiekt wymaganej klasy
    - Czyli jeśli obiekt danej klasy oferuje metodę `wydaj_dzwiek()` to nie ważne czy będzie to klasa reprezentująca zwierze czy samolot (no całkowicie nie powiązane ze sobą klasy, bez żadnej relacji dziedziczenia) to i tak zostanie to wykonane (w dynamicznym typowaniu został by zgłoszony błąd że klasa się nie zgadza)
  - Sprawdzanie odbywa się w czasie wykonywania
    - Kompilator nie wyrzuci błędu, dopiero podczas uruchomienia program zakończy się błędem że np. dana metoda nie istnieje w obiekcie 
  ### Przykład
  ```c++
  template<typename T> void draw_template(T table[],size_t n) { 
      for(size_t i=0;i<n;++i)
          table[i].draw();
  }
  ```
  
- **Klasa abstrakcyjna**
  - Klasa z której nie możemy tworzyć żadnych obiektów
  - Zawierająca metody wirtualne które muszą być zimplementowane przez klasę dziedziczącą po niej
  - Precyzuje wymagania które musi spełniać klasa dziedzicząca po niej.

- **Funkcja wirtualna**
  - Funkcja klasy abstrakcyjnej 
  - Nie posiada implementacji
  - Dziedzicząca po niej klasa musi ją zaimplementować 
