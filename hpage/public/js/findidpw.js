function clickbtn(but){
    var btn2, btn=$(but)
    if(btn.attr('id')==='idfind'){
        btn2=$('#pwfind');
        $('form').html(`
        <table>
            <tr>
                <td><input class="inputbox" name= "name" id="name" type="text" placeholder="성명"></td>
            </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <input class="click" type="button" value="확인"  onclick="Pressbtn('#new')">
        </div>
        `)
    }
    else {
        btn2=$('#idfind');
        $('form').html(`
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
        </div>`);
    }
    if(btn.css("background-color") != "rgb(241, 237, 237)"){
        btn.css("background-color","rgb(241, 237, 237)");
        btn2.css("background-color","rgb(176, 182, 182)");
    }
}

enterpress=function(){
    if(window.event.keyCode==13)
    Pressbtn('#new');
}
Pressbtn=function(form){
    var NAME=$('#name');
    var ID=$('#id');
    if(NAME.val()===""){
        alert('이름을 입력해주세요');
        NAME.focus();
        return;
    }
    if(ID.val()===""){
        alert('아이디를 입력해주세요');
        ID.focus();
        return;
    }

    $(form).submit();
}