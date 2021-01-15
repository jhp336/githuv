var db =require('./db.js');

module.exports=function(app){
    var passport = require('passport')
    , LocalStrategy = require('passport-local').Strategy;
    app.use(passport.initialize());
    app.use(passport.session());
    
    passport.serializeUser(function(user, done) {
        done(null, user.key);
    });
    
    passport.deserializeUser(function(id, done) {
        var user=db.get('users').find({
            key:id
        }).value();
        done(null, user);
    });

    passport.use(new LocalStrategy({
        usernameField: 'user_id',
        passwordField: 'user_pw'
    },
    function(username, password, done) {
        var user=db.get('users').find({
            id:username
        }).value();
        if (!user) {
            return done(null, false, { message: '아이디 입력 오류' });
        }
        if (user.password!=password) {
            return done(null, false, { message: '비밀번호 입력 오류' });
        }
        return done(null, user);
    }
    ));
    return passport;
}