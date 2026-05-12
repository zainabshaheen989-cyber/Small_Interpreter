const express = require("express");
const bodyParser = require("body-parser");
const { exec } = require("child_process");
const fs = require("fs");
const path = require("path");

const app = express();

app.use(bodyParser.json());
app.use(express.static("public"));

// ⭐ HOME PAGE ROUTE (FIX)
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "public", "index.html"));
});

app.post("/run", (req, res) => {
    let code = req.body.code;

    fs.writeFileSync("input.txt", code);

    exec("interpreter.exe < input.txt", (error, stdout, stderr) => {
        if (error) {
            return res.json({ output: stderr || error.message });
        }

        res.json({ output: stdout });
    });
});

app.listen(3000, () => {
    console.log("Server running on http://localhost:3000");
});