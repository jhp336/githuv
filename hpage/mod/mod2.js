const f = require("session-file-store")

module.exports={
    userinfo:function(name,nick,id,quest,ans,year,month,day){
        return `<header>
        <h1><p style="color:orange">${nick}<p> 님의 회원 정보</h1>
        </header>
        <form id="new" method="post" action="/:userid/userinfo/assign">
        <table>
        <tr>
            <td><label for="name">성명</label></td>
            <td><input class="inputbox2" name="name" id="name" type="text" value="${name}" disabled></td>
        </tr>
        <tr>
            <td><label for="nickname">닉네임</label></td>
            <td>
                <input class="inputbox2" id="nickname" name="nickname" type="text" value="${nick}" disabled onkeydown="nicknamechange()">
                <button id="nicknamedupcheck" type="button" onclick="duplicheck()"hidden>중복확인</button>
                <input type="text" class="dupli" id="nicknamedupok" value="사용 가능" hidden disabled>
            </td>
            
        </tr>
        <tr>
            <td><label for="id">아이디</label></td>
            <td><input class="inputbox2" name="id" id="id" type="text" value="${id}" disabled onkeydown="idchange()">
            <button id="iddupcheck" type="button" onclick="duplicheck_()" hidden>중복확인</button>
            <input type="text" class="dupli" id="iddupok" value="사용 가능" hidden disabled>
        </tr>
        <tr>
            <td><label for="direct">분실 시 질문</label></td>
            <td>
                <input name="quest" id="quest" class="inputbox2" type="text" value="${quest}" disabled>
            </td>                        
        </tr>
        <tr>
            <td><label for="ans">답변</label></td>
            <td><input class="inputbox2" type="text" name="ans" id="ans" value="${ans}" disabled ></td>
        </tr>
        <tr>
            <td><label for="birth">생년월일</label></td>
            <td>
                <input class="inputbox2" name="year" id="year" type="text" value="${year}" maxlength="4" style="width: 67px;" disabled>
                <input class="inputbox2" type="text" name="month" id="month" style="width:60px;" value="${month}" maxlength="2" disabled>
                <input class="inputbox2" type="text" name="day" id="day" value="${day}" maxlength="2" style="width: 18px;" disabled>
            </td>
        </tr>
        </tabel>
        <br>
        <div style="text-align: center;">      
                <input class="click" type="button" id="assign" value="수정">
        </div> 
        </form>`
    },
    mainpg:function(nick,id){
        return `<body>
        <header>
            <h1>NTBoard</h1>
            <div>
                <p font-size: 15px; font-weight: bold;">${nick}&nbsp님</p>
                <span><button onclick="
                            location.href='/auth/logout'
                            ">로그아웃</button></span>
                <span><button onclick="
                            location.href='/${id}/userinfo'
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
    }


}