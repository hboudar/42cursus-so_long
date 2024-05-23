# so_long
so_long: A 2D game escape adventure (C project)
This repository contains the code for a 2D game called so_long, created in C using the MiniLibX library. The goal of the game is to collect all collectibles on a map and reach the exit, while avoiding walls and (optionally) enemies.

This project is designed to help improve skills in window management, event handling, colors, textures, and more.

Features:

Basic 2D game with player movement and collectible gathering
Map parsing from a custom .ber format
Optional enemy interaction (bonus)
Optional sprite animation (bonus)
Clean code structure and adherence to coding standards
Getting Started:

Clone this repository.
Ensure you have the MiniLibX library installed.
Compile the project using the included Makefile.
Run the program with a valid map file as an argument (e.g., ./so_long my_map.ber).

<h1 align="center">
	📖 So_long
</h1>

<p align="center">
	<b><i>A 2D game escape adventure</i></b><br>
</p>
<p align="center">
<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Cloneg7/so_long?color=lightblue" />
<img alt="Code language count" src="https://img.shields.io/github/languages/count/Cloneg7/so_long?color=yellow" />
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Cloneg7/so_long?color=blue" />
</p>

## 📜 Table of Contents

- [💡 Mandatory Part](#m)
- [💡 Bonus Part](#b)

# 💡 Mandatory Part <a name = "m"></a>

> _This program :._

	 The goal of the game is to collect all collectibles on a map and reach the exit, while avoiding walls.

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run like using the MiniLibX library.

### Instructions

**1. To use the function in your code, simply include its header:**

```C
#include "manadatory/so_long.h"
```

#### 📋 Testing
> _Simply run this command (add as an argument a map from maps with a map...):_
```shell
make && ./so_long maps/map.ber 
```
-------
# 💡 Bonus Part <a name = "b"></a>

> _As a <code>bonus</code> to the Mandatory requirement, the function should has :._
	<ul>
  	<li>
    	<ul>
         <li>Make the player lose when they touch an enemy patrol.</li>
         <li>Add some sprite animation.</li>
         <li>Display the movement count directly on screen instead of writing it in the shell.</li>
    	</ul>
  	</li>
   <ul/>

**1. To use the function in your code, simply include its header:**

```C
#include "bonus_so_long_bonus.h"
```

#### 📋 Testing
> _Simply run this command (add as an argument a map from maps with a mapb...):_
```shell
make && ./so_long_bonus maps/mapb.ber
```
> _Or :_
```shell
./pipex_bonus "here_doc" <limiter> <cmd1> <cmd2> ... <outfile>
