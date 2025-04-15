## Rotation X
$$R(A)=\begin{bmatrix}1 &0 & 0\\0 &cos(A) &-sin(A)\\0 &sin(A) &cos(A) \end{bmatrix}$$

## Rotation Y
$$R(B)=\begin{bmatrix}cos(B) &0 &sin(B)\\0 &1 &0\\ -sin(B) &0 &cos(B) \end{bmatrix}$$

## Rotation Z
$$R(C)=\begin{bmatrix}cos(C) &-sin(C) &0\\sin(C) &cos(C) &0\\0 &0 &1 \end{bmatrix}$$

## Rotation 3D for vector

$$\begin{bmatrix}i &j &k\end{bmatrix} * R(A)*R(B)*R(C) = 
        \begin{bmatrix}
         V1 &V2 &V3
        \end{bmatrix}$$ 

$$V1=\begin{bmatrix}
        jsin(A)sin(B)cos(C) \\
        -kcos(A)sin(B)cos(C) \\
        +jcos(A)sin(C) \\ 
        +ksin(A)sin(C) \\ 
        +icos(B)cos(C) \\
    \end{bmatrix}$$

$$V2=\begin{bmatrix}
        jcos(A)cos(C) \\
        +ksin(A)cos(C) \\
        -jsin(A)sin(B)sin(C) \\
        +kcos(A)sin(B)sin(C) \\
        -icos(B)sin(C) \\
    \end{bmatrix}$$

$$V3=\begin{bmatrix}
        kcos(A)cos(B) \\
        -jsin(A)cos(B) \\
        +isin(B) \\
    \end{bmatrix}$$

## Z-Buffer
- use z buffer let $R^3$ to  $R^2$
- in the code the K1 equal $z'$
$$ x' = x*z'/z $$
$$ y' = y*z'/z $$

### pseudocoe
```c
// First of all, initialize the depth of each pixel.
d(i, j) = infinite // Max length

// Initialize the color value for each pixel to the background color
c(i, j) = background color

// For each polygon, do the following steps :
for (each pixel in polygon's projection)
{
    // Find depth i.e, z of polygon
    //   at (x, y) corresponding to pixel (i, j)   
    if (z < d(i, j))
    {
        d(i, j) = z;
        c(i, j) = color;
    }
}
```

## Reference 
[Spinning Cube](https://www.youtube.com/watch?v=p09i_hoFdd0)

[How does the Spinning Cube work?](https://www.youtube.com/watch?v=0E0UBphVRhY)

[Z-Buffering](https://en.wikipedia.org/wiki/Z-buffering)
