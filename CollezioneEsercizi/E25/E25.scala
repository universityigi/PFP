object E25 extends App{

  case class Rational (n: Int, d:Int){
  require(d != 0)
  def abs(x:Int) = if (x < 0) -x else x
  def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a%b)
  def getN = n / gcd(abs(n), abs(d))
  def getD = d / gcd(abs(n), abs(d))
  def +(other:Rational):Rational = new Rational(getN * other.getD + getD * other.getN, getD * other.getD)
  def -(other:Rational):Rational = this + (new Rational(-1 * other.getN, other.getD))
  def *(other:Rational):Rational = new Rational(getN * other.getN, getD * other.getD)
  def /(other:Rational):Rational = new Rational(getN * other.getD, getD * other.getN)
  def <(other:Rational):Boolean = (this.getN.toDouble / this.getD.toDouble) < (other.getN.toDouble / other.getD.toDouble)
  def >(other:Rational):Boolean = (this.getN.toDouble / this.getD.toDouble) > (other.getN.toDouble / other.getD.toDouble)
  override def equals (other:Any) = {
    other match {
      case r:Rational => this.getN == r.getN && this.getD == r.getD
      case _ => false
    }
  }
  override def toString: String = this.getN.toString + "/" + this.getD.toString
}
val r1 = Rational(2, 7)
    val r2 = Rational(8, 6)
    val r3 = Rational(4, 14)
    println(r1+r2)  // stampa 34/21
    println(r1-r2)  // stampa -22/21
    println(r1*r2)  // stampa 8/21
    println(r1/r2)  // stampa 3/14
    println(r1==r3) // stampa true
    println(r1!=r3) // stampa false
    println(r1!=r2) // stampa true
    println(r1<r2)  // stampa true
    println(r2<r1)  // stampa false
}
