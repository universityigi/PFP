// scrivere la soluzione in questo file
import scala.language.implicitConversions
object Point{
	implicit def convPoin(l:List[Point])= PointList(l)

}
case class PointList(l:List[Point]) {
		def +++(m:List[Point])={
			l ::: m
		}
	}

case class Point(x:Float,y:Float){
	override def toString="("+this.x+","+this.y+")" 
}
	
case class Circle(x:Float,y:Float,r:Float){
	def contains (p:Point)={
		p.x>=this.x && p.x<=2*this.r && p.y>=this.y && p.y<=this.r*2
	}
	def >?(l:List[Point]) ={
		l.forall(x=>this.contains(x))
	}
	def >>(l:List[Point])={
		l.filter(x=>this.contains(x))
	}
}
