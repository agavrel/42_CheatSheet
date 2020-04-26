
# 42 School Cheat Sheet by [agavrel](https://www.github.com/agavrel)

## :two_hearts: Intended for 42 alumni, current students and candidates

> **Truth can only be found in one place: the code** – *Robert C. Martin, Clean Code: A Handbook of Agile Software Craftsmanship*

---
# Table of Content

* **[0. About 42 School](#about-42-school)**
    * **[0x00 ~ What is 42 School](#0x00--what-is-42-school)**
    * **[0x01 ~ For Candidates: About the "Piscine"](#0x01--for-candidates-about-the-piscine)**    
        * **[My guess on the success criteria](#coffee-my-guess-on-the-success-criteria)**  
        * **[List of Essential Items](#star-list-of-essential-items)**  
    * **[0x02 ~ Coding simple C programs](#0x02--coding-simple-c-programs)**  
        * **[First by installing a C compiler on your computer](#first-by-installing-a-c-compiler-on-your-computer)**  
        * **[ft_putchar](#ft_putchar)**  
        * **[ft_strlen](#ft_strlen)**  
        * **[ft_putstr](#ft_putstr)**  
    * **[0x03 ~ 42 Projects Guides](#0x03--42-projects-guides)**  
    * **[0x04 ~ Choosing your Path](#0x04--choosing-your-path)**  
    * **[0x05 ~ Swindle the norminette - *truander la norme*](#0x05--swindle-the-norminette---truander-la-norme)**  
        * **[While Loops](#while-loops)**  
        * **[If Brackets](#if-brackets)**  
        * **[Write Colorful Usage](#write-colorful-usage)**  
        * **[Function Pointers](#function-pointers)**  
---
* **[1. Common Beginner Mistakes](#fire-common-beginner-mistakes)**  
    * **[0x00 ~ Array Overflow](#0x00--array-overflow)**  
    * **[0x01 ~ Segmentation Fault](#0x01--segmentation-fault)**  
    * **[0x02 ~ Bus error](#0x02--bus-error)**  
    * **[0x03 ~ Stack smashing](#0x03--stack-smashing)**  
    * **[0x04 ~ Modifying value of a local variable given as function parameter](#0x04--modifying-value-of-a-local-variable-given-as-function-parameter)**  
    * **[0x05 ~ Unprotected Malloc](#0x05--unprotected-malloc)**  
    * **[0x06 ~ Freeing memory that has already been fred](#0x06--freeing-memory-that-has-already-been-fred)**  
    * **[0x07 ~ Do Not Use Global Variables](#0x07--do-not-use-global-variables)**  
    * **[0x08 ~ Variable Length Arrays](#0x08--variable-length-arrays)**  
    * **[0x09 ~ Using ft_ prefix for all functions](#0x09--using-ft_-prefix-for-all-functions)**  
    * **[0x0A ~ Usage of Sequence Point](#0x0a--usage-of-sequence-point)**  
    * **[0x0B ~ Assignment of read-only location](#0x0b--assignment-of-read-only-location)**  
    * **[0x0C ~ Carefully use define preprocessor macros](#oxoc--carefully-use-define-preprocessor-macros)**  
    * **[0x0D ~ Comparing Float and Double](#0x0d--comparing-float-and-double)**  
    * **[0x0E ~ Wrong usage of pointers](#0x0e--wrong-usage-of-pointers)**  
    * **[0x0F ~ Undefined Behavior](#0x0f--undefined-behavior)**  

---
* **[2. Clean Code](#snowflake-clean-code)**  
    * **[0x00 ~ Meaningful and Explicit Names](#0x00--meaningful-and-explicit-names)**  
    * **[0x01 ~ Write short functions](#0x01--write-short-functions)**  
    * **[0x02 ~ Using structure for basic items](#0x02--using-structure-for-basic-items)**  
    * **[0x03 ~ Using flags for projects' options](#0x03--using-flags-for-projects-options)**  
    * **[0x04 ~ Using gcc flags for Makefile](#0x04--using-gcc-flags-for-makefile)**  
    * **[0x05 ~ Using preprocessor DEBUG macros](#0x05--using-preprocessor-debug-macros)**  

---
* **[3. Programmer Tools](#programmer-tools)**      
    * **[0x00 ~ Code Editors](#0x00--code-editors)**  
    * **[0x01 ~ Terminal Bash](#0x01--terminal-bash)**  
    * **[0x02 ~ Git](#0x02--git)**  
    * **[0x03 ~ Productivity Gains](#0x03--productivity-gains)**  
    * **[0x04 ~ Add a a new binary in the PATH environment variable](#0x04--add-a-a-new-binary-in-the-path-environment-variable)**  
    * **[0x05 ~ Computer Graphics Libraries](#0x05--computer-graphics-libraries-ubuntu)**  
---
* **[4. Curated list of Programming Learning Materials](#gem-curated-list-of-programming-learning-materials)**  
    * **[0x00 ~ C Knowledge](#0x00--c-knowledge)**  
    * **[0x01 ~ Algorithm](#0x01--algorithm)**  
    * **[0x02 ~ Bitwise Manipulations](#0x02--bitwise-manipulations)**  
    * **[0x03 ~ Network](#0x03--network)**  
    * **[0x04 ~ Hacking & Security](#0x04--hacking--security)**  
    * **[0x05 ~ Computer Graphics](#0x05--computer-graphics)**  
    * **[0x06 ~ Computer Vision & AI](#0x06--computer-vision--ai)**  
    * **[0x07 ~ C++ Optimization](#0x07--c-optimization)**  
    * **[0x08 ~ Assembly Optimization](#0x08--assembly-optimization)**  
    * **[0x09 ~ Functional Programing](#0x09--functional-programing-by-leonard-marquez)**  
    * **[0x0A ~ Misc](#0x0a--misc)**  
    * **[0x0B ~ Science-Fictions Masterpieces](#0x0b--science-fiction-masterpieces)**  
---
* **[5. Tutorials](#tutorials)**  
    * **[0x00 ~ Optimization - Aiming for the lowest latency](#0x00--optimization---aiming-for-the-lowest-latency)**  
        * **[Optimization flags](#optimization-flags)**  
        * **[Multithreading and Parallelization](#multithreading-and-parallelization)**  
        * **[Vectorization](#vectorization)**  
        * **[Combining Optimization Flags, Parallelization and Vectorization](#combining-optimization-flags-parallelization-and-vectorization)**  
        * **[Last but not least: Getting the right algorithm](#last-but-not-least-getting-the-right-algorithm)**  
    * **[0x01 ~ Computer Graphics - Using SDL2 to create Fractal](#0x01--computer-graphics---using-sdl2-to-create-fractal)**  
        * **[Using SDL2 to create Computer Graphics](#using-sdl2-to-create-computer-graphics)**  
        * **[Example with a Barnsley Fern Fractal](#example-with-a-barnsley-fern-fractal)**  
    * **[0x02 ~ Hacking - Buffer Overflow](#0x02--hacking---buffer-overflow)**  
        * **[Introduction](#introduction)**  
        * **[Buffer overflow to hijack a password](#buffer-overflow-to-hijack-a-password)**  
        * **[Shellcode Execution to get root access](#shellcode-execution-to-get-root-access)** 
---
* **[6. Epilogue]()** 
    * **[0x00 ~ Wanted PR](#0x00--wanted-pull-requests)**  
    * **[0x01 ~ Question ? Broken Link ? Wanna contribute ?](#0x01--question--broken-link--wanna-contribute-)**  
    * **[0x02 ~ Liked it ?](#0x02--liked-it-)**  
    * **[0x2A ~ About the Author](#musical_score-0x2a--about-the-author)**  


---
# About 42 School

---
## 0x00 ~ What is 42 School

> 42 is more than just a disruptive educational model and coding school. What makes us unique and a major player in the tech world are the defining characteristics of the 42 culture. Every element of 42 shows our culture, from the students, to the curriculum structure and content, to the $0 tuition and innovative admissions process.

That's right, the school is FREE, originally funded and founded in Paris by generous **philanthropist billionaire [Xaviel Niel](https://en.wikipedia.org/wiki/Xavier_Niel)**.

> **I'm not unusual; it's the others who are strange** ― *Xavier Niel*

The name of the school, "42", is a tribute to [The Hitchhiker's Guide to the Galaxy](https://en.wikipedia.org/wiki/The_Hitchhiker%27s_Guide_to_the_Galaxy), a comedy science fiction series created by Douglas Adams.

> 42, or The Answer to the Ultimate Question of Life, The Universe, and Everything

There are no teachers but a pedagogic team that ensure that students do not harm the material and provide a cursus syllabus to follow. What is learned is hence mainly achieved through peer-to-peer project review and [RTFM](https://en.wikipedia.org/wiki/RTFM).

![RTFM meme](https://i.kym-cdn.com/photos/images/newsfeed/000/017/668/Mao_RTFM_vectorize_by_cmenghi.png?1318992465)

Most of the entrance exam and early cursus is done in [C language](https://en.wikipedia.org/wiki/C_(programming_language)).  

> **Nevertheless, C retains the basic philosophy that programmers know what they are doing; it only requires that they state their intentions explicitly.** ― *Brian W. Kernighan, The C Programming Language*

C is the most pedagogic programming language you can learn as it allows to understand the basis of programming from simple concepts like **conditions** {if, elseif, else}, **loops** {while, do while, for}, **write system calls** and **pointers** to more advanced one like **function pointers** and **memory allocation**.

Later on you can specialize in other languages: Python will fit data scientists and devops, javascript for frontend developers and C# for those looking for a career in finance.

> **When you say 'I wrote a program that crashed Windows,' people just stare at you blankly and say 'Hey, I got those with the system, for free.'** ― *Linus Torvalds*

You will learn how to do what [Muggles](https://en.wikipedia.org/wiki/Muggle) were only able to do accidentally.

---
## 0x01 ~ For Candidates: About the "Piscine"

> **If you're going through hell, keep going.** ― *Winston Churchill*

The piscine is the entrance exam that consists of **4 weeks fully dedicated to coding**, solving exercises and submitting solo and group projects to peer review.  

**It does not matter if you fail a project, an exam or a day as long as you keep striving**. Someone who has never been interested before in Computer Science would never be able to complete everything in time, yet he will not prevent from being successful.

### :coffee: My guess on the success criteria
* **0x00 Come as you are** ... or forget this bullshit and prepare a little bit with [subjects on github](https://github.com/Binary-Hackers/42_Subjects/tree/master/01_Piscines/C/EN), courtesy of my friend binary hacker.

* **0x01 Prepare to nail the exams** on the 4 exams session, knowing that the 3 firsts exams are limited in term of how far you can go and it is not a big deal to miss the first 3 exams as the most important is IMHO the maximum level you can reach. **Succeeding the first 4 exercises (36 pts)** should be enough to make sure you quality.

* **0x02 Get an acceptable percentage of review from peers** (probably 80% is enough, but you would get 90 to 97% if you are nice). *Don't be too nice, but don't be a dick with [vim .swp files](https://lmgtfy.com/?q=What+is+the+purpose+of+swap+files%3F) and .DS_Store*.

>  [.DS_Store](https://en.wikipedia.org/wiki/.DS_Store) – The name of a file in the Apple OS X operating system for storing custom attributes of a folder such as the position of icons or the choice of a background image. These files are created when you manipulate your files with the [Finder GUI](https://en.wikipedia.org/wiki/Graphical_user_interface).

* **0x03 The logging time has no or very little influence**, I know it as a fact for seeing people constantly logged in (but slacking) failing the piscine and students barely present being accepted. However the more time you spend in 42 school will certainly directly influence your skills and positively impact other related topics

* **0x04 It is strongly recommended to succeed at least one group project**, especially the first one that is really easy.

* **0x05 There is a special and unique achievement awarded to the most helpful/smart student.** This achievement does not show up on the student profile until he asks for it.

* **0x06 Be aware of the different rules** : Many things are forbidden like declaring and assigning a variable in the same line, using printf or using for loops. The daily assignment must be pushed on git before Day + 1 at 11pm42.

* **0x07 [Boys Only] Don't waste time flirting** : For some who have been living in the basement of their parents' house for years it is a good opportunity to see what a girl looks like in real life. Nevertheless, you have to under that 1/this is not the right time and place to do so.

* **0x08 You can sleep in the school during the selection** - *I recommended you to not do it, you will have very poor sleep.* - If you still go for it here is a list of essential items you should bring: **a toothpaste, a toothbrush, a soap and a towel on top of your phone, charger and mattress. Oh and a credit card also, unless you prefer to bring 10kg of cookies**

### :star: List of Essential Items

> "Never give up on something that you can't go a day without thinking about." ― Winston Churchill

:sleeping_bed: Mattress or equivalent and Pillow  
:electric_plug: Phone charger  
:iphone: Phone  
:droplet: Toothpaste and Toothbrush  
:bathtub: Soap and 2-4 Towels  
:money_mouth_face: Credit Card  
:heart: Kleenex  


---
## 0x02 ~ Coding simple C programs

> **시작이 반이다** ― *The beginning is half of the way (Korean proverb)* 

### First by installing a C compiler on your computer
* On Windows it is a bit tricky, you will have to install [Mingw](http://www.mingw.org/)
* On Linux it is pretty straightforward since it is only installed and if not ```apt-get``` will make it easy.
* On MAC it is not much more difficult, google how to do it.

You should then try to recode basic C functions

### ft_putchar

*A minimalist c program that will puzzle beginners, write it in a file named a.c and create a.out with ```gcc a.c && ./a.out```*

The following program will print a char by making use of [write](http://man7.org/linux/man-pages/man2/write.2.html)

```c
#include <unistd.h>

void	ft_putchar(char c) // void because the function does not return any value, it writes directly, char is the type of the variable c that is given as parameter to the function ft_putchar by the main function.
{
	write(1, &c, 1);			// ssize_t write(int fd, const void *buf, size_t count); or in human language: write count letters of buf (which is a pointer) to fd (if fd = 1 this is your terminal, stdout)
}

int	main(void) {
	ft_putchar(42);				// will print a star
	// ft_putchar(42 + '0');	// will only print 4
	// ft_putchar("4");			// will not work, you are using " instead of ', so C language think it is a char array.
	return 0;
}
```

Once you understand well how to print a character, you should try to return the length of many together (it is called a [string](https://en.wikipedia.org/wiki/String_(computer_science)))

### ft_strlen

```c
#include <unistd.h>

int		ft_strlen(char *str) {
	int i = 0;					// set variable i to 0
	while (str[i] != NULL)		// while the char array does not reach a NULL character
		i++;					// increment i, equivalent of i = i + 1;

	return i;					// return i variable to the caller function
}

int main(void) {
	int i = ft_strlen("Duck Tales");	// declare i, call the function ft_strlen, and assign its output to i
	printf("%d", i); // remember that it is forbidden to submit a function with printf during the Piscine
	return 0;
}
```
*NB: remember that it is forbidden to submit a function with printf during the Piscine*

### ft_putstr

Then print a whole string by recoding the libc function 'puts':
```c
#include <stdio.h> // header for puts

int main(void) {
	puts("Duck Tales");
	return 0;
}
```

This can be achieve by using and index that starts on the first character and is progressively incremented until NULL as string are NULL terminated:
```c
#include <unistd.h>

void	ft_putstr(char *str) {
	int i = 0;

	while(str[i] != NULL)
		write(1, &str[i++], 1);
}
```

Along with the main function slightly modified to make use of your code:
```c
int main(void) {
	ft_putstr("Duck Tales");
	return 0;
}
```

You can also use only the pointer since you do not care of the return value (the function type being void)
```c
#include <unistd.h>

void	ft_putstr(char *str) {
	while(*str)
		write(1, s++, 1);
}
```

Or even use the length of the string to print the whole string at once, hence avoiding many *[system calls](https://en.wikipedia.org/wiki/System_call) (write)* that are costly for the program execution:

```c
void	ft_putstr(char *str) {
	write(1, str, ft_strlen(str));
}
```
*NB: You have to include ft_strlen in the same file AND above the function to make it work.*

Next you should **study the different concepts in programming**, especially spend time understanding the different [C data types](https://en.wikipedia.org/wiki/C_data_types), [the concept of pointers](https://en.wikipedia.org/wiki/Pointer_(computer_programming)) and [arrays](https://en.wikipedia.org/wiki/Array_data_type), because it is what you have been using up to now and it will only get more complicated.


---
## 0x03 ~ 42 Projects Guides

> **Do what you think is interesting, do something that you think is fun and worthwhile, because otherwise you won’t do it well anyway.** ― *Brian W. Kernighan*

|Name|Track|Hashtags|What you will learn|
|-|-|-|-|
|Fillit|General|Architecture, Parsing, Algo|[Description from a student](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)|
|Printf|Algorithm|Architecture, Parsing, utf-8|[UTF-8 Conversion table](https://en.wikipedia.org/wiki/UTF-8)<br>[Variadic Function](https://en.wikipedia.org/wiki/Variadic_function)|
|[Filler](https://github.com/agavrel/42-filler)|Algorithm|Parsing, Algo, Bot|42 forums have good threads on this project|
|Lem-In|Algorithm|Parsing, Algo, Chained-Lists|[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)|
|Corewar|Algorithm|Architecture, parsing, disassembler, virus, VM|[About the original Game](https://en.wikipedia.org/wiki/Core_War)|
|LS|System|Parsing, Recursion, Chained-Lists|[The Good Old Manual](http://man7.org/linux/man-pages/man1/ls.1.html)|
|Minishell|System|Environment Variables, Shell|[Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)|
|Malloc|System|Algo, Memory, HashCollision|[The Good Old Manual](http://man7.org/linux/man-pages/man3/malloc.3.html)|
|FDF|Computer Graphics|Parsing, Creativity|[Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm), [Use of Graphics Library](https://en.wikipedia.org/wiki/Graphics_library), [Trigonometry](https://en.wikipedia.org/wiki/Trigonometry), [Rotations](https://en.wikipedia.org/wiki/Rotation_(mathematics)), [3D Projection](https://en.wikipedia.org/wiki/3D_projection), [ARGB Color Space](https://en.wikipedia.org/wiki/RGBA_color_space)|
|Fractol|Computer Graphics|Fractals, Mathematics, ARGB, HUV|[Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)|
|Wolfenstein 3d|Computer Graphics|Raytracing, Rotation|[About the original Wolfenstein 3d](https://en.wikipedia.org/wiki/Wolfenstein_3D)|
|NmOtool|System|Symbol Table, .dll .so|[Implement List the symbols in a .so file](https://stackoverflow.com/questions/34732/how-do-i-list-the-symbols-in-a-so-file)
|LibftAsm|System|x86 Assembly Instructions|[Refer to the Intel Bible](https://software.intel.com/en-us/articles/intel-sdm)
|[RT](https://github.com/Chr0nos/rt)|Computer Graphics|Ray Tracing|Create a Scene of enlightened polygons 
|Particles System|Computer Graphics|Graphics Effects|[simulate certain kinds of "fuzzy" phenomena](https://en.wikipedia.org/wiki/Particle_system)

---
## 0x04 ~ Choosing your Path

### How to choose your specialization

There are currently 4 main branches: [Infographics](https://en.wikipedia.org/wiki/Infographic), Algorithms, System and Web.
All branchs are interesting and you should try to explore each branch's initial project:
* If you are aiming to work in the video game industry and like Mathematics then you should go for **Infographics**. Remember that this path is tough and not necessarily as rewarding as the other ones, but you will have the luxury to work in the video game industry.
* **Algorithm branch** is/was mainly based on flawless parsing and not so much on algorithm quality. Fortunately with the nomination of Benny as the head of the Pedagogy there will be more efforts to reward smart algorithms. Algorithms is the best one if you want to join a prestigious company like Google
* **System** is the best for those who like security, network and how computers truly work since you will have to ultimately recode your own operating system.
* **Web** is good for those who like to build websites, perhaps mobile app as well (react native) and want to become a freelancer.


---
## 0x05 ~ Swindle the norminette - *truander la norme*

### While loops

*Only 25 lines ? No problem:*
```c
int draw_lines(int len) { // NB: len is positive or equal to 0
	int i;
	
	i = 0;
	while (i < len)
	{
		puts("Looping"); // NB: you will have to use your own function, ft_putstr, of course
		draw_line(i);
		i++;
	}
}
```
**Originally 9 lines**

```c
int draw_lines(int len) {
	int i;

	i = -1;
	while (++i < len && puts("Looping"))
		draw_line(i);
}
```
**Now 5 lines**

```c
int draw_lines(int len) {
	while (--len >= 0 && puts("Looping")) // it works
		draw_line(len); // NB: make sure that drawing backward does not impact algo
}
```
**2 lines**

```c
int draw_lines(int len, int i) { // If you really need to call from 0 to len then you can also have i passed as a parameter = -1
	while (++i < len && puts("Looping"))
		draw_line(i);
}
```
**2 lines, with prototype modification (ugly)**


---
### [If brackets](https://github.com/keuhdall)

```c
if (true)
{
	func1();
	func2();
}
```
**5 lines**

```c
if (true)
	func1();
if (true)
	func2();
```
**4 lines**  

**NB: Beware of these tricks, it could potentially make your program less efficient. In the above example you use two [branching instructions](https://en.wikipedia.org/wiki/Branch_(computer_science)) - *if* - instead of one and in the while example the -1 initialization and puts inside the while hinder readability**

---
### [Write colorful usage](https://github.com/mrdotb)
```c
int	usage(void)
{
	static char usage_str[] =

	GREEN"philo_one\n"RESET
	"Simulation of the philosopher.\n\n"
	YELLOW"USAGE:\n    "RESET
	GREEN"philo_one "RESET
	"number_of_philosopher time_to_die time_to_eat "
	"time_to_sleep [number_of_time_each_philosophers_must_eat]\n\n"
	YELLOW"ARGS:\n    "RESET
	"All args must be positive integer\n";
	ft_putstr_fd(usage_str, 1);
	return (1);
}
```

---
### [Function Pointers](https://github.com/mrdotb)

```c
void			listen_keystroke(t_dlist **lst)
{
	char		buffer[8];
	int			el;
	static void	(*f[])(t_dlist **lst) = { lst_validate, lst_del_one,
		lst_del_one, lst_move_left, lst_move_right, lst_move_up,
		lst_move_down, lst_select, lst_esc, lst_void_ret};

	ft_memset(buffer, 0, 8);
	while (read(0, buffer, 8) != -1)
	{
		el = ft_chrmatch(buffer);
		f[el](lst);
		render(find_first(lst), 0);
		ft_memset(buffer, 0, 8);
	}
}
```

---
# :fire: Common Beginner Mistakes

> **Experience is the name everyone gives to their mistakes** – *[Oscar Wilde](https://en.wikipedia.org/wiki/The_Picture_of_Dorian_Gray)*

---
## 0x00 ~ Array overflow

In C the index of an array starts at 0. Because C does not perform boundary checking when using arrays, if you access outside the bounds of a stack based array it will just access another part of already allocated stack space, like in this example:

```c
#include <stdio.h>

void    somefunction3(void)
{
    int a[5] = {1,3,5,7,9};
    printf("%d\n", a[5]);
}
```
In this example, 5 is the size of the array and if you try to access it it will overflow. Remember that the maximum array index you can ever access is its size minus 1.

I would suggest to use as much as possible a const :
```c
#include <stdio.h>

void    somefunction3(void)
{
	const int len = 5;
	int a[len] = {1,3,5,7,9};
	for (int i = 0; i < len; i++) // safe
		printf("%d\n", a[i]);
}
```

---
## 0x01 ~ Segmentation Fault

> **There are two ways to write error-free programs; only the third one works** – *Alan J. Perlis*

*Many potential reasons for this...*


---
## Loop segfault
One common mistake is that you had declared a loop and either:

#### Forgot to increment the counter

```c
int i = 0;

while (i < 10)
{
	write(1, &i + '0', 1);
	// but where is i++ ?
}
```

#### Correct way

```c
int i = 0;

while (i < 10)
{
	write(1, &i + '0', 1);
    	i++;
}
```

### Forgot the exit condition:

```c
int somevariable = 0;
while (42) // always True ! You will be 42 for life ;)
{
    // call to some stuff that never succeed to set someVariable to 1;
    if (somevariable == 1) // make sure that somevariable will equal 1 at some point.
        break ;
}
```

### Used an assignation = instead of a boolean expression != == <= >=

```c
#include <stdio.h>

int main(void) {
	unsigned int x = 10;

	while (--x != 0)
	{
		printf("0 0 0 1 0 1 0 1 0 ");
		if (x = 1) {			// oopsie !!
			printf("* ");
			x--;
		}
	}
	return 0;
}
```
*PS: will you be able to fix this code ?*  

Also classic with lists:  you have a loop and its crucial condition that allows the function to return, but used an assignation instead of comparison
```c
int i = 0;

while (list)
{
    if (list = NULL) // You want to use if (list == NULL)
        return i;
    i++;
    list=list->next;
}
return -1; // will always return -1
```

### Quizz: What will print this loop ?

```c
unsigned char c = 0;

while (c < 150)
{
	write(1, &c, 1);
	c++;
}
```

> **Talk is cheap. Show me the code** ― *Linus Torvalds*


### Accessing the next link in a chained-list without checking the current one

Another example with linked-lists
```c
typedef struct  s_list {
      void      *data;
      t_list    *next;
 }              t_list;

/*
** function to go 2 links further in a chained-list
*/

void somefunction(t_list *list)
{
    if (list->next != NULL)
    {
        list = list->next->next;
    }
}
```

if the current link of list is null you will get a segfault. The correct way is to always check the current link before the next one:
```c
void somefunction(t_list *list)
{
    if (list && list->next) // if both list and list->next exist
        list = list->next->next;
}
```

### Accessing an index in a loop for program with either graphics or a board game
```c
int somefunction(int y_max, int x_max, int array[y_max][x_max]);
{
    int y;
    int x;

    y  = 0;
    while (y < y_max)
    {
        x = 0;
        while (x < x_max)
        {
            if (array[y][x-1] > array[y][x]) // don't you see there is a problem ?
                array[y][x] = array[y][x-1];
            if (array[y+1][x] > array[y][x]) // don't you see there is another problem ?
                array[y][x] = array[y+1][x];
        }

    }
}
```

These lines should be corrected the following way:
```c
if (x > 0 && array[y][x-1] > array[y][x])
if (y < y_max - 1 && array[y+1][x] > array[y][x]) // strictly inferior to last possible index which is y_max - 1,
// you may also write y <= y_max - 2
```

You may also notice that we can even do better by changing the starting value of x or the exit condition of the y loop **in the case that we were to check only one of the two if conditions.**
```c
x = 1;
while (y < y_max - 1)
```

Another example
```c
int main(void) {
	const int x_max = 3;
	const int y_max = 3;
	int a[y_max][x_max];
	
	for (int y = 0; y < y_max; y++)
    	for (int x = 0; x < x_max; x++)
			a[y+6][x] = x + y;
}
```

---
## 0x02 ~ Bus error

Occur when your processor cannot even attempt the memory access requested, like trying to access an address that does not satisfy its alignment requirements.
```c
int main(void) {
	const int x_max = 3;
	const int y_max = 3;
	int a[y_max][x_max];
	
	for (int y = 0; y < y_max; y++)
    	for (int x = 0; x < x_max; x++)
			a[y][x] = a[x] + a[y];
}
```


---
## 0x03 ~ Stack smashing

See below in the recommended books the one by Aleph One, how you can make use of such "error"
```c
int main(void) {
	const int x_max = 3;
	const int y_max = 3;
	int a[y_max][x_max];
	
	for (int y = 0; y < y_max; y++)
    	for (int x = 0; x < x_max; x++)
        	a[y][x] = x + y;

	for (int y = 0; y < y_max; y++) {
    	for (int x = 0; x < x_max; x++) {
        	a[y+6][x] += a[y][x];
    	}
	}
}
```

---
## 0x04 ~ Modifying value of a local variable given as function parameter

Local variable value are allocated on the stack, which is cleaned once you exit the function.

### Useless variable change

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

### Useful variable change

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
    return a + 1;
}

int solve(void)
{
    int a = 5;

    a = increment_a(a);
}
```

## 0x05 ~ Unprotected malloc

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

Protect both the malloc **and its return value**:
It is not good enough to protect the malloc in the callee function (the function called) if the returned value is not also protected in the caller function (the function 'above')
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
	free(matrix);
}
```

---
## 0x06 ~ Freeing memory that has already been fred

In the previous example, if you don't need the variable matrix anymore you can free it.  

However do not attempt to free twice or to free a stack based variable:
```c
int main(void) {
	int *matrix;

	if (!(matrix = malloc(sizeof(int) * 9)))
		return 1; // NB: exceptionnally return 1 in the main, it means that an error occured
	free(matrix); // OK
	free(matrix) // Not OK

	return 0; // return 0, the program run without error
}
```


---
## 0x07 ~ Do Not use global variables

> "Theory and practice sometimes clash. And when that happens, theory loses.  
Every single time." ― Linus Torvalds

Global variables are forbidden in 42 School except for a few exceptions, see this interesting article: [Are Global Variables Bad](https://stackoverflow.com/questions/484635/are-global-variables-bad)
However many students, me including, found a way to circumvent this interdiction: you first declare a structure in the header that will contain all our variables:

> "Don’t comment bad code—rewrite it." ― *Brian W. Kernighan, The Elements of Programming Style*

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


---
## 0x08 ~ Variable Length Arrays

[Waiter! There's a VLA in my C!](http://ayekat.ch/blog/vla)

The following example is a VLA and this is bad for many reasons, the most critical being that the memory is allocated on the stack which has a limited size.
```c
int somefunction(int y, int x, int array[y][x]);
```
My peer reviewer: "wow [your filler](https://github.com/agavrel/42-filler) run so fast!"
Me: "really ?" (how to tell them that it was not compliant with the norm? :D)

---
## 0x09 ~ Using ft_ prefix for all functions

*ft_* should only be added to functions you want to re-use through different projects (and add to your personal library, the libft project) not for specific program functions.


---
## 0x0A ~ [Usage of Sequence Point](https://en.m.wikipedia.org/wiki/Sequence_point)
```c
#include <unistd.h>

int main()
{
	int i = 0; 
	i = (i++);
	write(1, &i + '0', 1);

	return 0;
}
```
Guess what will be printed.


---
## 0x0B ~ Assignment of read-only location
```c
int main()
{
	const char s[20] = "hello world";
	*s = 'a';
	s[0] = 'b';

	return 0;
}
```

You cannot change what you have declared as const.


---
## OXOC ~ Carefully use define preprocessor macros

```c
#include <stdio.h>

#define MAX(a,b)	a > b ? a : b

int main(void) {
	int a = 5;
	int b = 42;
	int c = 40 +  MAX(a,b);
	
	printf("%d\n", c);
	return 0;
}
```

This will return 5, becaure the compiler understand it as :
```c
int main(void) {
	int a = 5;
	int b = 42;
	int c = 40 + 5 > 42 ? 5 : 42; // if 47 > 42 then c = a (5) , else c = b (42);
	...
}
```

The correct usage is to always encapsulate your ```#define``` with brackets to make sure it works as intended:
```c
#define MAX(a,b)	(a > b ? a : b)
```

That said you should avoid using macros who act like functions in the first place. Also note that you should always capitalize macro names and const variables, it is a convention.


---
## 0x0D ~ Comparing float and double

```c
#include <stdio.h>

int main(void) {
	double d = 1.1;
	float f = 1.1;

	if (f != d)
		puts("float and double are different\n");
	if (f != 1.1)
		puts("Do not compare a float to an integer value\n");
	if (d == 1.1)
		puts("But that's okay for a double\n");
	if (f == 1.1f)  // note the extra 'f' at the end
		puts("This is how you compare a float to a float value\n");

	return 0;
}
```

They are represented differently. If you want to learn more about how they work take a look at [wikipedia](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) or wach below video.  

<a href="https://www.youtube.com/watch?v=PZRI1IfStY0" target="_blank"><img src="http://img.youtube.com/vi/PZRI1IfStY0/0.jpg"
alt="Floating Point Numbers" width="240" height="180" border="10" /></a>


---
## 0x0E ~ Wrong usage of pointers

Pointers are the memory location of the value of this variable

An example with ft_swap

### The wrong way to use pointers
```c
void ft_swap(int *a, int *b)
{
	int *tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}
```

This will segfault, because you declared tmp as a pointer, but what you want is tmp to store the value of the memory address of a.

### The correct way to use pointers
```c
void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
```

### Swapping without using another variable
```c
=void ft_swap(int *a, int *b)
{
	*a ^= *b;		// (1) a = a ^ b
	*b ^= *a;		// (2) b = b ^ (a ^ b) = a
	*a ^= *b;		// (3) a = (a ^ b) ^ a  = b  // a was set to a^b (1) and b became a (2)
	
}
```
**NB: if you xor a number by itself you set it to 0. ```a ^= a;``` is equivalent to ```a = 0;```**  
*If you like it you can [learn more about bitwise operations here](https://github.com/agavrel/42-Bitwise_Operators)*

### Main to test above functions
```c
#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 42;

	printf("a: %d \t b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("a: %d \t b: %d\n", a, b);
	return 0;
}
```

---
## 0x0F ~ Undefined Behavior

Undefined behavior means that the result is **as much unpredictable as a [pangolin](https://en.wikipedia.org/wiki/Pangolin) sneezing in some faraway country**. *You don't want to have your program depending on it.*

```c
#include <stdio.h>

char omg(char i) {
return ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i + ++i \
 	+ ++i + ++i + ++i + ++i + ++i + ++i -5;
}


int main(int argc, char **argv) {
	unsigned char i = omg(i);

	if (i++ > 254)
		printf("%d\n", ++i);
}
```
*Try guessing the output*


---
# :snowflake: Clean Code

> "You are reading this book for two reasons. First, you are a programmer. Second, you want to be a better programmer. Good. We need better programmers." ― *Robert C. Martin in Clean Code*

Now some guidelines that should hopefully help your coding style


---
## 0x00 ~ Meaningful and Explicit Names

> “Don’t comment bad code, rewrite it.” Brian W. Kernighan, The Elements of Programming Style

I once met a developer who was using hp and mp instead of x and y for coordinates.  
While being a very good reference to [JRPG]()... it is totally out of question to code like this.
The function name should always be:
* In English, forget about chauvinism!
* At least 5 letters. It is okay to have shorter exceptionally for well-known variables like int index -> int i, temporary -> tmp and pointer -> ptr.
* Self-explanatory: build_graph instead of graph or build_it
* For long name use either camel case (saveClientConfig) or snake case (save_client_config) and stick to one style.

### Writing a function check if a file exist

```c
#include <sys/stat.h>	// stat
#include <stdbool.h> 	// bool type
#include <stdio.h>		// printf

bool	file_exist (char *filename)	// Always use bool for Manichean functions
{
  struct stat   buffer;

  return !stat(filename, &buffer);
}

int		main(int ac, char **av) {
	if (ac != 2)
		return 1;

	if (file_exist("a.out"))
		printf("%s exists\n", av[1]);
	else
		printf("%s does not exist\n", av[1]);

	return 0;
}
```


---
## 0x01 ~ Write short functions

> "FUNCTIONS SHOULD DO ONE THING. THEY SHOULD DO IT WELL. THEY SHOULD DO IT ONLY." ― *Robert C. Martin in Clean Code (p35)*

**42 has a rigid but fair rule: limits every functions to 25 lines.**  

*Let's see a case study with a function to get lower case (from 'A' to 'a') for a given character*

**0b001 Function done by a 42 'Piscineux' (AKA it works):**
```c
char	to_lower_by_piscineux(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else if (c >= 'a' && c <= 'a')	// useless else if, since both else if and else return the same value
		return c;
	else
		return c;
}
```

**0b010 Good 42 Student who read GNU C library's tolower's man and read ```int tolower(int c)``` (prototype):**
```c
int		to_lower_by_student(int c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else			// NB: Don't keep this extra "else" as there is no code executed after the return statement
		return c;
}
```

**0b011 However you could save memory by using only 1 byte (char) instead of 4 (int) since ASCII values range from 0 to 127 as demonstrated by Steve Maguire in "Writing Solid Code" (p101):**
```c
char	to_lower_by_smaguire(char c) {
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}
```

**0b100 My own version: [making use of the ASCII table](https://en.wikipedia.org/wiki/ASCII) and apply the Do Only One Thing principle:**
```c
#include <stdbool.h>    // bool type

bool	is_upper_case(int c) {
	return ((unsigned int)(c - 'A') <= ('Z' - 'A'));
}

int		to_lower_by_agavrel(int c) {		// Check ASCII table and you will notice a nice pattern
	return is_upper_case(c) ? c | 0b100000 : c;
}
```

**0b101 You may try above functions with the following main program:**
```c
#include <unistd.h>		// write syscall

void	putchar_endl(char c) {	// NB: endl stands for endline, '\n'
	write(1, &c, 1);
	write(1, "\n", 1);
}

#include <ctype.h> 		// GNU C Library tolower

int		main(int ac, char **av) {
	if (ac != 2)
		return 1;

	unsigned char c = *av[1];
	putchar_endl(tolower(c));
	putchar_endl(to_lower_by_piscineux(c));
	putchar_endl(to_lower_by_student(c));
	putchar_endl(to_lower_by_smaguire(c));
	putchar_endl(to_lower_by_agavrel(c));

	return 0;
}
```

**0b110 Have you tried [one step closer](https://www.youtube.com/watch?v=kSUsBpdugX0) to the bytecode  ?**
```c
int		to_lower_assembly(int c) {
	__asm__ __volatile__ (R"(
	.intel_syntax noprefix
		mov     eax, %0
        lea		edx, [eax - ('A')]
		or      %0, 0b100000
		cmp		edx, 'Z'-'A'
        cmovb	eax, %0		
	.att_syntax noprefix)"
	:[c]"=r" (c)
	:: "memory");
}
```


---
## 0x02 ~ Using structure for basic items

If you are using coordinates it might be interesting to create a structure 'point' or 'coord'

```c
typedef struct s_point
{
    int y;
    int x;
}           t_point;

void somefunction(void){
    t_point p;

    p.x = 2;
    p.y = 5;

    //alternatively:  p = {5, 2};
}
```


---
## 0x03 ~ Using flags for projects' options

For each project you will often have to parse flag input. In Linux the flag usually come after a '-' and allow for extra functionalities.
It is quite useful know how to store such critical information into only 4 bytes *which is sizeof(integer)*

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

The 'a' flag will be on bit 1, 'l' on bit 2, 'R' on bit 4, 'r' on bit 8 etc.
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

*NB: Be very cautious as & and | have lower precedence than relational operators:*
```c
if (flags & FLAG_L == MASK) // equivalent to (flags & (FLAG_L == MASK))
```

*Correct example:*
```c
if ((flags & FLAG_L) == MASK)
```

You can unset a flag by clearing the corresponding bit the following way:
```c
void    somefunction2(int *flags)
{
	flags &= ~FLAG_A;
}
```

> **Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live** – *John Woods*

An even more readable and better approach is to declare a struct using bitfield:

```c
struct 	flags_t
{
	int a : 1;
	int b : 1;
	int c : 1;
	//etc
}

#include <unistd.h>

int	main(void) {
	struct flags_t flags = {0};
	t.a = 1;
	if (t.a)
		write(1, "flag a is set\n", 14);
	return 0;
}
```
PS: Of course rename flags' name with more meaningful ones.


---
## 0x04 ~ Using gcc flags for Makefile

> **It's funny how the smallest things I've done speak the loudest about me, but I like that** ― *Xavier Niel*

```
gcc -Wall -Wextra -Werror -O2
```
* O2 will improve performance  ##Create a new repository on the command line
* pedantic is not requested but is a good one to check ISO C compliance

> Issue all the warnings demanded by strict ISO C and ISO C++; reject all programs that use forbidden extensions, and some other programs that do not follow ISO C and ISO C++. For ISO C, follows the version of the ISO C standard specified by any -std option used.

You can read the details about each flag on [gccgnu website](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)


---
## 0x05 ~ Using preprocessor DEBUG macros

You can improve the performance of your program by using what we call preprocessor macros
```c
#include <unistd.h>

#define DEBUG true

int main(void) {
	if (DEBUG)
		write(1, 42, 1);
	return 0;
}
```
As a convention name should be capitalized with '_' to join words

---
# Programmer Tools

---
## 0x00 ~ Code Editors

### Vim, Code Editor used in 42

VIM is the text editor used in 42. You access a file by using ```vim filename```. To exit VIM  with elegance vim type ```:q```, if you fail to exit VIM you might consider becoming a freelance web developer.

> To generate a truly random string, put a web developer in front of Vim and tell them to exit

You can access VIM configuration by typing
```
vim ~/.vimrc
```

Below is my configuration
```
set number							" Show line number
syntax on							" Highlight syntax
set mouse=r							" Enable mouse click, + enable to copy paste without taking line number
set cursorline						" Enables cursor line position tracking
hi Normal guibg=NONE ctermbg=NONE	" keep vim transparency
highlight CursorLine ctermfg=darkgreen ctermbg=darkgrey cterm=bold	" highlight row with foreground background and style as defined
"highlight CursorColumn ctermbg=darkgrey								" hilight column
highlight CursorLineNR ctermfg=red ctermbg=darkblue cterm=bold	" Sets the line numbering to red background

set cursorcolumn 					" Highlight current column
set tabstop=4						" set tab to 4 spaces
set autoindent						" auto indent file on save

set modeline				" make vim change in a specific file
set modelines=5
```

Some shortcuts that are very handy:
```
CTRL+HOME	send you at the beginning of the file
CTRL+END	send you at the end of the file
YY			copy
PP			paste
DD			delete row
D5D			delete 5 rows
w			save file
q			quit file
:vs {file location}		open another file on the side
:ws			save and quit
ZZ			save and quit
:x			save and quit
:q!			quit without change
ZQ			quit without change
```

### Visual Studio Code

I love VIM and it will always be useful to know how to use it, especially now with the "Cloud" being something you might have to access servers who lack code editors with real GUI.

That said If you want to give a try to another editor I would recommend Visual Studio Code.

My settings.json:
```
{
    "workbench.colorTheme": "Monokai",
    "glassit-linux.opacity": 93
}
```

### Atom

Good editor also, quite hackable, I have been using it for years but recently switch to VIM & VS Code


---
## 0x01 ~ Terminal Bash

[Bash](https://en.wikipedia.org/wiki/Bash_(Unix_shell)) is the terminal you will be using

You can create alias by accessing
```
vim ~/.bashrc
```

```
alias ls="ls -la"
```

PS: Don't create this alias on another's student computer, even thought you might think it is funny, it will wipe out everything:
```
alias ls="rm -rf ./~"
```


---
## 0x02 ~ Git

### Setting up a new Git Repository using [CLI](https://en.wikipedia.org/wiki/Command-line_interface)

It can be done easily using the following command line:  
```
reponame='docker'
mkdir $reponame
touch README.md
git init
git add README.md
git commit -m "[INIT] First commit"
git remote add origin git@github.com:agavrel/$reponame.git
git push -u origin master
```

### Change last commit without changing commit message

> **I choose a lazy person to do a hard job. Because a lazy person will find an easy way to do it** ― *Bill Gates*

It can be done easily using the following command line
```
git add README.md \
&& git commit --amend --no-edit \
&& git push --force
```
**NB: Beware because it will destroy the previous commit with all what it implies**


---
## 0x03 ~ Productivity Gains 

### [Compile and Execute file on changes](https://superuser.com/questions/181517/how-to-execute-a-command-whenever-a-file-changes?page=2&tab=votes#tab-top)

Create ou run the following script (necessite to download ```sudo apt-get install inotifywait```)
```
while inotifywait -e close_write agavrel.s; do \
nasm -f elf64 agavrel.s \
&& gcc agavrel.c agavrel.o -o a.out \
&& ./a.out arg1 arg2 \
; done
```
Now each time you compile your file you will set the output, very efficient with a transparent editor.

---
### [Run Commands in Background](https://linuxize.com/post/how-to-run-linux-commands-in-background/)

You can have multiple processes running in the background at the same time with ```&``` after the command.  
However the background process will continue to write messages to the terminal from which you invoked the command.  

To suppress the stdout and stderr messages use the following syntax:  
```
command > /dev/null 2>&1 &
```

```>/dev/null 2>&1``` means redirect ```stdout``` to ```/dev/null``` and ```stderr``` to ```stdout```

Use the jobs utility to display the status of all stopped and background jobs in the current shell session:
```
jobs -l
```
_NB: a Job is the process running thanks to the command execution_

To bring the job to the foreground use :
```
fg %ID
```
NB: you can use ```bg``` to do the reverse, from foreground to background.

To kill the process use:
```
kill -9 ID
```
Obviously replace ```ID``` in the above examples with the job ID you got from ```jobs -l```.


---
## 0x04 ~ [Add a a new binary in the PATH environment variable](https://stackoverflow.com/questions/14637979/how-to-permanently-set-path-on-linux-unix)

Example with terraform:
```
sudo mkdir /opt/terraform
unzip ~/Downloads/terraform_0.12.13_linux_amd64.zip /opt/terraform
```

add to PATH environment variable:
```
export PATH="$PATH:/opt/terraform"
```

then create simlink in /user/bin
```
cd /usr/bin
sudo ln -s /opt/terraform terraform
```

Update path for current session
```
source ~/.profile
```
or
```
source ~/.bashrc
```


---
## 0x05 ~ Computer Graphics Libraries (Ubuntu)

#### Minilibx Installation

Link
```
https://github.com/42Paris/minilibx-linux
```

### SDL2 Installation

Link
```
http://www.libsdl.org/download-2.0.php#source
```

Then
```
./configure
&& make
&& sudo make install
&& sudo apt-get install ibsdl2-dev libsdl2-ttf-dev
&& sudo apt-get libsdl2-image-2.0-0 libsdl2-image-dev
```


---
# :gem: Curated list of Programming Learning Materials

*Only petty thieves would google "torrent" or "pdf" keywords, real Gentlemen would purchase a digital copy*

---
## 0x00 ~ C Knowledge

> **C is [quirky](https://en.wiktionary.org/wiki/quirky), flawed, and an enormous success** ― *[Dennis Ritchie, Creator of the C language](https://en.wikipedia.org/wiki/Dennis_Ritchie)*

Title | How Interesting | Author
---|---|---
**[The C Programming Language 2nd Ed Subsequent Edition](https://www.goodreads.com/book/show/515601.The_C_Programming_Language)** | :two_hearts: | *by Brian Kernighan and Dennis Ritchie*
**[Obscure C Features](https://multun.net/obscure-c-features.html)** | :star::star::star::star::star: | *[by Multun](https://github.com/multun)*
**[Characters, Symbols and the UTF-8 Miracle - Computerphile](https://www.youtube.com/watch?v=MijmeoH9LT4)** | :star::star::star::star: | *by Tom Scott*
**[Automatic Vectorization](https://www.codingame.com/playgrounds/283/sse-avx-vectorization/autovectorization)** | :star::star::star::star: | *[by Marchete](https://github.com/marchete)*
**[Writing Solid Code](http://cs.brown.edu/courses/cs190/2008/documents/restricted/Writing%20Solid%20Code.pdf)** | :star::star::star::star: | *by Steve Maguire*
**[Fast wc Multithread SIMD](https://github.com/expr-fi/fastlwc)** | :star::star::star::star: | *by [expr-fi](https://github.com/expr-fi)*
**[OpenMP Multithreading Programming](https://bisqwit.iki.fi/story/howto/openmp/)** | :star::star::star::star: | *by Joel Yliluoma*
**[Understanding lvalues and rvalues](https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/)** | :star::star::star::star: | *by Eli Bendersky*
**[The Practice of Programing](http://index-of.co.uk/Etc/The.Practice.of.Programming.-.B.W..Kernighan..pdf)** | :star::star::star: | *by Brian W. Kernighan and Rob Pike*
**[Modern C](https://gforge.inria.fr/frs/download.php/file/38170/ModernC.pdf)** | :star::star::star: | *by Jens Gustedt*
**[Duff's Device](http://www.lysator.liu.se/c/duffs-device.html)** | :star::star::star: | *by Tom Duff*
**[Structure Packing](http://www.catb.org/esr/structure-packing/)** | :star::star::star: | *by Eric S. Raymond*
**[Cello, High Level Programming to C](https://github.com/orangeduck/Cello)** | :Star::star::star: | *by Daniel Holden*
**[Are Global Variables Bad](https://stackoverflow.com/questions/484635/are-global-variables-bad)** | :star: | *StackOverFlow*


---
## 0x01 ~ Algorithm

Title | How Interesting | Author
---|---|---
**[Nailing the Coding Interview](https://github.com/agavrel/Nailing-the-Coding-Interview)** | :kr: | *by Antonin Gavrel*
**[A curated list of Awesome Competitive Programming](https://codeforces.com/blog/entry/23054)** | :star::star::star::star: | *by Inishan (Jasmine Chen)*
**[The Algorithm Design Manual](https://www.goodreads.com/book/show/425208.The_Algorithm_Design_Manual)** | :star::star::star::star: | *by Steven S. Skiena*
**[A tour of the top 5 sorting algorithms with Python code](https://medium.com/@george.seif94/a-tour-of-the-top-5-sorting-algorithms-with-python-code-43ea9aa02889)** | :star::star: | *by George Seif*


---
## 0x02 ~ Bitwise Manipulations

> **The word bit is a contraction of binary digit that was coined by the statistician John Tukey in the mid 1940s** ― *Brian W. Kernighan, D Is for Digital*

Title | How Interesting | Author
---|---|---
**[Hacker's Delight](https://doc.lagout.org/security/Hackers%20Delight.pdf)** | :two_hearts: | *by Henry S. Warren Jr.*
**[Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)** | :two_hearts: | *by Sean Eron Anderson*
**[De Bruijn Sequence](https://www.chessprogramming.org/De_Bruijn_Sequence)** | :star::star:


---
## 0x03 ~ Network

> **I would tell you a joke about UDP but I’m afraid you wouldn’t get it**

Title | How Interesting | Author
---|---|---
**[Next Generation Kernel Network Tunnel - WireGuard](https://www.wireguard.com/papers/wireguard.pdf)** | :two_hearts: | by JA Donenfeld |
**[Onion Routing](https://www.youtube.com/watch?v=QRYzre4bf7I)** | :star::star::star::star: | *by Computerphile*
**[TCP Meltdown](https://www.youtube.com/watch?v=AAssk2N_oPk)** | :star::star: | *by Computerphile*


---
## 0x04 ~ Hacking & Security

> **Never underestimate the determination of a kid who is time-rich and cash-poor.** ― *Cory Doctorow, Little Brother*

Title | How Interesting | Author
---|---|---
**[Smashing The Stack For Fun And Profit](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)** | :two_hearts: | *by Aleph One*
**[Breaking the x86 Instruction Set](https://www.youtube.com/watch?v=KrksBdWcZgQ)** | :star::star::star::star::star: | *[by Domas](https://github.com/xoreaxeaxeax)*
**[Buffer Overflow, Race Condition, Input Validation, Format String](http://www.cis.syr.edu/~wedu/Teaching/cis643/schedule.html)** | :star::star::star::star: | *by Wenliang (Kevin) Du*
**[Meltdown](https://meltdownattack.com/meltdown.pdf)** | :star::star::star::star: | *by Lipp, Schwarz, Gruss, Prescher, Haas, Mangard, Kocher, Genkin, Yarom, and Hamburg*
**[Basic Linux Privilege Esclation](https://blog.g0tmi1k.com/2011/08/basic-linux-privilege-escalation/)** | :star::star::star: | *by g0tmi1k* 
**[Network Protocol Fuzzing and Buffer Overflow](https://blog.own.sh/introduction-to-network-protocol-fuzzing-buffer-overflow-exploitation/) | :star::star::star::star: | *by Joey Lane*
**[Secure Programming HOWTO](https://dwheeler.com/secure-programs/Secure-Programs-HOWTO.pdf)** | :star::star::star: | *by David A. Wheeler*
**[Efficiently Generating Python Hash Collisions](https://www.leeholmes.com/blog/2019/07/23/efficiently-generating-python-hash-collisions/)** | :star::star:
**[Stochastic Process Wikipedia](https://en.wikipedia.org/wiki/Stochastic_process)** | :star::star:
**[Gimli: a cross-platform permutation](https://eprint.iacr.org/2017/630.pdf)** | :star::star:
**[LiveOverflow](https://www.youtube.com/channel/UClcE-kVhqyiHCcjYwcpfj9w)** | :star::star:


---
## 0x05 ~ Computer Graphics

Title | How Interesting | Author
---|---|---
**[SDL2 Tutorial](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php)** | :two_hearts | *by mysterious Lazyfoo*
**[Fast Inverse Square Root](https://en.wikipedia.org/wiki/Fast_inverse_square_root)** | :two_hearts: | attributed to John Carmack (Quake III)
**[Game Engine Architecture](http://ce.eng.usc.ac.ir/files/1511334027376.pdf)** | :star::star::star::star::star: | *by Jason Gregory*
**[Introduction to Computer Graphics](https://www.youtube.com/watch?v=t7g2oaNs-c8&list=PLQ3UicqQtfNuKZjdA3fY1_X9gXn13JLlW&index=1)** | :star::star::star::star::star: | *by Justin Solomon*
**[3d Fractal Flame Wisps](https://tigerprints.clemson.edu/cgi/viewcontent.cgi?article=2704&context=all_theses)** | :star::star::star: | *[by Yujie Shu](https://www.semanticscholar.org/author/Yujie-Shu/11523322)*
**[Geometry Caching Optimizations in Halo 5](https://www.youtube.com/watch?v=uYAjUOlEgwI)** | :star::star::star: | *by Zabir Hoque and Ben Laidlaw*
**[Light and Shadows in Graphics](https://www.youtube.com/watch?v=LUjXAoP5GG0)** | :star::star: | *by Tom Scott*
**[Screen Space Ambient Occlusion Tutorial](http://john-chapman-graphics.blogspot.com/2013/01/ssao-tutorial.html)** | :star::star: | *by Tom Scott*
**[Exponentiation by Squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)**  | :star: | *Wikipedia*


---
## 0x06 ~ Computer Vision & AI

Title | How Interesting | Author
---|---|---
**[OpenCV Tutorial](https://docs.opencv.org/2.4/opencv_tutorials.pdf)** | :star::star::star:


---
## 0x07 ~ C++ Optimization

> **C++ is a horrible language. It's made more horrible by the fact that a lot of substandard programmers use it, to the point where it's much much easier to generate total and utter crap with it** ― *Linus Torvalds 2007*

Title | How Interesting | Author
---|---|---
**[Optimizing software in C++](https://www.agner.org/optimize/optimizing_cpp.pdf)** | :two_hearts: | *by Agner Fog*
**[Intel Intrinsics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)** *[What is it](https://en.wikipedia.org/wiki/Intrinsic_function)* | :star::star::star::star: | *Intel*
**["Low Latency C++ for Fun and Profit"](https://www.youtube.com/watch?v=BxfT9fiUsZ4)** | :star::star::star::star: | *by Carl Cook*
**[Why I Created C++](https://www.youtube.com/watch?v=JBjjnqG0BP8)** | :star::star::star: | *Bjarne Stroustrup*
**[CppCon 2018 “High-Radix Concurrent C++”](https://www.youtube.com/watch?v=75LcDvlEIYw)** | :star::star::star: | *Olivier Giroux*
**[C++ Features](https://github.com/AnthonyCalandra/modern-cpp-features)**| :star::star::star: | *by Anthony Calandra*


---
## 0x08 ~ Assembly Optimization

> **People say that you should not micro-optimize. But if what you love is micro-optimization... that's what you should do** ― *Linus Torvalds*

Title | How Interesting | Author
---|---|---
**[Intel® 64 and IA-32 architectures software developer’s manual](https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-sdm-combined-volumes-1-2a-2b-2c-2d-3a-3b-3c-3d-and-4)** | :two_hearts: | *Intel*
**[Optimizing subroutines in assembly x86 language](https://www.agner.org/optimize/optimizing_assembly.pdf)** | :two_hearts: | *by Agner Fog*
**[Online Compiler Explorer](https://godbolt.org/)** | :star::star::star::star::star: | *by Godbolt*
**[Online Assembler and Disassembler](https://defuse.ca/online-x86-assembler.htm#disassembly)** | :star::star::star::star: | *by [Taylor Hornby](https://github.com/defuse)*
**[A Guide to inline assembly for C and C++](https://www.ibm.com/developerworks/rational/library/inline-assembly-c-cpp-guide/) | :star::star::star::star: | *by Salma Elshatanoufy and William O'Farrell*
**[Tips for Golfing in x86/x64 Bytecode](https://codegolf.stackexchange.com/questions/132981/tips-for-golfing-in-x86-x64-machine-code)** | :star::star::star: | *by StackExchange*
**[The Art of Assembly Language](http://www.staroceans.org/kernel-and-driver/The.Art.of.Assembly.Language.2nd.Edition.pdf)** | :star::star: | *by Randal Hyde*
**[GDB Tutorial](https://www.cs.cmu.edu/~gilpin/tutorial/)** | :star::star: | *by Andrew Gilpin*


---
## 0x09 ~ Functional Programing *[by Leonard Marquez](https://github.com/keuhdall)*

> **A monad is just a monoid in the category of endofunctors, what's the problem?** ― *James Iry*

Title | How Interesting | Author
---|---|---
**[Learn You a Haskell for Great Good!](http://learnyouahaskell.com/chapters)** | :two_hearts: | *by Miran Lipovača*
**[Functors, Applicatives, And Monads In Pictures](http://adit.io/posts/2013-04-17-functors,_applicatives,_and_monads_in_pictures.html)** | :two_hearts: | *by Aditya Bhargava*
**[Category Theory course by Bartosz Milewski](https://www.youtube.com/watch?v=I8LbkfSSR58&list=PLbgaMIhjbmEnaH_LTkxLI7FMa2HsnawM_)** | :star::star::star::star::star: | *by Bartosz Milewski*
**[Wise Man's Haskell](https://andre.tips/wmh/)** | :star::star::star::star: | *by Andre Popovitch*
**[Real World Haskell](http://book.realworldhaskell.org/read/)** | :star::star::star: | *by Bryan O'Sullivan*
**[Martin Odersky's Scala course](https://www.coursera.org/learn/progfun1)** | :star::star: | *by Martin Odersky*


---
## 0x0A ~ Misc

> **Everyone knows that debugging is twice as hard as writing a program in the first place. So if you're as clever as you can be when you write it, how will you ever debug it?** ― *Brian W. Kernighan*

Title | How Interesting | Author
---|---|---
**[A Super Mario 64 decompilation](https://github.com/agavrel/sm64)** | :star::star::star::star::star: | *by a bunch of clever folks*
**[Vim 101 Quick Movement](https://medium.com/usevim/vim-101-quick-movement-c12889e759e0)** | :star::star::star::star: | *Alex R. Young*
**[Math for Game Programmers: Dark Secrets of the RNG](https://www.youtube.com/watch?v=J5qnnxFoBss)** | :star::star::star: | *by Shay Pierce*
**[Clean Code](https://www.investigatii.md/uploads/resurse/Clean_Code.pdf)** | :star::star::star: | *by Robert C. Martin*
**[Why Java Suck](https://tech.jonathangardner.net/wiki/Why_Java_Sucks)** | :star: | *by Jonathan Gardner*
**[XOR Linked List – A Memory Efficient Doubly Linked List](http://en.wikipedia.org/wiki/XOR_linked_list)** | :star: | *Wikipedia* 
**[XOR Linked List – C Implementation](https://stackoverflow.com/questions/3531972/c-code-for-xor-linked-list)** | :star: | *StackOverFlow*


---
## 0x0B ~ Science-Fiction Masterpieces

> **To succeed, planning alone is insufficient. One must improvise as well** ― *Isaac Asimov, Foundation*

Format | Title | How Interesting | Author
---|---|---|---
Book | **[The Foundation](https://en.wikipedia.org/wiki/Foundation_series)** | :two_hearts: | *by [Isaac Asimov](https://en.m.wikipedia.org/wiki/Isaac_Asimov)*
Book | **[The Hitchhiker's Guide to the Galaxy](https://www.goodreads.com/book/show/841628.The_Hitchhiker_s_Guide_to_the_Galaxy)** | :two_hearts: | *by [Douglas Adams](https://en.m.wikipedia.org/wiki/Douglas_Adams)*
AudioBook | **[The Hitchhiker's Guide to the Galaxy](https://www.youtube.com/watch?v=dPbr0v_V-cI&list=PLYT7LhCzuTTdtIGcDOP-PPMxAWYo3qF5r&index=3&t=3167s)** | :two_hearts | *by Douglas Adams and read by Stephen Moore*
Movie | **[Ready Player One](https://en.wikipedia.org/wiki/Ready_Player_One_(film))** | :two_hearts: | by *[Steven Spielberg](https://en.wikipedia.org/wiki/Steven_Spielberg)*
Movie | **[Matrix](https://en.wikipedia.org/wiki/The_Matrix)** | :two_hearts: | *by the Wachowskis*
Book | **[Hyperion](https://en.m.wikipedia.org/wiki/Hyperion_(Simmons_novel))** | :star::star::star::star: | *by [Dan Simmons](https://en.m.wikipedia.org/wiki/Dan_Simmons)*
Movie | **[War Games](https://en.wikipedia.org/wiki/WarGames)** | :star::star::star: | *directed by John Badham*
Book | **[Elon Musk Biography](https://www.goodreads.com/book/show/25541028-elon-musk)** | :star::star::star::star::star: | *by Ashlee Vance*


---
# Tutorials

<a href="https://www.youtube.com/watch?v=Jen46qkZVNI&t=30s" target="_blank"><img src="http://img.youtube.com/vi/Jen46qkZVNI/0.jpg"
alt="Boxer's Perfect Rush SCV" width="240" height="180" border="10" /></a>

---
## 0x00 ~ Optimization - Aiming for the lowest latency

When you want to aim for lowest latency - *i.e maximum speed* - there are many things that will improve your program to create a better binary: Optimization flag, parallelization, vectorization and carefully crafting your algorithm.


### Optimization flags

Especially for Computer Graphics projects, you will want to turn on these optimization flags, [listed on gcc website](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html).

> Without any optimization option, the compiler’s goal is to reduce the cost of compilation and to make debugging produce the expected results. Statements are independent: if you stop the program with a breakpoint between statements, you can then assign a new value to any variable or change the program counter to any other statement in the function and get exactly the results you expect from the source code.
Turning on optimization flags makes the compiler attempt to improve the performance and/or code size at the expense of compilation time and possibly the ability to debug the program.

**To use it simply compile the program with:**
```
gcc -O2 a.c
```
NB: It is the letter 'o' and not a zero. You may also use O3.


### Multithreading and Parallelization

The historical (and current) approach is to add more power via [multithreading](https://en.wikipedia.org/wiki/Multithreading_(computer_architecture)), [multiprocessing](https://en.wikipedia.org/wiki/Multiprocessing), [Grid Computing](https://en.wikipedia.org/wiki/Grid_computing) or even [Cloud Computing](https://en.wikipedia.org/wiki/Cloud_computing). Two libraries exist for this use: [OpenMP](https://www.openmp.org/wp-content/uploads/openmp-examples-4.5.0.pdf) and [pthread](http://man7.org/linux/man-pages/man7/pthreads.7.html), you will have to compile respectively with:
```
gcc -fopenmp -O3 a.c
```
and:
```
gcc -pthread -O3 a.c
```


### [Vectorization](https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions)

> Modern graphics processing units (GPUs) are often wide SIMD implementations, capable of branches, loads, and stores on 128 or 256 bits at a time.
Intel's latest AVX-512 SIMD instructions now process 512 bits of data at once.

As a double is 64 bits - *i.e 8 bytes or octets* - **instead of iterating overs value 1 by 1, you will be able to compute up to 8 double at the time** - *i.e 512 / 64* - if your computer support it (but most likely, as of 2020, your computer will only handle 256 bits register).

**Vectorization the most efficient way to quickly gain performance gains without the overhead of threads' initialization**.

**Demonstration: Getting Min and Max value from a float array**
```c
/* Vectorization example by agavrel */
#include <stdio.h>  // printf
#include <stdlib.h> // rand()
#include <time.h>   // time
#include <xmmintrin.h>  // 128 bits register _m128

float m128_max_float(__m128 src) {
    __m128 n[4];

	// a) n[0] = src >> 64                                  So lets say src is composed of floats a b c d, it becomes 0 0 a b
    n[0] = _mm_shuffle_ps(src, src, _MM_SHUFFLE(0,0,3,2));
	// b) n[1] = {max(a,0), max(b,0) max(a,c) max(b,d)}     NB: actually we don't care about the two highest float at this point, I will call them 'x': {x, x max(a,c) max(b,d)}
    n[1] = _mm_max_ps(src, n[0]);                             
	// c) n[2] = n[1] >> 32                                 So n2 become {0 x x max(a,c)}
    n[2] = _mm_shuffle_ps(n[1], n[1], _MM_SHUFFLE(0,0,0,1));
	// d) n[3] = {x x x max(max(a,c), max(b,d))}
    n[3] = _mm_max_ps(n[1], n[2]);                            

    return _mm_cvtss_f32(n[3]);   // d) Hence max(a,b,c,d), stored in the lowest 32 bits of n[3], is loaded into a float that we return. We don't care about the other bits
}

float m128_min_float(__m128 src) {
    __m128 n[4];

    n[0] = _mm_shuffle_ps(src, src, _MM_SHUFFLE(0,0,3,2));
    n[1] = _mm_min_ps(src, n[0]);
    n[2] = _mm_shuffle_ps(n[1], n[1], _MM_SHUFFLE(0,0,0,1));
    n[3] = _mm_min_ps(n[1], n[2]);

    return _mm_cvtss_f32(n[3]);
}

#define SIZE  1000000000L // 1 billion. Yes.

void  get_min_max(long i, float array[i]) {
  __m128 max;
  __m128 min;
  
  max = _mm_loadu_ps(array); // will load first 4 float into max
  min = _mm_loadu_ps(array); // will load first 4 float into min
  while ((i -= 4L))
  {
    __m128 tmp = _mm_loadu_ps(array + i);
    max = _mm_max_ps(max, tmp);
    min = _mm_min_ps(min, tmp);
  }

  printf("Max value: %f\t Min value: %f\n", m128_max_float(max), m128_min_float(min));
}

void  get_min_max_like_bocalian(long size, float array[size]) {
  float max;
  float min;
  int i;

  max = array[0];
  min = array[0];
  i = 1L;
  while (i < size)
  {
    float tmp = array[i++];
    max = tmp < max ? max : tmp;
    min = tmp > min ? min : tmp;
  }

  printf("Max value: %f\t Min value: %f\n", max, min);
}

int main()
{
  long i;
  float *data;
  clock_t time;

  srand(time(NULL));  // seed
  data = (float *)malloc(SIZE * sizeof(float));
  i = -1L;
  while (++i < SIZE) {
    data[i] = (float)rand() / (float)(RAND_MAX) * 1000.0f;
   /* printf("%.02f\t\t", data[i]);     // I commented these lines because it slows considerably the program.
    if (!(i & 15))
      printf("\n");*/
  }

  time = clock();
  get_min_max(SIZE, data);
  time = clock() - time;
  double elapsed_time = ((double)time) / CLOCKS_PER_SEC;
  printf("Executed in %f seconds\n", elapsed_time);

  time = clock();
  get_min_max_like_bocalian(SIZE, data);
  time = clock() - time;
  elapsed_time = ((double)time) / CLOCKS_PER_SEC;
  printf("Executed in %f seconds\n", elapsed_time); 

  return 0;
}
```

And compile with:
```
gcc vectorization.c -O3  && ./a.out 
```

You will notice that the vectorized approach will be about 3 times faster (NB: For this specific example). If I was using mm256 or mm512 registers, the vectorized program would be even faster by a factor of 2 and 4 respectively.

*Now that you realize the performance boost, how about using what you just learn for your RayTracing project?*


### Combining Optimization Flags, Parallelization and Vectorization

*a) **You can take a look at [this very interesting project](https://github.com/expr-fi/fastlwc/blob/master/fastlwc-mt.c)** which aim to show how fast wc can get using the various tools C has to offer to optimize speed. After downloading the file, you will also need to download the header: [simd.h](https://github.com/expr-fi/fastlwc/blob/master/simd.h), which make use of [Intel intrinsic](https://software.intel.com/sites/landingpage/IntrinsicsGuide/).*  

*b) Compile it with the flags:*
```
gcc fastlwc-mt.c -fopenmp -O3
```

*c) Create a random file:*
```
dd if=/dev/urandom of=sample.txt bs=64M count=16 iflag=fullblock
```

*d) Compare wc with the new binary with:*
```
time ./a.out sample.txt \
&& time wc sample.txt
```


### Last but not least: Getting the right algorithm

Try to give a shot at solving this [algorithm problem](https://github.com/agavrel/Nailing-the-Coding-Interview/tree/master/math/the_dancer):

```c
int32_t dancer_position(uint32_t time_elapsed) { ;}
```

**The right algorithm is usually the corner stone of an efficient program.**


---
## 0x01 ~ Computer Graphics - Using [SDL2](https://www.libsdl.org/index.php) to create Fractal

### Using SDL2 to create Computer Graphics
You can follow tutorials to create a simple program with SDL on [Lazyfoo's website](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php) or on SDL2 official website.

You will also have to install SDL2:
```
brew install sdl2
```

With SDL2 you have to first ```init_sdl``` - *see function below*. Then you will keep the user entertained with a loop ```while (42)``` that can only be escaped by clicking on the the close button or pressing escape. While the loop is active, user's actions will be recorded thanks to ```SDL_PollEvent```. You then draw pixel by using ```SDL_RenderDrawPoint``` and you refresh image with ```SDL_RenderPresent```.

### Example with a Barnsley Fern Fractal

[Michael Barnsley](https://en.wikipedia.org/wiki/Michael_Barnsley) was a British mathematician who coined a fractal algorithm to represent a fern.  

![Barnsley Fern](https://raw.githubusercontent.com/agavrel/42_CheatSheet/master/img/BarnsleyFern.png)

The algorithm is explained in detail on [wikipedia](https://en.wikipedia.org/wiki/Barnsley_fern)  

Find below the code for the whole program, compile it with :
```
gcc barnsley.c -lSDL2 -O3
```

You will need about 10 000 iterations of n to draw the shape. On each keypress you will increase the number of iterations by 400.
```c
#pragma message "\033[1;31mRequire SDL2\033[0m, \033[1;92mbrew install sdl2\033[0m and compile with \033[1;5;36mgcc barnsley.c -lSDL2\033[0m  && ./a.out  " __FILE__ "..."
// gcc main.c -lSDL2 -O3 -Wall -Werror -Wextra --pedantic&& ./a.out
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH	600
#define	WINDOW_HEIGHT	800

typedef struct		s_cnb
{
	double			real;
	double			imag;
}					t_cnb;

typedef struct		s_pixel
{
	int				x;
	int				y;
}					t_pixel;

void	barnsley(SDL_Renderer *renderer, t_cnb *c) {
	float	rng;
	t_pixel	i;
	static const float probability[3] = {0.01f, 0.08f, 0.15f};
	long n = 400;

	while (n--) {
		rng = ((float)rand() / (float)RAND_MAX);
		if (rng <= probability[0]) {
			c->real = 0;
			c->imag *= 0.16f;
		}
		else if (rng <= probability[1]){
			c->real = -0.15f * c->real + 0.28f * c->imag;
			c->imag = 0.26f * c->real + 0.24f * c->imag + 0.44f;
		}
		else if (rng <= probability[2]) {
			c->real = 0.2f * c->real + -0.26f * c->imag;
			c->imag = 0.23f * c->real + 0.22f * c->imag + 1.6f;
		}
		else {
			c->real = 0.85f * c->real + 0.04f * c->imag;
			c->imag = -0.04f * c->real + 0.85f * c->imag + 1.6f;
		}
		i.x = (c->real + 3) * 70;
		i.y = WINDOW_HEIGHT - c->imag * 70;
    	SDL_RenderDrawPoint(renderer, i.x, i.y);
	}
}

bool	error_sdl(char *error_msg) {
	printf( "%s! SDL_Error: %s\n", error_msg, SDL_GetError() );
	return false;
}

bool	init_sdl(SDL_Window **window, SDL_Renderer **renderer) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (error_sdl("SDL could not initialize!"));
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, window, renderer);
	if (*window == NULL)
		return (error_sdl("Window could not be created!"));
	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 0);
	SDL_RenderClear(*renderer);
    SDL_SetRenderDrawColor(*renderer, 0xbf, 0xff, 0, 0);

	return true;
}

int		main(void) {
    SDL_Event event;
    SDL_Window *window;
	SDL_Renderer *renderer;
	t_cnb c;
	
	if (!(init_sdl(&window, &renderer)))
		return 1;

	c = (t_cnb) {.real = 0, .imag = 0}; // PS: legal for Norminette
    while (42) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				break ;
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
					break ;
				barnsley(renderer, &c);
				SDL_RenderPresent(renderer);
			}
		}
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
```

---
## 0x02 ~ Hacking - Buffer Overflow

### Introduction

Let's take a look at the function strcpy, shall we? Type ```man strcpy``` in your terminal:

> *The  strcpy() function copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by dest.  The strings may not overlap, and the destination string dest must be large enough to receive the copy.  Beware of buffer overruns!  **(See BUGS.)***

**NB: Usage of brackets for what is considered as one of the most critical security flaw in the world**

> ***BUGS:**  
If  the  destination  string of a strcpy() is not large enough, then anything might happen ― **NB: Undefined Behavior**.  Overflowing fixed-length string buffers is a favorite cracker technique for taking complete control of the machine.  Any time a program reads or copies data into a buffer, the program first needs to  check  that  there's  enough  space. This may be unnecessary if you can show that overflow is impossible, but be careful: programs can get changed over time, in ways that may make the impossible possible.*

```c
#include <string.h>
#include <stdio.h>

int main(void) {
	char s[11];

	strcpy(s, "hello world");
	puts(s);	

	return 0;
}
```

While this look okay if you count each letter, if you happen to read again the definition of strcpy (just above) you will notice: 
> ***including the terminating null byte ('\0')***

So you are trying to copy 12 characters in fact, into a 11 characters buffer. You will get the nice message:

```bash
In function ‘main’:
warning: ‘__builtin_memcpy’ writing 12 bytes into a region of size 11 overflows the destination [-Wstringop-overflow=]
strcpy(s, "hello world");
```

In fact all functions that you will find in [```#include <banned.h>```](https://github.com/git/git/blob/master/banned.h) represent potential security risks and should be avoided as much as possible.

### Buffer overflow to hijack a password

```c
#include <stdio.h>
#include <string.h> // for strcmp, compare two strings and return 0 if they are equal

char    *strcpy_until(char *dst, char *src, char until)
{
	int i = -1;

	while (src[++i] != until)
		dst[i] = src[i];
    
	return (dst);
}

int     main(int ac, char **av) {
    int n = 5;
    char password[] = "sarang hae"; // we don't know
    char buffer[4] = "kkk";

    if (ac != 2)
        return 1;
    printf("n equals %d\n", n);
    printf("you would have never guessed, password was '%s'\n\n", password);
    char *s = &buffer[3];
    char shellcode[] = "\x42\x61\x67\x61\x76\x72\x65\x6c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x2a\x00\x00\x01";
    strcpy_until(s, shellcode, '\x01');
    printf("n equals '%d'\n", n);
    printf("password now equals: '%s'\n", password);

    if (!strcmp(password, av[1])) {
        printf("\nSuccessfully hacked user with password \e[1;5;92m%s\e[0m\n", password);        
    }
    return 0;
}
```
*Would you have guessed the password?*  

Some explanations:
* ```strcpy_until``` will copy until a specific character, hence allowing to bypass the NULL that terminates the string
* ```char shellcode[]``` can be used to, instead of just replacing value at memory addresses, execute the value that have been replaced. See next below...


### Shellcode Execution to get root access

> **When something is important enough, you do it even if the odds are not in your favor** ― *Elon Musk*

You will now have to compile with:
```
gcc -fno-stack-protector -z execstack a.c
```

* ```-fno-stack-protector a.c``` is to disable the [Stack-Guard mechanism](https://en.wikipedia.org/wiki/Buffer_overflow_protection)
* Compiler make prevent stack from being executable and ```-z execstack``` reverse that protection.


Last you will also **temporarily** disable randomize va space with:
```
sudo sysctl -w kernel.randomize_va_space=0
```
NB: You can use safer method ```setarch `uname -m` -R /bin/bash``` which is [more safe](https://askubuntu.com/questions/318315/how-can-i-temporarily-disable-aslr-address-space-layout-randomization)

Once done with experiments do not forget to set back randomize back to normal:
```
sysctl -a --pattern "randomize" && \
sudo sysctl -w kernel.randomize_va_space=2
```

{WIP}



--- 
# Epilogue

--- 
## 0x00 ~ Wanted Pull Requests

> **If you know how to make software, then you can create big things** ― *Xavier Niel*

*One function related to each 42 project to help students get started*  
*In-depth examples with pointers*  
*Books on system design*  
*Exemple of a Makefile "qui fait le cafe"*


---
## 0x01 ~ Question ? Broken Link ? Wanna contribute ?

> **I think it's very important to have a feedback loop, where you're constantly thinking about what you've done and how you could be doing it better** ― *Elon Musk*

*Raise an issue or even better: submit a pull request*


---
## 0x02 ~ Liked it ?
*Show your appreciation by starring the repo, sharing on slack, RT and 'lache un com magueule' skyblog™*

![Kimg Jeong Un applauding](https://raw.githubusercontent.com/agavrel/42_CheatSheet/master/img/kimjeongun_meme.gif)

> 잘했어 동무 계속 [배우자](https://www.youtube.com/watch?v=ukBcC-sK3wQ) ― *Good Job Comrade, let's keep studying*


---
## :musical_score: 0x2A ~ About the Author

**[Antonin GAVREL](https://www.linkedin.com/in/antonin-gavrel-086b2618/)**
