var express = require('express');
var router = express.Router();
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({ extended: false }))
var shortid = require('shortid');
var db = require('../mod/db.js');

module.exports = function (passport) {
    router.post('/join', function (req, res) {
        var post = req.body;
        var name = post.name;
        var nick = post.nickname;
        if (db.get('users').find({
            nickname: nick
        }).value()) {
            res.send(`<script>alert('닉네임 중복! 다시 만들어주세요');window.history.back();</script>`)
            return;
        }
        var id = post.id;
        if (db.get('users').find({
            id: id
        }).value()) {
            res.send(`<script>alert('아이디 중복! 다시 만들어주세요');window.history.back();</script>`)
            return;
        }
        var pw = post.pw;
        var quest = post.quest;
        if(post.direct)
        quest=post.direct;
        var ans = post.ans;
        var year = post.year;
        var month = post.month;
        var day = post.day;
        if(day<10&&day[0]!='0') day='0'+day;
        // var joinday,visit,post,comment;
        var userinf = {
            key: shortid.generate(),
            name: name,
            nickname: nick,
            id: id,
            password: pw,
            question: quest,
            answer: ans,
            year: year,
            month: month,
            day: day
        }
        db.get('users').push(userinf).write();

        
        req.login(userinf, function (err) {
            req.session.save(function () {
                res.redirect('/');
            });
        })
    })

    router.post('/login',
        passport.authenticate('local', {
            successRedirect: '/',
            failureRedirect: '/home/login',
            failureFlash: true
        })
    );

    router.get('/logout', function (req, res) {
        req.logout();
        req.session.save(function () {
            res.redirect('/home/login');
        })
    });

    return router;
}