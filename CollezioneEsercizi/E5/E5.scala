object E5{
	def concatena(f1:Double=>Double,f2:Double=>Double,f3:Double=>Double,a:Double,b:Double)={
		def conc(x:Double)={
			if(x<a) f1(x)
			else if (x>b) f2(x)
			else f3(x)
		}
		conc _
	}
}
