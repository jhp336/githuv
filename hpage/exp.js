var express=require('express');
var app=express();
var flash=require('connect-flash');
var session = require('express-session')
var FileStore = require('session-file-store')(session);

app.use(express.static('public'));
app.use(session({
  secret: 'keyboard cat',
  resave: false,
  saveUninitialized: true,
  //store:new FileStore()
}))
app.use(flash());
var passport = require('./mod/passport.js')(app);

app.use('/',require('./routes/index.js'));
app.use('/home',require('./routes/home.js'));
app.use('/auth',require('./routes/auth.js')(passport));


app.use(function(req,res,next){
    res.status(404).send("<script>alert('페이지가 존재하지 않습니다!');window.history.back();</script>");
});
app.use(function(err, req, res, next) {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});
app.listen(3000);
