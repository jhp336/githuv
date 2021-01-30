function question(ele) {
    var val = $(ele).val();
    if (val === "질문 없음") {
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
        alert('닉네임을 한글 또는 영문을 포함한 2~10 글자로 작성해주세요');
        NICK.focus();
        return;
    }//닉네임 처리

    var ID = $('#id');
    var test3 = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]{4,12}$/;
    if (!test3.test(ID.val())) {
        alert('아이디를 영문과 숫자 4~12자리로 공백없이 작성해주세요');
        ID.focus();
        return;
    }
    //아이디 처리
    
    var PW = $("#pw");
    var test4 = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9~!@#$%^&*?]{4,12}$/;
    if (!test4.test(PW.val())) {
        alert('비밀번호를 영문과 숫자 4~12자리로 공백없이 작성해주세요 + 특수문자 ~!@#$%^&*? 포함 가능!')
        PW.focus();
        return;
    }
    //비번 처리
    
    var PWC = $('#pwc');
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

    var dup1=$('#nicknamebool').val();
    if(dup1!='1'){
        alert('닉네임 중복확인을 해주세요!');
        NICK.focus();
        return;
    }   
    var dup2=$('#idbool').val();
    if(dup2!='1'){
        alert('아이디 중복확인을 해주세요!');
        ID.focus();
        return;
    }//중복 확인 처리

    if($('#quest').val()==="dir" && $('#direct').val()===''){
        alert('직접 입력할 질문을 작성해주세요!');
        $('#direct').focus();
        return;
    }
    if($('#quest').val()!="질문 없음"&& $('#ans').val()===''){
        alert('질문에 답변을 해주세요!');
        $('#ans').focus();
        return;
    }//질문 답변 입력시 처리

    if($('#year').val()){
        var test5=/^[0-9]{4,4}$/;
        if(!test5.test($('#year').val())){
            alert('년도는 4자리 숫자로!');
            $('#year').focus();
            return;
        }
    }
    if($('#day').val()){
        var val=$('#day').val();
        var test6=/^[0-9]{1,2}$/;
        if(!test6.test(val)||val<1||val>31){
            alert('날짜는 1~31 사이의 숫자로!!');
            $('#day').focus();
            return;
        }
    }//생년월일 처리
    
    $(form).submit();
}

enterpress = function () {
    if (window.event.keyCode == 13)
        Check('#new');
}

duplicheck = function () {
    var test = /^(?=.*[a-zA-Z]|.*[가-힣])[a-zA-Z0-9가-힣]{2,10}$/;
    if (!test.test($('#nickname').val())) {
        alert('닉네임은 한글 또는 영문을 포함한 2~10 글자로 작성해주세요');
        $('#nickname').focus();
        return;
    }
    $('#new').attr('action', '/home/newaccount');
    $('#new').submit();
}

duplicheck_ = function () {
    var test = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]{4,12}$/;
    if (!test.test($('#id').val())) {
        alert('아이디는 영문과 숫자 4~12자리로 공백없이 작성해주세요');
        $('#id').focus();
        return;
    }
    $('#new').attr('action', '/home/newaccount_');
    $('#new').submit();
}

nicknamechange = function () {
    $('#nicknamebool').val('');                    //중복확인 필요
    $('#nicknamedupok').attr('hidden', true);        
    $('#nicknamedupcheck').attr('hidden', false);    //사용가능->중복확인 
}//닉네임 칸 내용 변경시

idchange = function () {    
    $('#idbool').val('');                          //중복확인 필요
    $('#iddupok').attr('hidden', true);              
    $('#iddupcheck').attr('hidden', false);          //사용가능->중복확인
}//아이디 칸 내용 변경시
