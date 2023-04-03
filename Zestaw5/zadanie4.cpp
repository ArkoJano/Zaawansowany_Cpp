//
// Created by Arek on 03.04.2023.
//

#include <iostream>


template<typename T, typename U> class is_convetible{
    static char test(U);
    static int test(...);
    static T makeT();

public:
    static const bool yes = (sizeof(test(makeT())) == sizeof(char));
    static const bool same_type = false;
};

template <typename T> class is_convetible<T, T>{
public:
    static const bool yes = true;
    static const bool same_type = true;
};

template<typename T> struct Strip {
    typedef T arg_t;
    typedef T striped_t;
    typedef T base_t;
    typedef const T   const_type;

    typedef T&        ref_type;
    typedef T&        ref_base_type;
    typedef const T & const_ref_type;


};

template<typename T> struct Strip< T const> {
    typedef const T arg_t;
    typedef       T striped_t;
    typedef typename Strip<T>::base_t  base_t;
    typedef T const   const_type;

    typedef T const & ref_type;
    typedef T &       ref_base_type;
    typedef T const & const_ref_type;


};

template<typename T> struct Strip<T&> {

    typedef T& arg_t;
    typedef T  striped_t;
    typedef typename Strip<T>::base_t  base_t;
    typedef base_t const    const_type;

    typedef T               ref_type;
    typedef base_t &        ref_base_type;
    typedef base_t const &  const_ref_type;


};


int main() {
    std::cout<<std::boolalpha;
    std::cout<<is_convetible<Strip< const int&>::base_t,int>::same_type<<std::endl;
    std::cout<<is_convetible<Strip< const int&>::striped_t,const int>::same_type<<std::endl;

}