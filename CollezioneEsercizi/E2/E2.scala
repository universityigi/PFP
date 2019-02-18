object E2{
	def applicaDueVolte(f:Int=>Int)={
		def incrementa(x:Int):Int={
			f(f(x))
		}
		incrementa _
	}
}
