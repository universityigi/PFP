import java.awt.Color

// classe astratta che rappresenta elementi grafici 2D
sealed abstract class Shape

// cerchio di raggio r centrato in (x,y) di colore c
case class Circle(x:Double, y:Double, r:Double, c:Color = Color.RED) extends Shape

// segmento di linea da (x1,y1) a (x2,y2) di colore c
case class Line(x1:Double, y1:Double, x2:Double, y2:Double, c:Color = Color.RED) extends Shape

// si veda https://docs.oracle.com/javase/7/docs/api/java/awt/Color.html
// per la documentazione sui colori
