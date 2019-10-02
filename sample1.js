// Sample Javascript program.

/*
This is a multiline comment.
To run this program, type `node sample1.js`
*/


let a = 20; // Does not need to set the datatype of variable for declaration.
var b = 40;
const c = 60; // These are the three types of possible declarations.

console.log("Output of a+b+c: ");
console.log(a+b+c); // Prints to console (terminal).

// If the value of a const variable is changed, an error is thrown. Value is CONSTANT
// 'let' is block-scoped, it is visible only in the block it is declared in.
// 'var' is function-scoped, it is visible in the function where it is declared.


var emptySizeTenArray = new Array(10);
console.log(emptySizeTenArray); // Should show `[ <10 empty items> ]`

var dynamicArray = []; // Empty array with no elements
dynamicArray.push("element0"); // Array has a flexible size
dynamicArray.push(1);
dynamicArray.push('3');
console.log(dynamicArray); // Array can have elements with different datatypes.


var combinedArray = dynamicArray.concat(['c', 'a', 't']); // Concatenate two arrays and returns the new array
console.log(combinedArray); // Write 'combinedArray.' and press 'Ctrl+Space' to see possible array manipulation functions (on VSCode).

// Sample function declaration
function sampleFunc() {

    console.log("\nOutput of first for loop");
    for(let i = 0; i<10; i++) {
        // The variable i is only accessible in this block.
        console.log(Math.pow(i,2)); // Printing squares of i
    }

    console.log("\nOutput of second for loop");
    for (var j=0; j<6; j++) {
        // j is accessible in this block and also in the rest of the function. Hoisting
        console.log(combinedArray[j]);
    }

    console.log("Value of 'j' after second for loop is " + j); // j is accessible here because it is declared as var.
    console.log(`Value of 'j' is ${j} after second for loop`); // Alternate printing syntax without concatenation. Note: `(backtick) is used not '
}

console.log("\nOutput of sampleFunc() is as follows.") // Note: Semicolons at the end are optional.
sampleFunc(); // Calling the function sampleFunc().

function newFunc() {
    combinedArray.forEach( (value, index) => { // Note: This is an example of a callback function.
        // Example of forEach loop.
        console.log(`Value: ${value}`); // Value of the element
        console.log(`Index: ${index}`); // Index of the element
    });
    return "HelloWorld";
}

console.log("\nOutput of newFunc():");
var returnedVal = newFunc(); // Executes newFunc, prints the values, and stores the returned value in the variable
console.log(returnedVal); // See the value of returnedVal -> Hello World

( // This paranthesis is for Immediately Invoked Function Expression 
    () => { // Start of function
        console.log("This is a nameless function");
    } // End of function
); // Execute a nameless function

( // Execute
    function () { // Alternative way to create nameless function that runs as soon as it is defined
        console.log("Another nameless function")
    }
);
