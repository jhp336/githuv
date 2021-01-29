var db=require('./db');
module.exports={
    userinfo:function(originnick,name,nick,id,quest,ans,year,month,day){
        return `<header>
        <h1><span style="color:orange;">${originnick}</span> 님의 회원 정보</h1>
        <p><a href="/">메인 페이지로</a></p>
        </header>
        <form id="new" method="post" action="/${id}/userinfo/assign">
        <div style="text-align:center">
        <input class="inputbox3" value="ID: ${id}" disabled>
        <input type="hidden" name="id" value="${id}" hidden>
        </div>
        <br>
        <table>    
        <tr>
            <td><label for="name">성명</label></td>
            <td><input class="inputbox2 modif2" name="name" id="name" type="text" value="${name}" disabled></td>
        </tr>
        <tr>
            <td><label for="nickname">닉네임</label></td>
            <td>
                <input class="inputbox2 modif2" id="nickname" name="nickname" type="text" value="${nick}" disabled onkeydown="nicknamechange()">
                <button id="nicknamedupcheck" type="button" onclick="duplicheck('${id}');"hidden>중복확인</button>
                <input type="text" class="dupli" id="nicknamedupok" value="사용 가능" hidden disabled>
            </td>
        </tr>
        <tr>
            <td><label for="quest">분실 시 질문</label></td>
            <td>
                <input name="quest" id="quest" class="inputbox2 modif2" type="text" value="${quest}" disabled>
            </td>                        
        </tr>
        <tr>
            <td><label for="ans">답변</label></td>
            <td><input class="inputbox2 modif2" type="text" name="ans" id="ans" value="수정 시 볼 수 있습니다" style="font-style: italic; color:red" disabled ></td>
        </tr>
        <tr>
            <td>생년월일</label></td>
            <td>
                <input class="inputbox2 modif2" name="year" id="year" type="text" value="${year}" maxlength="4" style="width: 67px;" disabled>
                <input class="inputbox2 modif2" type="text" name="month" id="month" style="width:27px;" value="${month}" maxlength="2" disabled>
                <input class="inputbox2 modif2" type="text" name="day" id="day" value="${day}" maxlength="2" style="width: 27px;" disabled>
            </td>
        </tr>
        <input type="hidden" name="nicknamebool" id="nicknamebool">
        </table>
        <br>
        <div style="text-align: center;">      
                <input class="click" type="button" id="modify" value="수정" onclick="Modify('${ans}',0);">
                <input class="inputbox2 modif" type="password" name="pw" placeholder="비밀번호" hidden>
                <p><input class="click modif" type="button" value="완료" hidden onclick="Check('#new')">
                <input class="click modif" type="button" value="취소" hidden onclick="
                window.history.back();
                "><p>
        </div> 
        </form>`
    },
    mainpg:function(nick,id){
        return `<body>
        <header>
            <h1>NTBoard</h1>
            <div>
                <p style="font-size: 15px; font-weight: bold;">${nick}&nbsp님</p>
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