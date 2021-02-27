//
// Created by Jon on 1/6/2021.
//

#ifndef MATCHING_ENGINE_ORDER_H
#define MATCHING_ENGINE_ORDER_H
#include <ctime>

class order{
public:
    order(){}
    order(const int order_type, const int order_quantity, const double share_price, const time_t order_time):
    type(order_type), quantity(order_quantity), price(share_price), time(order_time),
    next(nullptr){};

    int type;       //1 for buy 2 for sell
    int quantity;   //quantity of shares
    double price;       //price of shares
    time_t time;  //time order was placed
    order* next;    //points to next order

};
#endif //MATCHING_ENGINE_ORDER_H
