var express = require('express');
const db = require('../mod/db.js');
var router = express.Router();
var mod = require('../mod/mod.js');

router.get('/', function (req, res) {
    console.log(req.session.passport)
    if (!req.user) {
        res.redirect('/home/login');
        return;
    }
    var body = `<body>
        <header>
            <h1>NTBoard</h1>
            <div>
                <p font-size: 15px; font-weight: bold;">${req.user.nickname}&nbsp님</p>
                <span><button onclick="
                            location.href='/auth/logout'
                            ">로그아웃</button></span>
                <span><button onclick="
                            location.href='/${req.user.id}/userinfo'
                            ">회원정보</button></span>
            </div>
            <br>
        </header>

        <div id="new">
            <table>
                <tr>
                    <td><button>자유게시판</button></td>
                    <td><button>비밀게시판</button></td>
                </tr>
            </table>
        </div>
    </body> `
    var html = mod.HTML('메인페이지','',body);
    res.send(html);
});

router.get('/:userid/userinfo',function(req,res){
    var user=db.get('users').find({
        id:req.params.userid
    }).value();
    if(!user){
        res.send("<script>alert('페이지가 존재하지 않습니다!');location.href='/';</script>");
        return;
    }
    if (!req.user||req.user.key!=user.key) {
        res.send(`<script>alert('권한이 없습니다!');window.history.back();</script>`)
        return;
    }

    res.send('hi');
})
module.exports = router;