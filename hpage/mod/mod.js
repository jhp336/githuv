module.exports={
    HTML:function(title,body){
        return `
        <!DOCTYPE html>
        <html>
            <head>
                <link rel="stylesheet" href="/css/style.css">
                <meta charset="utf-8">
                <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha256-4+XzXVhsDmqanXGHaHvgh1gMQKX40OUvDEBTu8JcmNs=" crossorigin="anonymous"></script>
                <script src="/js/${title}.js"></script>
                <title>${title}</title>
            </head>
        <body onkeypress="enterpress()">
            ${body}
        </body>
    </html>
        `
    },
    BODY:function(title){
        if(title=="login")
        return `<header>
        <h1>로그인</h1>
        <p style="font-weight:bold;">계정에 로그인을 해주세요!</p>
    </header>
    <form id="new" name="login" method="POST" action="login.php">
        <table>
            <tr>
                <td><input class="inputbox" name="user_id" id="id" type="text" placeholder="아이디"></td>
            </tr>
            <tr>
                <td><input class="inputbox" name="user_pw" id="pw" type="password" placeholder="비밀번호"></td>
            </tr>
        </table>     
        <div style="text-align: center;">
            <input id="login" class="btn" type="button" value="로그인" onclick="Login('#new')">
        </div>
        <div style="text-align: center;"><a href="/home/findidpw">아이디/비밀번호를 잊으셨나요?</a></div>
        <div style="text-align: center;"><a href="/home/newaccount">계정이 없으신가요?</a></div>
    </form>`
    
    else if(title=="newaccount")
    return `<header>
    <h1>회원가입</h1>
     <p style="font-weight:bold;">새 계정을 만들어 보세요!</p>
        </header>
        <form id="new" name="new" method="POST" action="./register">
            <table>
                <tr>
                    <td><label for="name"><span>* </span>성명</label></td>
                    <td><input class="inputbox2" id="name" type="text" placeholder="성명"></td>
                </tr>
                <tr>
                    <td><label for="id"><span>* </span>아이디</label></td>
                    <td><input class="inputbox2" name="id" id="id" type="text" placeholder="아이디"></td>
                </tr>
                <tr>
                    <td><label for="pw"><span>* </span>비밀번호</label></td>
                    <td><input class="inputbox2" id="pw" type="password" placeholder="비밀번호"></td>
                </tr>
                <tr>
                    <td><label for="pwc"><span>* </span>비밀번호 확인</label></td>
                    <td><input class="inputbox2" id="pwc" type="password" placeholder="비밀번호 확인"></td>
                </tr>
                <tr>
                    <td><label for="direct"><span>&nbsp&nbsp</span>분실 시 질문</label></td>
                    <td>
                        <select class="inputbox2" style="width:224px; height: 30px;" name="que" onchange="question(this)">
                            <option value="0">::선택::</option>
                            <option value="별명은?">별명은?</option>
                            <option value="고향은?">고향은?</option>
                            <option value="dir">직접 입력</option>
                        </select>
                    </td>                        
                </tr>
                <tr>
                    <td></td>
                    <td><input class="inputbox2" type="text" id="direct" placeholder="질문을 입력하세요" hidden></td>
                </tr>
                <tr>
                    <td><label for="ans"><span>&nbsp&nbsp</span>답변</label></td>
                    <td><input class="inputbox2" type="text" id="ans" disabled ></td>
                </tr>
                <tr>
                    <td><label for="birth"><span>&nbsp&nbsp</span>생년월일</label></td>
                    <td>
                        <input class="inputbox2" id="birth" type="text" pattern="[0-9]{4,4}" placeholder="년도(4자리)" maxlength="4" style="width: 70px;">
                        <select class="inputbox2" style="width:60px; height: 30px; " >
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
                        <input class="inputbox2" type="text" placeholder="일" pattern="[0-9]{1,2}" maxlength="2" style="width: 34.9px;">
                    </td>
                </tr>
                <tr>
                    <td><span>&nbsp&nbsp</span>성별</td>
                    <td>
                        <input name="sex" type="radio">남성
                        <input name="sex" type="radio">여성    
                    </td>
                </tr>
                <tr>
                    <td></td><td><div style="text-align: right; font-size: x-small;"><span>* </span>표시는 필수 입력</div></td>
                </tr>
                <tr><td><br></td></tr>
                
            </table>             
            <div id="btn" style="text-align: center;">      
                <button class="click" type="button" onclick="
                Check('#new');
                ">완료</button>
                <input class="click" type="button" value="취소" onclick="
                location.href='/home/login'
                ">
            </div> 
        </form>`
        else if(title=="findidpw")
        return `<header>
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
        <form id="new">
        <table>
            <tr>
                <td><input class="inputbox" name="name" id="name" type="text" placeholder="성명"></td>
            </tr>
        </table>
        <br>
        <div style="text-align: center;">
            <input class="click" type="button" value="확인" onclick="Pressbtn('#new')">
        </div>
        </form>`

        else return 'err'
    }
}