#pragma once

#ifndef FINAL_PRACTICE_PRODUCTSMANAGER_H
#define FINAL_PRACTICE_PRODUCTSMANAGER_H

#include <list>
#include <memory>

#include "Product.h"

namespace FinalPractice::Main::Product
{
    class ProductsManager
    {
    private:
        static inline std::list<std::shared_ptr<Product>> m_products;

    public:
        static std::shared_ptr<Product> createProduct() noexcept;

        static void save(const std::string_view&);
        static void load(const std::string_view&);

        static bool isProductExists(const std::uint16_t& productID) noexcept;

        static std::list<std::shared_ptr<Product>> getProducts() noexcept;

        static void removeProduct(const std::uint16_t& ID) noexcept;
    };
}

#endif //FINAL_PRACTICE_PRODUCTSMANAGER_H
