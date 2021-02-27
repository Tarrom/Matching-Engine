//
// Created by Jon on 1/6/2021.
//

#ifndef MATCHING_ENGINE_MATCHING_ENGINE_H
#define MATCHING_ENGINE_MATCHING_ENGINE_H
#include "trade_list.h"
#include <tuple>

trade_list match(order_book* book){
    time_t trade_time=time(0);
    trade_list return_trades;
    if (book->head_buy==nullptr || book->head_sell==nullptr){
        return_trades.add_trade(new order(3,0,0,trade_time));
        return return_trades;

    }

    if (book->head_buy->price<book->head_sell->price){
        return_trades.add_trade(new order(3,0,0,trade_time));
        return return_trades;

    }

    while (book->head_buy->price>=book->head_sell->price){
        double trade_price=book->head_sell->price;
        int trade_quantity=0;
        while (trade_price==book->head_sell->price&& book->head_buy->price>=book->head_sell->price&& book->head_buy!=nullptr&& book->head_sell!=nullptr) {

            if (book->head_buy->quantity < book->head_sell->quantity) {
                trade_quantity+=book->head_buy->quantity;
                book->head_sell->quantity-=book->head_buy->quantity;
                order* temp=book->head_buy;
                book->head_buy=temp->next;
                delete temp;
            }
            else if (book->head_buy->quantity==book->head_sell->quantity){
                trade_quantity+=book->head_sell->quantity;
                order* temp=book->head_sell;
                book->head_sell=temp->next;
                order* temp2=book->head_buy;
                book->head_buy=temp->next;
                delete temp;
                delete temp2;
            }
            else{
                trade_quantity+=book->head_sell->quantity;
                book->head_buy->quantity-=book->head_sell->quantity;
                order* temp=book->head_sell;
                book->head_sell=temp->next;
                delete temp;
            }

        }

        return_trades.add_trade(new order(3,trade_quantity,trade_price,trade_time));


    }
    return return_trades;
}


#endif //MATCHING_ENGINE_MATCHING_ENGINE_H
