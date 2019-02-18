import java.awt.Color

object Model2D {

  def getGrid(n:Int) = {

    val RED = new Color(0xFF0000) // in formato RGB (Red-Blue-Green) o anche Color.RED

    // completare costruzione di un modello 2D di una griglia con n linee verticali ed n linee orizzontali
    
    List.range(1,n+1).map(x=>x/n).flatMap((x:Double) => List(
        Line(0.0,0.5,1.0,0.5,RED), // linea rossa
        Line(0.5,0,0.5,1.0)        // linea colore default (nero)
    )).toList
    
  }

  def main(args:Array[String]) {
    println("Displaying 20x20 grid...")
    Frame2D.display(Model2D.getGrid(20), 500, 500)
  }
}
