function clickbtn(but){
    var btn2, btn=$(but);
    if(btn.attr('id')==='idfind'){
        btn2=$('#pwfind');
        $("form").html(`
        <table>
            <tr>
                <td><label for="name">성명</label></td>
                <td><input id="name" type="text" placeholder="성명"></td>
            </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <input class="click" type="submit" value="확인">
        </div>
        `)
    }
    else {
        btn2=$('#idfind');
        $('form').html(`
        <table>
            <tr>
                <td><label for="name">성명</label></td>
                <td><input id="name" type="text" placeholder="성명"></td>
            </tr>
            <tr>
                <td><label for="id">아이디</label></td>
                <td><input id="id" type="text" placeholder="아이디"></td>
            </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <input class="click" type="submit" value="확인">
        </div>`);
    }
    if(btn.css("background-color") != "rgb(241, 237, 237)"){
        btn.css("background-color","rgb(241, 237, 237)");
        btn2.css("background-color","rgb(176, 182, 182)");
    }
}
