var mod = require('./mod.js');
var mod2 = require('./mod2.js');
var db = require('./db.js');
require('body-parser')

module.exports = {
    dupli_new: function (req, str, which) {
        var post = req.body;
        var body = mod.NEWACC();
        var html = mod.HTML('회원가입', 'newaccount', body);
        var add = `</script>`
        if (which == 'nickname') {
            var info = post.nickname;
            var user = db.get('users').find({
                nickname: info
            }).value();
            if (post.idbool === '1') {
                add = `$('#iddupok').attr('hidden',false);
            $('#iddupcheck').attr('hidden',true);
            $('#idbool').val('1');`+ add;        //id 사용가능 정보전달
            }
        }
        else {
            var info = post.id;
            var user = db.get('users').find({
                id: info
            }).value();
            if (post.nicknamebool === '1') {
                add = `$('#nicknamedupok').attr('hidden',false);
            $('#nicknamedupcheck').attr('hidden',true);
            $('#nicknamebool').val('1');`+ add;  //닉네임 사용가능 정보전달
            }
        }

        if (post.ans === undefined)
            post.ans = '';
        var script = `<script>
        $('#name').val('${post.name}');
        $('#nickname').val('${post.nickname}');
        $('#id').val('${post.id}');
        $('#pw').val('${post.pw}');
        $('#pwc').val('${post.pwc}');
        $('#quest').val('${post.quest}');
        $('#direct').val('${post.direct_q}');
        $('#ans').val('${post.ans}');
        $('#year').val('${post.year}');
        $('#month').val('${post.month}');
        $('#day').val('${post.day}');
        `
        if (post.quest != "질문 없음") {
            script = script + `$('#ans').attr('disabled', false);`
            if (post.quest === 'dir')
                script = script + `$('#direct').show();`
        }

        if (user)//중복있는경우
            script = script + `$('#${which}').focus();
    alert('해당 ${str}이(가) 이미 있습니다. 다시 정해주세요!');`;
        else script = script + `$('#${which}dupok').attr('hidden',false);
    $('#${which}dupcheck').attr('hidden',true);
    $('#${which}bool').val('1');`; //중복 x


        return html + script + add;
    },

    dupli_mod: function (req,originnick) {
        var post = req.body;
        var body = mod2.userinfo(originnick, post.name, post.nickname, post.id
            , post.quest, post.ans, post.year, post.month, post.day);
        var html = mod.HTML(`${originnick}님의 회원정보`, 'userinfo', body);
        var info = post.nickname;
        var user = db.get('users').find({
            nickname: info
        }).value();

        var script = '<script>';

        if (user)//중복있는경우
            script = script+`$('#nickname').focus();
    alert('해당 닉네임이 이미 있습니다. 다시 정해주세요!');
    Modify('${post.ans}',0);</script>`;
        else script = script+ `$('#nicknamedupok').attr('hidden',false);
    $('#nicknamedupcheck').attr('hidden',true);
    $('#nicknamebool').val('1');
    Modify('${post.ans}',1);</script>`; //중복 x

        return html + script;
    }

}
