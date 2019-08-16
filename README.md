# Algorithms Projects
👨🏽‍💻🤓 Assignment for 'Algorithms' subject about basic concepts of programming

## More Information
These projects are all made using the programming language C, however, the speaking language was Portuguese.

### Usage
To execute the program, it's necessary to compile the code and execute the compiled file. For that you need to use the following commmand (for that you need to install the GNU Compiler, if you have Windows, you can use an IDE like: DevC++):

```sh
$ gcc PROJECT_NAME.c –o PROJECT_NAME
$ ./PROJECT_NAME
```

### Código Morse / Morse Code
The main objectives of this work are:

• Understand how the Morse coding method works;

• Apply concepts and operations to use the method;

The project are divided in two parts, the first one is covert alphabet caracters in morse coding, using an input file called *decodificado.txt* and return the result in the file: *codificado.txt*. The second part is the opposite, it means, that is a converter from morse coding to our alphabet caracters using the file *codificado.txt* to *decodificado.txt*.
In the following image you can see the convertion table used for this program.

<img src = 'https://github.com/vitorCamargo/algorithms/blob/master/C%C3%B3digo%20Morse/convertion-table.png' alt = 'Convertion Table' height = '270' style = 'height: 270px;' />

### Interruptor (Compatibilidade de Conectores) / Power Plugs (Connector Compatibility)
Given a file *entrada.txt* that contains two lines with five binary numbers (0 represents an outlet and 1 represents a plug), verify that both connectors are compatible and print "Compatible" or "Incompatible" as a result of your analysis.

For a simple example, if you have the following entry, the system will print "Incompatible"
```
1 0 0 1 0
1 0 1 1 0
```

But, if the input file be:
```
1 1 0 1 0
0 0 1 0 1
```

The output will be: "Compatible".

### Jogo da Velha / Tic-tac-toe
The main objectives of this work are:

• Develop an application that implements a tic-tac-toe game;

• The app must allow two players to play 1 match, and in the end inform the winner or draw.
