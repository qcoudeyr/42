const express = require("express");
const path = require("path");

const app = express();

// Constants
const PORT = 8080;

// Serve static files from the "views" directory
app.use(express.static(path.join(__dirname, "views")));

// Redirect all requests to views/index.html
app.get("*", (req, res) => {
  res.sendFile(path.join(__dirname, "views", "index.html"));
});

app.listen(PORT, () => {
  console.log(`Node.js app listening on http://localhost:${PORT}`);
});
