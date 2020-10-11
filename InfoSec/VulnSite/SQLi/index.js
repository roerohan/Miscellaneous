import express from 'express';
import mysql from 'mysql';
import path from 'path';
import bodyParser from 'body-parser';
import preventInjection from './preventInjection.js';

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'nodejs',
    password: 'password1337',
    database: 'webapp',
});

connection.connect();

const app = express();
const PORT = process.env.PORT || 3000;

app.use(bodyParser.urlencoded({ extended: false }))

app.get('/', (_req, res) => {
    res.sendFile(path.resolve('.', 'login.html'));
});

app.post('/', preventInjection, (req, res) => {
    const { email, password } = req.body;
    const query = `SELECT * FROM USERS WHERE email='${email}' AND password='${password}'`;

    connection.query(query, function (error, results, fields) {
        if (error) {
            res.send(error);
            return;
        }

        if (results) {
            res.send('Logged in successfully!');
        }
    });
});

app.listen(PORT, () => console.log('Server Running on PORT', PORT));

// Intended
// curl -X POST -d "email=infosec@vit.ac.in" -d "password=this_is_a_secret_password" http://localhost:3000
// 
// SQL Injection Payload
// curl -X POST -d "email=' or 1=1 -- " -d "password=something" http://localhost:3000
