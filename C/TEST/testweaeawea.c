void print_str(char *str)
{
    //在函数内部，可以通过指针访问和修改字符串
    printf("The original string is: %s\n", str); //打印原始字符串
    str[0] = 'H'; //修改字符串的第一个字符
    printf("The modified string is: %s\n", str); //打印修改后的字符串
}

int main()
{
    //定义一个字符串变量
    char s[] = "hello";
    //调用自定义函数，传入字符串的地址
    print_str(s);
    //在main函数中，可以看到字符串被修改了
    printf("The string in main is: %s\n", s);
    return 0;
}