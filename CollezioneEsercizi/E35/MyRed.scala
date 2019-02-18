import scala.language.implicitConversions
object MyRed{
	implicit def convRed[T](l:List[T]) = new MioRed(l)
}
case class MioRed[T](l:List[T]){
	def myReduce(f:(T,T)=>T):Option[T]={
		if(l==Nil) None
		else{
			def aux(l:List[T], i:T):Option[T]=l match{
				case Nil => None
				case (h1::Nil) => Some(h1)
				case (h1::t1) => aux(t1,f(i,h1))
			}
			aux(l,l.head)
		}
	}
}
