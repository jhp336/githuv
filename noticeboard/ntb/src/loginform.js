import React, {component} from 'react';
import {Form, Button} from 'react-bootstrap';
import axios from 'axios';
import $ from 'jquery';
import {} from 'jquery.cookies';
axios.defaults.withCredentials = true;
const headers = {withCredentials: true};

class LoginForm extends component {
    join=()=>{
        const send_para={
            headers,
            email: this.joinEmail.value,
            name: this.joinName.value,
            password: this.joinPw.value
        };
        axios
        .post("http://localhost:8080/member/join",send_para)
        .then(returndata => {
            if(returndata.data.message) {
                alert(returndata.data.message);
            }
            else alert("회원가입 실패");
        })
        .catch(err=>{
            console.log(err);
        });
    };

    login=()=>{
        const send_para={
            headers,
            email: this.loginEmail.value,
            password: this.loginPw.value
        };
        axios
        .post("http://localhost:8080/member/login",send_para)
        .then(returndata => {
            if(returndata.data.message) {
               // console.log("login_id:" + returndata.data._id);
                $.cookie("login_id", returndata.data._id);
                alert(returndata.data.message);
                window.location.reload();    //새로고침
            }
            else alert("로그인 실패");
        })
        .catch(err=>{
            console.log(err);
        });
    }
}