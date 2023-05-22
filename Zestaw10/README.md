1 . Opisz wykorzystując funkcjonalne przykłady występujące w C++17 execution policy  :

```c++
std::execution::sequenced_policy,  
std::execution::parallel_policy,
std::execution::parallel_unsequenced_policy,
```

2. Wykonanie bardzo prostego programu:

```c++
#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>

int main() {
    std::vector<int> vec(10'000'000);   
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::for_each(std::execution::par, vec.begin(), vec.end(), [&output](int& elem) {
        if (elem % 2 == 0) {
            output.push_back(elem);
      }
    });
}
```

 który zakończy się tragicznie z punktu widzenia programisty (`core dupmed`).
 Wykorzystując `std::lock_guard` zmodyfikuj `lambda expression` tak aby nie dochodziło do niezsynchronizowanego dostępu 
 do wektora wyjściowego. Porównaj wydajność przy wykorzystaniu polityki typu `seq`.



3. Wybierz z listy algorytmów pięć różnych algorytmów i przedstaw przykład wykorzystania, w którym równoległe obliczenia 
przyśpieszą obliczenia proporcjonalnie do ilości występujących w procesorze rdzeni.

4. Niektóre z tych algorytmów są nowe:

```c++
std::for_each_n
std::exclusive_scan 
std::inclusive_scan
std::transform_exclusive_scan 
std::transform_inclusive_scan
std::parallel::reduce 
std::parallel::transform_reduc
```

ósmy algorytm `std::for_each` różni się i też uważamy go za nowy, ponieważ oprócz dodatkowej polityki wykonywania teraz 
zwracanym typem jest `void`… 
Przygotuj na podstawie dokumentacji (https://en.cppreference.com/w/cpp/experimental/parallelism) przykłady wykorzystania
tych algorytmów. 
W przypadku `reduce` wykorzystaj `alfa expression` 
```c++
( [](auto fir, auto sec){
    return fir + ":" + sec;
}); )
```
do zdefiniowania `BinaryOp` w celu dodawania stringów.  