# CubeMate: Rubik's Cube Solver

CubeMate is a C++ application that solves a standard 3x3 Rubik's Cube using the Layer by Layer (Beginner's) method. The project aims to provide an intuitive user experience, including a graphical interface and step-by-step animated solutions.

## Features

- Solves 3x3 Rubik's Cube using the Beginner's (Layer by Layer) method
- Step-by-step solution output
- Plans for GUI input and animated solution visualization (in progress)
- Written in modern C++ for performance and clarity

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- graphics.h library (for GUI/visualization)
- [Optional] An IDE supporting C++ projects

### Installation

1. **Clone the repository:**
    ```bash
    git clone https://github.com/muhaimeen90/CubeMate.git
    cd CubeMate
    ```
2. **Ensure all source files are present.**

### Running the Solver

1. **Build and run the project:**
    - If you use an IDE, open `cubeclass.cpp` and run the project.
    - Or, from the command line:
        ```bash
        g++ cubeclass.cpp -o CubeMate -lgraph
        ./CubeMate
        ```
    - Make sure your environment supports `graphics.h`.
2. **Follow the on-screen instructions to input your cube's state.**

## Roadmap

- [ ] Graphical user interface for input
- [ ] Animated visualization of solution steps
- [ ] Support for more cube sizes and solving methods

## Contributing

Contributions are welcome! Please open issues or submit pull requests to help improve CubeMate. For major changes, please open an issue first to discuss your ideas.

## License

[MIT License](LICENSE) <!-- Or specify your license here -->

## Credits

Created by [muhaimeen90](https://github.com/muhaimeen90)
