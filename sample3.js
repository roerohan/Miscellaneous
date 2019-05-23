// Sample Javascript Program, Promises and Async Await

// Use of too many callbacks results in code which is not easily understandable. Hence promises are used instead of callbacks.
// A promise is like a promise in real life, it can either be fulfilled or resolved, or not fulfilled and rejected.


// Promises - Section One
// function checkIfEven(num) {
//     return new Promise( (resolve, reject) => { // This returns a new instance of promise, passed a callback function to it with resolve and reject as params
//         if(num%2==0) // Check if number is even, if yes, resolve the promise and send back the number.
//             resolve(num);
//         else // If odd, reject and send back a string "Odd".
//             reject("Odd");
//     });
// }

// checkIfEven(133)
//     .then( (number) => { // Check if 133 is even, then execute nameless function: (num) => {}
//         console.log(`${number} is Even`); // Value of number would've been the sent back by checkIfEven(...), had it been even
//     })
//     .catch( (errMessage) => {
//         console.log(`${errMessage} number found`); // Value of errMessage is "Odd", because 133 is not even
//     });

// Promises - Section Two

// Promise.all can be used if there are many promises that need to be satisfied.

function checkIfEven(num) {
    return new Promise( (resolve, reject) => { // This returns a new instance of promise, passed a callback function to it with resolve and reject as params
        if(num%2==0) // Check if number is even, if yes, resolve the promise and send back the number.
            resolve(num);
        else // If odd, reject and send back a string "Odd".
            reject("Odd");
    });
}

function checkIfGreaterThanTen (num) {
    return new Promise ( (resolve, reject) => {
        if(num>10)
            resolve(num);
        else
            reject("Less than 10");
    });
}

var promises = []
promises.push (checkIfEven(122));
promises.push (checkIfGreaterThanTen(114));

Promise.all(promises)
    .then( (num) => { // Num is an array containing 122 and 114, the first promise returns 112, the second promise returns 114
        console.log(num);
    })
    .catch( (errMessage) => {
        console.log(errMessage); // errMessage contains the error which occurs first in the promises (if any)
    });
