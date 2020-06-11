# ImageFilters

This is a set of custom image filters for PPM format images. These filters include:

Conway's Game of Life filter: This is an image filter for PPM format images that will run Conway's Game of Life on each color of an image. Every different color is treated as a separate instance of the simulation. Blank pixels will be filled with the original image to prevent odd effects.

Blur: This filter will take the average of the colors of surrounding pixels with a user-defined radius and set the central pixel to that color for every pixel in the image to create a blur effect

More filters to come...