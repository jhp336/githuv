Modify = function (answer, dup) {//dup=1이면 중복확인 완료 0이면 확인 전
    $('.modif2').attr('disabled', false);
    if (dup === 1){
        $('#nicknamedupcheck').attr('hidden',true);
        $('#nicknamedupok').attr('hidden', false);
        $('#nicknamebool').val(1);
    }
    
    else {
        var len=$('#nickname').val().length;
        $('#nicknamedupcheck').attr('hidden', false);
        $('#nickname').focus();
        $('#nickname')[0].setSelectionRange(len,len);//커서 끝으로 하기위함
        alert('해당 닉네임이 이미 있습니다. 다시 정해주세요!');       
    }
    $("#ans").attr('style', '');
    $('#ans').val(answer);

    $('#modify').attr('hidden', true);
    $('.modif').attr('hidden', false);
    $('body').attr('onkeydown',"enterpress()")
}//수정 버튼 클릭
duplicheck = function (id) {
    var test = /^(?=.*[a-zA-Z]|.*[가-힣])[a-zA-Z0-9가-힣]{2,10}$/;
    if (!test.test($('#nickname').val())) {
        alert('닉네임은 한글 또는 영문을 포함한 2~10 글자로 공백없이 작성해주세요');
        $('#nickname').focus();
        return;
    }

    $('#new').attr('action', `/${id}/userinfo/modify`);
    $('#new').submit();
}//중복 확인
nicknamechange = function () {
    $('#nicknamebool').val('');                    //중복확인 필요
    $('#nicknamedupok').attr('hidden', true);
    $('#nicknamedupcheck').attr('hidden', false);    //사용가능->중복확인 
}//닉네임 칸 내용 변경시

Check = function (form) {
    var NAME = $('#name');
    var test1 = /^[가-힣]{1,12}$/;
    if (!test1.test(NAME.val())) {
        alert('이름을 한글 1~12자리로 공백없이 작성해주세요');
        NAME.focus();
        return;
    }
    //이름 처리

    var NICK = $('#nickname');
    var test2 = /^(?=.*[a-zA-Z]|.*[가-힣])[a-zA-Z0-9가-힣]{2,10}$/;
    if (!test2.test(NICK.val())) {
        alert('닉네임을 한글 또는 영문을 포함한 2~10 글자로 공백없이 작성해주세요');
        NICK.focus();
        return;
    }//닉네임 처리

    var dup1 = $('#nicknamebool').val();
    if (dup1 != '1') {
        alert('닉네임 중복확인을 해주세요!');
        NICK.focus();
        return;
    }  //중복 확인 처리

    if ($('#quest').val() != '' && $('#ans').val() === '') {
        alert('질문에 답변을 해주세요!');
        $('#ans').focus();
        return;
    }
    if ($('#quest').val() === '' && $('#ans').val() != '') {
        alert('질문이 없는데 답변이 있습니다..?');
        $('#quest').focus();
        return;
    }
    //질문 답변 입력시 처리

    if ($('#year').val()) {
        var test5 = /^[0-9]{4,4}$/;
        if (!test5.test($('#year').val())) {
            alert('년도는 4자리 숫자로!');
            $('#year').focus();
            return;
        }
    }
    if ($('#month').val()) {
        var val = $('#month').val();
        var test6 = /^[0-9]{1,2}$/;
        if (!test6.test(val) || val < 1 || val > 12) {
            alert('태어난 달은 1~12 사이의 숫자로!!');
            $('#month').focus();
            return;
        }
    }
    if ($('#day').val()) {
        var val = $('#day').val();
        var test6 = /^[0-9]{1,2}$/;
        if (!test6.test(val) || val < 1 || val > 31) {
            alert('날짜는 1~31 사이의 숫자로!!');
            $('#day').focus();
            return;
        }
    }//생년월일 처리

    if ($('#pw').val() === '') {
        $('#msg').html('계정의 비밀번호를 입력해주세요!');
        $('#pw').focus();
        return;
    }

    $(form).submit();
}
enterpress = function () {
    if (window.event.keyCode == 13)
        Check('#new');
}

function clickbtn(but) {
    var btn2, btn = $(but)
    if (btn.attr('id') === 'basicinf') 
    btn2 = $('#pwinf');
    else btn2 = $('#basicinf');
       
    if (btn.css("background-color") != "rgb(241, 237, 237)") {
        btn.css("background-color", "rgb(241, 237, 237)");
        btn2.css("background-color", "rgb(176, 182, 182)");
    }
}