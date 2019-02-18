// completare questo file con la soluzione...

sealed abstract class Tree(){
	def minMax:(Int,Int,Int)= { 
		val (min,count1)=this.min
		val (max,count2)=this.max
		(min,max,count1+count2)
	}
	def min:(Int,Int)= this match{
		case E() => (Integer.MAX_VALUE,0)
		case T(l,x,r) => {
			val (minimo,count)=l.min
			( x min minimo,count+1)
		}
	}
	def max:(Int,Int)= this match{
		case E() => (Integer.MIN_VALUE,0)
		case T(l,x,r) => {
			val (massimo,count)=r.max
			( x max massimo,count+1)
		}
	}
}
case class E() extends Tree()
case class T(l:Tree, x:Int, r:Tree) extends Tree()
