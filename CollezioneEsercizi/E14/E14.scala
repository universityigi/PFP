object E14{
	def mymap(l:List[Int],f:Int=>Int):List[Int]=l match{
		case Nil => Nil
		case h::t => f(h)::mymap(t,f)
	}
}
