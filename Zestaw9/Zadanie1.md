# unique_ptr
Jest reprezentacją zarządzalnego wskaźnika na pojedynczy obiekt. Oznacza to, że może istnieć tylko jeden `unique_ptr` wskazujący na dany obiekt, a gdy ten wskazujący `unique_ptr` jest usuwany lub traci zasięg, to obiekt, na który wskazuje, jest automatycznie usuwany.  Nie może być kopiowany, ale za to może być przekazany za pomocą `std::move()`. Ma taki sam rozmiar jak normalny wskaźnik (4 do 8 dla 32-bit, 8 do 16 bajtów dla 64-bit).

# shared_ptr

Jest reprezantajcą wskaźnika, który może być współdzielony przez wiele `shared_ptr`. Oznacza to, że może istnieć wiele `shared_ptr` wskazujący na dany obiekt, a obiekt zostanie automatycznie usunięty, gdy ostatni  `shared_ptr` traci zasięg. Może być wykorzystany np. gdybyśmy chcieli zwrócić kopię wskaźnika z kontenera ale zachować oryginał. Wszystkie wystąpienia wskazują na ten sam obiekt i mają wspólny dostęp do jednego "bloku sterującego", który zwiększa i zmniejsza liczbę odwołań po każdym dodaniu nowego wskaźnika `shared_ptr`, wykroczeniu przez wskaźnik poza zakres lub jego zresetowaniu . Jego rozmiar jest zazwyczaj większy z uwagi na dodatkowy "*blok sterujący*".
