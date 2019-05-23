// Sample Javascript program.

let a = 20; // Do not need datatype of variable for declaration.
var b = 40;
const c = 60; // These are the three types of possible declarations.

console.log("Output of a+b+c: ");
console.log(a+b+c); // Prints to console (terminal).

// If the value of a const variable is changed, an error is thrown.
// 'let' is block-scoped, it is visible only in the block it is declared in.
// 'var' is function-scoped, it is visible in the function where it is declared.

/*
This is a multiline comment.
To run this program, type `node sample1.js`
*/

var arr1 = new Array(10);
console.log(arr1); // Should show `[ <10 empty items> ]`

var arr2 = []; // Empty array with no elements
arr2.push("element0");
arr2.push(1);
arr2.push('3');
console.log(arr2); // Array can have elements with different datatypes.

var arr3 = arr2.concat(['c', 'a', 't']); // Concatenate two arrays and returns the new array
console.log(arr2); // Write 'arr2.' and press 'Ctrl+Space' to see possible array manipulation functions (on VSCode).

// Sample function declaration
function sampleFunc() {

    console.log("\nOutput of first for loop");
    for(let i = 0; i<10; i++) {
        // The variable i is only accessible in this block.
        console.log(Math.pow(i,2)); // Printing squares of i
    }

    console.log("\nOutput of second for loop");
    for (var j=0; j<6; j++) {
        // j is accessible in this block and also in the rest of the function.
        console.log(arr3[j]);
    }

    console.log("Value of 'j' after second for loop is " + j); // j is accessible here because it is declared as var.
    console.log(`Value of 'j' is ${j} after second for loop`); // Alternate printing syntax without concatenation. Note: `(backtick) is used not '
}

console.log("\nOutput of sampleFunc() is as follows.") // Note: Semicolons at the end are optional.
sampleFunc(); // Calling the function sampleFunc().

function newFunc() {
    arr3.forEach( (value, index) => { // Note: This is an example of a callback function.
        // Example of forEach loop.
        console.log(`Value: ${value}`); // Value of the element
        console.log(`Index: ${index}`); // Index of the element
    });
    return "HelloWorld";
}

console.log("\nOutput of newFunc():");
var returnedVal = newFunc(); // Executes newFunc, prints the values, and stores the returned value in the variable
console.log(returnedVal); // See the value of returnedVal.

( // This paranthesis is for execution
() => { // Start of function
    console.log("This is a nameless function");
} // End of function
); // Execute a nameless function

( // Execute
    function () { // Alternative way to create nameless function
        console.log("Another nameless function")
    }
);
