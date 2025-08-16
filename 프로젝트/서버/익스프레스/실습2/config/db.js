var mysql = require('mysql');

module.exports = mysql.createPool({
	host:'localhost',
	user:'root',
	password:'1234',
	database:'ex',
	port:3306
});