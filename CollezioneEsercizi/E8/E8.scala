object E8{
	def isSorted(l:List[Int]):Boolean={
		val l2=l.sorted
		if(l==l2) true 
		else false
	}
	def isSortedRic(l:List[Int]):Boolean= l match{
		case Nil => true
		case (h::t) if(h < t.head) => isSorted(t)
		case _ => false
	}
	def isSortedIt(l:List[Int])={
		l.sliding(2).forall(y=>y(0)<=y(1))
	}
}

