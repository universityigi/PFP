object E15{
	def minMax(l:List[Int])={
		def aux(l2:List[Int],min:Int,max:Int):(Int,Int)=l2 match{
				case Nil => (min,max)
				case h::t if(h < min) => aux(t,h,max)
				case h::t if (h>max) => aux(t,min,h)
				case h::t => aux(t,min,max)
		}
		aux(l,l(0),l(0))
	}
}
