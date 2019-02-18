object Model2D {

  def getToroidalMandala(numPetals:Int) = {

    // completare costruzione di un modello 2D di un Mandala toroidale
    (1 to numPetals).map(x=> new Circle(0.5+0.25*Math.sin(x), 0.25*Math.cos(x)+0.5, 0.25)).toList
  }

  def main(args:Array[String]) {
    println("Displaying Toroidal Mandala...")
    Frame2D.display(Model2D.getToroidalMandala(24), 500, 500)
  }
}
