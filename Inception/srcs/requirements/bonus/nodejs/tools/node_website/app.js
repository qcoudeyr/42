var express = require("express");
var cors = require("cors");

var app = express();
var router = express.Router();

var path = __dirname + '/views/';

// Use the CORS middleware
app.use(cors());

// Constants
const PORT = 3000; // Change this to the desired port
const HOST = '0.0.0.0';

router.use(function (req,res,next) {
  console.log("/" + req.method);
  next();
});

router.get("/",function(req,res){
  res.sendFile(path + "index.html");
});

app.use(express.static(path));
app.use("/", router);

app.listen(PORT, function () {
  console.log('Node.js app listening on port ' + PORT);
});
