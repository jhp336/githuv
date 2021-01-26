module.exports = {
    HTML: function (title, js, body) {
        return `
        <!DOCTYPE html>
        <html>
            <head>
                <link rel="stylesheet" href="/css/style.css">
                <meta charset="utf-8">
                <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha256-4+XzXVhsDmqanXGHaHvgh1gMQKX40OUvDEBTu8JcmNs=" crossorigin="anonymous"></script>
                <script src="/js/${js}.js"></script>
                <title>${title}</title>
            </head>
        <body onkeydown="enterpress()">
            ${body}
        </body>
    </html>
        `
    },
    LOGIN: function (msg) {
        wrong = '';
        if (msg != "")
            wrong = '<script>$(\'#id\').focus()</script>';

        return `<header>
        <h1>로그인</h1>
        <p style="font-weight:bold;">계정에 로그인을 해주세요!</p>
        </header>
        <form id="new" name="login" method="post" action="/auth/login">
        <table>
            <tr>
                <td><input class="inputbox" name="user_id" id="id" type="text" placeholder="아이디"></td>
            </tr>
            <tr>
                <td><input class="inputbox" name="user_pw" id="pw" type="password" placeholder="비밀번호"></td>
            </tr>
            <tr style="text-align: right; color:red;"><td id="msg">${msg}</td></tr>
        </table>     
        <div style="text-align: center;">
            <input id="login" class="btn" type="button" value="로그인" onclick="Login('#new')">
        </div>
        <div style="text-align: center;"><a href="/home/findidpw">아이디/비밀번호를 잊으셨나요?</a></div>
        <div style="text-align: center;"><a href="/home/newaccount">계정이 없으신가요?</a></div>
        </form>${wrong}`
    },
    NEWACC: function () {
        return `<header>
    <h1>회원가입</h1>
     <p style="font-weight:bold;">새 계정을 만들어 보세요!</p>
        </header>
        <form id="new" name="new" method="post" action="/auth/join">
            <table>
                <tr>
                    <td><label for="name"><span>* </span>성명</label></td>
                    <td><input class="inputbox2" name="name" id="name" type="text" placeholder="성명"></td>
                </tr>
                <tr>
                    <td><label for="nickname"><span>* </span>닉네임</label></td>
                    <td>
                        <input class="inputbox2" id="nickname" name="nickname" type="text" placeholder="닉네임" onkeydown="nicknamechange()">
                        <button id="nicknamedupcheck" type="button" onclick="duplicheck()">중복확인</button>
                        <input type="text" class="dupli" id="nicknamedupok" value="사용 가능" hidden disabled>
                    </td>
                    
                </tr>
                <tr>
                    <td><label for="id"><span>* </span>아이디</label></td>
                    <td><input class="inputbox2" name="id" id="id" type="text" placeholder="아이디" onkeydown="idchange()">
                    <button id="iddupcheck" type="button" onclick="duplicheck_()">중복확인</button>
                    <input type="text" class="dupli" id="iddupok" value="사용 가능" hidden disabled>
                </tr>
                <tr>
                    <td><label for="pw"><span>* </span>비밀번호</label></td>
                    <td><input class="inputbox2" name="pw" id="pw" type="password" placeholder="비밀번호"></td>
                </tr>
                <tr>
                    <td><label for="pwc"><span>* </span>비밀번호 확인</label></td>
                    <td><input class="inputbox2" name="pwc" id="pwc" type="password" placeholder="비밀번호 확인"></td>
                </tr>
                
                <tr>
                    <td><label for="direct"><span>&nbsp&nbsp</span>분실 시 질문</label></td>
                    <td>
                        <select name="quest" id="quest" class="inputbox2" style="width:204px; height: 30px;" name="que" onchange="question(this)">
                            <option value="질문 없음">::선택::</option>
                            <option value="별명은?">별명은?</option>
                            <option value="고향은?">고향은?</option>
                            <option value="dir">직접 입력</option>
                        </select>
                    </td>                        
                </tr>
                <tr>
                    <td></td>
                    <td><input class="inputbox2" type="text" name="direct_q" id="direct" placeholder="질문을 입력하세요" hidden></td>
                </tr>
                <tr>
                    <td><label for="ans"><span>&nbsp&nbsp</span>답변</label></td>
                    <td><input class="inputbox2" type="text" name="ans" id="ans" disabled ></td>
                </tr>
                <tr>
                    <td><label for="birth"><span>&nbsp&nbsp</span>생년월일</label></td>
                    <td>
                        <input class="inputbox2" name="year" id="year" type="text" placeholder="년도(4자리)" maxlength="4" style="width: 67px;">
                        <select class="inputbox2" name="month" id="month" style="width:60px; height: 30px; " >
                        <option>월</option>
                        <option>01</option>
                        <option>02</option>
                        <option>03</option>
                        <option>04</option>
                        <option>05</option>
                        <option>06</option>
                        <option>07</option>
                        <option>08</option>
                        <option>09</option>
                        <option>10</option>
                        <option>11</option>
                        <option>12</option>
                        </select>
                        <input class="inputbox2" type="text" name="day" id="day" placeholder="일" maxlength="2" style="width: 18px;">
                    </td>
                </tr>
                <tr>
                    <td></td><td><div style="text-align: right; font-size: x-small;"><span>* </span>표시는 필수 입력</div></td>
                </tr>
                <tr><td><br></td></tr>
                <input type="hidden" name="nicknamebool" id="nicknamebool">
                <input type="hidden" name="idbool" id="idbool">

            </table>             
            <div style="text-align: center;">      
                <button class="click" type="button" onclick="
                Check('#new');
                ">완료</button>
                <input class="click" type="button" value="취소" onclick="
                location.href='/home/login'
                ">
            </div> 
        </form>`
    },
    FINDIDPW: function (opt, msg) {
        var part = `<header>
        <h1>아이디/비밀번호 찾기</h1>
        <p><a href="/home/login">로그인 화면으로</a></p>    
        </header>
        <div style="text-align: center;">
        <input class="findbtn" id="idfind" type="button"  value="아이디 찾기" style="background-color: rgb(241, 237, 237);" onclick="
        clickbtn(this);
        ">
        <input class="findbtn" id="pwfind" type="button" value="비밀번호 찾기"style="background-color: rgb(176, 182, 182)" onclick="
        clickbtn(this);
        ">
        </div>
        <form id="new" onsubmit="return false;" method="post" action="/home/findidpw">
        `
        
        if (!opt) //찾기 전
            return part +
                `<table>
        <tr>
            <td><input class="inputbox" name= "name" id="name" type="text" placeholder="성명"></td>
        </tr>
        <tr>
            <td><input class="inputbox" name="nickname" id="nickname" type="text" placeholder="닉네임"></td>
        </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <button class="click" type="button" onclick="Pressbtn('#new')">확인</button>
            </div>
        </form>`;

        var result=`<table>
                    <tr>
                        <td>${opt} 찾기 결과</td><td></td>
                    </tr>
                    <tr>
                        <td><input class="inputbox3" type="text" disabled value="${msg}"></td>
                    </tr>
                </table>
            <br>
            </form>`;
        if(opt==="아이디"){            
            return part + result;
            }
        if(opt === "비밀번호"){
            var btn = `<script>
            $('#pwfind').css("background-color", "rgb(241, 237, 237)");
            $('#idfind').css("background-color", "rgb(176, 182, 182)");
            </script>`
            if(!msg.question) //계정 정보x 혹은 질문 답변까지 완료 시
            return part+ btn + result;
            var id=msg.id;
            if(msg.question==='dir')//질문이 직접입력일 시
            msg=msg.direct;
            else msg=msg.question;
            return part + btn
            +`<table>
            <tr>
                <td>${opt} 찾기 결과</td><td></td>
            </tr>
            <tr>
                <td><input class="inputbox3" type="text" disabled value="${msg}"></td>
            </tr>
            <tr>
                <td><input class="inputbox3" type="text" name="answer" placeholder="답변"></td>
            </tr>
            <input type="hidden" name="id" value="${id}">
            </table>
            <br>
            <div style="text-align: center;">
                <button class="click" type="button" onclick="Pressbtn('#new')">확인</button>
            </div>
            </form>
            `
        }

    }

}
