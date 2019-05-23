// Sample javascript program, callbacks.

// Comment out all other sections before executing one section.

// Section One
function slowFunction(num) {
    setTimeout( () => { // This is a callback function(A function passed inside another)
        console.log(`You entered ${num}.`);
        console.log("This took 2 seconds");
    }, 2000);
}

slowFunction(10);
console.log("This gets printed first."); // This line gets printed first, even though it is typed later.
//This can be made to function in order with callbacks.

// // Section Two

// // Creating a function with a callback function. The callback is a function, like any other function.
// // In JS you can pass a function as a parameter.
// function slowerFunc(num, callback) {
//     console.log("Waiting for 2.5 seconds.");
//     setTimeout( () => {
//         console.log(`You entered ${num}`);
//         callback(); // Execute the function which was passed as callback.
//     }, 2500);
// }

// slowerFunc(15, function () { // Passing a nameless function, alternative: slowerFunc(10, () => {
//     console.log("This gets printed afterwards because this function passed as a callback.")
// });

// // Section Three

// // You can pass any function as a callback

// function someFunc(num, callback) {
//     console.log("Waiting for 3 seconds.");
//     setTimeout( function () { // Passing a nameless function [ same as () => { ]
//         console.log(`You entered ${num}`);
//         callback(); // Execute the function which was passed as callback.
//     }, 3000);
// }

// function passAsCallback() {
//     var a = "callback";
//     console.log(`This is the ${a} function`);
// }

// someFunc(20, passAsCallback);
