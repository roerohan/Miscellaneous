import fs from 'fs';

const logFile = fs.readFileSync('./logs/combined.log', 'utf-8');

const sql_meta = new RegExp('(%27)|(\')|(--)|(%23)|(#)', 'ig').exec(logFile);
const sql_meta2 = new RegExp('((%3D)|(=))[^\n]*((%27)|(\')|(--)|(%3B)|(;))', 'ig').exec(logFile);
const sql_typical = new RegExp('w*((%27)|(\'))((%6F)|o|(%4F))((%72)|r|(%52))', 'ig').exec(logFile);
const sql_union = new RegExp('((%27)|(\'))union', 'ig').exec(logFile);


let total = sql_meta ? sql_meta.length : 0;
total += sql_meta2 ? sql_meta2.length : 0;
total += sql_typical ? sql_typical.length : 0;
total += sql_union ? sql_union.length : 0;

console.log(`There are ${total} instances of SQL injection/XSS in the log file 'combined.log'.`);
