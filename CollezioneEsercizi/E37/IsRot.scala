import scala.language.implicitConversions
object IsRot{
	implicit def convRort[T](l:Seq[T])= new MioRot(l)
}

class MioRot[T](l:Seq[T]){
	def isRot(m:Seq[T]) :Option[Int]={
		if(l.filter(x=>m.contains(x))==l){
			val join=for{
				i<- 0 until m.size
				(a,b) = m splitAt(i)
				if(l==b++a)
			}yield i
			if(join.isEmpty) None
			else Some(join.head)
		}
		else{
			None
		}
	}
}
