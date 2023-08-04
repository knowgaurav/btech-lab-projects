// const http = require('http');

// const app = http.createServer((req, res) => {
//     var mongoose = require('mongoose');
//     mongoose.connect('mongodb://localhost:27017/tutorialkart');

//     var db = mongoose.connection;

//     db.on('error', console.error.bind(console, 'connection error:'));

//     db.once('open', function () {
//         console.log("Connection Successful!");
//     });

// });

// const PORT = process.env.PORT || 3000;

// app.listen(PORT, () => {
//     console.log(`Listening on port ${PORT}`);
// })

var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function (err, db) {
    if (err) throw err;
    var dbo = db.db("company");
    var query = { first_name: "Krisha" };
    dbo.collection("users").find(query).toArray(function (err, result) {
        if (err) throw err;
        console.log(result);
        db.close();
    });
});

// var mongoose = require('mongoose');
// mongoose.connect('mongodb://localhost:27017/');

// var db = mongoose.connection;

// db.on('error', console.error.bind(console, 'connection error:'));

// db.once('open', function () {
//     console.log("Connection Successful!");
// });