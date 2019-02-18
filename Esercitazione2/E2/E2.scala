object E2{
	def corrisp[A,B](a:List[A],b:List[B], f:A=>B):Boolean= (a,b) match{
		case (Nil,Nil) => true
		case (Nil, _) => true
		case (_,Nil) => true
		case (h1::t1,h2::t2) if(h2==f(h1)) => corrisp(t1,t2,f)
		case _ => false
	}
}
