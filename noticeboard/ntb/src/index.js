import React from 'react';
import ReactDOM from 'react-dom';
import {Hashrouter} from 'react-router-dom';
import "bootstrap/dist/css/bootstrap.min.css";
import Header from './header';
import Body from './body';
import Footer from './footer';


ReactDOM.render(
  <Hashrouter>
    <Header/>
    <Body/>
    <Footer/>
  </Hashrouter>
);


