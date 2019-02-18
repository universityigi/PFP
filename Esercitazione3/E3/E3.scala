sealed abstract class BinTree {
    // Scrivere la soluzione qui...
    def isSearchTree:Boolean=this match{
		case E() => true
		case T(l,e,r)  => (l,r) match{
			case (E(), E()) => true
			case (E(),T(l2,e2,r2)) if(e<e2) => r.isSearchTree
			case (T(l1,e1,r1),E()) if(e>e1) => l.isSearchTree
			case (T(l1,e1,r1),T(l2,e2,r2)) if(e>e1 && e<e2) => l.isSearchTree && r.isSearchTree
			case _ => false
		} 
	}
}

// albero non vuoto
case class T(l:BinTree, e:Int, r:BinTree) extends BinTree 

// albero vuoto
case class E() extends BinTree
