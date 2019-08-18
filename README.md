# 42 School Cheat Sheet by [Antonin Gavrel](www.github.com/agavrel)

*Intended for 42 current and future 42 students*

### Introduction to 42

Description from the US School official website:
> 42 is more than just a disruptive educational model and coding school. What makes us unique and a major player in the tech world are the defining characteristics of the 42 culture. Every element of 42 shows our culture, from the students, to the curriculum structure and content, to the $0 tuition and innovative admissions process.

Most of the course are about C coding.

### About the "Piscine"
The piscine is the entrance exam that consists of 4 weeks fully dedicated at solving exercises and submitting group and solo projects.  
Although the school advise you to "come as you are", and this is what I did, it does certainly help to prepare beforehand.  
You can find the [subject on github](https://github.com/Binary-Hackers/42_Subjects/tree/master/01_Piscines/C/EN), courtesy of my friend binary hacker.
As this cheatsheet is intended for 42 students I will not talk too much about this. Few things to know:

**Guidelines to succeed:**
* It does not matter if you fail a project, an exam or a day as long as you keep striving. Someone who has never been interested before in Computer Science would never be able to complete everything in time, yet he will not prevent from being successful.
* My opinion on what are the criteria to succeed are: 1/ How far you went on the 4 exams session, knowing that the 3 firsts exams are limited in term of how far you can go, 2/ to have an acceptable percentage of review from peers (probably 80% is enough, but you would get 90 to 97% if you are nice). 3/ The logging time has no or very little influence, but it certainly directly influence your skills, 4/ it is strongly advised to succeed at least one group project.
* There is a special and unique achievement awarded to the most helpful/smart student. This achievement does not show up on the student profile until he asks for it.

### 42 Projects Guides
|Name|Track|Hashtags|What you will learn|
|-|-|-|-|
|Fillit|General|Architecture, Parsing, Algo|[Description from a student](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)|
|Printf|Algorithm|Architecture, Parsing, utf-8|[UTF-8 Conversion table](https://en.wikipedia.org/wiki/UTF-8)<br>[Variadic Function](https://en.wikipedia.org/wiki/Variadic_function)|
|Filler|Algorithm|Parsing, Algo, Bot|42 forums have good threads on this project|
|Lem-In|Algorithm|Parsing, Algo, Chained-Lists|[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)|
|Corewar|Algorithm|Architecture, parsing, disassembler, virus, VM|[About the original Game](https://en.wikipedia.org/wiki/Core_War)|
|LS|System|Parsing, Recursion, Chained-Lists|[The Good Old Manual](http://man7.org/linux/man-pages/man1/ls.1.html)|
|Minishell|System|Environment Variables, Shell|[Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)|
|Malloc|System|Algo, Memory, HashCollision|[The Good Old Manual](http://man7.org/linux/man-pages/man3/malloc.3.html)|
|FDF|Infographics|Parsing, Creativity|[Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)|
|Fractol|Infographics|Fractals, Mathematics, ARGB, HUV|[Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)|
|Wolfenstein 3d|Infographics|Raytracing, Rotation|[About the original Wolfenstein 3d](https://en.wikipedia.org/wiki/Wolfenstein_3D)|

### C Must-Read Books
*Download if you are a petty thief like me, adding the "torrent" or "pdf" keyword behind:*

The C Programming Language *by Brian Kernighan and Dennis Ritchie*  
[[C++] Optimizing software in C++ - Agner Fog (pdf)](https://www.agner.org/optimize/optimizing_cpp.pdf)  

### Common Beginner Mistakes

##### Array overflow
C does not perform boundary checking when using arrays.  
If you access outside the bounds of a stack based array it will just access another part of already allocated stack space, like in this example:

```c
void    somefunction3(void)
{
    int a[5];

    printf("%d\n", a[5]); // as 5 it is a size of the array and you try to access it it will overflow. Remember that the maximum array index you can ever access is its size minus 1.
}
```

##### Segmentation Fault
Many potential reasons for this. One commonly reason is that you declared a loop and either 1/ forgot to increment the counter or 2/ forgot the exit condition:
```c
int i = 0;

while (i < 10)
{
    {some stuff}
    // but where is i++ ?
}
```

```c
int somevariable = 0;
while (42) // always true
{
    {some stuff}
    if (somevariable == 1) // make sure that somevariable will equal 1 at some point.
        break ;
}
```

Correct way:
```c
int i = 0;

while (i < 10)
{
    {some stuff}
    i++;
}
```

*Practice: what about this loop ?*
```c
unsigned char c = 0;

while (c < 150)
{
    {some stuff}
    c++;
}
```

##### Accessing value of a local variable
Local variable value are allocated on the stack, which is cleaned once you exit the function.
```c
void increment_a(int a)
{
    a++; // it will have no effect
}

int solve(void)
{
    int a = 5;

    increment_a(a);
}
```

Hence if you want to modify a value you either have to use a pointer to the memory address:
```c
void increment_a(int *a)
{
    *a++;
}

int solve(void)
{
    int a = 5;

    increment_a(&a);
}
```

or return the local value:
```c
int increment_a(int a)
{
    return a+1;
}

int solve(void)
{
    int a = 5;

    a = increment_a(a);
}
```

##### Unprotected malloc
Do NOT leave a malloc unprotected:
```c
int allocate_memory(void)
{
    int *matrix;

    matrix = malloc(sizeof(int) * 9))

    return matrix;
}

int somefunction(void)
{
    int *matrix;

    matrix = allocate_memory();
}
```

Protect the malloc and also its return value:
```c
int allocate_memory(void)
{
    int *matrix;

    if (!(matrix = malloc(sizeof(int) * 9))) // this is short for matrix = malloc(sizeof(int) * 9; if (matrix == NULL)
		return NULL;   // the malloc is now protected,

    return matrix;
}

int somefunction(void)
{
    int *matrix;

    if ((matrix = allocate_memory()) == NULL) // the return value is also protected
        exit(); // note that often you can't or don't want to use exit() and will need to return 0 along all the functions up to the main function.
}
```

##### Freeing memory that has already been fred

Following the previous example, if you don't need the variable matrix anymore you can free it just by using:
```c
free(matrix); // do not attempt to free twice or to free a stack based variable
```

```c
free(matrix); // do not attempt to free twice or to free a stack based variable
```

##### Do Not use global variables
Global variables are forbidden in 42 School except for a few exceptions, see this interesting article: [Are Global Variables Bad](https://stackoverflow.com/questions/484635/are-global-variables-bad)
However many students, me including, found a way to circumvent this interdiction: you first declare a structure in the header that will contain all our variables:
```c
typedef struct s_env
{
    int a;
    int b;
    int c[4];
    // ... other variables you may need
}           t_env;
```
And then using it the following way in the program:
```c
void somefunction2(t_env *env)
{
    env->b = 2;
}

void somefunction(t_env *env)
{
    env->a = 1;

    somefunction2(env);
}

int main(void)
{
    t_env env;

    somefunction(&env);

    printf("%d\n", env.a);
    printf("%d\n", env.b);
}
```

This is "legal" in 42 (it is not a global variable, it is a structure passed along functions), it "works", but it is a very poor architecture choice. It is okay for beginner to do this but as your skill grows you should find more clever ways to architecture your programs.

##### VLA - Variable Length Arrays
The following example is a VLA and this is bad for many reasons, the most critical being that the memory is allocated on the stack which has a limited size.
```c
int somefunction(int y, int x, int array[y][x]);
```
[Waiter! There's a VLA in my C!](http://ayekat.ch/blog/vla)

##### using ft_ prefix for all functions

*ft_* is intended for functions you want to add to the libft project and use along your projects, not for specific program functions.

### Good practices

##### Using flag for projects' options
For each project you will often have to parse flag input. In Linux the flag usually come after a '-' and allow for extra functionalities.
It is quite useful know how you can store such critical information into only 4 bytes *which is sizeof(integer)*
```c
static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int			get_flags(char *s, int *flags)
{
	int		n;

	while (*(++s))
	{
		if ((n = ft_strchr_index("alRrtdG1Ss", *s)) == -1)
			return (0);
		*flags |= (1 << n);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int	i;

	int flags = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-' && av[i][2])
			return (i + 1);
		if (!get_flags(av[i], &flags))
			return (-1);
	}
	return (i);
}
```

The a flag will be on bit 1, l on bit 2, R on bit 4, r on bit 8 etc.
You can then test if the flag was on by using the following:
```c
#define FLAG_A  0b001
#define FLAG_L  0b010
#define FLAG_RR 0b100
#include <stdio.h>

void    somefunction(int *flags)
{
    if (flags & FLAG_A)
        printf("Flag a is set!\n");    
}
```

You can unset a flag by clearing the corresponding bit the following way:
```c
void    somefunction2(int *flags)
{
    flags &= ~FLAG_A;
}
```

##### Using gcc flags for Makefile
```
gcc -Wall -Wextra -Werror -O2
```
* O2 will improve performance  
* pedantic is not requested but is a good one to check ISO C compliance

> Issue all the warnings demanded by strict ISO C and ISO C++; reject all programs that use forbidden extensions, and some other programs that do not follow ISO C and ISO C++. For ISO C, follows the version of the ISO C standard specified by any -std option used.


You can read the details about each flag on [gccgnu website](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
