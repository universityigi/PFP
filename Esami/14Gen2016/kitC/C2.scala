// scrivere la soluzione in questo file
object C2{
	def ps(l1:List[Int],l2:List[Int]):Int=(l1,l2) match{
		case (Nil,Nil) => 0
		case (_,Nil) => 0
		case (Nil,_) => 0
		case (h1::t1,h2::t2) => h1*h2+ps(t1,t2)
		
	}
}
