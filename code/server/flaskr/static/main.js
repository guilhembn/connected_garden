var myChart;
var i = 0;


function updatePlot(data){
    if (myChart != null && data != null){
        const colors = ['rgba(255, 99, 132, 1.0)', 'rgba(255, 99, 132, 0.2)']
        myChart.data.datasets[0].data.length = 0;
        myChart.data.datasets[0].pointBackgroundColor.length = 0;
        for (var i=0; i < data.length; i++){
            d = data[i];
            myChart.data.datasets[0].data.push({"x": new Date(d["timestamp"] * 1000), y: d["temperature"]});
            myChart.data.datasets[0].pointBackgroundColor.push(colors[d["timestamp_estimated"]]);
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
                backgroundColor: 'rgba(255, 0, 0, 0.6)',
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

