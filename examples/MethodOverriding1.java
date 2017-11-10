// ----------------------
// MethodOverriding1.java
// ----------------------

class A {
    public String f (int i) {
        return "A.f";}

    public String g (int i) {
        return "A.g";}

    public String h (int i) {
        return "A.h";}}

class B extends A {
    public String f (int i) {
        return "B.f";}

    public String g (String s) {
        return "B.g";}

    public String h (double d) {
        return "B.h";}}

final class MethodOverriding1 {
    public static void main (String[] args) {
        System.out.println("MethodOverriding1.java");

        B x = new B();

        assert x.f(2) == "B.f";
        assert x.g(2) == "A.g";
        assert x.h(2) == "A.h";

        System.out.println("Done.");}}
