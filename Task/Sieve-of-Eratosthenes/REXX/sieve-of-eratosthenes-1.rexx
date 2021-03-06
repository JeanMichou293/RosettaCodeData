/*REXX program  generates primes  via the  sieve of Eratosthenes  algorithm.            */
parse arg H .;   if H=='' | H==","  then H=200   /*optain optional argument from the CL.*/
w=length(H);     @prime=right('prime', 20)       /*W:   is used for aligning the output.*/
@.=.                                             /*assume all the numbers are  prime.   */
#=0                                              /*number of primes found  (so far).    */
     do j=2  for H-1;  if @.j==''  then iterate  /*all prime integers up to H inclusive.*/
     #=#+1                                       /*bump the prime number counter.       */
     say  @prime right(#,w)  " ───► " right(j,w) /*display the  prime  to the terminal. */
         do m=j*j  to H  by j;  @.m=; end /*m*/  /*strike all multiples as being ¬ prime*/
     end   /*j*/                                 /*       ───                           */
say
say  right(#,w+length(@prime)+1) 'primes found.' /*stick a fork in it,  we're all done. */
