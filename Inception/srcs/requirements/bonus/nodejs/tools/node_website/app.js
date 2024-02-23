const http = require("http");
const fs = require("fs");

const server = http.createServer((req, res) => {
  console.log(`${req.method} ${req.url}`);

  // Handle CORS headers
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE");
  res.setHeader("Access-Control-Allow-Headers", "Content-Type");

  // Redirect all requests to views/index.html
  fs.readFile(__dirname + "/views/index.html", (err, data) => {
    if (err) {
      res.writeHead(500);
      return res.end("Error loading index.html");
    }

    res.writeHead(200, { "Content-Type": "text/html" });
    res.end(data);
  });
});

// Constants
const PORT = 8080; // Change this to the desired port
const HOST = "0.0.0.0";

server.listen(PORT, HOST, () => {
  console.log(`Node.js app listening on http://${HOST}:${PORT}`);
});
