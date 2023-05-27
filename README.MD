# Shapedrawer

## What is it?

Simple command line interpreter application for drawing shapes out of ASCII characters.
Developed for educational purposes only to learn how to work:
* in a small team
* with project management tools like Jira or Confluence
* with simple CI/CD (GitHub Actions)
* with C++ code with Makefile and unit tests

## Submodule Catch2 initialization

```
git submodule update --init --recursive --force
```

## Build application

```
make shapedrawer
```

## Build examples

```
make examples
```

## Build unittests

```
make unittest
```

## Build all

```
make all
```

## Debug with vscode

Make sure you have C++ tools plugin installed in vscode.

Please start vscode in the repo directory.

Build the project.

Start debugging.
