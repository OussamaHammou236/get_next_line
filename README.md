# Git Next Line

This repository contains the implementation of a simple function named `git_next_line` in the C programming language. The purpose of this function is to read the next line from a given input stream, similar to the behavior of the `getline` function.

## Introduction

The `git_next_line` function is designed to provide a convenient way to read lines from an input stream in C programs. It handles dynamic memory allocation to ensure flexibility and ease of use.

## Getting Started

To get started with using or contributing to this project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/OussamaHammou236/git_next_line.git
   cd git_next_line
2.Compile the source code:
   ```bash
   gcc get_next_line.c get_next_line_utils.c

## Usage

   Here's a simple example of how to use the git_next_line function in your C program :
   ```bash
   int main(void)
   {
      int fd = open("test", O_RDONLY);
      printf("%s",get_next_line(fd));
      return 0;
   }
