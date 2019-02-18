object E4{
	def fibo(n:Int):Int={
		if(n==1) 1
		else if(n==2) 1
		else fibo(n-1)+fibo(n-2)
	}
}
