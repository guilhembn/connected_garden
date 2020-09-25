var myChart;
var i = 0;

function computeDewPoint(temperature, humidity){
    const a = 17.27;
    const b = 237.7;
    const alpha = a * temperature / (b + temperature) + Math.log(humidity/100);
    return Math.round(b * alpha / (a - alpha));
}


function updatePlot(data){
    if (myChart != null && data != null){
        const colors = ['rgba(255, 99, 132, 1.0)', 'rgba(255, 99, 132, 0.2)']
        const colorsDewPoints = ['rgba(50, 20, 255, 1.0)', 'rgba(50, 20, 255, 0.2)']
        myChart.data.datasets[0].data.length = 0;
        myChart.data.datasets[0].pointBackgroundColor.length = 0;
        myChart.data.datasets[1].data.length = 0;
        myChart.data.datasets[1].pointBackgroundColor.length = 0;
        var dewPoint, d;
        for (var i=0; i < data.length; i++){
            d = data[i];
            dewPoint = computeDewPoint(d["temperature"], d["humidity"]);    
            myChart.data.datasets[0].data.push({"x": new Date(d["timestamp"] * 1000), y: d["temperature"]});
            myChart.data.datasets[0].pointBackgroundColor.push(colors[d["timestamp_estimated"]]);
            myChart.data.datasets[1].data.push({"x": new Date(d["timestamp"] * 1000), y: dewPoint});
            myChart.data.datasets[1].pointBackgroundColor.push(colorsDewPoints[d["timestamp_estimated"]]);
        }
        myChart.update();
    }
}

function getData(range='day'){
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.onreadystatechange = function() { 
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200){
            updatePlot(JSON.parse(xmlHttp.responseText)["data"]);
        }
    }
    xmlHttp.open("GET", "/connected_garden/data?range="+range, true); 
    xmlHttp.send(null);
}

window.onload = function() {
    var ctx = document.getElementById('test_plot');
    myChart = new Chart(ctx, {
        type: 'line',
        data: {
            datasets: [{
                data: [],
                pointBackgroundColor: [],
                fill: false,
                lineTension: 0
            },
            {
                data: [],
                pointBackgroundColor: [],
                fill: false,
                lineTension: 0
            }]
        },
        options: {
            scales: {
                xAxes: [{
                    type: 'time',
                    time: {
                        unit: 'hour'
                    }
                }]
            },
            aspectRatio: 3,
            maintainAspectRatio: false
        }
    });
    getData();

};

