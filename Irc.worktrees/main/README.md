# IRC Server Project

## Introduction

This project involves the creation of an IRC server, which is a part of the larger system of Internet Relay Chat (IRC) that allows users to communicate with each other in real-time. The server should be able to handle multiple clients and provide a robust set of IRC features.

## General Rules

- The program must not crash under any circumstances, including running out of memory.
- A Makefile should be provided to compile the source files without relinking.
- The code must comply with the C++ 98 standard and compile with the flags `-Wall -Wextra -Werror`.
- Any external and Boost libraries are forbidden.

## Mandatory Part

### Program Name

`ircserv`

### Turn-in Files

List of files to be turned in (as specified in the project description).

### Non-blocking File Descriptors

The server must use non-blocking file descriptors and handle multiple client connections simultaneously.

## Bonus Part

The bonus part will only be evaluated if the mandatory part is perfect. Possible bonus features include:

- File transfer handling.
- A bot for the server.

## Submission and Peer-evaluation

Turn in your assignment through your Git repository as usual. Ensure that the file names are correct and that you have created test programs for your project.

## Installation

```bash
# Clone the repository
git clone <repository-url>

# Navigate to the project directory
cd <project-directory>

# Compile the project using the Makefile
make
```

## Usage

```bash
# Start the IRC server
./ircserv <port> <password>
```

Replace `<port>` with the port number you want to run your server on and `<password>` with the password required for connecting to the server.

## Contributing

To contribute to this project, please follow the standard GitHub workflow:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes.
4. Push to your fork.
5. Submit a pull request.

## License

This project is licensed under the [LICENSE](LICENSE) file in the root directory of this source tree.

## Acknowledgments

- Mention any individuals or organizations that have contributed to the development of this project.
- Any reference client used during the evaluation process.