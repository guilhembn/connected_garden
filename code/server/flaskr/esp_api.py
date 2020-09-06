from flask import Blueprint, request, jsonify
from flaskr.db import get_db

bp = Blueprint('esp_api', __name__, url_prefix='/esp')

@bp.route("/new_measurement", methods=('GET', 'POST'))
def new_measurement():
    if request.method == "POST":
        timestamp = request.form['timestamp']
        temperature = request.form['temperature']
        humidity = request.form['humidity']
        
        db = get_db()
        if timestamp.isdigit() and temperature.isdigit() and humidity.isdigit():
            existing = db.execute("SELECT id FROM measure WHERE timestamp = ?", (int(timestamp), )).fetchone()
            if existing is None:
                db.execute("INSERT INTO measure (timestamp, temperature, humidity) VALUES (?, ?, ?)", (int(timestamp), int(temperature), int(humidity)))
                db.commit()
                return jsonify({"success": True})
    return jsonify({"success": False})

