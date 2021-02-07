module.exports = {
    userinfo: function (originnick, name, nick, id, email, quest, ans, year, month, day, pw) {
        return `<body>
        <header>
        <h1><span style="color:orange;">${originnick}</span> 님의 회원 정보</h1>
        <p><a href="/">메인 페이지로</a></p>
        </header>
        <div style="text-align: center;">
        <input class="findbtn btncss" type="button" id="basicinf" value="기본 정보" style="background-color: rgb(241, 237, 237);" onclick="
        clickbtn(this, '${id}', '${nick}', '${name}', '${email}', '${quest}', '${ans}', '${year}', '${month}', '${day}')
        ">
        <input class="findbtn btncss" id="pwinf" type="button" value="비밀번호 변경" style="background-color: rgb(176, 182, 182)" onclick="
        clickbtn(this, '${id}')     
        ">
        </div>
        <form id="new" method="post" action="/${id}/userinfo">
        <div style="text-align:center">
        <input style="border:2px double" class="inputbox3" value="ID: ${id}" disabled>
        <input type="hidden" name="id" value="${id}" hidden>
        </div>
        <br>
        <table>    
        <tr>
            <td><label for="name"><span class="star modif" hidden>* </span>성명</label></td>
            <td><input class="inputbox2 modif2" name="name" id="name" type="text" value="${name}" disabled></td>
        </tr>
        <tr>
            <td><label for="nickname"><span class="star modif" hidden>* </span>닉네임</label></td>
            <td>
                <input class="inputbox2 modif2" id="nickname" name="nickname" type="text" value="${nick}" disabled oninput="nicknamechange()">
                <button id="nicknamedupcheck" type="button" style="cursor:pointer;" onclick="duplicheck('${id}');"hidden>중복확인</button>
                <input type="text" class="dupli" id="nicknamedupok" value="사용 가능"hidden disabled>
            </td>
        </tr>
        <tr>
            <td><label for="email"><span class="star modif" hidden>* </span>이메일</label></td>
            <td><input class="inputbox2 modif2" name="email" id="email" type="text" value="${email}" disabled></td>
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
        <tr class="modif" hidden>
            <td></td><td><div style="text-align: right; font-size: x-small;"><span class="star">* </span>표시는 필수 입력</div></td>
        </tr>
        <input type="hidden" name="nicknamebool" id="nicknamebool">
        </table>
        <br>
        <div style="text-align: center;">      
                <input class="click btncss" type="button" id="modify" value="수정" onclick="Modify('${ans}',1);">
                <input class="inputbox2 modif" type="password" id="pw" name="pw" placeholder="비밀번호" value="${pw}" hidden>
                <div style="text-align: center; color:red; font-size:14px;" id="msg"></div>
                <p><input class="click modif btncss" type="button" value="완료" hidden onclick="Check('#new')">
                <input class="click modif btncss" type="button" value="취소" hidden onclick="
                location.href='/${id}/userinfo'
                "><p>
        </div> 
        </form>
        <script>
        $('.modif2').css('font-weight','bold')
        </script>
        `
    },
    header:function(nick,id){
        return `<body>
        <header>
            <h1><a href="/">NTBoard</a></h1>
            <div>
                <p style="font-size: 15px; font-weight: bold;">${nick}&nbsp님</p>
                <span><button style="cursor:pointer;" onclick="
                            location.href='/auth/logout'
                            ">로그아웃</button></span>
                <span><button style="cursor:pointer;" onclick="
                            location.href='/${id}/userinfo'
                            ">회원정보</button></span>
            </div>
            <br>
        </header>`
    },
    mainpg: function (nick, id) {
        return this.header(nick,id)+

        `<div id="new">
            <table>
                <tr>
                    <td><button style="cursor:pointer;" onclick="
                    location.href='/square'
                    ">자유게시판</button></td>
                    <td><button style="cursor:pointer;" onclick="
                    location.href='/square'
                    ">비밀게시판</button></td>
                </tr>
            </table>
        </div>`
    },
    square:function(db,nick,id){
        var head= this.header(nick,id);
        var  int=`
        <div id="grid">
        <table class="boardcate">
            <tr>
                <td>전체 글보기</td>
            </tr>
            <tr>
                <td>--드라마</td>
            </tr>
            <tr>
                <td>--영화</td>
            </tr>
            <tr>
                <td>--애니메이션</td>
            </tr>
            <tr>
                <td>--도서</td>
            </tr>
        </table>
        <div class="postlist">
            <table class="board">
            <tr><td><div style="text-align:right">    
            <input style="cursor:pointer" type="button" value="글쓰기" onclick="
            location.href='/square/write';
            "></div></td><tr>
        </div>`
        if(!db.length)
        var list=`<tr><td>게시글이 없습니다</td></tr></table></div></div>`
        else {
            var list='</table></div></div>';
            for(var i=0;i<db.length;i++){
                if(db[i].maintxt.length>15)
                var text=db[i].maintxt.substr(0,14)+'...';
                else var text=db[i].maintxt;
            var list= `<tr><td><div style="font-size:25px;font-weight:bold"><a href='/square/`+(i+1)+`'>${db[i].title}</a>&nbsp&nbsp&nbsp&nbsp
             <span style="font-size:15px;">by ${db[i].author}</span></div>
            <div>${text}</div><div>${db[i].date}</div>
            </td></tr>`+list;
            }
        }       
        return head+int+list
    },
    write:function(title,maintxt,num){
        return `
        <body>
        <form id="post" onsubmit="return false;"  method="post" action='/square/write'>
        <table>
            <tr>
                <td>
                <input type="text" class="inputbox" id="title" name="title" placeholder="제목" value="${title}"}>
                <span id="msg1" style="text-align: right; color:red;"></span>
                </td>
            </tr>
            <tr>
                <td>
                <textarea class="inputbox" id="maintxt" name="maintxt" placeholder="내용을 입력해주세요"}>${maintxt}</textarea>
                </td>
            </tr>  
            <tr style="text-align: right; color:red;"><td id="msg2"><br></td></tr>  
            <input type="hidden" name="num" value="${num}">  
        </table>    
        <div style="text-align: center;">      
                <button class="click btncss" type="button" onclick="
                Write('#post');
                ">완료</button>
                <input id="cancel" class="click btncss" type="button" value="취소" onclick="
                window.history.back();
                ">
            </div> 
        </form>
        `
    },
    post:function(title,maintxt,num){
        return`<body> 
        <form id="post" onsubmit="return false;"  method="post" action='/square/modify'>
        <table>
            <tr><td><div style="text-align:right">   
                <input style="cursor:pointer" type="button" value="글 목록" onclick="
                location.href='/square'">
                <input style="cursor:pointer" type="button" value="글 수정" onclick="
                form.submit();
                "></div></td><tr>
            <tr>
                <td>
                <input class="inputbox" id="title" name="title" value="${title}" readonly></div>
                <div id="date" style="font-size:10px; color:gray;"></div>
                </td>
            </tr>
            <tr>
                <td>
                <textarea id="maintxt" name="maintxt" style="font-size:30px;font-weight:bold" readonly>${maintxt}</textarea>
                </td>
            </tr>
            <input type="hidden" name="num" value="${num}">  
        </table>    
        </form>`
    }

}