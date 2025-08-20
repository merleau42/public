import logo from './assets/logo.svg';
import './css/App.css';

import Header   from  './components/Header.jsx';
import Slide    from  './components/Slide.jsx';
import Contents from  './components/Contents.jsx';
import Footer   from  './components/Footer.jsx';


export default function App() {
  return (
    <div id="wrap">
      <Header />
      <Slide />
      <Contents />
      <Footer />
    </div>
  );
}