object E17 extends App{
	def sqrt(x:Double)={
		def avg(y:Int):Double={
			val media=(y*y+x)/(2*y)
			if(abs(y*y -x) <0.01) y
			else media
		}
		def abs(x:Double):Double={
			if(x<0) -x
			else x
		}
		avg(1)
	}
	println("Radice quadrata di 2: "+sqrt(2))
}
