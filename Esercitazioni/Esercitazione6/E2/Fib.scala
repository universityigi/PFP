object Fib {
    def fib(a:Int, b:Int)(n:Int):Long = 
        if (n < 2) a
        else if (n == 2) b
        else fib(a,b)(n-1) + fib(a,b)(n-2)
}
