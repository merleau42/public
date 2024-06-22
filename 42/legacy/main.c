#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// char *null_str = NULL;

ft_printf("\n\n1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest");
   printf(  "\n1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest");

// ft_printf("\n\n%c", 'a');
//    printf(  "\n%c", 'a');

// ft_printf("\n\n%c%c%c*", '\0', '1', 1);
//    printf(  "\n%c%c%c*", '\0', '1', 1);

// ft_printf("\n\n%c small string", 'a');
//    printf(  "\n%c small string", 'a');

// ft_printf("\n\n%c small string", '\0');
//    printf(  "\n%c small string", '\0');

// ft_printf("\n\nthe char is: %c", 'a');
//    printf(  "\nthe char is: %c", 'a');

// ft_printf("\n\nthe char is: %c", '\0');
//    printf(  "\nthe char is: %c", '\0');

// ft_printf("\n\nn%cs", 'a');
//    printf(  "\nn%cs", 'a');

// ft_printf("\n\n%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
//    printf(  "\n%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');

// ft_printf("\n\nl%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
//    printf(  "\nl%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');

// ft_printf("\n\nl%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
//    printf(  "\nl%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');

// ft_printf("\n\n%s", "");
//    printf(  "\n%s", "");

// ft_printf("\n\nthis is a %s", "test");
//    printf(  "\nthis is a %s", "test");

// ft_printf("\n\nthis is 1 %s with %s %s", "test", "multiple", "strings");
//    printf(  "\nthis is 1 %s with %s %s", "test", "multiple", "strings");

// ft_printf("\n\n%s%s%s%s", "This ", "is", " an ugly ", "test");
//    printf(  "\n%s%s%s%s", "This ", "is", " an ugly ", "test");

// ft_printf("\n\n%s", "This is a rather simple test.");
//    printf(  "\n%s", "This is a rather simple test.");

// ft_printf("\n\n%s", "-2");
//    printf(  "\n%s", "-2");

// ft_printf("\n\n%s", "-24");
//    printf(  "\n%s", "-24");

// ft_printf("\n\n%s", "-stop");
//    printf(  "\n%s", "-stop");

// ft_printf("\n\n%s", "-0003");
//    printf(  "\n%s", "-0003");

// ft_printf("\n\n%s", "000-0003");
//    printf(  "\n%s", "000-0003");

// ft_printf("\n\n%s", "0x42");
//    printf(  "\n%s", "0x42");

// ft_printf("\n\n%s", "0x0000042");
//    printf(  "\n%s", "0x0000042");

// ft_printf("\n\nsome naugty tests: %s", "0000%");
//    printf(  "\nsome naugty tests: %s", "0000%");

// ft_printf("\n\nsome naugty tests: %s", "    %");
//    printf(  "\nsome naugty tests: %s", "    %");

// ft_printf("\n\nsome naugty tests: %s", "%000");
//    printf(  "\nsome naugty tests: %s", "%000");

// ft_printf("\n\n%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!");
//    printf(  "\n%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!");

// ft_printf("\n\n%s", null_str);
//    printf(  "\n%s", null_str);

// ft_printf("\n\n%s everywhere", null_str);
//    printf(  "\n%s everywhere", null_str);

// ft_printf("\n\neverywhere %s", null_str);
//    printf(  "\neverywhere %s", null_str);

// ft_printf("\n\n%s", "h");
//    printf(  "\n%s", "h");

// ft_printf("\n\nt%st%s", "a", "u");
//    printf(  "\nt%st%s", "a", "u");

// ft_printf("\n\n%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");
//    printf(  "\n%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");

// int test = 42;
// ft_printf("\n\n%p", &test);
//    printf(  "\n%p", &test);

// ft_printf("\n\n%p is a virtual memory address", &test);
//    printf(  "\n%p is a virtual memory address", &test);

// ft_printf("\n\nThe address of the answer is %p", &test);
//    printf(  "\nThe address of the answer is %p", &test);

// ft_printf("\n\nThe address is %p, so what?", &test);
//    printf(  "\nThe address is %p, so what?", &test);

// int *ptr = &test;
// ft_printf("\n\nA pointer at %p points to %p", &test, &ptr);
//    printf(  "\nA pointer at %p points to %p", &test, &ptr);

// ft_printf("\n\nThis %p is a very strange address", (void *)(long int)test);
//    printf(  "\nThis %p is a very strange address", (void *)(long int)test);

// char *mallocked = malloc(2);
//    printf("This %p is an address from the heap", mallocked);
// free(mallocked);

// ft_printf("\n\n%p", NULL);
//    printf(  "\n%p", NULL);

// ft_printf("\n\nThe NULL macro represents the %p address", NULL);
//    printf(  "\nThe NULL macro represents the %p address", NULL);

// ft_printf("\n\nThis %p is even stranger", (void *)-1);
//    printf(  "\nThis %p is even stranger", (void *)-1);

// ft_printf("\n\n%d", 0);
//    printf(  "\n%d", 0);

// ft_printf("\n\n%d", 10);
//    printf(  "\n%d", 10);

// ft_printf("\n\n%d, %d", 10, 20);
//    printf(  "\n%d, %d", 10, 20);

// ft_printf("\n\n%d%d%d%d", 10, 20, 30, 5);
//    printf(  "\n%d%d%d%d", 10, 20, 30, 5);

// ft_printf("\n\n%d %d", 2147483647, (int)-2147483648);
//    printf(  "\n%d %d", 2147483647, (int)-2147483648);

// ft_printf("\n\n42 - 84 is %d", -42);
//    printf(  "\n42 - 84 is %d", -42);

// ft_printf("\n\n%d C is the lowest temperature in the universe", -273);
//    printf(  "\n%d C is the lowest temperature in the universe", -273);

