import './App.css';
import Plot from 'react-plotly.js';

import GDP from './gdp.json';
import Unemployment from './unemployment.json';

function App() {
  const getRandomColor = () => {
    const letters = '0123456789ABCDEF';
    let color = '#';
    for (let i = 0; i < 6; i += 1) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
  };

  const xUnemployment = Unemployment.map((item) => item.month);
  const yUnemployment = Unemployment.map((item) => item.percent);

  const xGDP = GDP.map((item) => item.country);
  const yGDP = GDP.map((item) => item.percentage);
  
  return (
    <div className="App">
      <h1>Visualization of Trends in the Financial Sector since the Onset of COVID-19</h1>
      <div>Name: Rohan Mukherjee, Reg: 18BCE0221</div>


      <div className="sensex category">
        <h2>BSE and NSE Sensex analysis for Stock Markets</h2>
        <p>The following data demonstrates that the stock market values fell during the months of lockdown.</p>
        <iframe
          id="moneywiz_widget"
          name="moneywiz_widget"
          src="//money.rediff.com/widget/moneywizwidget"
          scrolling="no"
          frameborder="0"
          marginHeight="0"
          marginWidth="0"
          title="sensex"
          style={{ marginLeft: "5vw" }}
        />
      </div>


      <div className="category">
        <h2>GDP of various countries</h2>
        <p>The GDP in almost all countries has been on the decline since the start of the pandemic.</p>
        <Plot
          className="plot"
          data={[
            {
              x: xGDP,
              y: yGDP,
              name: 'unemployment',
              type: 'bar',
              marker: { color: getRandomColor() },
            }
          ]}
          layout={{
            width: '1000',
            height: '500',
            title: 'GDP of various countries',
            xaxis: {
              title: 'Month'
            },
            yaxis: {
              title: 'Percentage'
            }
          }}
          useResizeHandler
        />
      </div>


      <div className="category">
        <h2>Unemployment rates due to COVID-19</h2>
        <p>Unemployment rates are on the increase, peaking during the month of June.</p>
        <Plot
          className="plot"
          data={[
            {
              x: xUnemployment,
              y: yUnemployment,
              name: 'unemployment',
              type: 'scatter',
              mode: 'lines+markers',
              marker: { color: getRandomColor() },
            }
          ]}
          layout={{
            width: '1000',
            height: '500',
            title: 'Unemployment Rates in 2020',
            xaxis: {
              title: 'Month'
            },
            yaxis: {
              title: 'Percentage'
            }
          }}
          useResizeHandler
        />
      </div>
    </div>
  );
}

export default App;
