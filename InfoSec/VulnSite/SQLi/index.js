import express from 'express';
import mysql from 'mysql';
import path from 'path';
import bodyParser from 'body-parser';
import winston from 'winston';
import preventInjection from './preventInjection.js';

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'nodejs',
    password: 'password1337',
    database: 'webapp',
});

const logger = winston.createLogger({
    level: 'info',
    format: winston.format.json(),
    defaultMeta: { service: 'user-service', time: +new Date() },
    transports: [
        //
        // - Write all logs with level `error` and below to `error.log`
        // - Write all logs with level `info` and below to `combined.log`
        //
        new winston.transports.File({ filename: './logs/error.log', level: 'error' }),
        new winston.transports.File({ filename: './logs/combined.log' }),
    ],
});

connection.connect();

const app = express();
const PORT = process.env.PORT || 3000;

app.use(bodyParser.urlencoded({ extended: false }));

app.get('/', (req, res) => {
    logger.info(req.url);
    res.sendFile(path.resolve('.', 'login.html'));
});

// app.post('/', preventInjection, (req, res) => {
app.post('/', (req, res) => {
    logger.info(req.url);
    logger.info(req.body);

    const { email, password } = req.body;
    const query = `SELECT * FROM USERS WHERE email='${email}' AND password='${password}'`;

    connection.query(query, function (error, results, fields) {
        if (error) {
            res.send(error);
            return;
        }

        if (results && results.length) {
            console.log(results);
            res.send('<h1>Logged in successfully!</h1>');
        } else {
            res.send('<h1>Login failed!</h1>');
            logger.error(req.body);
        }
    });
});

app.listen(PORT, () => console.log('Server Running on PORT', PORT));

// Intended
// curl -X POST -d "email=infosec@vit.ac.in" -d "password=this_is_a_secret_password" http://localhost:3000
// 
// SQL Injection Payload
// curl -X POST -d "email=' or 1=1 -- " -d "password=something" http://localhost:3000
