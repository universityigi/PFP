object E23{
	def profila[T](exp: => T):(T,Long)={
		val start =System.nanoTime
		val v=exp
		val e= System.nanoTime -start
		(v,e)
	}
}
