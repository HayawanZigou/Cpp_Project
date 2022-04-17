#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <type_traits>

//TASK_4 Obj-2.1                               TASK_4 Obj-2.7
template<std::size_t dimension, typename Type, std::enable_if_t<std::is_arithmetic_v<Type>, bool> = true>
class Point
{

private:
 
    
    std::size_t size() const { return dimension;}


public:

    std::array<Type, dimension> values;
   
    Point()=default;

    // //TASK_4 Obj-2.3
    // Point(Type x, Type y) : values { x, y } {static_assert(dimension == 2);} //TASK_4 Obj-2.5: assertion pour qu'on ne puisse pas créer un Point à 3 dimensions avec 2 parametres.

    // Point(Type x, Type y, Type z) : values { x, y, z } {}

    //TASK_4 Obj-2.6
    template <typename... Args>
    Point(Type v, Args&&... init) : values { v, static_cast<Type>(std::forward<Args>(init))... }
    {
        static_assert(sizeof...(init) <= dimension);
    }
    
   

    Type& x() { 
        static_assert(dimension > 0); //TASK_4 Obj-2.5
        return values[0]; 
    }
    
    Type x() const {
        static_assert(dimension > 0); //TASK_4 Obj-2.5
        return values[0]; 
    }

    Type& y() { 
        static_assert(dimension > 1); //TASK_4 Obj-2.5
        return values[1]; 
    }
    
    Type y() const { 
        static_assert(dimension > 1); //TASK_4 Obj-2.5
        return values[1];
    }
     
    Type& z() {
        static_assert(dimension > 2); //TASK_4 Obj-2.5
        return values[2];
    }
    
    Type z() const { 
        static_assert(dimension > 2); //TASK_4 Obj-2.5
        return values[2];
    }


    Type& value(int d) 
    {
        assert(d >=0 && d < dimension);
        return values[d]; 
    }

    Type value(int d) const 
    {
        assert(d >=0 && d < dimension);
        return values[d]; 
    }

    Point& operator+=(const Point& other)
    {
        assert(other.size() == size());
        int i=0;
        std::transform(values.begin(), values.end(), values.begin(), [&other, &i](Type v){return v + other.values[i++];});
        return *this;
    }

    Point& operator-=(const Point& other)
    {
        assert(other.size() == size());

        int i=0;
        std::transform(values.begin(), values.end(), values.begin(), [&other, &i](Type v){return v - other.values[i++];});
        return *this;
    }

    Point& operator*=(const Type scalar)
    {

        std::transform(values.begin(), values.end(), values.begin(), [scalar](Type v){return v * scalar;});
        return *this;
    }

    Point& operator*=(const Point& other)
    {
        int i=0;
        std::transform(values.begin(), values.end(), values.begin(), [&other, &i](Type v){return v * other.values[i++];});
        return *this;
    }


    Point operator+(const Point& other) const
    {
        Point result = *this;
        result += other;
        return result;
    }

    Point operator-(const Point& other) const
    {
        Point result = *this;
        result -= other;
        return result;
    }

    Point operator*(const Type scalar) const
    {
        Point result = *this;
        result *= scalar;
        return result;
    }

    Point operator*(const Point& other) const
    {
        Point result = *this;
        result *= other;
        return result;
    }

    Point operator-() const 
    {
        Point result = *this;
        std::transform(values.begin(), values.end(), result.values.begin() ,[&result](Type v){return -v; });
        return result;
    }

    Type length() const 
    { 
        return std::sqrt(std::inner_product(values.begin(), values.end(), values.begin(), 0.f));
    }

    Type distance_to(const Point& other) const { return (*this - other).length(); }


    Point& normalize(const Type target_len = 1.0f)
    {
        const Type current_len = length();
        if (current_len == 0)
        {
            throw std::logic_error("cannot normalize vector of length 0");
        }

        *this *= (target_len / current_len);
        return *this;
    }    

    Point& cap_length(const Type max_len)
    {
        assert(max_len > 0);

        const Type current_len = length();
        if (current_len > max_len)
        {
            *this *= (max_len / current_len);
        }

        return *this;
    }
};