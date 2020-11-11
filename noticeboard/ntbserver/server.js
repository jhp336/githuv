const express = require("express");
const app = express();
const cors = require("cors");  //동일 기원 차단 해제?
const session = require("express-session");
const connect = require("./schemas");

connect();

const corsOption = {
    origin: true,
    credentials: true
};

app.use(
    session({
        resave: false,
        saveUninitialized: true,
        secret: "jhp",
        cookie: {
            httpOnly:true,
            secure:false
        }
    })
);

app.use(cors(corsOption));

app.use(express.json());
app.use(express.urlencoded({extended:true}));

app.use("/member", require("./routes/memberrouter"));
app.use("/board", require("./routes/boardrouter"));

app.listen(8080, () => {
    console.log("hi");
});