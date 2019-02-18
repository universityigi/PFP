object E1Main extends App {
    var punti = 0
    
    val s1:Double=>Double = E1.sommaFun(x=>x, x=>x+1)
    val n1 = s1(2)
    println(n1+" (corretto: 5.0)")
    if (n1==5) punti += 1 
    
    val s2 = E1.sommaFun(x=>2*x, x=>x+2)
    val n2 = s2(3)
    println(n2+" (corretto: 11.0)")
    if (n2==11) punti += 1 
    
    val s3 = E1.sommaFun(x=>math.sin(x), x=>math.cos(x))
    val n3 = s3(3.14142)
    println(n3+" (corretto: ~-1.0)")
    if (math.abs(n3+1.0)<0.01) punti += 1
    
    println("Punti: " + punti + " su 3")
}
