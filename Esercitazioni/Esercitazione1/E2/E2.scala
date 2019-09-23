object E2{
	def mcd(x:Int, y:Int):Int={
		if (y==0) x
		else mcd(y, x%y)
	}
}
