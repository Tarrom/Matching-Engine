//
// Created by Jon on 1/6/2021.
//

#ifndef MATCHING_ENGINE_ORDER_BOOK_H
#define MATCHING_ENGINE_ORDER_BOOK_H
#include "order.h"
#include <iostream>

class order_book{
public:
    order_book(){
        head_sell=nullptr;
        head_buy=nullptr;
    }

    // store the buy order book in a linked list ordered from high price to low price and
    // from earlier order to later order if price is the same

    // store the sell order book in a linked list ordered from low price to high price and
    // from earlier order to later order if price is the same

    order* head_sell;

    order* head_buy;



    void order_by_time(order* neworder, order*p, order*q){
        // given a new order, this function takes a new order already in the correct place in
        // the order book according to price and if there is other orders of the same price
        // already in the order book it will arrange them from earliest order to latest order

        //the p pointer points to where the new order should be in the order book according
        //to just the price.  if there are multiple orders in the orderbook with the same price
        //as the new order p points to the first order in the order book
        //the q pointer points to
        if (p->price!=neworder->price){
            q->next=neworder;
            neworder->next=p;
            return;
        }

        order* time_head=p;
        while (p->next!=nullptr&&p->next->price==neworder->price && neworder->time>p->time){
            p=p->next;
        }
        if (p==time_head && neworder->time<p->time){
            q->next=neworder;
            neworder->next=p;
            return;
        }
        else if (p->next==nullptr && neworder->time>p->time){
            p->next=neworder;
            return;
        }
        else if (p->next->price!=p->price&& neworder->time>p->time){
            order* r=p->next;
            p->next=neworder;
            neworder->next=r;
            return;

        }


        while (q->next!=p){
            q=q->next;
        }
        q->next=neworder;
        neworder->next=p;

    }

    void insert_order(order* neworder){



        if (head_buy==nullptr&& neworder->type==1){
            head_buy=neworder;
            return;
        }

        if (head_sell==nullptr&& neworder->type==2){
            head_sell=neworder;
            return;
        }
        order* p;
        order* q;

        // use p pointer to find correct place in linked list by price, then
        // by time if there are other orders in the order book with the same price
        // as the new order

        // then q will go through the linked list until it is right behind p
        // then have q point to the new order and the new order point to p
        if (neworder->type==1){
            p=head_buy;
            q=head_buy;
            while (p->next!=nullptr&&neworder->price<p->price) {
                p = p->next;
            }
            if (p==head_buy&& neworder->price>p->price){
                head_buy=neworder;
                head_buy->next=p;
                return;
            }
            else if (p==head_buy&& neworder->price==p->price){
                if (neworder->time<p->time){
                    head_buy=neworder;
                    head_buy->next=p;
                    return;
                }
                else if (neworder->time>p->time){
                    if (p->next==nullptr){
                        p->next=neworder;
                        return;
                    }
                    while (neworder->time>p->time && neworder->price==p->price){
                        p=p->next;
                    }
                    q->next=neworder;
                    neworder->next=p;
                    return;
                }


            }

            else if (p->next==nullptr&& neworder->price<p->price){
                p->next=neworder;
                return;
            }

            while (q->next!=p){
                q=q->next;
            }
            order_by_time(neworder,p,q);

        }

        if (neworder->type==2){
            p=head_sell;
            q=head_sell;
            while (p->next!=nullptr&&neworder->price>p->price) {
                p = p->next;
            }
            if (p==head_sell&& neworder->price<p->price){
                head_sell=neworder;
                head_sell->next=p;
                return;
            }
            else if (p==head_sell&& neworder->price==p->price){
                if (neworder->time<p->time){
                    head_sell=neworder;
                    head_sell->next=p;
                    return;
                }
                else if (neworder->time>p->time){
                    if (p->next==nullptr){
                        p->next=neworder;
                        return;
                    }
                    while (neworder->time>p->time && neworder->price==p->price){
                        p=p->next;
                    }
                    q->next=neworder;
                    neworder->next=p;
                    return;
                }


            }

            else if (p->next==nullptr&& neworder->price>p->price){
                p->next=neworder;
                return;
            }

            while (q->next!=p){
                q=q->next;
            }
            order_by_time(neworder,p,q);
        }


    }

    void print_buy_list(){
            for (order* p=this->head_buy;p!=nullptr;p=p->next) {
                std::cout << "Buy order" << '\n';
                std::cout << "Price is " <<p->price<< '\n';
                std::cout << "Quantity is " <<p->quantity<< '\n';
                std::cout << "Time is " <<p->time<< '\n';
            }
    }


    void print_sell_list(){
        for (order* p=this->head_sell;p!=nullptr;p=p->next) {
            std::cout << "Sell order" << '\n';
            std::cout << "Price is " <<p->price<< '\n';
            std::cout << "Quantity is " <<p->quantity<< '\n';
            std::cout << "Time is " <<p->time<< '\n';
        }


    }
};
#endif //MATCHING_ENGINE_ORDER_BOOK_H
