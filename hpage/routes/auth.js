var express = require('express');
var router = express.Router();
const bodyParser = require('body-parser')
router.use(bodyParser.urlencoded({ extended: false }))
var shortid = require('shortid');
var db = require('../mod/db.js');
var mod = require('../mod/mod.js');

module.exports = function (passport) {
    router.post('/join', function (req, res) {
        var post = req.body;
        var name = post.name;
        var nick = post.nickname;
        var id = post.id;
        var pw = post.pw;
        var quest = post.quest;
        var direct = post.direct_q;
        var ans = post.ans;
        var year = post.year;
        var month = post.month;
        var day = post.day;
        // var joinday,visit,post,comment;
        var userinf = {
            key: shortid.generate(),
            name: name,
            nickname: nick,
            id: id,
            password: pw,
            question: quest,
            direct: direct,
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

    router.post('/duplication', function (req, res) {
        var user = db.get('users').find({
            nickname: req.body.nickname
        }).value();
        if (user) {
            var body = `<script>
            alert('중복된 닉네임이 있습니다. 다시 정해주세요');
            window.history.back();
            </script>`;
            var html = mod.HTML('회원가입', '', body);
            res.send(html);
        }
        else {
            var body = `<script>
            alert('사용 가능한 닉네임입니다!');
            window.history.back();
            </script>`;
            var html = mod.HTML('회원가입', '', body);
            res.send(html);
        }
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