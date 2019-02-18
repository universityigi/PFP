sealed abstract class BinTree {
    def sum :Int= this match{
		case E() => 0
		case T(l,e,r) => (l,r) match{
			case (E(),E()) => e
			case (T(l1,e1,r1), E()) => e+l.sum
			case (E(), T(l2,e2,r2)) => e+r.sum
			case (T(l1 ,e1,r1), T(l2,e2,r2)) => l.sum+e+r.sum
			
		}
	}
}

// albero non vuoto
case class T(l:BinTree, e:Int, r:BinTree) extends BinTree 

// albero vuoto
case class E() extends BinTree
