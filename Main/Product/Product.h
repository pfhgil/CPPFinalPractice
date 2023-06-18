#pragma once

#ifndef FINAL_PRACTICE_PRODUCT_H
#define FINAL_PRACTICE_PRODUCT_H

#include <iostream>

namespace FinalPractice::Main::Product
{
    class Product
    {
    public:
        std::uint16_t m_id = 0;
        std::string m_name;
        float m_cost = 0;

        Product() = default;
        Product(const std::uint16_t id, std::string name, const float& cost) : m_id(id), m_name(std::move(name)), m_cost(cost) { }
    };
}

#endif //FINAL_PRACTICE_PRODUCT_H
