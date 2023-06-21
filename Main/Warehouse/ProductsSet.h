#pragma once

#ifndef FINAL_PRACTICE_PRODUCTSSET_H
#define FINAL_PRACTICE_PRODUCTSSET_H

#include "Product/ProductsManager.h"
#include <map>

namespace FinalPractice::Main::Warehouse
{
    class ProductsSet
    {
    public:
        std::shared_ptr<Product::Product> m_product;
        int m_count = 0;

        ProductsSet() = default;
        ProductsSet(std::shared_ptr<Product::Product> product, const int& count) : m_product(std::move(product)), m_count(count) { }
    };
}

#endif //FINAL_PRACTICE_PRODUCTSSET_H
