var express = require('express');
var router = express.Router();
var mod = require('../mod/mod.js');

router.get('/', function (req, res) {
    console.log(req.session.passport)
    if (!req.session.passport||!req.session.passport.user) {
        res.redirect('/home/login');
        return;
    }
    var body = `<body>
        <header>
            <h1>NTBoard</h1>
            <div style="margin-left:20px;">
                <p font-size: 15px; font-weight: bold;">${req.user.nickname}&nbsp님</p>
                <span><button onclick="
                            location.href='/auth/logout'
                            ">로그아웃</button></span>
                <span><button onclick="
                            location.href='/home/userinfo'
                            ">회원정보</button></span>
            </div>
            <p></p>
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
module.exports = router;