// -----------
// Mon, 18 Sep
// -----------

/*
types

default backer for stack/queue    is deque,  because deque  is faster at resisizing
default backer for priority_queue is vector, because vector is faster at indexing

voting
    max of   20 candidates
    max of 1000 ballots

input
    the value    of the number on the ballot indicates which candidate
    the position of the number on the ballot indicates which preference

procedure
    there might be a tie, if so, done, output the tiers
    someone has 501 or more, done, one winner
    identify the losers, look at only their ballots, looking at next choice
*/
