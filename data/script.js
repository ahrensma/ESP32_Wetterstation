window.addEventListener('load', () => {
  const tempGauge = new LinearGauge({
    renderTo: 'tempGauge',
    width: 200,
    height: 400,
    units: "Temperature (°C)",
    minValue: 0,
    maxValue: 50,
    majorTicks: ["0", "10", "20", "30", "40", "50"],
    minorTicks: 2,
    strokeTicks: true,
    highlights: [
      { from: 0, to: 10, color: 'rgba(0,0, 255, .3)' },
      { from: 30, to: 50, color: 'rgba(255, 0, 0, .3)' }
    ],
    colorPlate: "#fff",
    borderShadowWidth: 0,
    borders: false,
    needleType: "arrow",
    needleWidth: 2,
    animationDuration: 1500,
    animationRule: "linear"
  }).draw();

  const humGauge = new RadialGauge({
    renderTo: 'humGauge',
    width: 300,
    height: 300,
    units: "Humidity (%)",
    minValue: 0,
    maxValue: 100,
    majorTicks: ["0", "20", "40", "60", "80", "100"],
    minorTicks: 2,
    strokeTicks: true,
    highlights: [
      { from: 0, to: 30, color: 'rgba(0, 0, 255, .3)' },
      { from: 60, to: 100, color: 'rgba(255, 0, 0, .3)' }
    ],
    colorPlate: "#fff",
    borderShadowWidth: 0,
    borders: false,
    needleType: "arrow",
    needleWidth: 2,
    animationDuration: 1500,
    animationRule: "linear"
  }).draw();

  function fetchData() {
    fetch('/sensor')
      .then(response => response.json())
      .then(data => {
        tempGauge.value = data.temperature;
        humGauge.value = data.humidity;
      })
      .catch(error => console.error('Error:', error));
  }

  setInterval(fetchData, 5000);
});
