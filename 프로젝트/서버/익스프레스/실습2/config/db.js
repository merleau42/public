var mysql = require('mysql2');

module.exports = mysql.createPool({
	host:'sql.freedb.tech',
	user:'freedb_soybean',
	password:'ewceXBp*sz9A9y@',
	database:'freedb_ex_mysql',
	port:3306
});

// smallbut
// https://freedb.tech/dashboard/