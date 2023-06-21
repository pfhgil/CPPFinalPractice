#pragma once

#ifndef FINAL_PRACTICE_CARTSTATUS_H
#define FINAL_PRACTICE_CARTSTATUS_H

namespace FinalPractice::Main::Cart
{
    enum CartStatus
    {
        BUILDING, // в процессе сборки гостем
        PAID, // оплачен
        PREPARING, // приготавливается
        PASSED_TO_WAITER, // передан официанту
        COMPLETED // выполнен
    };

    static inline std::string cartStatusToString(const CartStatus& cartStatus)
    {
        switch(cartStatus)
        {

            case BUILDING: return "собирается клиентом";
            case PAID: return "оплачен";
            case PREPARING: return "приготавливается";
            case PASSED_TO_WAITER: return "отдан официанту";
            case COMPLETED: return "выдан";
        }

        return "";
    }
}

#endif //FINAL_PRACTICE_CARTSTATUS_H
