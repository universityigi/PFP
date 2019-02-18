object E4Main extends App {
    println(E4.ugualiIn(x=>x+x, x=>2*x, 10)+" [corretto: true]")
    println(E4.ugualiIn(x=>x+x, x=>x*x, 5)+" [corretto: false]")
    println(E4.ugualiIn(x=>x+x, x=>x*x, 0)+" [corretto: true]")
    
    println(E4.ugualiInRic(x=>x+x, x=>2*x, 10)+" [corretto: true]")
    println(E4.ugualiInRic(x=>x+x, x=>x*x, 5)+" [corretto: false]")
    println(E4.ugualiInRic(x=>x+x, x=>x*x, 0)+" [corretto: true]")
}
