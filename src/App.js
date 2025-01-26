import ApiCall from './components/ApiCall';
import MainDetails from './components/MainDetails';
import SecondaryDetails from './components/SecondaryDetails';
import Hourly from './components/Hourly';
import Weekly from './components/Weekly';
function App() {
  return (
    <div>
      <ApiCall/>
      <MainDetails/>
      <SecondaryDetails/>
      <Hourly/>
      <Weekly/>
    </div>
  );
}

export default App;
