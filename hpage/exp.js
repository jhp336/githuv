var express=require('express');
var app=express();
var flash=require('connect-flash');

app.use(express.static('public'));

app.use('/',require('./routes/index.js'));
app.use('/home',require('./routes/home.js'));
app.use('/auth',require('./routes/auth.js'));

var passport = require('passport')
  , LocalStrategy = require('passport-local').Strategy;
  app.use(passport.initialize());
  app.use(passport.session());

  passport.serializeUser(function(user, done) {
    done(null, user.id);
  });
  
  passport.deserializeUser(function(id, done) {
    User.findById(id, function(err, user) {
      done(err, user);
    });
  });

passport.use(new LocalStrategy({
    usernameField: 'user_id',
    passwordField: 'user_pw'
  },
  function(username, password, done) {
    User.findOne({ username: username }, function (err, user) {
      if (err) { return done(err); }
      if (!user) {
        return done(null, false, { message: 'Incorrect username.' });
      }
      if (!user.validPassword(password)) {
        return done(null, false, { message: 'Incorrect password.' });
      }
      return done(null, user);
    });
  }
));

  app.post('/auth/login',
  passport.authenticate('local', { 
        successRedirect: '/',
        failureRedirect: '/home/login' 
    }));

app.use(function(req,res,next){
    res.status(404).send("Sorry, I can't find");
});
app.use(function(err, req, res, next) {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});
app.listen(3000);
