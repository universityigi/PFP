object E13{
	def equal(l1:List[Int],l2:List[Int]):Boolean=(l1,l2) match{
		case (Nil,Nil) => true
		case (Nil,_) => false
		case (_,Nil) => false
		case (h1::t1,h2::t2) if(h1==h2) => equal(t1,t2)
		case _ => false
	}
}
