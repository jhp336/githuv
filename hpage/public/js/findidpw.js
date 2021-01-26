function clickbtn(but) {
    var btn2, btn = $(but)
    if (btn.attr('id') === 'idfind') {
        btn2 = $('#pwfind');
        $('#change').html(`
        <form id="new"  onsubmit="return false;" method="post" action="/home/findidpw">
        <table>
            <tr>
                <td><input class="inputbox" name= "name" id="name" type="text" placeholder="성명"></td>
            </tr>
            <tr>
                <td><input class="inputbox" name="nickname" id="nickname" type="text" placeholder="닉네임"></td>
            </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <input class="click" type="button" value="확인"  onclick="Pressbtn('#new')">
        </div>
        </form>`)
    }
    else {
        btn2 = $('#idfind');
        $('#change').html(`
        <form id="new"  onsubmit="return false;" method="post" action="/home/findidpw">
        <table>
            <tr>
                <td><input class="inputbox" name="name" id="name" type="text" placeholder="성명"></td>
            </tr>
            <tr>
                <td><input class="inputbox" name="id" id="id" type="text" placeholder="아이디"></td>
            </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <input class="click" type="button" value="확인"  onclick="Pressbtn('#new')">
        </div>
        </form>`);
    }
    if (btn.css("background-color") != "rgb(241, 237, 237)") {
        btn.css("background-color", "rgb(241, 237, 237)");
        btn2.css("background-color", "rgb(176, 182, 182)");
    }
}

enterpress = function () {
    if (window.event.keyCode == 13)
        Pressbtn('#new');
}
Pressbtn = function (form) {
    var NAME = $('#name');
    var NICK = $('#nickname');
    var ID = $('#id');
    if (NAME.val() === "") {
        alert('이름을 입력해주세요');
        NAME.focus();
        return;
    }
    if (NICK.val() === "") {
        alert('닉네임을 입력해주세요');
        NICK.focus();
        return;
    }
    if (ID.val() === "") {
        alert('아이디를 입력해주세요');
        ID.focus();
        return;
    }
    $(form).attr('onsubmit',true);
    $(form).submit();
}
