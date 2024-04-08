# Define the project.
project('refgen', 'c')

# Define the dependencies.
raylib = dependency('raylib')

# Define the include directory.
include_dir = include_directories('include')

# Define the sources.
sources = ['src/main.c']

# Define the executable.
executable('refgen', sources, include_directories: include_dir, dependencies: [raylib])
