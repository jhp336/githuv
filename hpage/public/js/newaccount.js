function question(ele) {
    var val = $(ele).val();
    if (val === '0') {
        $("#direct").hide();
        $('#ans').attr('disabled', true);
    }
    else {
        $("#direct").hide();
        $('#ans').attr('disabled', false)
        if (val === 'dir')
            $("#direct").show();
    }
}

Check = function (form) {
    var ID = $('#id');
    var NAME = $('#name');
    var PW = $("#pw");
    var PWC = $('#pwc');
    var NICK = $('#nickname');
    var test1 = /^[가-힣]{1,12}$/;
    var test2 = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]{4,12}$/;
    var test3 = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9~!@#$%^&*?]{4,12}$/;
    var test4 = /^(?=.*[a-zA-Z])[a-zA-Z0-9가-힣]{2,10}|(?=.*[가-힣])[a-zA-Z0-9가-힣]{2,10}$/;

    if (NAME.val() === "") {
        alert('이름을 입력하세요');
        NAME.focus();
        return;
    }
    if (!test1.test(NAME.val())) {
        alert('이름은 한글 1~12자리로 공백없이 작성해주세요');
        NAME.focus();
        return;
    }
    //이름 처리

    if (NICK.val() === "") {
        alert('사용할 닉네임을 입력해 주세요');
        NICK.focus();
        return;
    }
    if (!test4.test(NICK.val())) {
        alert('닉네임은 한글 또는 영문을 포함한 2~10 글자로 작성해주세요');
        NICK.focus();
        return;
    }//닉네임 처리

    if (ID.val() === "") {
        alert('아이디를 입력하세요(영문과 숫자 조합, 4~12자리)');
        ID.focus();
        return;
    }
    for (i = 0; i < ID.val().length; i++) {
        if (!test2.test(ID.val())) {
            alert('아이디는 영문과 숫자 4~12자리로 공백없이 작성해주세요');
            ID.focus();
            return;
        }
    }//아이디 처리

    if (PW.val() === "") {
        alert('비밀번호를 입력하세요(영문과 숫자 조합, 4~12자리, 특수문자 ~!@#$%^&*? 가능)');
        PW.focus();
        return;
    }
    for (i = 0; i < PW.val().length; i++) {
        if (!test3.test(PW.val())) {
            alert('비밀번호는 영문과 숫자 4~12자리로 공백없이 작성해주세요 + 특수문자 ~!@#$%^&*? 포함 가능!')
            PW.focus();
            return;
        }
    }//비번 처리

    if (PWC.val() === "") {
        alert('비밀번호 확인 칸을 작성해주세요');
        PWC.focus();
        return;
    }
    if (PW.val() != PWC.val()) {
        alert('비밀번호가 일치하지 않습니다');
        PWC.focus();
        return;
    }//비번 일치 처리



    $(form).submit();
}

enterpress = function () {
    if (window.event.keyCode == 13)
        Check('#new');
}

duplicheck=function(){
    if(!$('#nickname').val()){
        alert('닉네임을 입력해주세요')
        $('#nickname').focus();
        return;
    }
    if($('#nicknamebool').val()==='0')
    $('#new').attr('action','/home/newaccount');
    $('#new').submit();
}

duplicheck_=function(){
    if(!$('#id').val()){
        alert('아이디를 입력해주세요')
        $('#id').focus();
        return;
    }
    $('#new').attr('action','/home/newaccount_');
    $('#new').submit();
}

nicknamechange=function(){
    $('#nicknamedupok').attr('hidden',true);
    $('#nicknamedupcheck').attr('hidden',false);    
    $('#nicknamebool').val('0');
}

idchange=function(){
    $('#iddupok').attr('hidden',true);
    $('#iddupcheck').attr('hidden',false);
    $('#idbool').val('0');
}
