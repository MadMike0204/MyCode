//斐波那契数列（调用自身的函数 称为递归recursion）

unsigned long Fibonacci(unsigned n)
{
    if (n > 2)
        return Fibonacci(n - 1 );
    else
        return 1;
}