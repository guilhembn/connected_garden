from flask import Blueprint, request, jsonify
from flaskr.db import get_db

bp = Blueprint('esp_api', __name__, url_prefix='/esp')

@bp.route("/new_measurement", methods=('GET', 'POST'))
def new_measurement():
    if request.method == "POST":
        timestamp = request.form['timestamp']
        temperature = request.form['temperature']
        humidity = request.form['humidity']
        estimated_timestamp = request.form['timestampestimated']
        
        db = get_db()
        if timestamp.isdigit() and temperature.isdigit() and humidity.isdigit() and estimated_timestamp is not None:
            existing = db.execute("SELECT id FROM measure WHERE timestamp = ?", (int(timestamp), )).fetchone()
            if existing is None:
                estimated_timestamp = 1 if estimated_timestamp == "1" else 0
                db.execute("INSERT INTO measure (timestamp, temperature, humidity, estimatedTimestamp) VALUES (?, ?, ?, ?)", 
                        (int(timestamp), int(temperature), int(humidity), estimated_timestamp))
                db.commit()
                return jsonify({"success": True})
    return jsonify({"success": False})

