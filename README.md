# CS50 Filter
A command-line image processing program written in the C programming language that applies visual filters to 24-bit BMP images by manipulating individual pixel colour values.

## Features:
- Grayscale Filter: Converts images to grayscale by calculating the average red, green, and blue values of each pixel.
- Sepia Filter: Applies a sepia colour effect using weighted RGB calculations and colour value clamping.
- Reflection Filter: Horizontally reflects images by swapping pixel positions across each row.
- Blur Filter: Applies a blur effect by averaging the RGB values of surrounding pixels within a 3x3 area.
- Pixel Manipulation: Processes images using RGB pixel structures and two-dimensional arrays.
- BMP Handling: Reads and writes bitmap image files, accounting for image headers and row padding.
- Command-Line Arguments: Allows users to select a filter using `-b`, `-g`, `-r`, or `-s` flags.
- Input Validation: Checks filter selection, command-line usage, and supported BMP file formats.

#

Developed as apart of the curriculum for [Harvard University's CS50X: Introduction to Computer Science](https://cs50.harvard.edu/x/2025/psets/4/filter/less/)
