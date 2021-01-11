var express=require('express');
var app=express();

app.use(express.static('public'));

app.use('/',require('./routes/index.js'));
app.use('/home',require('./routes/home.js'));


app.use(function(req,res,next){
    res.status(404).send("Sorry, I can't find");
});
app.use(function(err, req, res, next) {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});
app.listen(3000);
