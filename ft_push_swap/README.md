# Push Swap
Push Swap is a Project in which you have to sort Numbers on the Heap Stack using given Instructions to Sort the Numbers using two different Stacks.

a Stack and b Stack

In the Beginning every Number is pushed into the a Stack.

x numbers are now in a list called "a Stack"

Lets make an example with the Numbers "5 3 4 2 1"
5 is the Beginning of the a Stack.
1 is the End of the a Stack.


One of the Operations to Sort the Numbers is called "rra".

"rra" moves the last number of the stack of the beginning of the stack.

"5 3 4 2 1" becomes "1 5 3 4 2"


another Operation is "pb" it pushes the first number of stack a to stack b

"1 5 3 4 2" becomes "5 3 4 2"

"1" is now in the b stack

now we use the rra operation again.

"5 3 4 2" becomes "2 5 3 4"

now we use the sa operation (swap a stack) it swaps the first two values.

"2 5 3 4" becomes "5 2 3 4"

now we use the ra operation, it puts the first number at the end of the list. (stack)

"5 2 3 4" becomes "2 3 4 5"

now we use the pa operation,
it pushes the first number from b stack to a stack

"2 3 4 5" becomes "1 2 3 4 5"

every Number is now succesfully sorted.

So the Topic of this Project is to implement an algorhytm that sorts a list of 5, 100 and 500 random numbers, with the lowest amount of Operations possible.

For a complete explanation of all possible Operations please check out the Operations README.


In this Project in teached myself how to use doubly linked lists. I used doubly linked lists to store the numbers on the heap.
I very certainly could have done it with arrays and it would have been at lot easier, but I wanted to teach myself more.

