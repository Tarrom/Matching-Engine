# Matching-Engine

This repository is a simple matching engine for a single stock that contains an order book for the buy orders and sell orders, each in seperate linked lists.  Buy Orders are ordered first from high price to low price and if the price is the same, the earlier order goes before the later order.  Likewise, the sell orders are ordered from low price to high price and if the price of two orders are the same, the earlier order goes first.

In addition to the order book, the matching engine contains a function that looks at the order book and matches buy orders with sell orders.  The orders are matched in a way most advantageous to the buyer, so if an order is matched it is executed at the sell order.  Again, earlier orders will be prioritized over later orders if the prices are the same.  If no buy order has a greater price than any sell order then no trade will be executed.

This code consists of one class for an order, which consists of an integer indicating if it is a buy order, sell order or a trade, the order price, the order quantity and the order time.  There is another class for the order book, which maintains a singly linked list for the buy orders and a singly linked list for the sell orders.  Each list has a pointer pointing to the head of each linked list.  When a order is added to the order book, it is added to the appropriate list depending on if it is a buy order or sell order and then inserted into the appropriate place in the list depending on it's price and time.

Lastly there is a matching function that looks at the order book and executes trades.  The function checks the head of the buy list and head of the sell list to see if the order price of the head of the buy list is greater than the order price of the head of the sell list.  If it is, it matches the buy order with the sell order, taking into account the quantity of the orders.  The trade is executed at the price of the sell order.  When trades are matched, a seperate order is created consisting of the trade, and added to a seperate "trade list" order book.  This keeps track of the trades in a linked list.  Also, when trades are executed they are removed from the order book.  When a buy order is removed from the order book the head of the buy list is updated.  The same happens for the sell list.  The matching engine will then check again to see if the price of the order at the head of the buy list is greater than the price of the order at the head of the sell list.  The matching function returns the trade list, which is again a list of the trade orders.  If no trades are executed the trade list consists of an order of quantity 0 and price 0.  The order book is passed in the function as a pointer because we only need to modify the existing order book.

The main of this program consists of a test that adds a bunch of buy and sell orders and then matches them.

Possible future improvements to this program:

When a trade executes, in addition to returning a trade list consisting of the overall orders, it would be very useful to return those trades individually for each seperate order.  After all, each person placing their order should know if their order was executed or not.

Create some sort of network interface that would simulate how someone would connect to the exchange to place their order

Create a UI for someone to place orders

