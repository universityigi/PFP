sealed abstract class BinTree {
    def map(f:Int=>Int):BinTree = this match{
		case E() => this
		case T(l,e,r) => (l,r) match{
			case (E(),E()) => T(E(),f(e),E())
			case (T(l1,e1,r1),E()) => T(l.map(f),f(e),E())
			case (E(),T(l2,e2,r2)) => T(E(),f(e),r.map(f))
			case (T(l1,e1,r1),T(l2,e2,r2)) => T(l.map(f),f(e),r.map(f))
		}
	}
}

// albero non vuoto
case class T(l:BinTree, e:Int, r:BinTree) extends BinTree 

// albero vuoto
case class E() extends BinTree