// ft_printf("\n\n%dxC is the lowest temperature in the universe", -273);
//    printf(  "\n%dxC is the lowest temperature in the universe", -273);

// ft_printf("\n\n%dsC is the lowest temperature in the universe", -273);
//    printf(  "\n%dsC is the lowest temperature in the universe", -273);

// ft_printf("\n\n%dpC is the lowest temperature in the universe", -273);
//    printf(  "\n%dpC is the lowest temperature in the universe", -273);

// ft_printf("\n\n%i", 0);
//    printf(  "\n%i", 0);

// ft_printf("\n\n%i", 10);
//    printf(  "\n%i", 10);

// ft_printf("\n\n%i, %i", 10, 23);
//    printf(  "\n%i, %i", 10, 23);

// ft_printf("\n\n%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779);
//    printf(  "\n%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779);

// ft_printf("\n\n%i %i", 2147483647, (int)-2147483648);
//    printf(  "\n%i %i", 2147483647, (int)-2147483648);

// ft_printf("\n\n%iq%i", 21447, -21648);
//    printf(  "\n%iq%i", 21447, -21648);

// ft_printf("\n\n%u", 42);
//    printf(  "\n%u", 42);

// ft_printf("\n\n%u", 0);
//    printf(  "\n%u", 0);

// ft_printf("\n\n%u", 2147483647);
//    printf(  "\n%u", 2147483647);

// ft_printf("\n\n%u", (unsigned int)2147483648);
//    printf(  "\n%u", (unsigned int)2147483648);

// ft_printf("\n\n%u", (unsigned int)3147983649);
//    printf(  "\n%u", (unsigned int)3147983649);

// ft_printf("\n\n%u", (unsigned int)4294967295);
//    printf(  "\n%u", (unsigned int)4294967295);

// ft_printf("\n\n%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);
//    printf(  "\n%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);

// ft_printf("\n\n%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);
//    printf(  "\n%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);

// ft_printf("\n\n%x", 0);
//    printf(  "\n%x", 0);

// ft_printf("\n\n%x", 1);
//    printf(  "\n%x", 1);

// ft_printf("\n\n%x", 10);
//    printf(  "\n%x", 10);

// ft_printf("\n\n%x", 16);
//    printf(  "\n%x", 16);

// ft_printf("\n\n%x", 160);
//    printf(  "\n%x", 160);

// ft_printf("\n\n%x", 255);
//    printf(  "\n%x", 255);

// ft_printf("\n\n%x", 256);
//    printf(  "\n%x", 256);

// ft_printf("\n\n%x", 3735929054u);
//    printf(  "\n%x", 3735929054u);

// ft_printf("\n\nthe password is %x", 3735929054u);
//    printf(  "\nthe password is %x", 3735929054u);

// ft_printf("\n\n%x is the definitive answer", 66u);
//    printf(  "\n%x is the definitive answer", 66u);

// ft_printf("\n\nthis is the real number: %x", -1u);
//    printf(  "\nthis is the real number: %x", -1u);

// ft_printf("\n\n%X", 0);
//    printf(  "\n%X", 0);

// ft_printf("\n\n%X", 1);
//    printf(  "\n%X", 1);

// ft_printf("\n\n%X", 10);
//    printf(  "\n%X", 10);

// ft_printf("\n\n%X", 16);
//    printf(  "\n%X", 16);

// ft_printf("\n\n%X", 160);
//    printf(  "\n%X", 160);

// ft_printf("\n\n%X", 255);
//    printf(  "\n%X", 255);

// ft_printf("\n\n%X", 256);
//    printf(  "\n%X", 256);

// ft_printf("\n\n%X", (unsigned int)3735929054);
//    printf(  "\n%X", (unsigned int)3735929054);

// ft_printf("\n\nthe password is %X", (unsigned int)3735929054);
//    printf(  "\nthe password is %X", (unsigned int)3735929054);

// ft_printf("\n\n%X is the definitive answer", (unsigned int)66);
//    printf(  "\n%X is the definitive answer", (unsigned int)66);

// ft_printf("\n\nthis is the real number: %X", (unsigned int)-1);
//    printf(  "\nthis is the real number: %X", (unsigned int)-1);

// ft_printf("\n\n%%");
//    printf(  "\n%%");

// ft_printf("\n\n100%%");
//    printf(  "\n100%%");

// ft_printf("\n\n%%p is how you print a pointer in printf");
//    printf(  "\n%%p is how you print a pointer in printf");

// ft_printf("\n\nthe '%%%%' is used to print a %% in printf");
//    printf(  "\nthe '%%%%' is used to print a %% in printf");

// ft_printf("\n\n%%%%%%%%%%%%%%%%");
//    printf(  "\n%%%%%%%%%%%%%%%%");

// ft_printf("\n\n%%c%%s%%p%%d%%i%%u%%x%%X%%");
//    printf(  "\n%%c%%s%%p%%d%%i%%u%%x%%X%%");

// ft_printf("\n\n%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
//    printf(  "\n%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);

// ft_printf("\n\n%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000);
//    printf(  "\n%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000);

// ft_printf("\n\n%c - %s - %p %d - %i - %u - %x %X %%", 'c', "", (void *)-1, 20, -20, -1, -1, 200000000);
//    printf(  "\n%c - %s - %p %d - %i - %u - %x %X %%", 'c', "", (void *)-1, 20, -20, -1, -1, 200000000);

// ft_printf("\n\n%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000);
//    printf(  "\n%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000);

// ft_printf("\n\n%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, NULL, 20, -20, -1, -1, 200000000);
//    printf(  "\n%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, NULL, 20, -20, -1, -1, 200000000);

// ft_printf("\n\n%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
//    printf(  "\n%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);

}