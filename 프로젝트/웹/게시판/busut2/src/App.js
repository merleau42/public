import axios        from 'axios';

import './App.css';
import Header   from  './components/Header.jsx';
import Slide    from  './components/Slide.jsx';
import Contents from  './components/Contents.jsx';
import Footer   from  './components/Footer.jsx';

import logo from './assets/logo.svg';

export default function App() {
  const getAllperson = async () => {
    // await axios.get('/person')
    const host = 'https://7777-firebase-solved-1748384822791.cluster-ikxjzjhlifcwuroomfkjrx437g.cloudworkstations.dev';
    await axios.get(`${host}/person`)
    .then(res=>{
      console.log(res);
      document.getElementById('msg').innerText = JSON.stringify(res);
    })
  }
  return (
    // <div id="wrap">
    //   <Header />
    //   <Slide />
    //   <Contents />
    //   <Footer />
    // </div>
    <div className="App">
      <button onClick={getAllperson}>모두 조회</button>
      <span id="msg">msg</span>
    </div>
  );
}